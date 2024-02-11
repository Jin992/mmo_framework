cmake_minimum_required(VERSION 3.1...3.27)
project(librpc LANGUAGES CXX)

find_package(CapnProto CONFIG REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp )
file(GLOB headers CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB capnp_files CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/proto/*.capnp)

capnp_generate_cpp(CPNP_GENERATED_SOURCES addressbookHeaders ${capnp_files})

add_library(${PROJECT_NAME} STATIC  ${headers} ${sources} ${CPNP_GENERATED_SOURCES})
add_library(libmmo::rpc ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/proto/  ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}  CapnProto::capnp-rpc libmmo::common) 