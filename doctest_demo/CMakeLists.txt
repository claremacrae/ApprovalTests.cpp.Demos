project(doctest_demo)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}
        main.cpp
        Test01.cpp
        Test02.cpp
        )
target_link_libraries(${PROJECT_NAME} ApprovalTests include doctest)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

include(WarningsAsErrors)
