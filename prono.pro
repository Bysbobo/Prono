QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Prono
TEMPLATE = app

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += include

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/widgets/about.cpp \
    src/centralwidget.cpp \
    src/model/treemodel.cpp \
    src/league.cpp \
    src/match.cpp \
    src/team.cpp \
    src/widgets/addleaguewidget.cpp \
    src/widgets/addteamwidget.cpp \
    src/widgets/informationwidget.cpp

HEADERS  += include/mainwindow.h \
    include/widgets/about.h \
    include/centralwidget.h \
    include/model/treeitem.h \
    include/model/treemodel.h \
    include/league.h \
    include/match.h \
    include/team.h \
    include/widgets/addleaguewidget.h \
    include/widgets/addteamwidget.h \
    include/widgets/informationwidget.h

DISTFILES += \
    resources/database/Infos.txt \
    resources/database/Matches.txt

RESOURCES += \
    resources/ressources.qrc

test {
    message(Test build)
    QT += testlib
    TARGET = UnitTests

    SOURCES -= src/main.cpp

    HEADERS += tests/matchtest.h \
               tests/teamtest.h

    SOURCES += tests/matchtest.cpp \
               tests/main.cpp \
               tests/teamtest.cpp
} else {
    message(Normal build)
}
