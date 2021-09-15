cmake_minimum_required(VERSION 3.12)

project(Telegram_tool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(PUBLIC_INCLUDES
	src/Core/includes/Requests.hpp
	src/Core/includes/Telegram.hpp
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Demo_bot)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

set(PRIVATE_SOURCES
	src/Core/src/Requests.cpp
	src/Core/src/Telegram.cpp
)

add_library(${PROJECT_NAME} STATIC
			${PUBLIC_INCLUDES}
			${PRIVATE_SOURCES}
)

add_subdirectory(json ${PROJECT_SOURCE_DIR}/json)
add_subdirectory(src/Demo ${PROJECT_SOURCE_DIR}/src/Demo)

target_include_directories(${PROJECT_NAME} PUBLIC src/Core/includes)
target_link_libraries(${PROJECT_NAME} PRIVATE WinInet.lib)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/)