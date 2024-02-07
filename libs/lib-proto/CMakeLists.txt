cmake_minimum_required(VERSION 3.1...3.27)
project(-proto CXX)

find_package(Protobuf REQUIRED)
file(GLOB proto_files CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.proto)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${proto_files})
protobuf_generate_python(PROTO_PY ${proto_files} )

add_library(${PROJECT_NAME} STATIC  ${PROTO_SRCS} ${PROTO_HDRS} ${proto_files})
add_library(libmmo::protobuf ALIAS ${PROJECT_NAME})
add_custom_target(pythonSrc ALL DEPENDS ${PROTO_PY})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} -lprotobuf)