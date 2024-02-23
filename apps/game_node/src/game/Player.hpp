#ifndef MMO_GAME_PLAYER_HPP
#define MMO_GAME_PLAYER_HPP
#include"Subject.hpp"
#include <memory>
#include <utility>
#include "GameSession.hpp"
#include "commands/GameCommandBase.hpp"
#include "game/Character.hpp"

class Player;

struct PlayerCommand {
    std::shared_ptr<GameCommandBase> command;
    Player             &playerRef;
};

class Player
: public Subject<PlayerCommand>
, public Observer<std::shared_ptr<GameCommandBase>>
{
    public:
        explicit Player(std::shared_ptr<TcpSession> sessionPtr);
        Player(const Player& other) = delete;
        Player(Player&& other) noexcept;
        ~Player();

        void operator=(const Player &) = delete;
        Player& operator=(Player&& other);

        mmo::common::game::Character getGameCharacter();
        void updateGamecharacter(mmo::common::game::Character &character);

        GameSession &getGameSession();
        void update(std::shared_ptr<GameCommandBase> playerAction) final;
        
    private:
        GameSession                     mGameSession;
        mmo::common::game::Character    mGameCharacter;
        static int                      mInstanceIdCnt;
        
};
#endif