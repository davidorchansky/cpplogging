cmake_minimum_required (VERSION 2.6)
project (cpplogging C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

# Remove 'lib' prefix for shared libraries on Windows
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()
 
add_library(${PROJECT_NAME} SHARED src/Loggable.cpp)

SET(${PROJECT_NAME}_CXX_COMPILE_FLAGS "-fPIC -std=c++0x")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${${PROJECT_NAME}_CXX_COMPILE_FLAGS}")
SET(CMAKE_BUILD_TYPE Release)


SET(${PROJECT_NAME}_INCLUDE_DIRS includes spdlog/include)
message(STATUS "${PROJECT_NAME} include dirs: ${${PROJECT_NAME}_INCLUDE_DIRS}")

target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} pthread)

SET(${PROJECT_NAME}_INCLUDES "includes/Loggable.h")

#https://cmake.org/cmake/help/v3.0/command/install.html 
install(TARGETS ${PROJECT_NAME}	LIBRARY DESTINATION "lib")
install(FILES ${${PROJECT_NAME}_INCLUDES} DESTINATION "include")
install(DIRECTORY "spdlog/include" DESTINATION "include")
	
