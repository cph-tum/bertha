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

# library
add_library(${PROJECT}core SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/src/device.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/bertha/core.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/bertha/core/device.hpp)
set_target_properties(${PROJECT}core PROPERTIES
  CXX_STANDARD 11
  VERSION ${VERSION_CORE}
  SOVERSION ${VERSION_MAJOR})
target_include_directories(${PROJECT}core PUBLIC "include")
if(USE_TESTS)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT}core PRIVATE -fprofile-arcs
      -ftest-coverage)
    target_link_libraries(${PROJECT}core -lgcov)
  endif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
endif()

# Python interface
if(USE_PYTHON)
  include_directories("include" ${PYTHON_INCLUDE_DIRS})
  set_source_files_properties(swig/core.i PROPERTIES CPLUSPLUS ON)
  set(CMAKE_SWIG_OUTDIR ${PYTHON_IFACE_PATH})
  swig_add_module(core python swig/core.i)
  set_target_properties(${SWIG_MODULE_core_REAL_NAME} PROPERTIES
    CXX_STANDARD 11
    LIBRARY_OUTPUT_DIRECTORY ${PYTHON_IFACE_PATH}
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PYTHON_IFACE_PATH}
    LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${PYTHON_IFACE_PATH}
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PYTHON_IFACE_PATH}
    LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PYTHON_IFACE_PATH})
  set(SWIG_MODULE_core_REAL_NAME ${SWIG_MODULE_core_REAL_NAME} PARENT_SCOPE)
  target_link_libraries(${SWIG_MODULE_core_REAL_NAME} PRIVATE
    ${PROJECT}core)
  if(APPLE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
      target_link_libraries(${SWIG_MODULE_core_REAL_NAME} PRIVATE
        "-undefined dynamic_lookup")
    endif()
  endif()
  if(WIN32)
    target_link_libraries(${SWIG_MODULE_core_REAL_NAME} PRIVATE
      ${PYTHON_LIBRARIES})
  endif()
endif(USE_PYTHON)

# Catch2 unit tests
if(USE_TESTS)
  add_executable(${PROJECT}coretest tests/main.cpp)
  target_include_directories(${PROJECT}coretest PRIVATE "include")
  target_link_libraries(${PROJECT}coretest Catch2::Catch2 ${PROJECT}core)
  set_target_properties(${PROJECT}coretest PROPERTIES CXX_STANDARD 11)
  catch_discover_tests(${PROJECT}coretest)
endif(USE_TESTS)

# install library
install(TARGETS ${PROJECT}core
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# install public header files
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
