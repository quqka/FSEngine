cmake_minimum_required(VERSION 3.1)

project(Hazel)
set(SRC_LIST 
            src/Hazel/Application.cpp
            src/Hazel/Log.cpp)
add_library(Hazel STATIC ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC vendor/spdlog/include)