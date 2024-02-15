#ifndef MMO_GAME_PLAYER_HPP
#define MMO_GAME_PLAYER_HPP
#include"Subject.hpp"
#include <memory>
#include "GameSession.hpp"
#include "commands/GameCommand.hpp"

class Player;

struct PlayerCommand {
    std::shared_ptr<GameCommandBase>   commandPtr;
    std::shared_ptr<Player>            playerPtr;
};

class Player
: public std::enable_shared_from_this<Player>
, public Subject<PlayerCommand>
, public Observer<std::shared_ptr<GameCommandBase>>
{
    public:
        Player(std::shared_ptr<TcpSession> sessionPtr)
        : mGameSessionPtr(new GameSession(sessionPtr))
        {
            mGameSessionPtr->registerObserver(*this);
        }

        Player(const Player& other) = delete;
        Player(Player&& other) noexcept {
            mGameSessionPtr = std::move(other.mGameSessionPtr);
        }

        void operator=(const Player &) = delete;
        Player& operator=(Player&& other)
        {
            mGameSessionPtr = std::move(other.mGameSessionPtr);
            return *this;
        }

        ~Player()
        {
            mGameSessionPtr.reset();
        }

        void update(std::shared_ptr<GameCommandBase> commandPtr) final
        {
            std::cout << "Received Player Data" << std::endl;
            //PlayerCommand playerAction = {.commandPtr=commandPtr, .playerPtr=this->shared_from_this()};
            //notifyObservers(playerAction);   
        }

    private:
        std::shared_ptr<GameSession> mGameSessionPtr;
        
};
#endif