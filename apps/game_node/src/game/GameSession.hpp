#ifndef MMO_GAME_SESSION_HPP
#define MMO_GAME_SESSION_HPP

#include <memory>
#include "net/TcpSession.hpp"
#include "commands/GameCommand.hpp"
#include "Subject.hpp"
#include <iostream>
#include "game/protocols/json.hpp"
using json = nlohmann::json;

class GameSession
: public Observer<net::common::RawNetworkData>
, public Subject<std::shared_ptr<GameCommandBase>>
{
    public:
        GameSession(std::shared_ptr<TcpSession> tcpSessionPtr)
        : mTcpSessionPtr(tcpSessionPtr)
        {
            tcpSessionPtr->registerObserver(*this);
        }

        ~GameSession() override {}


        void update(net::common::RawNetworkData data) final
        {
            std::shared_ptr<GameCommandBase> command = std::make_shared<GameCommandBase>();
            json jsonData = json::parse(data);
            std::cout << jsonData.dump(4) << std::endl;
            notifyObservers(command);
        }



    private:
        std::shared_ptr<TcpSession> mTcpSessionPtr;

};
#endif