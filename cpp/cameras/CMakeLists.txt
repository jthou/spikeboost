cmake_minimum_required(VERSION 3.15)
project(sps_cameras)

include(../cmake_global.cmake)

option(BUILD_CAMERA_EMULATORS "Build camera emulators" OFF)

include_directories(../include)
##set(SRC ../include/cameras/sps_usb.h)
if(BUILD_CAMERA_EMULATORS)
  set(SRC ${SRC} sps_usb_emulator.cpp)
else()
  set(SRC ${SRC} sps_usb_device.cpp)
endif()

# cpp share library
message(STATUS "SRC: ${SRC}")
message(STATUS ${PROJECT_NAME})
add_library(${PROJECT_NAME} SHARED ${SRC})

if(WIN32)
  set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

# python module
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../external/pybind11/include)
pybind11_add_module(py_sps_cameras ${SRC} sps_usb_pybind11.cpp)
target_link_libraries(py_sps_cameras PRIVATE pybind11::module)
target_link_libraries(py_sps_cameras PRIVATE sps_cameras)