#include "game/GameSession.hpp"
#include <iostream>
#include "game/protocols/json.hpp"
using json = nlohmann::json;

GameSession::GameSession(std::shared_ptr<TcpSession> tcpSessionPtr)
: mTcpSessionPtr(std::move(tcpSessionPtr))
{
    mTcpSessionPtr->registerObserver(*this);
    mTcpSessionPtr->start();
}

GameSession::GameSession(GameSession&& other) noexcept {
    mTcpSessionPtr = std::move(other.mTcpSessionPtr);
}

GameSession& GameSession::operator=(GameSession&& other) noexcept
{
    mTcpSessionPtr = std::move(other.mTcpSessionPtr);
    return *this;
}


void GameSession::update(net::common::RawNetworkData data)
{
    GameCommandBase command;
    //json jsonData = json::parse(data);
    //std::cout << jsonData.dump(4) << std::endl;
    notifyObservers(command);
}