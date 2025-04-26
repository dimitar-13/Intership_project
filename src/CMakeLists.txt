cmake_minimum_required(VERSION 3.28.1) 
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;MinSizeRel;Test" CACHE STRING "" FORCE)

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
get_filename_component(TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../tests" ABSOLUTE)
add_subdirectory("${TESTS_DIR}" "${CMAKE_BINARY_DIR}/tests")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Test>:TEST>
)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME})