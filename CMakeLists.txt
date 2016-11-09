cmake_minimum_required (VERSION 2.6)
project (cpplogging C CXX)

add_library(${PROJECT_NAME} SHARED src/Loggable.cpp)

SET(CUSTOM_CXX_COMPILE_FLAGS "-fPIC -std=c++0x")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CUSTOM_CXX_COMPILE_FLAGS}")
SET(CMAKE_BUILD_TYPE Release)


SET(PROJECT_INCLUDES includes spdlog/include)
message(STATUS "${PROJECT_NAME} include dirs: ${PROJECT_INCLUDES}")

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDES})

target_link_libraries(cpplogging pthread)
