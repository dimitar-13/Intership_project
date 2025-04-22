cmake_minimum_required(VERSION 3.28.1) 

set (CMAKE_CXX_STANDARD 17)

project("Shapes")

add_executable(${PROJECT_NAME} "entry_point.cpp")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/figures")

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/*.h" )
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")