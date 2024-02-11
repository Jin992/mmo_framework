#include "game/XYZVector.hpp"

namespace game {
    XYZVector::XYZVector()
    {}
        
    XYZVector::XYZVector(int x, int y, int z)
    : mX(x), mY(y), mZ(z)
    {}

    XYZVector::XYZVector(const json &jsonObj){
        mX = std::stoi(jsonObj["x"].get<std::string>());
        mY = std::stoi(jsonObj["y"].get<std::string>());
        mZ = std::stoi(jsonObj["z"].get<std::string>());
    }

    std::ostream &operator<<(std::ostream &strm, const XYZVector &obj)
    {
        strm << "{x: " << obj.x() << " y: " << obj.y() << " z: " << obj.z() << "}";
        return strm;
    }
}