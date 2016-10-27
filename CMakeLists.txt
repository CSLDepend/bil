cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(bil CXX C)

include_directories(SYSTEM "${CMAKE_CURRENT_SOURCE_DIR}/third party")

add_subdirectory(src)
add_subdirectory(drivers)
