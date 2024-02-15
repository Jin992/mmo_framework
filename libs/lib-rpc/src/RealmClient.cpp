#include "RealmClient.hpp"
#include <iostream>

namespace rpc::realm::client {

    RealmClient::RealmClient(const std::string &serverAddr)
    : mContext(kj::setupAsyncIo())
    {
      kj::Network& network = mContext.provider->getNetwork();
      auto& waitScope = mContext.waitScope;
      mAddr = network.parseAddress(serverAddr).wait(waitScope);
      mConnection = mAddr->connect().wait(waitScope);
      mRpcConnPtr = std::make_unique<capnp::TwoPartyClient>(*mConnection);
      mRealmClientPtr = std::make_unique<RealmBase::Client>(mRpcConnPtr->bootstrap().castAs<RealmBase>());
    }

    void RealmClient::updateCharacter(const Character &character)
    {
      auto req = mRealmClientPtr->updateCharacterRequest();
      //req.getCharacter().setId(character.getId());
      //req.getCharacter().setInstanceId(character.getInstanceId());
      auto updatePromise = req.send();

      auto readPromise = updatePromise.getValue().readRequest().send();
      auto responce = readPromise.wait(mContext.waitScope);
      KJ_ASSERT(responce.getValue() == true);

      std::cout << "PASS" << std::endl;
    }

}