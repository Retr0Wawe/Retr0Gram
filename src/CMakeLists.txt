cmake_minimum_required(VERSION 3.12)

project(Telegram_tool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

#file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
#add_executable(${PROJECT_NAME} ${SRC_FILES})

set(PUBLIC_INCLUDES
	Core/includes/Requests.hpp
	Core/includes/Telegram.hpp
	)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

set(PRIVATE_SOURCES
	Core/src/Requests.cpp
	Core/src/Telegram.cpp
	Core/main.cpp
    )

add_executable(${PROJECT_NAME} 
			   ${PUBLIC_INCLUDES}
			   ${PRIVATE_SOURCES}
)

add_subdirectory(${PROJECT_SOURCE_DIR}/json)

target_include_directories(${PROJECT_NAME} PUBLIC Core/includes)
target_link_libraries(${PROJECT_NAME} PRIVATE WinInet.lib)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json)