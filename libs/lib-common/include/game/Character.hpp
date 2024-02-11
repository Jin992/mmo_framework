#ifndef MMO_GAME_CHARACTER
#define MMO_GAME_CHARACTER

#include "Motion.hpp"

namespace game {
    class Character
    {
        public:
            Character();
            Character(const std::string &id, const std::string &instanceId, const std::string &mapId, const Motion &motion);
            Character(const json &jsonObj);

            void update(const std::string &id, const std::string &instanceId, const std::string &mapId, const Motion &motion);

            std::string id() const { return mId; }
            std::string instanceId() const { return mInstanceId; };
            std::string mapId() const { return mMapId; }
            Motion      motion() const { return mMotion; }

            friend std::ostream &operator<<(std::ostream&, const Character&);

        private:
            std::string mId;
            std::string mInstanceId;
            std::string mMapId;
            Motion mMotion;
    };
}
#endif