cmake_minimum_required(VERSION 3.10)
project(qenv LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

find_package(GTest REQUIRED)
find_package(Armadillo REQUIRED)

add_compile_options(-O2 --debug)

if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found. Please make sure it is installed.")
endif()

add_library(qenv STATIC
    src/Confirm.cxx
    src/Engine.cxx
    src/Instructions.cxx
    src/qtils.cxx
    src/QubitClass.cxx
    src/QuditClass.cxx
)

add_library(qenv::qenv ALIAS qenv)

add_executable(confirm_test tests/confirm_.cpp)
add_executable(utils_test tests/utils.cpp)
add_executable(gates_test tests/gates.cpp)
add_executable(QD_gates_test tests/QD_gates.cpp)
add_executable(engine_test tests/engine.cpp)

target_link_libraries(engine_test PRIVATE qenv::qenv GTest::GTest GTest::Main ${ARMADILLO_LIBRARIES})

target_link_libraries(confirm_test PRIVATE qenv::qenv GTest::GTest GTest::Main ${ARMADILLO_LIBRARIES})

target_link_libraries(utils_test PRIVATE qenv::qenv GTest::GTest GTest::Main ${ARMADILLO_LIBRARIES})

target_link_libraries(gates_test PRIVATE qenv::qenv GTest::GTest GTest::Main ${ARMADILLO_LIBRARIES})

target_link_libraries(QD_gates_test PRIVATE qenv::qenv GTest::GTest GTest::Main ${ARMADILLO_LIBRARIES})

add_custom_target(execute_all_tests ALL COMMAND /home/bassneptun/qtest_env/execute_all_tests.sh WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
