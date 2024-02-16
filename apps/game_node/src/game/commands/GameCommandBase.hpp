#ifndef MMO_GAME_COMMAND_BASE_HPP
#define MMO_GAME_COMMAND_BASE_HPP

enum class GameCommandE
{
    PLAYER_LOAD = 0,
    PLAYER_UPDATE,
    GAME_CMD_MAX
};

class GameCommandBase
{
public:
    GameCommandBase(GameCommandE);
    ~GameCommandBase();

    virtual GameCommandE id();

private:
    GameCommandE  mCommandId;
};
#endif