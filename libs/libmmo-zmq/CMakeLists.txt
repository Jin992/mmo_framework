cmake_minimum_required(VERSION 3.1...3.27)
project(zmq CXX)

file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR} src/*.cpp)
file(GLOB_RECURSE headers ${PROJECT_SOURCE_DIR} include/*.hpp)

find_package(cppzmq)

add_library(${PROJECT_NAME} STATIC  ${sources} ${headers})
add_library(libmmo:: ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} cppzmq )

target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR}/include)
