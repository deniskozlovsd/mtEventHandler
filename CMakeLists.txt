cmake_minimum_required(VERSION 3.28)

project(ehandler LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


add_executable(ehandler main.cpp)

target_sources(ehandler
    PUBLIC
    EventHandler/eHandler.cpp)

target_compile_features(ehandler PUBLIC cxx_std_20)

target_include_directories(ehandler PUBLIC
                            ${CMAKE_CURRENT_SOURCE_DIR}/EventHandler/)