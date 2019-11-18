cmake_minimum_required(VERSION 3.6)

# library
add_library(${PROJECT}core SHARED
  src/device.cpp)
set_property(TARGET ${PROJECT}core PROPERTY CXX_STANDARD 11)
target_include_directories(${PROJECT}core PUBLIC "include")

# Python interface
if(USE_PYTHON)
  include_directories("include" ${PYTHON_INCLUDE_PATH})
  set_source_files_properties(swig/core.i PROPERTIES CPLUSPLUS ON)
  set(CMAKE_SWIG_OUTDIR ${PYTHON_IFACE_PATH})
  swig_add_module(core python swig/core.i)
  set_property(TARGET ${SWIG_MODULE_core_REAL_NAME} PROPERTY
    CXX_STANDARD 11)
  set_property(TARGET ${SWIG_MODULE_core_REAL_NAME} PROPERTY
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
