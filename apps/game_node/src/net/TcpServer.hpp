#ifndef MMO_NET_TCP_SERVER_HPP
#define MMO_NET_TCP_SERVER_HPP
#include <cstdlib>
#include <memory>
#include "Subject.hpp"
#include "net/TcpSession.hpp"

class TcpServer
: public Subject<std::shared_ptr<TcpSession>>
{
public:
  explicit TcpServer(short port);
  void run();

private:
  void do_accept();

private:
  boost::asio::io_context io_context;
  tcp::acceptor acceptor_;
};
#endif