project(EarchProtectiveShield)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

cmake_minimum_required(VERSION 3.10)

add_executable(EarchProtectiveShield src/main.cpp src/Game/Game.cpp src/Entity/Entity.cpp src/Player/Player.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(EarchProtectiveShield ${SDL2_LIBRARIES})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(EarchProtectiveShield ${SDL2_IMAGE_LIBRARIES})
