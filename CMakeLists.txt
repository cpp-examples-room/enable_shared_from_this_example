cmake_minimum_required(VERSION 3.5.2)

include("gate/cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.18.52.tar.gz"
    SHA1 "b16c19e28aefbb83b02aa90bacf8350fc45ef7d0")

project(enable_shared_from_this_example)
include("config.cmake")

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
