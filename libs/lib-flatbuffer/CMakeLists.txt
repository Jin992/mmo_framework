cmake_minimum_required(VERSION 3.1...3.27)
project(mmo-flatbuf CXX)

set(FLATC_CPP_FLAGS --gen-object-api --gen-compare --gen-mutable)

find_program(FLATBUFFERS_FLATC_EXECUTABLE flatc)
find_package(Flatbuffers CONFIG REQUIRED)

file(GLOB FLATBUFFER_SHCEMA_SCR CONFIGURE_DEPENDS 
                                ${PROJECT_SOURCE_DIR}/schema/game/common/*.fbs 
                                ${PROJECT_SOURCE_DIR}/schema/game/server/*.fbs 
                                ${PROJECT_SOURCE_DIR}/schema/game/character/*.fbs
                                )


flatbuffers_generate_headers(TARGET fltb 
        SCHEMAS ${FLATBUFFER_SHCEMA_SCR} 
        INCLUDE_PREFIX "./"
        FLAGS ${FLATC_CPP_FLAGS})


add_library(${PROJECT_NAME} INTERFACE)
add_dependencies(${PROJECT_NAME} fltb)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/fltb)