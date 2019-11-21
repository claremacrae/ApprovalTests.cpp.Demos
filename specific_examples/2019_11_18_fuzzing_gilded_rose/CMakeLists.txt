project(2019_11_18_fuzzing_gilded_rose)

set(GTEST_BOTH_LIBRARIES gtest gtest_main)

add_executable(${PROJECT_NAME}
    GildedRose.cc
    GildedRose.h
    GildedRoseApprovalTests.cc
    GildedRoseApprovalMain.cc
    )
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} ApprovalTests)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

#if(APPROVAL_TESTS_DEMOS_ENABLE_CODE_COVERAGE)
#    setup_target_for_coverage_lcov(
#            NAME ${PROJECT_NAME}_coverage
#            EXECUTABLE ${PROJECT_NAME}
#            DEPENDENCIES ${PROJECT_NAME})
#endif()
