#include "net/TcpServer.hpp"
#include <utility>
#include <iostream>

TcpServer::TcpServer(short port)
: io_context()
, acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{
    do_accept();
}

void TcpServer::run()
{
    io_context.run();
}

void TcpServer::do_accept()
{
    acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    auto sessionPtr = std::make_shared<TcpSession>(std::move(socket));
                    notifyObservers(sessionPtr);
                }
                do_accept();
            });
}