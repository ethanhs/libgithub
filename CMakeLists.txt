cmake_minimum_required(VERSION 3.2)

project(libgithub)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs)

add_executable(example example/user_info.cpp)
target_link_libraries(example ${CPR_LIBRARIES})
include_directories(${CPR_INCLUDE_DIRS} ${JSON_INCLUDE_DIR} include/)