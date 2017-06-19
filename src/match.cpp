#include "match.h"

Match::Match(const QString &homeTeam, const QString &awayTeam) :
    aPlayed(false),
    aHomeTeam(homeTeam),
    aAwayTeam(awayTeam)
{
}

Match::Match(const QString &homeTeam, const QString &awayTeam, unsigned int homeScore, unsigned int awayScore) :
    aPlayed(true),
    aHomeTeam(homeTeam),
    aAwayTeam(awayTeam),
    aHomeScore(homeScore),
    aAwayScore(awayScore)
{
}

bool Match::doesHomeTeamWin()
{
    Q_ASSERT(aPlayed);
    return aHomeScore > aAwayScore;
}

bool Match::doesAwayTeamWin()
{
    Q_ASSERT(aPlayed);
    return aHomeScore < aAwayScore;
}

bool Match::isADraw()
{
    Q_ASSERT(aPlayed);
    return aHomeScore == aAwayScore;
}
