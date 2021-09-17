cmake_minimum_required(VERSION 3.12)

project(Retr0Gram LANGUAGES CXX)

set(CMAKE_CXX_STANDART 14)

add_subdirectory(src/Core)

add_subdirectory(src/Demo)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DemoBot)