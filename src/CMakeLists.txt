cmake_minimum_required(VERSION 3.28.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;MinSizeRel;Test" CACHE STRING "" FORCE)

project("Shapes")

add_executable(${PROJECT_NAME} "entry_point.cpp")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/figures")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/core")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Test>:TEST>
)

if(CMAKE_CONFIGURATION_TYPES)
    set(CONFIG_IS_TEST "$<CONFIG:Test>")
else()
    set(CONFIG_IS_TEST "${CMAKE_BUILD_TYPE}" STREQUAL "Test")
endif()

if(CONFIG_IS_TEST OR CMAKE_BUILD_TYPE STREQUAL "Test")
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
    )
    FetchContent_MakeAvailable(Catch2)

    target_link_libraries(${PROJECT_NAME} PRIVATE
        Catch2::Catch2WithMain
    )

    get_filename_component(TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../tests" ABSOLUTE)
    add_subdirectory("${TESTS_DIR}" "${CMAKE_BINARY_DIR}/tests")

    include(CTest)
    include(Catch)
    catch_discover_tests(${PROJECT_NAME})
endif()
