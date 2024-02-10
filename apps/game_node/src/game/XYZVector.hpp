// #include <cstdint>
// #include <ostream>
// #include "net/protocols/json.hpp"
// #include <string>

// using json = nlohmann::json;

// namespace game {
// class XYZVector
// {
//     public:
//         XYZVector(){}
        
//         XYZVector(int x, int y, int z)
//         : mX(x), mY(y), mZ(z)
//         {}

//         XYZVector(const json &jsonObj){
//             mX = std::stoi(jsonObj["x"].get<std::string>());
//             mY = std::stoi(jsonObj["y"].get<std::string>());
//             mZ = std::stoi(jsonObj["z"].get<std::string>());
//         }

//         int x() const { return mX; }
//         int y() const { return mY; }
//         int z() const { return mZ; }

//         friend std::ostream &operator<<(std::ostream&, const XYZVector&);

//     private:
//         int mX;
//         int mY;
//         int mZ;
// };

// std::ostream &operator<<(std::ostream &strm, const XYZVector &obj)
// {
//     strm << "{x: " << obj.x() << " y: " << obj.y() << " z: " << obj.z() << "}";
//     return strm;
// }
// }