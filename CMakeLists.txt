cmake_minimum_required(VERSION 3.30)
project(operators)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)
include_directories(src)

add_executable(operators
        include/main.h
        src/gradient/sobel.cpp
        src/gradient/sobel.h
        main.cpp
        src/gradient/gradient_operator.h
)

target_link_libraries(operators ${OpenCV_LIBS})