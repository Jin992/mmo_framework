cmake_minimum_required(VERSION 3.1...3.27)
project(librpc CXX)

find_package(Protobuf REQUIRED REQUIRED)
find_package(gRPC CONFIG REQUIRED)
file(GLOB proto_files CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/proto/*.proto)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${proto_files} PLUGIN protoc-gen-grpc=${GRPC_CPP_PLUGIN_PATH})

add_library(${PROJECT_NAME} STATIC  ${PROTO_SRCS} ${PROTO_HDRS} ${proto_files})
add_library(libmmo::rpc ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})