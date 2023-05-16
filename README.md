# FaceDetection

Software Requirements
1. OpenCV
2. CMake
3. VS Code

Changes in CMakeLists.txt
1. Change project name
2. Change project directory 
    set(OpenCV_DIR "C:/Users/Raviteja/Downloads/opencv/build")
3. add_executable(FACEDETECTION main.cpp)
   target_link_libraries(FACEDETECTION ${OpenCV_LIBS})

Changes in c_cpp_properties.json file
1. Change Path 

Download and install opencv and CMAKE

1. https://opencv.org/releases/
2. https://cmake.org/download/

Add following paths in environemnt variable along with CMAKE
C:\Users\Raviteja\Downloads\opencv\build\x64\vc15\bin
C:\Users\Raviteja\Downloads\opencv\build\x64\vc15\lib

# TEST

Ctrl+shift+p 

1. CMake : Build
2. Cmake : Run without Debugging