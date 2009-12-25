PROJECT(CUDA-Qt-Framework)

# Tested only with version 2.8.
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)

# requires Qt4 and CUDA
# CUDA might not be part of CMake 2.6, either install 2.8 or install the CUDA modules yourself.
FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(CUDA REQUIRED)

install(FILES README.md LICENSE DESTINATION share/doc/${CMAKE_PROJECT_NAME}/)

# This is where the source code is.
SUBDIRS(src)
 