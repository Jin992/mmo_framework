#include "game/commands/GameCommandBase.hpp"

GameCommandBase::GameCommandBase(GameCommandE id)
: mCommandId(id)
{
}

GameCommandBase::~GameCommandBase()
{
}

GameCommandE GameCommandBase::id()
{
    return mCommandId;
}