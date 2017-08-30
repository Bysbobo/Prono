#ifndef MATCHTEST_H
#define MATCHTEST_H

#include <QtTest>
#include "match.h"

class MatchTest : public QObject
{
    Q_OBJECT

private slots:
    void nonPlayedMatch();
};

#endif // MATCHTEST_H
