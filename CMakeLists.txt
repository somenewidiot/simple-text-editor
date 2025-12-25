cmake_minimum_required(VERSION 3.16)

project("Simple Text Editor" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(steditor
    src/main.cpp
    src/editor.cpp
    src/editor.hpp
)

target_link_libraries(steditor Qt6::Widgets)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mno-direct-extern-access")
endif()
