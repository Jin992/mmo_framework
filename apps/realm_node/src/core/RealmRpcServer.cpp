#include "RealmRpcServer.hpp"
#include <capnp/rpc-twoparty.h>
#include "RealmImpl.hpp"
#include <iostream>

RealmRpcServer::RealmRpcServer(const std::string &rpcAddr)
: mContext(kj::setupAsyncIo())
{
    auto &network = mContext.provider->getNetwork();
    mAddr = network.parseAddress(rpcAddr).wait(mContext.waitScope);
    mListener = mAddr->listen();
}

void RealmRpcServer::run() 
{
    capnp::TwoPartyServer server(kj::heap<RealmImpl>());
    // Run forever, accepting connections and handling requests.
    std::cout << "Created Realm on port " << mListener->getPort() << std::endl;
    server.listen(*mListener).wait(mContext.waitScope);
}