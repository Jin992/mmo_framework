
#include <boost/asio.hpp>
#include "Common.hpp"

namespace net::tcp::base::response {
    class ResponseBase {
        public:
            virtual boost::asio::awaitable<net::common::RawNetworkData> get(net::common::RawNetworkData &&data)=0;
    };
}