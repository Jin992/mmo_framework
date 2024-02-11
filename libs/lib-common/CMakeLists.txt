cmake_minimum_required(VERSION 3.1...3.27)

project(common VERSION 1.0 LANGUAGES CXX)

file(GLOB sources CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/game/*.cpp)
file(GLOB headers CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/include/*.hpp)

add_library(${PROJECT_NAME} STATIC ${headers} ${sources})
add_library(libmmo::common ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)