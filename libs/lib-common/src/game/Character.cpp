#include "game/Character.hpp"

namespace mmo::common::game {
    Character::Character()
    {}

    Character::Character(const std::string &id, const std::string &instanceId, const std::string &mapId, const Motion &motion)
    : mId(id), mInstanceId(instanceId), mMapId(mapId), mMotion(motion)
    {}

    Character::Character(const json &jsonObj)
    {
        mId = jsonObj["id"].get<std::string>();
        mInstanceId = jsonObj["instanceId"].get<std::string>();
        mMapId = jsonObj["mapId"].get<std::string>();
        mMotion = Motion(jsonObj["motion"]);
    }

    void Character::set(const std::string &id, const std::string &instanceId, const std::string &mapId, const Motion &motion)
    {
        mId = id;
        mInstanceId = instanceId;
        mMapId = mapId;
        mMotion = motion;
    }

    std::ostream &operator<<(std::ostream& strm, const Character& obj)
    {
        strm << "Character{ Id: " << obj.id() << " InstanceId: " << obj.instanceId() << " MapId: " << obj.mapId() << " " << obj.motion();
        return strm;
    }

    json Character::toJson()
    {
        return {
            {"Character", {{"id", mId},
                           {"instanceId", mInstanceId},
                           {"mapId", mMapId},
                           {"motion", mMotion.toJson()}
                           }
            }
        };
    }
}