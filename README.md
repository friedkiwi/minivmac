# Mini vMac

This is a fork of Mini vMac (https://www.gryphel.com/c/minivmac/)

## Building

Build status: ![build status](https://travis-ci.com/friedkiwi/minivmac.svg?branch=master)

To build this repository:

1. create a `build` subdirectory
2. run `cmake ..` in this directory
3. `make` should give you a minivmac_x11 and/or a minivmac_sdl binary on Linux

To build for Windows, use MinGW-W64 with the included toolchain files:

1. create a `build` subdirectory
2. run `cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain_mingw32.txt ..` or `cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain_mingw64.txt ..` in this directory.

A `minivmac.exe` file for the specified architecture should have appeared.
