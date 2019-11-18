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

#ifndef BERTHA_CORE_DEVICE_HPP
#define BERTHA_CORE_DEVICE_HPP

namespace bertha {

/**
 * Represents a certain device or setup.
 * \ingroup CORE
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
