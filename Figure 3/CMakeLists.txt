cmake_minimum_required(VERSION 3.18)
project("Figure 3" CXX)

find_package(Python3 COMPONENTS Development REQUIRED)
find_package(SWIG 4.0 REQUIRED)
include(UseSWIG)

set_property(SOURCE Agent.i PROPERTY CPLUSPLUS ON)
swig_add_library(Figure-3
  LANGUAGE python
  OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}
  OUTFILE_DIR ${CMAKE_CURRENT_BINARY_DIR}
  SOURCES Agent.i Agent.cpp
)
set_target_properties(Figure-3 PROPERTIES OUTPUT_NAME CAgent
    SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE SWIG_COMPILE_OPTIONS -py3
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_features(Figure-3 PRIVATE cxx_std_20)
target_compile_options(Figure-3 PRIVATE -Wall -Wpedantic)
target_include_directories(Figure-3 PRIVATE ${Python3_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})
