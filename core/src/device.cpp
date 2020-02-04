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

#include <stdexcept>

#include <bertha/core/device.hpp>

namespace bertha {

device::device(double x_start, double x_end)
  : m_x_start(x_start), m_x_end(x_end)
{
    if (x_start > x_end) {
        throw std::invalid_argument("Device has negative length!");
    }
}

device::device(double length) : device::device(0.0, length) {}

device::~device() {}

double
device::get_length() const
{
    return (m_x_end - m_x_start);
}
}
