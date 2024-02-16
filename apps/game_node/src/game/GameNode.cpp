#include "game/GameNode.hpp"
#include <iostream>

namespace mmo::game::node {
    void GameNode::mProcessPlayerCommand(PlayerCommand command) {
        std::cout << "Received command from Player to process" << std::endl;
    }

    void GameNode::update(PlayerCommand &command) {
        auto task = [this, command]() { mProcessPlayerCommand(command); };
        mContext.post({"Process player", false, task});
    }

    void GameNode::update(std::shared_ptr<TcpSession> newSession) {
        addNewPlayer(newSession);
    }

    void GameNode::addNewPlayer(const std::shared_ptr<TcpSession>& newSession) {
        auto task = [this, newSession]() {
            mPlayers.emplace_back(newSession);
            mPlayers.rbegin()->registerObserver(*this);
        };
        mContext.post({"Add new player", true, task});
    }
}