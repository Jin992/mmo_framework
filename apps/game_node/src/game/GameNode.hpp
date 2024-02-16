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
    : public Observer<PlayerCommand&>
    , public Observer<std::shared_ptr<TcpSession>>
    {
        public:
            

        private:
            void mProcessPlayerCommand(PlayerCommand command)
            {
                std::cout << "Received command from Player to process" << std::endl;
            }

            void update(PlayerCommand &command)
            {
                auto task = [this, command](){ mProcessPlayerCommand(command); };
                mContext.post({"Process player", false, task});
            }

            void update(std::shared_ptr<TcpSession> newSession)
            {
                addNewPlayer(newSession);
            }

            void addNewPlayer(std::shared_ptr<TcpSession> newSession)
            {
                auto task = [this, newSession](){
                    mPlayers.emplace_back(newSession);
                    auto playerIter = mPlayers.rbegin();
                    playerIter->registerObserver(*this);
                };
                mContext.post({"Add new player", true, task});
            }

        private:
            WorkingContext    mContext;
            std::list<Player> mPlayers;


    };
}
#endif