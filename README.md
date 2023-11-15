# gray-scott-sim-G9

## Project introduction:
This project allows us group members to clone the template repository. Furthermore, there are mainly 3 testing frameworks we should choose. 
Then we should add a README file with detailed instructions for building the application locally, create a build system for the software, and implement continuous integration (CI) for the selected repository.


## Build System
1、why we choose cmake to build system？
CMake
Widely used: CMake is the build system most widely integrated with Google Test.
Cross-platform: CMake can be used on multiple platforms including Windows, Linux and macOS.
Feature-rich: It supports complex project structures including conditional compilation, different compilation options, discovery and linking dependencies.
Integrated CI: CMake is compatible with most CI/CD systems and is easy to integrate into the continuous integration process.

compared with Make、Bazel、Ninja、Meson, we learned it in class, all group members are familiar with it.


We configure the system build in the CMakeLists.txt.

There are the things we did in it:
1. Sets the minimum version requirement for CMake, which is 3.14. 
2. Project name defined.
3. Sets the compilation standard for C++. 
4. Test functionality enabled. 
5. The FetchContent module is used to declare external dependencies (in this case Google Test). 
6. Check and possibly download Google Test. 
7. The source files are added, creating an executable called GrayScottSim. 
8. Test files are added, creating a test executable named GrayScottTests. 
9. Linked the Google Test library to the test executable. 
10. Contains macros provided by Google Test to discover and register tests.


https://cmake.org/








## CI





## Required tools and skills
Git Bash, Clion, Cmake, github, continuous integration (CI), google-test, C++

## Details about 3 tests

### test1: Check that the type of the model parameters (F , k) matches that of the element typeof the u and v vectors.
Illustration about test1:



### test2: Check that the variables u and v are the same size.
Illustration about test2:



### test3: Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
Illustration about test3:

Test3 is simply a special value test. Let the two parameters u and v be 0 and check whether the output result meets the mathematical expected result. This kind of test is highly subjective and can often detect the system flaws and therefore it is necessary.

Testing frameworks:

https://github.com/google/googletest

Method introduction:

There are two methods EXPECT_DOUBLE_EQ and EXPECT_NEAR to complete the test. The first one is used to directly compare whether the expected output value and the actual output value are the same, and the second one is used to determine whether the actual output value and the estimated value are within a certain error.

## Contributors
Xiaoyuan Xu, Cai Gao, Chuang Li, Chu Duan, Yang Wei
