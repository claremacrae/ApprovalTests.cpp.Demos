# Needs CMake 3.14 or above
include(FetchContent)

# Prevent ctest creating cluttering up CLion with nearly 30 CTest targets
# (Continuous, ContinuousBuild etc) when it does:
#   include(CTest)
# This hack taken from https://stackoverflow.com/a/57240389/104370
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1) # hack to prevent CTest added targets

# -------------------------------------------------------------------
# Program Version Numbers - and/or commit IDs

# Tested with versions in range: v2.3.0 ... v2.13.3
# Does not work with devel, and v3 releases
set(Catch2Version
        "v2.x")

# Tested with versions in range: 2.3.4 ... 2.4.1
set(DocTestVersion
        "master")

# Tested with versions in range: release-1.8.0 ... release-1.10.0
set(GoogleTestVersion
        "master")

# -------------------------------------------------------------------
# Catch2
message(NOTICE "Fetching Catch2...")
set(CATCH_BUILD_TESTING OFF CACHE BOOL "")
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG ${Catch2Version})
FetchContent_MakeAvailable(Catch2)

# -------------------------------------------------------------------
# doctest
message(NOTICE "Fetching doctest...")
FetchContent_Declare(
        doctest
        GIT_REPOSITORY  https://github.com/onqtam/doctest.git
        GIT_TAG         ${DocTestVersion}
)
FetchContent_MakeAvailable(doctest)
set_target_properties(doctest_with_main PROPERTIES FOLDER "external")

# -------------------------------------------------------------------
message(NOTICE "Fetching googletest...")
# GoogleTest
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" )
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/abseil/googletest.git
        GIT_TAG ${GoogleTestVersion})
FetchContent_MakeAvailable(googletest)

# -------------------------------------------------------------------
# ApprovalTests.cpp
message(NOTICE "Fetching ApprovalTests.cpp...")

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
