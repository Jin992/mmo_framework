cmake_minimum_required(VERSION 3.1...3.27)
project(librpc CXX)

find_package(CapnProto CONFIG REQUIRED)

file(GLOB capnp_files CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/proto/*.capnp)

capnp_generate_cpp(addressbookSources addressbookHeaders addressbook.capnp)
# protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${capnp_files} PLUGIN protoc-gen-grpc=${GRPC_CPP_PLUGIN_PATH})

add_library(${PROJECT_NAME} STATIC  ${PROTO_SRCS} ${PROTO_HDRS} ${capnp_files})
add_library(libmmo::rpc ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME}  CapnProto::capnp)