//
// Created by Artes on 2/16/2024.
//

#ifndef GAME_NODE_GAMEPLAYERLOADCOMMAND_H
#define GAME_NODE_GAMEPLAYERLOADCOMMAND_H
#include "game/commands/GameCommandBase.hpp"
#include "game/Character.hpp"

class GamePlayerLoadCommand
: public GameCommandBase
{
public:
    GamePlayerLoadCommand(mmo::common::game::Character character);
    mmo::common::game::Character getCharacter() const;

private:
    mmo::common::game::Character mCharacterData;
};


#endif //GAME_NODE_GAMEPLAYERLOADCOMMAND_H
