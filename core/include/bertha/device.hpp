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

#ifndef BERTHA_DEVICE_HPP
#define BERTHA_DEVICE_HPP

namespace bertha {

/**
 * Represents a certain device or setup.
 */
class device
{
private:
    /**
     * Device start x coordinate.
     */
    double m_x_start;

    /**
     * Device end x coordinate.
     */
    double m_x_end;

public:
    /**
     * Constructs device using start and end coordinates.
     *
     * \param [in] x_start Device start x coordinate.
     * \param [in] x_end   Device end x coordinate.
     */
    device(double x_start, double x_end);

    /**
     * Constructs device with given length assuming start in origin.
     *
     * \param [in] length Device length.
     */
    explicit device(double length);

    /**
     * Deconstructs device.
     */
    ~device();

    /**
     * Gets device length.
     */
    double get_length() const;
};
}

#endif
