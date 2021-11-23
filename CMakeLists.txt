cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0048 NEW)

project(Time LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC Time.cxx)
target_include_directories(${PROJECT_NAME} PUBLIC .)