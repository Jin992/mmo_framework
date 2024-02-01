#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdio>
#include <iostream>
 
void report_error(std::string_view component, boost::system::error_code ec)
{
  std::cerr << component << " failure: "
            << ec << " ()" << ec.message() << ")\n";
}
 
boost::asio::awaitable<void> session(boost::asio::ip::tcp::socket socket, std::function<void(char*, std::size_t)> callback)
{
  try
  {
    char data[1024];
    for (;;)
    {
      std::size_t n = co_await socket.async_read_some(boost::asio::buffer(data), boost::asio::use_awaitable);
      callback(data, n);
      //co_await async_write(socket, boost::asio::buffer(data, n), boost::asio::use_awaitable);
    }
  }
  catch (boost::system::system_error const& e)
  {
    if (e.code() == boost::asio::error::eof)
      std::cerr << "Session done \n";
    else
      report_error("Session", e.code());
  }
}
 
boost::asio::awaitable<void> listener(boost::asio::io_context& context, unsigned short port, std::function<void(char*, std::size_t)> callback)
{
    boost::asio::ip::tcp::acceptor acceptor(context, {boost::asio::ip::tcp::v4(), port});
    try
    {
        for (;;)
        {
            std::cout << "Waiting for connection" << std::endl;
            boost::asio::ip::tcp::socket socket = co_await acceptor.async_accept(boost::asio::use_awaitable);
            boost::asio::co_spawn(context, session(std::move(socket), callback), boost::asio::detached);
        }
    }
    catch (boost::system::system_error const& e)
    {
        report_error("Listener", e.code());
    }
    std::cout << "Exiting listener" << std::endl;
}

class TcpServer{
    public:
        TcpServer(unsigned short port)
        : m_context()
        , m_port(port)
        {}

        void run(std::function<void(char*, std::size_t)> callback)
        {
            try {
                auto listen = listener(m_context, m_port, callback);
                boost::asio::co_spawn(m_context, std::move(listen), boost::asio::detached);
                std::cout << "Starting listening on Port: " << m_port << std::endl;
                m_context.run();
                std::cerr << "Server done \n";
            }
            catch (std::exception& e)
            {
                std::cerr << "Server failure: " << e.what() << "\n";
            }

        }

    private:
        boost::asio::io_context         m_context;
        short int                       m_port;
};