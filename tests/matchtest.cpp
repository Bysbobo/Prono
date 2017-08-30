//#include "match.h"
//#include <QtTest>

//class MatchTest : public QObject
//{
//    Q_OBJECT

//private slots:
//    void nonPlayedMatch();
//};

//void MatchTest::nonPlayedMatch()
//{
//    Match m(QString("Home"), QString("Away"));
//    QCOMPARE(m.isGamePlayed(), false);
//}

//QTEST_MAIN(MatchTest)
//#include "matchtest.moc"
#include "tests/matchtest.h"

void MatchTest::nonPlayedMatch()
{
    Match m(QString("Home"), QString("Away"));
    QCOMPARE(m.isGamePlayed(), false);
}
