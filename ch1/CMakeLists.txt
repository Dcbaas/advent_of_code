cmake_minimum_required (VERSION 3.8)

project(ch1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
	src/sonar.cpp
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${PROJECT_SOURCE_DIR}/include
)

configure_file(${PROJECT_SOURCE_DIR}/input/sample_depths.txt input/sample_depths.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/input/depths.txt input/depths.txt COPYONLY)
