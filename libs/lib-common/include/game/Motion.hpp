#ifndef MMO_GAME_MOTION
#define MMO_GAME_MOTION

#include <cstdint>
#include <ostream>
#include <string>
#include "XYZVector.hpp"

namespace mmo::common::game {
    class Motion {
        public:
            Motion();
            Motion(const std::string &mapName, const XYZVector &position, const XYZVector &rotation, const XYZVector &velocity);
            Motion(const json &jsonObj);

            const std::string &mapName() const { return mMapName; }
            const XYZVector &position() const { return mPostion; }
            const XYZVector &rotation() const { return mRotation; }
            const XYZVector &velocity() const { return mVelocity; }

            friend std::ostream &operator<<(std::ostream&, const Motion&);
        
        private:
            std::string mMapName;
            XYZVector mPostion;
            XYZVector mRotation;
            XYZVector mVelocity;
    };
}

#endif