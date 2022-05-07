cmake_minimum_required(VERSION 3.0)

project(add_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(ship SHARED Ships.cpp)

add_library(field SHARED Field.cpp)
target_link_libraries(field PUBLIC ship)

add_library(field_builder SHARED Field_builder.cpp)
target_link_libraries(field_builder PUBLIC ship field)

add_library(bot SHARED bot.cpp)
target_link_libraries(bot PUBLIC field_builder ship field)
