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

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <bertha/core.hpp>

TEST_CASE("Device construction (negative length) -- x1, x2", "[device]") {
    REQUIRE_THROWS(bertha::device(1.0, 0.5));
}

TEST_CASE("Device construction  (negative length) -- length", "[device]") {
    REQUIRE_THROWS(bertha::device(-0.1));
}

TEST_CASE("Device destruction -- x1, x2", "[device]") {
    REQUIRE_NOTHROW(bertha::device(100.0, 200.0));
}

TEST_CASE("Device destruction -- length", "[device]") {
    REQUIRE_NOTHROW(bertha::device(500.0));
}

TEST_CASE("Device length calculation -- x1, x2", "[device]") {
    bertha::device d(10.11, 20.33);
    REQUIRE(d.get_length() == Approx(10.22));
}

TEST_CASE("Device length calculation -- length", "[device]") {
    double length = 20;
    bertha::device d(length);
    REQUIRE(d.get_length() == Approx(length));
}
