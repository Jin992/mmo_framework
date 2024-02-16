#ifndef MMO_GAME_PLAYER_HPP
#define MMO_GAME_PLAYER_HPP
#include"Subject.hpp"
#include <memory>
#include <utility>
#include "GameSession.hpp"
#include "commands/GameCommandBase.hpp"

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
        explicit Player(std::shared_ptr<TcpSession> sessionPtr);
        Player(const Player& other) = delete;
        Player(Player&& other) noexcept;
        ~Player();

        void operator=(const Player &) = delete;
        Player& operator=(Player&& other);

        void update(GameCommandBase command) final;
    private:
        GameSession mGameSession;
        
};
#endif