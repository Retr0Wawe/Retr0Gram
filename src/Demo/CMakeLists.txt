cmake_minimum_required(VERSION 3.12)

project(DemoBot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} WIN32
			   src/main.cpp
)

target_link_libraries(${PROJECT_NAME} TelegramTool)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/)
