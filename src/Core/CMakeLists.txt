cmake_minimum_required(VERSION 3.12)

project(TelegramTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(PUBLIC_INCLUDES
	includes/Requests.hpp
	includes/Telegram.hpp
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DemoBot)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

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

add_subdirectory(../../vendor/json ${PROJECT_SOURCE_DIR}../../vendor/json )

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/)