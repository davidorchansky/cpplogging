cmake_minimum_required (VERSION 2.6)
project (cpplogging)

add_library(cpplogging SHARED src/Loggable.cpp)

SET(CUSTOM_CXX_COMPILE_FLAGS "-fPIC -std=c++0x")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CUSTOM_CXX_COMPILE_FLAGS}")

SET(CMAKE_BUILD_TYPE Release)

target_include_directories(cpplogging PUBLIC includes spdlog/include)
target_link_libraries(cpplogging pthread)
