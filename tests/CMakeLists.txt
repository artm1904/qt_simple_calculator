cmake_minimum_required(VERSION 3.10)
project(stream_handle_test VERSION 0.1.0)

enable_testing()

add_executable(${PROJECT_NAME}
    src/test.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${GOOGLETEST_SOURCE_DIR}/googletest/include
        ${CMAKE_SOURCE_DIR}/src/
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        GTest::gtest_main
        stream_handle
        project_options
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
