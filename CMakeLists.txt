cmake_minimum_required(VERSION 3.10)

project(EarchProtectiveShield)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(EarchProtectiveShield main.cpp)

target_link_libraries(EarchProtectiveShield ${SDL2_LIBRARIES})
