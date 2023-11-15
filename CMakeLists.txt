include_directories(${CMAKE_SOURCE_DIR}/src)

cmake_minimum_required(VERSION 3.14)
project(gray-scott-sim-main) # set Project Name

#Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# enable testing
enable_testing()

# Contains FetchContent module
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
)

# To avoid downloading it on every build, we can check if Google Test has already been downloaded.
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    #Add googletest directly to our build. This defines the targets gtest and gtest_main.
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# Add your source files
add_executable(GrayScottSim src/gs.cpp
        src/gs_main.cpp
)

# If there are other .cpp files, you can continue to add them here
# add_executable(YourExecutableName gs.cpp another_file.cpp)

# Add test executable
add_executable(GrayScottTests
        tests/test.cpp
        src/gs.cpp
)

# Link Google Test to the test executable
target_link_libraries(GrayScottTests gtest_main)

# Contains test macros for Google Test
include(GoogleTest)

# declare test
gtest_discover_tests(GrayScottTests)
