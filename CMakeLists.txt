cmake_minimum_required(VERSION 3.14)

project(Telegram_tool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

add_subdirectory(${PROJECT_SOURCE_DIR}/nlohmann_json)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}
	/nlohmann_json/include/nlohmann)

target_link_libraries(${PROJECT_NAME} nlohmann_json)