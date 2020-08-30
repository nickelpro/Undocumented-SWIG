cmake_minimum_required(VERSION 3.18)
project("Figure 1" CXX)

find_package(Python3 COMPONENTS Development REQUIRED)

add_library(CAgent MODULE Agent_wrap.cxx)
set_target_properties(CAgent PROPERTIES PREFIX "_")
target_include_directories(CAgent PRIVATE ${Python3_INCLUDE_DIRS})
