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
, public Subject<GameCommandBase>
{
    public:
        GameSession() {}
        GameSession(std::shared_ptr<TcpSession> tcpSessionPtr)
        : mTcpSessionPtr(std::move(tcpSessionPtr))
        {
            mTcpSessionPtr->registerObserver(*this);
            mTcpSessionPtr->start();
        }

//        GameSession(const GameSession& other) = delete;
//        GameSession(GameSession&& other) noexcept {
//            mTcpSessionPtr = std::move(other.mTcpSessionPtr);
//        }
//
//        void operator=(const GameSession &) = delete;
//        GameSession& operator=(GameSession&& other)
//        {
//            mTcpSessionPtr = std::move(other.mTcpSessionPtr);
//            return *this;
//        }


        void update(net::common::RawNetworkData data) final
        {
            GameCommandBase command;
            //json jsonData = json::parse(data);
            //std::cout << jsonData.dump(4) << std::endl;
            notifyObservers(command);
        }



    private:
        std::shared_ptr<TcpSession> mTcpSessionPtr;

};
#endif