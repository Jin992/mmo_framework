#include <memory>
#include "mmo.capnp.h"
#include <kj/async-io.h>
#include <capnp/rpc-twoparty.h>
#include <kj/debug.h>

namespace rpc::realm::client {
    class RealmClient 
    {
    public:
        RealmClient(const std::string &serverAddr);
        void updateCharacter(const Character &character);

    private:
        kj::AsyncIoContext mContext;
        kj::Own<kj::NetworkAddress> mAddr;
        kj::Own<kj::AsyncIoStream> mConnection;
        std::unique_ptr<capnp::TwoPartyClient> mRpcConnPtr;
        std::unique_ptr<RealmBase::Client> mRealmClientPtr;
    };
}
