include_directories(${CMAKE_SOURCE_DIR}/src)

cmake_minimum_required(VERSION 3.14) # 设置 CMake 最小版本
project(gray-scott-sim-main) # 设置你的项目名称

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 启用测试
enable_testing()

# 包含 FetchContent 模块
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
)

# 为了避免在每次构建时都下载，我们可以检查谷歌测试是否已经被下载了。
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    # 添加 googletest 直接到我们的构建。这将定义目标 gtest 和 gtest_main。
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# 添加你的源文件
add_executable(GrayScottSim src/gs.cpp
        src/gs_main.cpp
)

# 如果有其他.cpp文件，可以在这里继续添加
# add_executable(YourExecutableName gs.cpp another_file.cpp)

# 添加测试可执行文件
add_executable(GrayScottTests
        tests/test.cpp
        src/gs.cpp
)

# 链接 Google Test 到测试可执行文件
target_link_libraries(GrayScottTests gtest_main)

# 包含 Google Test 的测试宏
include(GoogleTest)

# 声明测试
gtest_discover_tests(GrayScottTests)
