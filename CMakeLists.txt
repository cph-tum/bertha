#
# bertha: Project skeleton for scientific software (C++ w/ Python interface).
#
# Copyright 2019 Michael Riesch <michael.riesch@tum.de>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.6)

# project information
set(PROJECT "bertha")
set(PROJECT_AUTHOR "Michael Riesch")
set(PROJECT_EMAIL "michael.riesch@tum.de")
set(PROJECT_URL "https://www.gitlab.com/cph-tum/bertha")
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION_PRRLS "")
set(VERSION_CORE "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set(VERSION_FULL "${VERSION_CORE}${VERSION_PRRLS}")
project(${PROJECT} VERSION ${VERSION_CORE})

# is python installation prefix set?
if(DEFINED ENV{PREFIX})
  set(PREFIX_SETUPPY "--prefix $ENV{PREFIX}")
endif()

# require CMake GNUInstallDirs package
include(GNUInstallDirs)

# CXX_STANDARD is required
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# export shared library symbols on Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

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
option(WITH_DOXYGEN "with(out) Doxygen documentation" ON)
option(WITH_FORMAT "with(out) clang-format support" ON)
option(WITH_PYTHON "with(out) Python interface" ON)
option(WITH_TESTS "with(out) Catch2 unit tests" OFF)

# Python interface dependencies available?
if(WITH_PYTHON)
  find_package(SWIG 2.0.12)
  find_package(PythonInterp)
  find_package(PythonLibs)
  if(SWIG_FOUND AND PythonLibs_FOUND AND PythonInterp_FOUND)
    include(${SWIG_USE_FILE})
    set(USE_PYTHON TRUE)
    set(PYTHON_IFACE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}")
  endif(SWIG_FOUND AND PythonLibs_FOUND AND PythonInterp_FOUND)
endif(WITH_PYTHON)

# Doxygen documentation
if(WITH_DOXYGEN)
  find_package(Doxygen)
  if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
      ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
      ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen" VERBATIM)
  endif(DOXYGEN_FOUND)
endif(WITH_DOXYGEN)

# clang-format support
if(WITH_FORMAT)
  find_program(CLANG_FORMAT NAMES "clang-format" "clang-format-6.0")
  if(CLANG_FORMAT)
    set(USE_FORMAT TRUE)
  endif(CLANG_FORMAT)
endif(WITH_FORMAT)

# Catch2 unit tests
if(WITH_TESTS)
  find_package(Catch2)
  if(Catch2_FOUND)
    set(USE_TESTS TRUE)
    include(CTest)
    include(Catch)
    enable_testing()
  endif(Catch2_FOUND)
endif(WITH_TESTS)

# add subdirectories
add_subdirectory(core)

# install Python interface
if(USE_PYTHON)
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/python/setup.py.in"
    "${CMAKE_CURRENT_BINARY_DIR}/setup.py.inc")
  file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/setup.py"
    INPUT "${CMAKE_CURRENT_BINARY_DIR}/setup.py.inc")
  file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/__init__.py"
    INPUT "${CMAKE_CURRENT_SOURCE_DIR}/python/__init__.py.in")
  install(CODE
    "execute_process(COMMAND ${PYTHON_EXECUTABLE} -m pip install . \
     ${PREFIX_SETUPPY} \
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})")
endif(USE_PYTHON)

# get all source files
get_target_property(CORE_SOURCE_FILES ${PROJECT}core SOURCES)
list(APPEND ALL_SOURCE_FILES ${CORE_SOURCE_FILES})

# code formatting check
if(USE_FORMAT)
  add_custom_target(format
    COMMAND ${CLANG_FORMAT} -style=file -i ${ALL_SOURCE_FILES}
    COMMENT "Formatting all source files")
endif(USE_FORMAT)
