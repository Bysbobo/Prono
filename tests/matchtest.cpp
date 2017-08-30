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

void MatchTest::nonPlayedUnitializedMatch()
{
    Match uninitialized;
    QCOMPARE(uninitialized.isGamePlayed(), false);
}

void MatchTest::forfeit()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), true, QString("Home"));
    QCOMPARE(m.isGameForfeited(), true);
}

void MatchTest::playedMatchOnForfeit()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), true, QString("Home"));
    QCOMPARE(m.isGamePlayed(), true);
}

void MatchTest::winnerOnForfeit()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), true, QString("Home"));
    QCOMPARE(m.doesHomeTeamWin(), false);
    QCOMPARE(m.doesAwayTeamWin(), true);
    QCOMPARE(m.isADraw(), false);
}

void MatchTest::nonForfeitOnMatchPlayed()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), 2, 1);
    QCOMPARE(m.isGameForfeited(), false);
}

void MatchTest::matchPlayed()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), 2, 1);
    QCOMPARE(m.isGamePlayed(), true);
}

void MatchTest::winnerOnMatchPlayed()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), 2, 1);
    QCOMPARE(m.doesHomeTeamWin(), true);
    QCOMPARE(m.doesAwayTeamWin(), false);
    QCOMPARE(m.isADraw(), false);
}

void MatchTest::draw()
{
    Match m(QString("2017"), 16, QString("Home"), QString("Away"), 2, 2);
    QCOMPARE(m.doesHomeTeamWin(), false);
    QCOMPARE(m.doesAwayTeamWin(), false);
    QCOMPARE(m.isADraw(), true);
}
