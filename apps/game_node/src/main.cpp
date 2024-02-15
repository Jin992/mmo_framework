#include "net/TcpServer.hpp"
#include "game/GameNode.hpp"


int main() {
    TcpServer server(8555);
    mmo::game::node::GameNode gameNode;
   
    server.registerObserver(gameNode);
    server.run();
    return 0;    
}