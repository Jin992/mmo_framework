#include "net/TcpSession.hpp"

TcpSession::TcpSession(tcp::socket socket)
: socket_(std::move(socket))
{}

void TcpSession::start()
{
    do_read();
}

void TcpSession::sendData(net::common::RawNetworkData data)
{
    do_write(data);
}

void TcpSession::do_read()
{
    auto self(this->shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
                            [this, self](boost::system::error_code ec, std::size_t length)
                            {
                                if (!ec)
                                {
                                    notifyObservers(net::common::RawNetworkData(data_, data_ + length));
                                    do_read();
                                }
                            });
}

void TcpSession::do_write(net::common::RawNetworkData data)
{
    auto self(this->shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/)
                             {
                                 if (!ec)
                                 {

                                 }
                             });
}