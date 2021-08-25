cmake_minimum_required(VERSION 3.12)

project(Telegram_tool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

#file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
#add_executable(${PROJECT_NAME} ${SRC_FILES})

add_executable(${PROJECT_NAME} 
	src/Headers.h
	src/Requests.hpp
	src/Telegram.hpp
	src/TGBotFunc.hpp
	src/Requests.cpp
	src/Telegram.cpp
	src/main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/json)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json)