cmake_minimum_required(VERSION 3.16)

project("Simple Text Editor" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Qt6 auto tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Source files
set(SOURCES
    src/main.cpp
    src/editor/editor.cpp
)

# Header files
set(HEADERS
    src/editor/editor.hpp
)

# Adding files to executable
add_executable(steditor
    ${SOURCES}
    ${HEADERS}
)

# Compiling stuff
target_link_libraries(steditor Qt6::Widgets)
target_compile_options(steditor PRIVATE -fvisibility=hidden)
