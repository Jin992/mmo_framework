#include "game/GameSession.hpp"
#include <iostream>
#include "game/commands/GamePlayerLoadCommand.hpp"
#include "game/commands/GamePlayerUpdateCommand.hpp"
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
    //GameCommandBase &command;
    json jsonData = json::parse(data);
    auto updateType = jsonData["updateType"].get<std::string>();
    if (updateType == "PLAYER_MOTION")
    {
        mmo::common::game::Character character(jsonData["Character"]);
        std::cout << character << std::endl;
        notifyObservers(std::make_shared<GamePlayerUpdateCommand>(character));
    }
}

void GameSession::sendCmdToClient(std::shared_ptr<GameCommandBase> cmd)
{
    if(cmd->id() == GameCommandE::PLAYER_UPDATE)
    {
        auto updateCmd = std::dynamic_pointer_cast<GamePlayerUpdateCommand>(cmd);
        auto character = updateCmd->getCharacter();
        auto jsonStr = character.toJson().dump();
        mTcpSessionPtr->sendData(net::common::RawNetworkData(jsonStr.begin(), jsonStr.end()));
    }

}