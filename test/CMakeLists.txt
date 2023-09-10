cmake_minimum_required(VERSION 3.10)

project("gtest")

enable_testing()
add_subdirectory(googletest)
add_executable(test_app main.cpp "../src/player.cpp")

target_link_libraries(test_app gtest_main gmock_main)