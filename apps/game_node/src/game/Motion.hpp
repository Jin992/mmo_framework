
// #include <cstdint>
// #include <ostream>
// #include <string>
// #include "XYZVector.hpp"

// namespace game {
// class Motion {
//     public:
//         Motion() {}
//         Motion(const std::string &mapName, const XYZVector &position, const XYZVector &rotation, const XYZVector &velocity)
//         : mMapName(mapName), mPostion(position), mRotation(rotation), mVelocity(velocity)
//         {}

//          Motion(const json &jsonObj) {
//             mMapName = jsonObj["map"].get<std::string>();
//             mPostion = XYZVector(jsonObj["position"]);
//             mRotation = XYZVector(jsonObj["rotation"]);
//             mVelocity = XYZVector(jsonObj["velocity"]);
//          }

//         const std::string &mapName() const { return mMapName; }
//         const XYZVector &postion() const { return mPostion; }
//         const XYZVector &rotation() const { return mRotation; }
//         const XYZVector &velocity() const { return mVelocity; }

//         friend std::ostream &operator<<(std::ostream&, const Motion&);
        
//     private:
//         std::string mMapName;
//         XYZVector mPostion;
//         XYZVector mRotation;
//         XYZVector mVelocity;
// };

// std::ostream &operator<<(std::ostream &strm, const Motion &obj)
// {
//     strm << " Motion{MapName:  " << obj.mapName() 
//          << " Position: " << obj.postion() << " Rotation: " 
//          << obj.rotation() << " Velocity: " << obj.velocity();
//     return strm;
// }
// }