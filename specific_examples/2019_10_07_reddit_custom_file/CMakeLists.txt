project(2019_10_07_reddit_custom_file)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}
        main.cpp
        FileHeaderTests.cpp
        FakeCustomFile.cpp
        FakeCustomFile.h
    FileHeaderTests-Catch.cpp)
target_link_libraries(${PROJECT_NAME} ApprovalTests include catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_FAST_COMPILE)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
