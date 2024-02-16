#include "game/GameNode.hpp"
#include <iostream>
#include "game/commands/GamePlayerUpdateCommand.hpp"

namespace mmo::game::node {
    void GameNode::mProcessPlayerCommand(PlayerCommand command) {
        if (command.command->id() == GameCommandE::PLAYER_UPDATE)
        {
            auto cmd = std::dynamic_pointer_cast<GamePlayerUpdateCommand>(command.command);
            auto character = cmd->getCharacter();
            /* Do some action on character */
            command.playerRef.updateGameClient(cmd);
        }
    }

    void GameNode::update(PlayerCommand command) {
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