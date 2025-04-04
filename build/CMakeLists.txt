cmake_minimum_required(VERSION 3.10)

project(CS2_Calculator_Yassin_Sandra)  # Fixed project name

set(SOURCE_FILES                       
    calculator.cpp
    test.cpp
)

add_executable(calcExe ${SOURCE_FILES})  # Using the variable instead of repeating file names
