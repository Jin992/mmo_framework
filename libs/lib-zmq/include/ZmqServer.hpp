#include "zmq.hpp"
#include "zmq_addon.hpp"
#include "ZmqAddrs.hpp"
#include <iostream>
namespace lib::mmo_zmq::server
{

template <typename REQ, typename RESP>
class ZmqServer {
public:
    /*
    req = ZMQ_REQ,
    rep = ZMQ_REP,
    dealer = ZMQ_DEALER,
    router = ZMQ_ROUTER,
    pub = ZMQ_PUB,
    sub = ZMQ_SUB,
    xpub = ZMQ_XPUB,
    xsub = ZMQ_XSUB,
    push = ZMQ_PUSH,
    pull = ZMQ_PULL,*/
    ZmqServer(zmq::socket_type type, const std::string &addr): mCtx(0), mSocket(mCtx, type)
    {
        try {
             mSocket.bind(addr);
        } catch (...)
        {

        }
    }

private:
    zmq::context_t mCtx;
    zmq::socket_t  mSocket;
};  

} // namespace name

