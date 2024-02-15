#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include "net/TcpSession.hpp"
#include "Subject.hpp"


class TcpServer
: public Subject<std::shared_ptr<TcpSession>>
{
public:
  TcpServer(short port) : io_context(), acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
  {
    do_accept();
  }

  void run()
  {
    io_context.run();
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket)
        {
          if (!ec)
          {
            auto sessionPtr = std::make_shared<TcpSession>(std::move(socket));
            notifyObservers(sessionPtr);
            std::cout << "Accept" << std::endl;
          }

          do_accept();
        });
  }

private:
  boost::asio::io_context io_context;
  tcp::acceptor acceptor_;

};
















// void report_error(std::string_view component, boost::system::error_code ec)
// {
//   std::cerr << component << " failure: "
//             << ec << " ()" << ec.message() << ")\n";
// }

// template <typename ResponseType>
// class TcpServer{
//     public:
//         TcpServer(unsigned short port)
//         : m_context()
//         , m_port(port)
//         , m_signals(m_context, SIGINT, SIGTERM)
//         {
//         }
//         void run()
//         {
//            m_signals.async_wait([this](auto, auto){ 
//               std::cout << "Ctrl + C detected, stop." << std::endl;
//               m_context.stop(); 
//             });
//             try {
//                 auto listen = listener(m_context, m_port);
//                 boost::asio::co_spawn(m_context, std::move(listen), boost::asio::detached);
//                 std::cout << "Starting listening on Port: " << m_port << std::endl;
//                 m_context.run();
//                 std::cerr << "Server done \n";
//             }
//             catch (std::exception& e)
//             {
//                 std::cerr << "Server failure: " << e.what() << "\n";
//             }

//         }
    
//     private:
//         boost::asio::awaitable<void> listener(boost::asio::io_context& context, unsigned short port)
//         {
//             boost::asio::ip::tcp::acceptor acceptor(context, {boost::asio::ip::tcp::v4(), port});
//             try
//             {
//               for (;;)
//               {
//                   boost::asio::ip::tcp::socket socket = co_await acceptor.async_accept(boost::asio::use_awaitable);
//                   boost::asio::co_spawn(context, session(std::move(socket)), boost::asio::detached);
//               }
//             }
//             catch (boost::system::system_error const& e)
//             {
//               report_error("Listener", e.code());
//             }
//             std::cout << "Exiting listener" << std::endl;
//         }

//         boost::asio::awaitable<void> session(boost::asio::ip::tcp::socket socket)
//         {
//           try
//           {
//             std::cout << "Connection established" << std::endl;
//             char data[1024];
//             for (;;)
//             {
//               std::size_t n = co_await socket.async_read_some(boost::asio::buffer(data), boost::asio::use_awaitable);
//               ResponseType response;
//               auto result = co_await response.get(net::common::RawNetworkData(data, data + n));
//               co_await async_write(socket, boost::asio::buffer(result), boost::asio::use_awaitable);
//             }
//           }
//           catch (boost::system::system_error const& e)
//           {
//             if (e.code() == boost::asio::error::eof)
//               std::cerr << "Session done eof\n";
//             else
//               report_error("Session", e.code());
//             }
//           }

//     private:
//         boost::asio::io_context         m_context;
//         short int                       m_port;
//         boost::asio::signal_set         m_signals;
// };