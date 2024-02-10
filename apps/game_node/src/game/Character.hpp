// #include "Motion.hpp"

// namespace game {
// class Character
// {
//     public:
//         Character(const std::string &id, const std::string &instanceId, const std::string &mapId, const Motion &motion) 
//         : mId(id), mInstanceId(instanceId), mMapId(mapId), mMotion(motion)
//         {}

//         Character(const json &jsonObj)
//         {
//             mId = jsonObj["id"].get<std::string>();
//             mInstanceId = jsonObj["instanceId"].get<std::string>();
//             mMapId = jsonObj["mapId"].get<std::string>();
//             mMotion = Motion(jsonObj["motion"]);
//         }

//         void update(const std::string &id, const std::string &instanceId, const std::string &mapId, const Motion &motion)
//         {
//             mId = id;
//             mInstanceId = instanceId;
//             mMapId = mapId;
//             mMotion = motion;
//         }

//         std::string id() const { return mId; }
//         std::string instanceId() const { return mInstanceId; };
//         std::string mapId() const { return mMapId; }
//         Motion      motion() const { return mMotion; }

//         friend std::ostream &operator<<(std::ostream&, const Character&);

//     private:
//         std::string mId;
//         std::string mInstanceId;
//         std::string mMapId;
//         Motion mMotion;
// };

// std::ostream &operator<<(std::ostream& strm, const Character& obj)
// {
//     strm << "Character{ Id: " << obj.id() << " InstanceId: " << obj.instanceId() << " MapId: " << obj.mapId() << " " << obj.motion();
//     return strm;
// }
// }