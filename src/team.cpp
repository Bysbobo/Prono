#include "team.h"

Team::Team(const QString &fullName, const QString &shortName):
    aFullName(fullName),
    aShortName(shortName)
{
}

QString Team::getListOfMatchesForTree() const
{
    QString ret("");
    if (aMatches.size() > 0)
    {
        if (aMatches.at(0).isGamePlayed())
            ret.append(aMatches.at(0).getHomeTeam()).append(QString("   ")).append(QString::number(aMatches.at(0).getHomeTeamScore()))
                    .append(QString(" - ")).append(QString::number(aMatches.at(0).getAwayTeamScore())).append(QString("   ")).append(aMatches.at(0).getAwayTeam());
        else
            ret.append(aMatches.at(0).getHomeTeam()).append(QString("     -     ")).append(aMatches.at(0).getAwayTeam());
    }
    const int size = aMatches.size();
    for (int i = 1; i < size; ++i)
    {
        if (aMatches.at(i).isGamePlayed())
            ret.append(QString("\n")).append(aMatches.at(i).getHomeTeam()).append(QString("   ")).append(QString::number(aMatches.at(i).getHomeTeamScore()))
                    .append(QString(" - ")).append(QString::number(aMatches.at(i).getAwayTeamScore())).append(QString("   ")).append(aMatches.at(i).getAwayTeam());
        else
            ret.append(QString("\n")).append(aMatches.at(i).getHomeTeam()).append(QString("     -     ")).append(aMatches.at(i).getAwayTeam());
    }
    return ret;
}
