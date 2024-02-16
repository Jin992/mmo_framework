#ifndef MMO_GAME_SESSION_HPP
#define MMO_GAME_SESSION_HPP

#include <memory>
#include "net/TcpSession.hpp"
#include "commands/GameCommandBase.hpp"
#include "Subject.hpp"

class GameSession
: public Observer<net::common::RawNetworkData>
, public Subject<std::shared_ptr<GameCommandBase>>
{
    public:
        GameSession() = default;
        explicit GameSession(std::shared_ptr<TcpSession> tcpSessionPtr);
        GameSession(const GameSession& other) = delete;
        GameSession(GameSession&& other) noexcept;

        void operator=(const GameSession &) = delete;
        GameSession& operator=(GameSession&& other) noexcept ;

        void update(net::common::RawNetworkData data) final;

        void sendCmdToClient(std::shared_ptr<GameCommandBase> cmd);

    private:
        std::shared_ptr<TcpSession> mTcpSessionPtr;

};
#endif