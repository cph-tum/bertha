cmake_minimum_required(VERSION 3.6)

# project information
set(PROJECT "bertha")
set(PROJECT_AUTHOR "Michael Riesch")
set(PROJECT_EMAIL "michael.riesch@tum.de")
set(PROJECT_URL "https://www.gitlab.com/cph-tum/bertha")
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
project(${PROJECT})

# is install prefix set?
set(PROJECT_PREFIX "")
if(DEFINED ENV{PREFIX})
  set(CMAKE_INSTALL_PREFIX $ENV{PREFIX})
  set(PROJECT_PREFIX "--prefix $ENV{PREFIX}")
endif(DEFINED ENV{PREFIX})

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
  find_package(PythonInterp)
  if(SWIG_FOUND AND PythonLibs_FOUND AND PythonInterp_FOUND)
    include(${SWIG_USE_FILE})
    set(USE_PYTHON TRUE)
  endif(SWIG_FOUND AND PythonLibs_FOUND AND PythonInterp_FOUND)
endif(WITH_PYTHON)

# library
add_library(${PROJECT}core SHARED
  src/device.cpp)
set_property(TARGET ${PROJECT}core PROPERTY CXX_STANDARD 11)
target_include_directories(${PROJECT}core PUBLIC "include")

# Python interface
if(USE_PYTHON)
  include_directories("include" ${PYTHON_INCLUDE_PATH})
  set_source_files_properties(swig/core.i PROPERTIES CPLUSPLUS ON)
  set(CMAKE_SWIG_OUTDIR ${PROJECT})
  swig_add_module(core python swig/core.i)
  set_property(TARGET ${SWIG_MODULE_core_REAL_NAME} PROPERTY
    CXX_STANDARD 11)
  set_property(TARGET ${SWIG_MODULE_core_REAL_NAME} PROPERTY
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT})
  swig_link_libraries(core ${PYTHON_LIBRARIES} ${PROJECT}core)
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/swig/setup.py.in"
    "${CMAKE_CURRENT_BINARY_DIR}/setup.py.inc")
  file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/setup.py"
    INPUT "${CMAKE_CURRENT_BINARY_DIR}/setup.py.inc")
  file(GENERATE
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}/__init__.py"
    INPUT "${CMAKE_CURRENT_SOURCE_DIR}/swig/__init__.py.in")
endif(USE_PYTHON)

# install destinations
include(GNUInstallDirs)

# install library
install(TARGETS ${PROJECT}core
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# install public header files
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# install Python interface module
if(USE_PYTHON)
  install(CODE
    "execute_process(COMMAND ${PYTHON_EXECUTABLE} -m pip install . \
     ${PROJECT_PREFIX} \
     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})")
endif(USE_PYTHON)
