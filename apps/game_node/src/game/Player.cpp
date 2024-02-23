#include "game/Player.hpp"
#include <iostream>

int Player::mInstanceIdCnt = 0;

Player::Player(std::shared_ptr<TcpSession> sessionPtr)
: mGameSession(std::move(sessionPtr))
{
    mGameCharacter.setInstanceId("player_" + std::to_string(mInstanceIdCnt++));
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

mmo::common::game::Character Player::getGameCharacter()
{
    return mGameCharacter;
}

void Player::updateGamecharacter(mmo::common::game::Character &character)
{
    mGameCharacter = character;
}

GameSession & Player::getGameSession()
{
    return mGameSession;
}

void Player::update( std::shared_ptr<GameCommandBase> cmd)
{
    PlayerCommand playerAc = {.command=cmd, .playerRef=*this};
    notifyObservers(playerAc);
}