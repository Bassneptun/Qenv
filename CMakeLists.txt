cmake_minimum_required(VERSION 3.10)
project(qtest_env LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

find_package(GTest REQUIRED)

if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found. Please make sure it is installed.")
endif()

add_library(qtest_env STATIC
    src/Confirm.cxx
    src/Engine.cxx
    src/Instructions.cxx
    src/qtils.cxx
    src/QubitClass.cxx
    src/QuditClass.cxx
)

add_library(qtest_env::qtest_env ALIAS qtest_env)

add_executable(tests tests/test.cpp)

target_link_libraries(tests PRIVATE qtest_env::qtest_env GTest::GTest GTest::Main)
