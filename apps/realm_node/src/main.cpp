#include "core/RealmRpcServer.hpp"

int main() {
  RealmRpcServer realm("0.0.0.0:5005");
  realm.run();
  return 0;
}
