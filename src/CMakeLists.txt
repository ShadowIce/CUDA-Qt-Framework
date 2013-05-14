# QT settings
# see http://www.cmake.org/cmake/help/cmake-2-8-docs.html#module:FindQt4
SET(QT_USE_QTOPENGL 1)
SET(QT_USE_QTXML 1)

IF(WIN32)
	SET (QT_USE_MOTIF 0)
ENDIF()

INCLUDE(${QT_USE_FILE})

# List of all the C++ source code files
SET(cuda_qt_framework_SRCS_CXX
	gui/MainWindow.cpp
	gui/OGLWidget.cpp
	
	main.cpp
)

# List of all Qt header files
SET(cuda_qt_framework_MOC_HDRS
	gui/MainWindow.h
	gui/OGLWidget.h
)

# List of Qt .ui files
SET(cuda_qt_framework_UIS
	gui/MainWindow.ui
)

# List of CUDA files
SET(cuda_qt_framework_CUDA_SRCS
	cuda/HelloCuda.cu
	cuda/MainCuda.cu
)

# .ui files
QT4_WRAP_UI(cuda_qt_framework_SRCS_CXX ${cuda_qt_framework_UIS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} gui)

# for moc
QT4_WRAP_CPP(cuda_qt_framework_SRCS_CXX ${cuda_qt_framework_MOC_HDRS})

IF(UNIX)
  CUDA_ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${cuda_qt_framework_CUDA_SRCS} ${cuda_qt_framework_SRCS_CXX})
ELSEIF(APPLE)
  CUDA_ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} MACOSX_BUNDLE ${cuda_qt_framework_CUDA_SRCS} ${cuda_qt_framework_SRCS_CXX})
ELSEIF(WIN32)
  CUDA_ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} WIN32 ${cuda_qt_framework_CUDA_SRCS} ${cuda_qt_framework_SRCS_CXX})
ENDIF()

TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

INSTALL(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
