#include "GamePlayerLoadCommand.hpp"

GamePlayerLoadCommand::GamePlayerLoadCommand(mmo::common::game::Character character)
: GameCommandBase(GameCommandE::PLAYER_LOAD), mCharacterData(character)

{}

mmo::common::game::Character GamePlayerLoadCommand::getCharacter() const
{
    return mCharacterData;
}