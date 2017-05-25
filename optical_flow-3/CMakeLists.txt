cmake_minimum_required (VERSION 2.6)
project (Face_detect)
find_package (OpenCV REQUIRED)
add_executable(FaceDetect Header.h myfunc.cpp main.cpp calc.cpp clean.cpp)
target_link_libraries( FaceDetect ${OpenCV_LIBS} )

