project(2019_11_18_fuzzing_gilded_rose)

set(GTEST_BOTH_LIBRARIES gtest gtest_main)

add_executable(GildedRoseApprovalTests
    GildedRose.cc
    GildedRose.h
    GildedRoseApprovalTests.cc
    GildedRoseApprovalMain.cc
    )
target_link_libraries(GildedRoseApprovalTests ${GTEST_BOTH_LIBRARIES} ApprovalTests)
set_property(TARGET GildedRoseApprovalTests PROPERTY CXX_STANDARD 14)
add_test(NAME GildedRoseApprovalTests COMMAND GildedRoseApprovalTests)
