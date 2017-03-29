# CMake minimal version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Project name
PROJECT(Prono)

# The makefile should be verbose by default
SET(CMAKE_VERBOSE_MAKEFILE TRUE)

# Enable unit tests
ENABLE_TESTING()

ADD_DEFINITIONS(-DROOTTOBDD=\"${Prono_SOURCE_DIR}/ressources/Infos.txt\")
# Add the subdirectories
SUBDIRS(includes src)
