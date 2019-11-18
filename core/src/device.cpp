/*
 * bertha: Project skeleton for scientific software (C++ w/ Python interface).
 *
 * Copyright (c) 2019, Computational Photonics Group, Technical University of
 * Munich.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include <bertha/device.hpp>

namespace bertha {

device::device(double x_start, double x_end)
  : m_x_start(x_start), m_x_end(x_end)
{
}

device::device(double length) : m_x_start(0.0), m_x_end(length)
{
}

device::~device()
{
}

double
device::get_length() const
{
    return (m_x_end - m_x_start);
}
}
