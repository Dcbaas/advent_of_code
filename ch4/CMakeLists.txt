cmake_minimum_required (VERSION 3.14)

project(ch4)
if(MSVC)
	set(CMAKE_CXX_STANDARD 23)
else()
	set(CMAKE_CXX_STANDARD 20)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE RELEASE)

set(SOURCES
	src/main.cpp
	src/bingo.cpp
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

#configure_file(${PROJECT_SOURCE_DIR}/input/sample_bingo.txt input/sample_bingo.txt COPYONLY)
#configure_file(${PROJECT_SOURCE_DIR}/input/bingo_data.txt input/bingo_data.txt COPYONLY)