#include "match.h"

Match::Match(const QString &homeTeam, const QString &awayTeam) :
    aPlayed(false),
    aForfeit(false),
    aHomeTeam(homeTeam),
    aAwayTeam(awayTeam)
{
}

Match::Match(const QString& season, uint8_t day, const QString &homeTeam, const QString &awayTeam, bool forfeit, const QString &teamForfeited) :
    aID(""),
    aSeason(season),
    aPlayed(true),
    aForfeit(forfeit),
    aDay(day),
    aHomeTeam(homeTeam),
    aAwayTeam(awayTeam),
    aForfeitTeam(teamForfeited)
{
}

Match::Match(const QString& season, uint8_t day, const QString &homeTeam, const QString &awayTeam, unsigned int homeScore, unsigned int awayScore) :
    aID(""),
    aSeason(season),
    aPlayed(true),
    aForfeit(false),
    aDay(day),
    aHomeTeam(homeTeam),
    aAwayTeam(awayTeam),
    aHomeScore(homeScore),
    aAwayScore(awayScore)
{
    aID.append(season).append(QString::number(day)).append(homeTeam).append(awayTeam);
}

bool Match::doesHomeTeamWin()
{
    Q_ASSERT(aPlayed);
    if (aForfeit)
        return aForfeitTeam != aHomeTeam;
    return aHomeScore > aAwayScore;
}

bool Match::doesAwayTeamWin()
{
    Q_ASSERT(aPlayed);
    if (aForfeit)
        return aForfeitTeam != aAwayTeam;
    return aHomeScore < aAwayScore;
}

bool Match::isADraw()
{
    Q_ASSERT(aPlayed);
    return !aForfeit && aHomeScore == aAwayScore;
}
