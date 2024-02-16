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
  TcpSession(tcp::socket socket);
  void start();
  void sendData(net::common::RawNetworkData data);

private:
  void do_read();
  void do_write(net::common::RawNetworkData data);

private:
  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

#endif