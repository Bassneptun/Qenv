cmake_minimum_required(VERSION 3.16)

project(qtest_env)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -Werror -pedantic -larmadillo)

set(SRC_DIR src)
set(INCLUDE_DIR include/header/)
set(OBJ_DIR include/object/)
set(EXE_DIR executables/)
set(TEST_DIR tests/)

set(SOURCES)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp")
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES}  
set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXE_DIR}))
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
