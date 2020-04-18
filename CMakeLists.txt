project(UnscentedKF)

cmake_minimum_required(VERSION 3.5)
add_definitions(-std=c++0x)
find_package(Eigen3)

include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(include)

set(SOURCES src/tools.cpp
            src/measurementpredictor.cpp
            src/statepredictor.cpp
            src/stateupdater.cpp
            src/data_point.cpp
            src/fusion_ukf.cpp
            src/process_data.cpp
            src/test_ukf.cpp)

add_executable(UnscentedKF ${SOURCES})
