#ifndef MMO_GAME_NODE_HPP
#define MMO_GAME_NODE_HPP
#include <list>
#include <vector>

#include "Observer.hpp"
#include "WorkingContext.hpp"
#include "game/Player.hpp"
#include "net/TcpSession.hpp"

namespace mmo::game::node 
{
    class GameNode
    : public Observer<PlayerCommand>
    , public Observer<std::shared_ptr<TcpSession>>
    {
        private:
            void mProcessPlayerCommand(PlayerCommand command);
            void addNewPlayer(const std::shared_ptr<TcpSession>& newSession);


            void update(PlayerCommand command) final;
            void update(std::shared_ptr<TcpSession> newSession) final;

        private:
            WorkingContext    mContext;
            std::list<Player> mPlayers;
    };
}
#endif