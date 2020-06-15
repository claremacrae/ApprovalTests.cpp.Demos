project(google_test_demo)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME}
        main.cpp
        Test01.cpp
        Test02.cpp
        Test03CustomReporters.cpp
        Test04ConsoleReporter.cpp
        Test05VerifyAll.cpp
        Test06VerifyAllCombinations.cpp
        Test07TestScenarios.cpp
        Test08Factorial.cpp
        )
target_link_libraries(${PROJECT_NAME} CONAN_PKG::approvaltests.cpp include CONAN_PKG::gtest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

#include(WarningsAsErrors)
