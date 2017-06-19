QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = perso
TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += include


SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/about.cpp \
    src/centralwidget.cpp \
    src/treemodel.cpp \
    src/league.cpp \
    src/match.cpp \
    src/team.cpp

HEADERS  += include/mainwindow.h \
    include/about.h \
    include/centralwidget.h \
    include/treeitem.h \
    include/treemodel.h \
    include/league.h \
    include/match.h \
    include/team.h

DISTFILES += \
    resources/database/Infos.txt \
    resources/database/Matches.txt

RESOURCES += \
    resources/ressources.qrc
