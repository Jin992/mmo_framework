#Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.1...3.27)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(game_node VERSION 1.0 LANGUAGES CXX)

 # Set C++ standard to C++20
 set(CMAKE_CXX_STANDARD 20)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB sources CONFIGURE_DEPENDS src/*.cpp src/net/*.cpp src/game/*.cpp src/game/commands/*.cpp)
file(GLOB headers CONFIGURE_DEPENDS src/*.hpp )

 # Find and set up the required packages
find_package(Threads REQUIRED)
find_package(Boost 1.80 COMPONENTS system)
#find_package(cppcoro REQUIRED)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread  -fcoroutines")

add_subdirectory(${PROJECT_SOURCE_DIR}/../../libs/lib-rpc rpc)
add_subdirectory(${PROJECT_SOURCE_DIR}/../../libs/lib-common common)

 # Adding something we can run - Output name matches target name
 add_executable(${PROJECT_NAME} ${headers} ${sources})
 target_include_directories(${PROJECT_NAME} PUBLIC  src/)
 # Make sure you link your targets with this command. It can also link libraries and
 # even flags, so linking a target that does not exist will not give a configure-time error.
 target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES} libmmo::rpc libmmo::common)#cppcoro::cppcoro)
# target_link_libraries(CoroSched PRIVATE Threads::Threads)