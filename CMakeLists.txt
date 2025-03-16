cmake_minimum_required(VERSION 3.10)
project(Algos)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

# Fetch raylib from GitHub
include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master  # or specify a specific commit/tag
)

# Fetch GoogleTest from GitHub
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# Make available the libraries
FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/main.cxx
)

set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/src/test/tests_main.cxx
)

# Build Game executable
add_executable(game ${SOURCES})
target_link_libraries(game raylib)

# Enable testing
enable_testing()

# Build tests executable
add_executable(tests ${TEST_SOURCES})
target_link_libraries(
    tests
    GTest::gtest_main
    raylib
    -lstdc++  # Link against the C++ standard library
    -lgcc_s   # Link against the GCC runtime
    -lpthread # Link against the pthread library (if using multithreading)
)
