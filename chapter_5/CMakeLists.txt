cmake_minimum_required(VERSION 3.10)
project(chapter_5)

set(CMAKE_CXX_STANDARD 11)

add_executable(chapter_5 main.cpp TCourse.cpp TCourse.h ../chapter_4/TString.cpp ../chapter_4/TString.h TStudent.cpp TStudent.h)