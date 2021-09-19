cmake_minimum_required(VERSION 3.12)

project(TelegramTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(PUBLIC_INCLUDES
	includes/Requests.hpp
	includes/Telegram.hpp
	includes/Debug.hpp
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DemoBot)

set(PRIVATE_SOURCES
	src/Requests.cpp
	src/Telegram.cpp
)

add_library(${PROJECT_NAME} STATIC
			${PUBLIC_INCLUDES}
			${PRIVATE_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PRIVATE WinInet.lib)

add_subdirectory(../../vendor/json ${CMAKE_BINARY_DIR}../../vendor/json )

add_subdirectory(../../vendor/spdlog ${CMAKE_BINARY_DIR}../../vendor/spdlog)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json)

target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}../../vendor/spdlog)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/)