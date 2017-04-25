# CMake minimal version required
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Project name
PROJECT(Prono)

# The makefile should be verbose by default
SET(CMAKE_VERBOSE_MAKEFILE TRUE)

# Enable unit tests
ENABLE_TESTING()

ADD_DEFINITIONS(-DROOTTOBDD1=\"${Prono_SOURCE_DIR}/ressources/Infos.txt\")
ADD_DEFINITIONS(-DROOTTOBDD2=\"${Prono_SOURCE_DIR}/ressources/Matchs.txt\")
# Add the subdirectories
SUBDIRS(includes src)
