cmake_minimum_required(VERSION 3.30)
project(operators)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(cuda)
include_directories(include)
include_directories(src)

add_executable(operators
        include/main.h
        src/gradient/sobel.cpp
        include/gradient/sobel.h
        main.cpp
        include/gradient/gradient_operator.h
        src/gradient/alt_sobel.cpp
        include/gradient/alt_sobel.h
        src/utils/image_utils.cpp
        include/utils/image_utils.h
        include/utils/sobel_util.h
        src/utils/path_helper.cpp
        include/utils/path_helper.h
)

target_link_libraries(operators ${OpenCV_LIBS})