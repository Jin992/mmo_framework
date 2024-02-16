#include "game/Player.hpp"
#include <iostream>

Player::Player(std::shared_ptr<TcpSession> sessionPtr)
: mGameSession(std::move(sessionPtr))
{
    mGameSession.registerObserver(*this);
}

Player::~Player()
{}

Player::Player(Player&& other) noexcept {
mGameSession = std::move(other.mGameSession);
}

Player& Player::operator=(Player&& other)
{
    mGameSession = std::move(other.mGameSession);
    return *this;
}


void Player::update(GameCommandBase command)
{
    std::cout << "Received Player Data" << std::endl;
    PlayerCommand playerAction = {.command=command, .playerRef=*this};
    notifyObservers(playerAction);
}