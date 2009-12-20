# QT settings
# see http://www.cmake.org/cmake/help/cmake-2-8-docs.html#module:FindQt4
SET(QT_USE_QTOPENGL 1)
SET(QT_USE_QTXML 1)

IF(WIN32)
	SET (QT_USE_MOTIF 0)
ENDIF()

INCLUDE(${QT_USE_FILE})

SET(cuda_qt_framework_SRCS_CXX
	gui/MainWindow.cpp
	
	main.cpp
)

SET(cuda_qt_framework_MOC_HDRS
	gui/MainWindow.h
)

SET(cuda_qt_framework_UIS
	gui/MainWindow.ui
)

# .ui files
QT4_WRAP_UI(cuda_qt_framework_SRCS_CXX ${cuda-qt-framework_UIS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# for moc
QT4_WRAP_CPP(cuda_qt_framework_SRCS_CXX ${cuda_qt_framework_MOC_HDRS})

IF(UNIX)
  ADD_EXECUTABLE(CUDA-Qt-Framework ${cuda_qt_framework_SRCS_CXX})
ELSEIF(APPLE)
  ADD_EXECUTABLE(CUDA-Qt-Framework MACOSX_BUNDLE ${cuda_qt_framework_SRCS_CXX})
ELSEIF(WIN32)
  ADD_EXECUTABLE(CUDA-Qt-Framework WIN32 ${cuda_qt_framework_SRCS_CXX})
ENDIF()

target_link_libraries(CUDA-Qt-Framework ${QT_LIBRARIES})
