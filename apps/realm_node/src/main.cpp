#include "mmo.capnp.h"
#include <kj/async-io.h>
#include <capnp/rpc-twoparty.h>
#include <kj/debug.h>
#include <capnp/message.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include "Character.hpp"

class RealmImpl final: public RealmBase::Server
{
public:
     kj::Promise<void> updateCharacter(UpdateCharacterContext context) final 
     {
        auto extCharacter = context.getParams().getCharacter();
        auto local = mCharactersHash.find(extCharacter.getId());
        if (local == mCharactersHash.end())
        {

            game::XYZVector pos(0,0,0);
            game::XYZVector rot(0,0,0);
            game::XYZVector vel(0,0,0);

            game::Motion motion(std::string("extCharacter."), pos, rot, vel);
            game::Character localChar(extCharacter.getId(), extCharacter.getInstanceId(), "", motion);
            mCharactersHash.insert({extCharacter.getId(), localChar});
        }
        else 
        {
            //mCharactersHash[extCharacter.getId()] =  extCharacter;
        }
        context.getResults().setStatus(true);
        return kj::READY_NOW;
     }

private:
    std::unordered_map<std::string, game::Character> mCharactersHash;
};

int main() {
// First we need to set up the KJ async event loop. This should happen one
  // per thread that needs to perform RPC.
  auto io = kj::setupAsyncIo();

  // Using KJ APIs, let's parse our network address and listen on it.
  kj::Network& network = io.provider->getNetwork();
  kj::Own<kj::NetworkAddress> addr = network.parseAddress("0.0.0.0:5005").wait(io.waitScope);
  kj::Own<kj::ConnectionReceiver> listener = addr->listen();

  // Write the port number to stdout, in case it was chosen automatically.
  uint port = listener->getPort();
  if (port == 0) {
    // The address format "unix:/path/to/socket" opens a unix domain socket,
    // in which case the port will be zero.
    std::cout << "Listening on Unix socket..." << std::endl;
  } else {
    std::cout << "Listening on port " << port << "..." << std::endl;
  }

  // Start the RPC server.
  capnp::TwoPartyServer server(kj::heap<RealmImpl>());

  // Run forever, accepting connections and handling requests.
  server.listen(*listener).wait(io.waitScope);
return 0;
}
