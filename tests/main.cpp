#include <QtTest>
#include "tests/matchtest.h"
#include "tests/teamtest.h"

int main(int argc, char *argv[])
{
    // Create the application
    QApplication a(argc, argv);

    // Create the match test object
    MatchTest matchTest;

    // Create the team test object
    TeamTest teamTest;

    return QTest::qExec(&matchTest, argc, argv) |
            QTest::qExec(&teamTest, argc, argv);
}
