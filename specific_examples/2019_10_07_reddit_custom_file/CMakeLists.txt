project(2019_10_07_reddit_custom_file)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}
    main.cpp
    FakeCustomFile.cpp
    FakeCustomFile.h
    FileHeaderTests-Catch.cpp
    FileHeaderTests-ApprovalTestsV1.cpp
    FileHeaderTests-ApprovalTestsV2.cpp
    FileHeaderTests-ApprovalTestsV3.cpp)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::approvaltests.cpp include CONAN_PKG::catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_FAST_COMPILE)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
