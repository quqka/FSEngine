cmake_minimum_required(VERSION 3.1)

project(Sandbox)
set(SRC_LIST src/SandBoxApp.cpp)

add_subdirectory(Hazel)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} Hazel)
target_include_directories(${PROJECT_NAME} PRIVATE Hazel/src)