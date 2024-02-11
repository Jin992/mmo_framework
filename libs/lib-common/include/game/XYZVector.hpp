#ifndef MMO_GAME_XYZ_VECTOR
#define MMO_GAME_XYZ_VECTOR

#include <cstdint>
#include <ostream>
#include "game/protocols/json.hpp"
#include <string>

using json = nlohmann::json;

namespace game {
    class XYZVector
    {
        public:
            XYZVector();
            XYZVector(int x, int y, int z);
            XYZVector(const json &jsonObj);

            int x() const { return mX; }
            int y() const { return mY; }
            int z() const { return mZ; }

            friend std::ostream &operator<<(std::ostream&, const XYZVector&);

        private:
            int mX;
            int mY;
            int mZ;
    };
}

#endif