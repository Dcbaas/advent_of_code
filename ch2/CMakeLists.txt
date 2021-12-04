cmake_minimum_required (VERSION 3.8)

project(ch2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE RELEASE)

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

target_link_libraries(${PROJECT_NAME}
	advent::common
)

configure_file(${PROJECT_SOURCE_DIR}/input/sample_travel_data.txt input/sample_travel_data.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/input/travel_data.txt input/travel_data.txt COPYONLY)