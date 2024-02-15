// #include "game/GameNode.hpp"
// #include "game/protocols/json.hpp"
// #include <iostream>
// #include <ranges>
// #include <cmath>

// using json = nlohmann::json;
// namespace mmo::game::node 
// {
//     using mmo::common::game::Character;

//     std::list<mmo::common::game::Character> GameNode::mNodeCharacters = {};
//     GameNode::GameNode()
//     //:  mRealmClient("127.0.0.1:5005")
//     {

//     }

//     GameNode::~GameNode()
//     {}

//     class CubeArea {
//         public:
//             CubeArea(const mmo::common::game::XYZVector &centerPoint, int32_t edgeLenght)
//             : mCenterPoint(centerPoint), mEdgeLenght(edgeLenght)
//             {}

//             bool isIncluded(const mmo::common::game::XYZVector &position)
//             {
//                 auto diff = mCenterPoint - position;
//                 // Check if the point is within the cube
//                 return (std::abs(diff.x()) <= mEdgeLenght / 2.0) 
//                     && (std::abs(diff.y()) <= mEdgeLenght / 2.0) 
//                     && (std::abs(diff.z()) <= mEdgeLenght / 2.0);
//             }

//         private:
//              mmo::common::game::XYZVector mCenterPoint;
//              int32_t mEdgeLenght;
//     };


//     std::vector<mmo::common::game::Character> GameNode::getNearCharacters(const mmo::common::game::Character &currentCharacter)
//     {
//         std::vector<mmo::common::game::Character> neighbors;
//         CubeArea neighborsDetectionArea(currentCharacter.motion().position(), 100);

//         std::copy_if(mNodeCharacters.begin(), mNodeCharacters.end(), std::back_inserter(neighbors), 
//                         [&neighborsDetectionArea](auto &v) {
//                             return neighborsDetectionArea.isIncluded(v.motion().position());
//                         });
//         return neighbors;
//     }

//     net::common::RawNetworkData GameNode::get(net::common::RawNetworkData &&data)
//     {
//         json jsonData = json::parse(data);

//         std::cout << jsonData.dump(4) << std::endl;
//         Character currentCharacter(jsonData["Character"]);

//         //mRealmClient.updateCharacter(mob);
//          std::cout << currentCharacter << std::endl;
//         return data;
//     }
// }