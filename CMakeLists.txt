cmake_minimum_required(VERSION 3.16)

project("Simple Text Editor" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Qt6 auto tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Sources
set(SOURCES
    src/main.cpp
    src/editor.cpp
)

set(HEADERS
    src/editor.hpp
)

add_executable(steditor
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(steditor Qt6::Widgets)

# Optional Clang flag
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mno-direct-extern-access")
endif()
