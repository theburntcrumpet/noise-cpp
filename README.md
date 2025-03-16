# Raylib C++ Template

A simple jumping off point for raylib on linux using CMake.

Just install raylib and Google Test on your distro.

TO DO:
- Tidy Up CMakeLists.txt
- Add Github actions
- Docker as build environment?

## Cross-compilation

This repo has been tested on fedora. Install `mingw64-gcc mingw64-g++`.

You can then use the following commands to build:

```bash
mkdir build-windows
cd build-windows
cmake -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake ..
make
```
