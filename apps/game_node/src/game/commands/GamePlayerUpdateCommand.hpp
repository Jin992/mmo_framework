#ifndef GAME_NODE_GAMEPLAYERUPDATECOMMAND_HPP
#define GAME_NODE_GAMEPLAYERUPDATECOMMAND_HPP
#include "game/commands/GameCommandBase.hpp"
#include "game/Character.hpp"

class GamePlayerUpdateCommand
: public GameCommandBase
{
public:
    GamePlayerUpdateCommand(mmo::common::game::Character character);
    mmo::common::game::Character getCharacter() const;

private:
    mmo::common::game::Character mCharacterData;

};


#endif //GAME_NODE_GAMEPLAYERUPDATECOMMAND_H
