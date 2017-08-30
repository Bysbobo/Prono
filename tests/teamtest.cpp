#include "teamtest.h"

void TeamTest::addingMatches()
{
    Match uninitialized;
    Team t(QString("full"), QString("short"));
    t.addMatch(uninitialized);
    QCOMPARE(t.getMatches().size(), 1);
}

void TeamTest::inferiorOperator()
{
    Team a(QString("a"), QString("ashort"));
    Team b(QString("b"), QString("bshort"));
    QCOMPARE(a < b, true);
}
