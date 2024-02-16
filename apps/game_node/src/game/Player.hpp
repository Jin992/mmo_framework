#ifndef MMO_GAME_PLAYER_HPP
#define MMO_GAME_PLAYER_HPP
#include"Subject.hpp"
#include <memory>
#include <utility>
#include "GameSession.hpp"
#include "commands/GameCommand.hpp"

class Player;

struct PlayerCommand {
    GameCommandBase     command;
    Player             &playerRef;
};

class Player
: public Subject<PlayerCommand &>
, public Observer<GameCommandBase>
{
    public:
        Player(std::shared_ptr<TcpSession> sessionPtr)
        : mGameSession(std::move(sessionPtr))
        {

            mGameSession.registerObserver(*this);
        }

//        Player(const Player& other) = delete;
//        Player(Player&& other) noexcept {
//            mGameSession = std::move(other.mGameSession);
//        }
//
//        void operator=(const Player &) = delete;
//        Player& operator=(Player&& other)
//        {
//            mGameSession = std::move(other.mGameSession);
//            return *this;
//        }

        ~Player()
        {
        }

        void update(GameCommandBase command) final
        {
            std::cout << "Received Player Data" << std::endl;
            PlayerCommand playerAction = {.command=command, .playerRef=*this};
            notifyObservers(playerAction);
        }

    private:
        GameSession mGameSession;
        
};
#endif