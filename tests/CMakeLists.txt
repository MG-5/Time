cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0048 NEW)
project(Time_test LANGUAGES CXX)

find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        ../Time.cxx
        main.cxx
        ConstructorTest.cxx
        AdditionTest.cxx
        AssignOperator.cxx
        SubtractionTest.cxx
        DifferenceTest.cxx
        OutputOperator.cxx
        SmallerThanOperator.cxx)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${GTEST_LDFLAGS}
        )
target_compile_options(${PROJECT_NAME} PRIVATE ${GTEST_CFLAGS})

include(CTest)
add_test(${PROJECT_NAME} ${PROJECT_NAME})