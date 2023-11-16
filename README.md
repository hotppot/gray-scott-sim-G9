# gray-scott-sim-G9

## Project introduction:
`gray-scott-sim-G9` is a C++ implementation of the Gray-Scott reaction-diffusion equations, utilizing CMake for streamlined builds. We maintain quality with Google Test, ensuring parameter types, variable sizes, and baseline behavior are correct. Our CI process, supported by GCC, upholds code integrity across platforms.

## Required tools and skills
Git Bash, Clion, Cmake, github, continuous integration (CI), google-test, C++

## Project Introduction Schedule
![Project](https://github.com/hotppot/gray-scott-sim-G9/assets/149593797/7a2bf3e8-e331-4214-baa4-cca7f102aae2)


## Group Collaboration Schedule
![img.png](img-group-collaboration-schedule.png)

## Build System
`gray-scott-sim-G9` is built using CMake, which is detailed in the `CMakeLists.txt` file. We chose CMake for its wide usage, especially with Google Test, and its cross-platform support is super convenient for developers. Additionally, its easy integration with CI/CD systems streamlines our build and testing processes.

### Prerequisites
Before building `gray-scott-sim-G9`, ensure you have the following tools installed on your system:
   - **CMake**: `gray-scott-sim-G9` uses CMake to manage the build process. The minimum required version of CMake for this project is 3.14, to check if CMake is installed and find its version, you can run `cmake --version` in your terminal. If you haven't installed CMake, please visit https://cmake.org/download/ to install it. The installation process may vary depending on your computer's operating system.
   - **GCC**: GCC (GNU Compiler Collection) is required to compile the source code of `gray-scott-sim-G9`. To ensure compatibility with our Continuous Integration (CI) setup, we recommend using GCC as the compiler for building the project. Our CI pipelines are configured with GCC, which ensures that the code compiles correctly and passes all tests under this compiler. It is likely that GCC is already installed on your system if you are using a Unix-like operating system. On Windows, you may want to install MinGW-w64 or Cygwin to get GCC. To check if GCC is installed and find its version, you can run `gcc --version` in your terminal. For installation instructions, refer to the [official GCC documentation](https://gcc.gnu.org/install/) or use your operating system's package manager.

* It's important to note that you don't need to download and install Google Test yourself, even though we have linked the Google Test library to the test executable in our `CMakeLists.txt` file. This is because in this file, we have configured the online download and installation of Google Test, and the version has already been determined, so you don't need to worry about it.
### Building the Project with CMake
To compile the project, create a build directory and run CMake from within it:

```bash
mkdir build
cd build
cmake .. -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
cmake --build .
```

This will configure the project to use GCC for C and C++ compilation and then build the project.

### 2 mian advantages when building system
```bash
cmake_minimum_required(VERSION 3.14)
#Set C++ standard
set(CMAKE_CXX_STANDARD 11)
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
```


## Details about 3 tests


The three test cases in this project were written using the GoogleTest framework to verify the stability of the Gray-Scott model algorithm implementation.

GoogleTest frameworks:

https://github.com/google/googletest

### test1: Check that the type of the model parameters (F , k) matches that of the element typeof the u and v vectors.
Illustration about test1:

This test verifies that the data types of the model parameters F and k are double, which is a basic check to ensure data type consistency.In addition, it checks that the types of F and k are the same as the types of the elements in the u and v vectors. This step ensures that the parameters are compatible with the data types used in the model, which is essential to avoid type conversion errors and maintain the precision of numerical computations.

Method introduction:

The ‘ASSERT_TRUE’ method is mainly used in this test; this method is used to verify whether the condition is true or not. If the condition is true, the test continues to execute; if the condition is false, it causes the test to fail and immediately stops the execution of the current test case. In this test this method, is used to verify that the types of F and k are the same as double.

### test2: Check that the variables u and v are the same size.
Illustration about test2:

This test ensures that the u and v vectors have the same dimensions. Since these two vectors represent the two chemicals in the model, they must be simulated on the same spatial grid, so they must have the same dimensions. The test first checks that the outer dimensions (i.e., the number of rows) are equal, and then for each row it checks that its inner dimensions (i.e., the number of columns) are equal.

Method introduction:

The ‘EXPECT_EQ’ method is primarily used in this test to compare whether two values are equal. If the values are equal, the test continues to execute; if the values are not equal, the ‘EXPECT_EQ’ method logs a failure but does not stop the execution of the current test case. This test utilises this method for comparing the dimensions of the u and v vectors, which is a more lenient test assertion because even if the dimensions do not match, the test continues execution to the end, logging all mismatches. This method is suitable for those cases where even a failure will not affect the execution of the rest of the test.

### test3: Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
Illustration about test3:

Test3 is simply a special value test. Let the two parameters u and v be 0 and check whether the output result meets the mathematical expected result. This kind of test is highly subjective and can often detect the system flaws and therefore it is necessary.

Method introduction:

There are two methods EXPECT_DOUBLE_EQ and EXPECT_NEAR to complete the test. The first one is used to directly compare whether the expected output value and the actual output value are the same, and the second one is used to determine whether the actual output value and the estimated value are within a certain error.



## CI
CI, is a methodology that involves regularly integrating code changes to ensure a fast and reliable build and test process.
It consists of three components：
1. Trigger
   When there is a push or pull request in 'main' branch, CI will automatically checking out the code.
2. Build
   We use CMake to construct and build the program in subdictionary 'build'. We've chosen the 'Release' build type to optimize our code for production environments. This ensures it performs efficiently when deployed.
3. CTEST




## Contributors
Xiaoyuan Xu, Cai Gao, Chuang Li, Chu Duan, Yang Wei



## Bibliography

CMake. (n.d.). Retrieved from [https://cmake.org/download/](https://cmake.org/download/)

GNU Compiler Collection (GCC). (n.d.). Retrieved from [https://gcc.gnu.org/install/](https://gcc.gnu.org/install/)

GoogleTest. (n.d.). Retrieved from [https://github.com/google/googletest](https://github.com/google/googletest)
