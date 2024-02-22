cmake_minimum_required(VERSION 3.0)
project(game)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(game main.cpp ${SOURCES})

target_include_directories(game PRIVATE src)

target_link_libraries(game raylib)
