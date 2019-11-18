/*
 * bertha: Project skeleton for scientific software (C++ w/ Python interface).
 *
 * Copyright 2019 Michael Riesch <michael.riesch@tum.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

%module core
%{
#include <bertha/core.hpp>
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

%include "../include/bertha/core/device.hpp"
