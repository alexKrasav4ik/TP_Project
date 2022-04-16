cmake_minimum_required(VERSION 3.0)

project(TpProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TpProject_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TpProject_SOURCE_DIR}/lib)

add_subdirectory(src)

add_executable(GAME interactor.cpp)
target_link_libraries(GAME PUBLIC ship field bot field_builder)
