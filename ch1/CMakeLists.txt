cmake_minimum_required (VERSION 3.8)

project(ch1)

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

target_link_libraries(${PROJECT_NAME}
	advent::common
)

configure_file(${PROJECT_SOURCE_DIR}/input/sample_depths.txt input/sample_depths.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/input/depths.txt input/depths.txt COPYONLY)
