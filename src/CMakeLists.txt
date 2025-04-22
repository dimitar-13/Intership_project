cmake_minimum_required(VERSION 3.28.1) 
set (CMAKE_CXX_STANDARD 17)

project("Shapes")

## Testing lib
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.4
)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} "entry_point.cpp")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/figures")

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/*.h" )
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")


target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME})