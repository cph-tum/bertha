%module pybertha
%{
#include <bertha/device.hpp>
%}

%include "stl.i"
%include "std_except.i"

%exception %{
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  } catch(...) {
  }
%}

%include "../include/bertha/device.hpp"
