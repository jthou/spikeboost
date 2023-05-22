cmake_minimum_required(VERSION 3.15)
project(test_examples)

include_directories(../../include)

set(TEST_NAME test_sps_usb)
add_executable(${TEST_NAME} test_sps_usb.cpp)
target_link_libraries(${TEST_NAME} PRIVATE sps_cameras)
