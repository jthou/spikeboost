cmake_minimum_required(VERSION 3.15)
project(sps_cameras)

option(BUILD_CAMERA_EMULATORS "Build camera emulators" ON)

include_directories(../include)
set(SRC ../include/cameras/sps_usb.h)
if(BUILD_CAMERA_EMULATORS)
  set(SRC ${SRC} sps_usb_emulator.cpp)
else()
  set(SRC ${SRC} sps_usb_device.cpp)
endif()

message(STATUS "SRC: ${SRC}")
add_library(${PROJECT_NAME} SHARED ${SRC})

if(WIN32)
  set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()