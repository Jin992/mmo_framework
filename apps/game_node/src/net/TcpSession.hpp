#ifndef MMO_NET_TCP_SESSION
#define MMO_NET_TCP_SESSION

#include <boost/asio.hpp>
#include "net/Common.hpp"
#include "Subject.hpp"
using boost::asio::ip::tcp;

class TcpSession
  : public std::enable_shared_from_this<TcpSession>, public Subject<net::common::RawNetworkData>
{
public:
  TcpSession(tcp::socket socket): socket_(std::move(socket))
  {}

  void start()
  {
    do_read();
  }

  void sendData(net::common::RawNetworkData data) 
  {
      do_write(data);
  }

private:
  void do_read()
  {
    auto self(this->shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        [this, self](boost::system::error_code ec, std::size_t length)
        {
          if (!ec)
          {
            auto data = net::common::RawNetworkData(data_, data_ + length);
            notifyObservers(data);
            //do_write(result);
            do_read();
          }
        });
  }

  void do_write(net::common::RawNetworkData data)
  {
    auto self(this->shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            //do_read();
          }
        });
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

#endif