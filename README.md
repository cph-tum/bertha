# bertha

Project skeleton for scientific software (C++ with Python interface).

This project skeleton aims to provide a clean and solid basis for small to
medium scientific software projects. It is assumed that the software is
written in C++ and built as dynamic library in order to provide high
performance. An interface for Python is automatically generated. The project
skeleton includes several features that facilitate good software engineering
practices:

 - Usage of a version control system (VCS) and appropriate work flow
 - Usage of project management tool including issue tracking
 - Automated build system using CMake
 - Automated packaging and deployment to a public repository using conda
 - Automated testing in continuous integration (CI)
 - Automatic documentation generation using Doxygen
 - Automatic code formatting checks using clang-format

<!-- GitHub badges -->
[![Build Status](https://travis-ci.org/cph-tum/bertha.svg?branch=master)](https://travis-ci.org/cph-tum/bertha)
[![Documentation](https://img.shields.io/badge/Documentation-GitHub%20Pages-informational)](https://cph-tum.github.io/bertha)
[![First Steps](https://img.shields.io/badge/First%20steps-Tutorial-important)](https://cph-tum.github.io/bertha/md_docs_TUTORIAL.html)

<!-- GitLab badges -->
[![Pipeline](https://gitlab.com/cph-tum/bertha/badges/master/pipeline.svg)](https://gitlab.com/cph-tum/bertha/pipelines/master/latest)
[![Coverage](https://gitlab.com/cph-tum/bertha/badges/master/coverage.svg)](https://gitlab.com/cph-tum/bertha/-/jobs/artifacts/master/file/build/coverage.html?job=coverage)
[![Documentation](https://img.shields.io/badge/Documentation-GitLab%20Pages-informational)](https://cph-tum.gitlab.io/bertha)
[![First Steps](https://img.shields.io/badge/First%20steps-Tutorial-important)](https://cph-tum.gitlab.io/bertha/md_docs_TUTORIAL.html)

## Install via conda

If you have a conda distribution installed, you can install bertha using

    $ conda install -c conda-forge bertha

from the `conda-forge` channel.

## Get the code

Make sure to clone using

    git clone --recurse-submodules [...]

in order to clone the third-party libraries recursively. Alternatively, issue

    git submodule update --init --recursive

in the repository if it already exists.

## Build instructions

The project is built using the CMake build system, which can be used via GUI
or command line. For brevity's sake, only the command line approach is
sketched below.

### Linux

The typical commands under Linux are

    $ cd bertha
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make -j 4
    $ make install

By default, the build type is set to release with debug information, which
enables debugging but features the optimization necessary for reasonable
performance. Adjust the -j command line parameter of the make command in
order to speed up the compilation.

The Doxygen documentation can be build with

    $ make doc

and the unit tests can be executed (assuming that CMake has been run with
`-DWITH_TESTS`) using

    $ make test

### Windows with MinGW (recommended)

Using the MinGW environment, the build under Windows is quite similar:

    $ cd bertha
    $ mkdir build
    $ cd build
    $ cmake .. -G "Unix Makefiles"
    $ make -j 4
    $ make install

The only difference is that the generator parameter must be explicitely set
to "Unix Makefiles".

### Windows with Visual Studio (experimental)

Here, you may want to specify a certain version of Visual Studio using

    $ cd bertha
    $ mkdir build
    $ cd build
    $ cmake .. -G "Visual Studio 11 2012"

After successful completion there is a Visual Studio `.sln` file in the build
directory. The build type can be set directly in Visual Studio.

## Dependencies

The following software packages are required to build the project:

 - CMake >= 3.6
 - C++ compiler (any recent version supporting C++11)
 - Python >= 2.7
 - swig >= 2.0.12

Additionally, the following components are required for unit tests, format
checks, documentaton generation, etc.:

 - Catch2 (any recent version)
 - clang-format (any recent version)
 - Doxygen (any recent version)
 - gcovr (any recent version)

## Contributing to bertha

Feel free to use the code and do not hesitate to create an issue on the
project web page. Any contributions are welcome.

If you found the code helpful and used it in your research, you can cite
the following paper:

M. Riesch and C. Jirauschek, "bertha: Project skeleton for scientific
software.", *In preparation*, (2019).

If desired, you can cite the project web page directly:

M. Riesch and C. Jirauschek, "bertha: Project skeleton for scientific
software.",
[https://gitlab.com/cph-tum/bertha](https://gitlab.com/cph-tum/bertha)
[Online], (2019).
