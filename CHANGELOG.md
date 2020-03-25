# Changelog

All notable changes to this project will be documented in this file.

The format is based on
[Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.2.0] - xxxx-xx-xx

## [1.1.0] - 2020-03-12

This release introduces support for GitHub and revises the existing code
base.

### Added
 - Support for GitHub (configuration for Travis CI, issue and PR templates)
 - Support for CMake target exports
 - Code of conduct

### Changed
 - Revised CMake build structure (SWIG support, cleanup)

## [1.0.0] - 2019-11-30

This is the first stable release that incorporates basic functionality.

### Added
 - Basic C++ library with SWIG interface file
 - CMake build system that builds and installs the library and the Python
   interface
 - Automatic documentation generation using Doxygen
 - Automatic formatting of C++ code
 - Basic support for continuous integration (CI)
