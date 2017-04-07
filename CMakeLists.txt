# CMake minimal version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

# Project name
PROJECT(Prono)

# Run MOC when necessary
SET(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, always look for includes there
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find QT5 Widgets module
FIND_PACKAGE(Qt5Widgets REQUIRED)

# Include the Qt5 Widgets files
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDES})

# The makefile should be verbose by default
SET(CMAKE_VERBOSE_MAKEFILE TRUE)

# Enable unit tests
ENABLE_TESTING()

# Add the definitions for the resources file
ADD_DEFINITIONS(-DROOTTOBDD=\"${Prono_SOURCE_DIR}/ressources/Infos.txt\")

# Add the definitions for QT5 Widgets module
ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS})

# Add the compilation flags for QT5 Widgets module so the build succeed
SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Add the subdirectories
SUBDIRS(includes src)
