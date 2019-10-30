cmake_minimum_required(VERSION 3.6)
project(bertha)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

# CXX_STANDARD is required
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was "
    "specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build."
    FORCE)
  # set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# specify components
option(WITH_PYTHON "with(out) Python interface" ON)

# Python interface dependencies available?
if(WITH_PYTHON)
  find_package(SWIG 2.0.12)
  find_package(PythonLibs)
  if(SWIG_FOUND AND PythonLibs_FOUND)
    include(${SWIG_USE_FILE})
    set(USE_PYTHON TRUE)
  endif(SWIG_FOUND AND PythonLibs_FOUND)
endif(WITH_PYTHON)

# library
#include_directories(include/)

add_library(bertha SHARED
  src/device.cpp)

set_property(TARGET bertha PROPERTY CXX_STANDARD 11)

target_include_directories(bertha PUBLIC include/)

# Python interface
if(USE_PYTHON)
  include_directories("include/" ${PYTHON_INCLUDE_PATH})
  set_source_files_properties(swig/bertha.i PROPERTIES CPLUSPLUS ON)
  swig_add_module(pybertha python swig/bertha.i)
  set_property(TARGET ${SWIG_MODULE_pybertha_REAL_NAME} PROPERTY
    CXX_STANDARD 11)
  swig_link_libraries(pybertha ${PYTHON_LIBRARIES} bertha)
endif(USE_PYTHON)
