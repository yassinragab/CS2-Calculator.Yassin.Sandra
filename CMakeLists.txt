cmake_minimum_required(VERSION 3.10)


project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    main.cpp
    test.cpp
    calculator.cpp
)



add_executable(calcExe ${SOURCES})