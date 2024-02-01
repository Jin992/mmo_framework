#include "PlayerMotion.hpp"
#include <map>
#include <list>

using PlayerMotionList =  std::list<PlayerMotion>;

class PlayerMotionService {
    public:
        PlayerMotionService(): m_playerMotions{}
        {}

        void updatePlrayerState(PlayerMotion request) 
        {
            std::string playerName = request.name;
            if (m_playerMotions.contains(playerName))
            {
                m_playerMotions.at(playerName).motion = request.motion;
            }
            else 
            {
                m_playerMotions.insert({request.name, request.motion});
            }
        }

        PlayerMotionList getPlayersNearMe(const std::string &playerName)
        {
            PlayerMotionList playersNearMe;
            for(auto const& [key, val]: m_playerMotions)
            {
                if (val.name != playerName) 
                {
                    // add more filters, e.g. by distance
                    // consider caching
                    playersNearMe.push_back(val);
                }
            }
            return playersNearMe;
        }

    private:
        std::map<std::string, PlayerMotion> m_playerMotions;
};