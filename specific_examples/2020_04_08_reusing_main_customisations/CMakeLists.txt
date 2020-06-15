project(2020_04_08_reusing_main_customisations)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}
        main.cpp
        SampleTest.cpp
        OurApprovalTestCustomisations.h
        )
target_link_libraries(${PROJECT_NAME} CONAN_PKG::approvaltests.cpp include Catch2::Catch2)
target_compile_definitions(${PROJECT_NAME} PRIVATE CATCH_CONFIG_FAST_COMPILE)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
