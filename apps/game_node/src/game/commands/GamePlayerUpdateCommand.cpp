#include "GamePlayerUpdateCommand.hpp"

GamePlayerUpdateCommand::GamePlayerUpdateCommand(mmo::common::game::Character character)
: GameCommandBase(GameCommandE::PLAYER_UPDATE), mCharacterData(character)
{}

mmo::common::game::Character GamePlayerUpdateCommand::getCharacter() const
{
    return mCharacterData;
}