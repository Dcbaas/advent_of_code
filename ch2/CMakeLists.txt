cmake_minimum_required (VERSION 3.8)

project(ch2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
	src/main.cpp
	src/dive.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${PROJECT_SOURCE_DIR}/include
)