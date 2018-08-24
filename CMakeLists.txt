cmake_minimum_required (VERSION 3.5)
project(drum-rest)
set (CMAKE_CXX_STANDARD 11)

include_directories(
	"${CMAKE_SOURCE_DIR}"
	${CMAKE_CURRENT_SOURCE_DIR}/../drumgizmo/src
	${CMAKE_CURRENT_SOURCE_DIR}/../drumgizmo/include
)

link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../drumgizmo/src/.libs
)

add_library(libpistache STATIC IMPORTED)

add_executable(drum-rest
  main.cpp
)

target_link_libraries(
	drum-rest
	pistache
	pthread
	dg
)





