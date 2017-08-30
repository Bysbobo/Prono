#ifndef MATCHTEST_H
#define MATCHTEST_H

#include <QtTest>
#include "match.h"

class MatchTest : public QObject
{
    Q_OBJECT

private slots:
    void nonPlayedUnitializedMatch();
    void nonPlayedMatch();
    void forfeit();
    void playedMatchOnForfeit();
    void winnerOnForfeit();
    void nonForfeitOnMatchPlayed();
    void matchPlayed();
    void winnerOnMatchPlayed();
    void draw();
};

#endif // MATCHTEST_H
