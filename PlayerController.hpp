#include "PlayerService.hpp"

class PalyerController {
    public:
        PalyerController(PlayerService &playerServiceRef)
        : m_playerServiceRef(playerServiceRef)
        {}

        PlayerMotionList updatePlayerLocation(PlayerMotion &motion)
        {
            m_playerServiceRef.updatePlrayerState(motion);
            return m_playerServiceRef.getPlayersNearMe(motion.name);
        }


    private:
        PlayerMotionService& m_playerServiceRef;
}