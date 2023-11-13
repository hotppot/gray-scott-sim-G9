cmake_minimum_required(VERSION 3.26)


set(This gs_test)

set (Sources
    gs_test.cpp
)

add_executable(${This} ${Sources})

# 链接gtest库和我们的gs库
target_link_libraries(${This} PUBLIC
    gtest_main
    gs
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

