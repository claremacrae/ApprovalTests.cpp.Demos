cmake_minimum_required(VERSION 3.14)

# disable testsuite if used via add_subdirectory()
if (NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
else()
    set(NOT_SUBPROJECT OFF)
endif ()

# Provide path for scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")

project(ApprovalTests.cpp.Demos)

set(CMAKE_VERBOSE_MAKEFILE off)

enable_testing()
add_subdirectory(include)

add_subdirectory(dependencies)

add_subdirectory(catch2_demo)
add_subdirectory(doctest_demo)
add_subdirectory(google_test_demo)
add_subdirectory(specific_examples)
