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
  src/device.cpp)
set_target_properties(${PROJECT}core PROPERTIES
  CXX_STANDARD 11
  VERSION ${VERSION_CORE}
  SOVERSION ${VERSION_MAJOR})
target_include_directories(${PROJECT}core PUBLIC "include")

# Python interface
if(USE_PYTHON)
  include_directories("include" ${PYTHON_INCLUDE_PATH})
  set_source_files_properties(swig/core.i PROPERTIES CPLUSPLUS ON)
  set(CMAKE_SWIG_OUTDIR ${PYTHON_IFACE_PATH})
  swig_add_module(core python swig/core.i)
  set_target_properties(${SWIG_MODULE_core_REAL_NAME} PROPERTIES
    CXX_STANDARD 11
    VERSION ${VERSION_CORE}
    SOVERSION ${VERSION_MAJOR}
    LIBRARY_OUTPUT_DIRECTORY ${PYTHON_IFACE_PATH})
  set(SWIG_MODULE_core_REAL_NAME ${SWIG_MODULE_core_REAL_NAME} PARENT_SCOPE)
  swig_link_libraries(core ${PYTHON_LIBRARIES} ${PROJECT}core)
endif(USE_PYTHON)

# install library
install(TARGETS ${PROJECT}core
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# install public header files
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})