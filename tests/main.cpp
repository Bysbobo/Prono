#include <QtTest>
#include "tests/matchtest.h"

int main(int argc, char *argv[])
{
    // Create the application
    QApplication a(argc, argv);

    // Create the main window and show it
    MatchTest matchTest;

    return QTest::qExec(&matchTest, argc, argv);
}
