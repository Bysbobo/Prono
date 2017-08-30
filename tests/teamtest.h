#ifndef TEAMTEST_H
#define TEAMTEST_H

#include <QtTest>
#include "team.h"

class TeamTest : public QObject
{
    Q_OBJECT

private slots:
    void addingMatches();
    void inferiorOperator();
};

#endif // TEAMTEST_H
