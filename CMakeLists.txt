cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE MAIN_SOURCES	*.cpp *.h *.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories("src")

add_executable (TSPAutoExperimenter ${MAIN_SOURCES})
