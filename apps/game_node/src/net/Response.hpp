#include "ResponseBase.hpp"
#include "game/protocols/json.hpp"
#include <iostream>
#include "game/Character.hpp"

using json = nlohmann::json;

namespace net::tcp::response {
    class Response: public net::tcp::base::response::ResponseBase
    {
        public:
            boost::asio::awaitable<net::common::RawNetworkData> get(net::common::RawNetworkData &&data) override {
                json jsonData = json::parse(data);
                //std::cout << jsonData.dump(4) << std::endl;
                // game::Character mob(jsonData["Character"]);
                // std::cout << mob << std::endl;
                co_return data;
            }
    };
}