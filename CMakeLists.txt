PROJECT(CUDA-Qt-Framework)

# Tested only with version 2.8.
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)

# requires Qt4 and CUDA
# CUDA might not be part of CMake 2.6, either install 2.8 or install the CUDA modules yourself.
FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(CUDA REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)

# Necessary on Ubuntu 11.10 if we specify the compiler with 
# "CXX=g++-4.4 CC=gcc-4.4 cmake" 
SET(CUDA_NVCC_FLAGS "-ccbin;${CMAKE_CXX_COMPILER}")

install(FILES README.md LICENSE DESTINATION share/doc/${CMAKE_PROJECT_NAME}/)

# This is where the source code is.
SUBDIRS(src)
 
