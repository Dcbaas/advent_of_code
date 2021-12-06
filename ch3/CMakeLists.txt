cmake_minimum_required (VERSION 3.14)

project(ch3)
if(MSVC)
	set(CMAKE_CXX_STANDARD 23)
else()
	set(CMAKE_CXX_STANDARD 20)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE RELEASE)

set(SOURCES
	src/main.cpp
	src/diagnostic.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${PROJECT_SOURCE_DIR}/include
)

find_package(Boost REQUIRED)

target_link_libraries(${PROJECT_NAME}
	advent::common
	Boost::boost
)

configure_file(${PROJECT_SOURCE_DIR}/input/sample_diagnostic.txt input/sample_diagnostic.txt COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/input/diagnostic_data.txt input/diagnostic_data.txt COPYONLY)