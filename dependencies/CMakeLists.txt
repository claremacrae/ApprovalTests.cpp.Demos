# Needs CMake 3.14 or above
include(FetchContent)

# -------------------------------------------------------------------
# ApprovalTests.cpp
set(APPROVAL_TESTS_BUILD_TESTING OFF CACHE BOOL "")
set(APPROVAL_TESTS_BUILD_EXAMPLES OFF CACHE BOOL "")
set(APPROVAL_TESTS_BUILD_DOCS OFF CACHE BOOL "")

set(APPROVAL_TESTS_BUILD_THIRD_PARTY_CATCH2 OFF CACHE BOOL "")
set(APPROVAL_TESTS_BUILD_THIRD_PARTY_DOCTEST OFF CACHE BOOL "")
set(APPROVAL_TESTS_BUILD_THIRD_PARTY_UT OFF CACHE BOOL "")

set(APPROVAL_TESTS_ENABLE_BOOST_TEST_INTEGRATION OFF CACHE BOOL "")
set(APPROVAL_TESTS_ENABLE_CPPUTEST_INTEGRATION OFF CACHE BOOL "")
set(APPROVAL_TESTS_ENABLE_GOOGLETEST_INTEGRATION OFF CACHE BOOL "")
set(APPROVAL_TESTS_ENABLE_UT_INTEGRATION OFF CACHE BOOL "")


FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG master)

FetchContent_MakeAvailable(ApprovalTests)

# -------------------------------------------------------------------
# Catch2
set(CATCH_BUILD_TESTING OFF CACHE BOOL "")
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.11.1)

FetchContent_MakeAvailable(Catch2)
