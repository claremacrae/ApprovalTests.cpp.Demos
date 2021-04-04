# Needs CMake 3.14 or above
include(FetchContent)

# Prevent ctest creating cluttering up CLion with nearly 30 CTest targets
# (Continuous, ContinuousBuild etc) when it does:
#   include(CTest)
# This hack taken from https://stackoverflow.com/a/57240389/104370
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1) # hack to prevent CTest added targets

# -------------------------------------------------------------------
# Catch2
message(NOTICE "Fetching Catch2...")
set(CATCH_BUILD_TESTING OFF CACHE BOOL "")
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x)
FetchContent_MakeAvailable(Catch2)

# -------------------------------------------------------------------
# doctest
message(NOTICE "Fetching doctest...")
FetchContent_Declare(
        doctest
        GIT_REPOSITORY  https://github.com/onqtam/doctest.git
        GIT_TAG         master
)
FetchContent_MakeAvailable(doctest)
set_target_properties(doctest_with_main PROPERTIES FOLDER "external")

# -------------------------------------------------------------------
# GoogleTest
message(NOTICE "Fetching googletest...")
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" )
FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/abseil/googletest.git
        GIT_TAG         master)
FetchContent_MakeAvailable(googletest)

# -------------------------------------------------------------------
# ApprovalTests.cpp
message(NOTICE "Fetching ApprovalTests.cpp...")
FetchContent_Declare(
        ApprovalTests
        GIT_REPOSITORY  https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG         master)
FetchContent_MakeAvailable(ApprovalTests)
