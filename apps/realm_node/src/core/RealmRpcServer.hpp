#include <kj/async-io.h>
#include <string>

class RealmRpcServer {
public:
  RealmRpcServer(const std::string &rpcAddr);

  void run();
private:
  kj::AsyncIoContext mContext;
  kj::Own<kj::NetworkAddress> mAddr;
  kj::Own<kj::ConnectionReceiver> mListener;
};