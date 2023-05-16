cmake_minimum_required(VERSION 3.0)
project(FACEDETECTION)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR "C:/Users/Raviteja/Downloads/opencv/build")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(FACEDETECTION main.cpp)
target_link_libraries(FACEDETECTION ${OpenCV_LIBS})