cmake_minimum_required(VERSION 3.10)
project(calculator VERSION 0.1.0 LANGUAGES CXX)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/contrib)

include(cmake/cpm.cmake)

CPMAddPackage(
    NAME GOOGLETEST
    GITHUB_REPOSITORY google/googletest
    VERSION 1.16.0
    SOURCE_DIR ${LIB_DIR}/googletest
    OPTIONS 
        "INSTALL_GTEST OFF"
        "gtest_force_shared_crt ON"
)
enable_testing()

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)
set_property(TARGET project_options PROPERTY CXX_EXTENSIONS OFF)

target_compile_options(project_options INTERFACE

    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra;-pedantic>
    $<$<CONFIG:Release>:-O3>
    $<$<CONFIG:Debug>:-O0;-g>
)

add_subdirectory(src)
