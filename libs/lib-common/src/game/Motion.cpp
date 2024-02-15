#include "game/Motion.hpp"

namespace mmo::common::game {
        Motion::Motion() 
        {}

        Motion::Motion(const std::string &mapName, const XYZVector &position, const XYZVector &rotation, const XYZVector &velocity)
        : mMapName(mapName), mPostion(position), mRotation(rotation), mVelocity(velocity)
        {}

        Motion::Motion(const json &jsonObj) 
        {
            mMapName = jsonObj["map"].get<std::string>();
            mPostion = XYZVector(jsonObj["position"]);
            mRotation = XYZVector(jsonObj["rotation"]);
            mVelocity = XYZVector(jsonObj["velocity"]);
         }

        std::ostream &operator<<(std::ostream &strm, const Motion &obj)
        {
            strm << " Motion{MapName:  " << obj.mapName() 
                 << " Position: " << obj.position() << " Rotation: " 
                 << obj.rotation() << " Velocity: " << obj.velocity();
            return strm;
        }

}