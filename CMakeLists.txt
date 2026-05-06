cmake_minimum_required(VERSION 3.14)
project(strutil-tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

option(COVERAGE "Build with --coverage flags for gcov/lcov" OFF)
option(STRUTIL_ENABLE_PARALLEL "Enable parallel sibling functions (drop_duplicate_par, sorting_ascending_par, ...) in strutil.h" OFF)

# GoogleTest via FetchContent (https://google.github.io/googletest/quickstart-cmake.html)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME} tests/strutil_tests.cpp tests/test_cases.cpp strutil.h)

if (STRUTIL_ENABLE_PARALLEL)
    target_compile_definitions(${PROJECT_NAME} PRIVATE STRUTIL_ENABLE_PARALLEL)
endif()

if (COVERAGE)
    target_compile_options(${PROJECT_NAME} PRIVATE --coverage)
    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main --coverage)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
endif()

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
