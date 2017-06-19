#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QVector>
#include "match.h"

class Team
{
public:
    Team(const QString &fullName, const QString &shortName);

    inline QString getFullName() const { return aFullName; }
    inline QString getShortName() const { return aShortName; }

    inline QVector<Match> getMatches() const { return aMatches; }
    inline QVector<Match>& getMatches() { return aMatches; }

private:
    QString aFullName;
    QString aShortName;

    QVector<Match> aMatches;
};

#endif // TEAM_H
