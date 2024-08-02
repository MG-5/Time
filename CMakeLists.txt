cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0048 NEW)

project(Time LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC Time.cxx)
target_include_directories(${PROJECT_NAME} PUBLIC .)

include(CTest)
if(BUILD_TESTING)
    find_package(GTest)

    add_executable(${PROJECT_NAME}_tests
            Time.cxx
            tests/main.cxx
            tests/ConstructorTest.cxx
            tests/AdditionTest.cxx
            tests/AssignOperator.cxx
            tests/SubtractionTest.cxx
            tests/DifferenceTest.cxx
            tests/OutputOperator.cxx
            tests/SmallerThanOperator.cxx)

    target_link_libraries(${PROJECT_NAME}_tests ${GTEST_BOTH_LIBRARIES})
    add_test(${PROJECT_NAME}_tests ${PROJECT_NAME}_tests)
endif()
