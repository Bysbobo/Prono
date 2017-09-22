#include "statistics.h"

Statistics::Statistics(const QVector<Team> &team, const QVector<Match> &matches):
    aTeam(team),
    aMatches(matches)
{
    // Initialize the statistics vectors
    const int size = aTeam.size();
    for (int i = 0; i < size; i++)
    {
        aRankings.push_back(0);
        aPoints.push_back(0);
        aGoalAverages.push_back(0);
        aScoredGoals.push_back(0);
        aTakenGoals.push_back(0);
    }

    // Compute the statistics
    computeStatistics();
}

int Statistics::getTeamIndex(const QString &name) const
{
    const int size = aTeam.size();
    for (int i = 0; i < size; i++)
    {
        if (name == aTeam.at(i).getFullName() || name == aTeam.at(i).getShortName())
            return i;
    }
    return -1;
}

void Statistics::computeStatistics()
{
    // Compute everything but the rankings and the goal averages
    const int mSize = aMatches.size();
    for (int i = 0; i < mSize; i++)
    {
        const Match &match = aMatches.at(i);
        if (match.isGamePlayed() || match.isGameForfeited())
        {
            if (match.doesAwayTeamWin())
            {
                const int winnerIndex = getTeamIndex(match.getAwayTeam());
                const int loserIndex = getTeamIndex(match.getHomeTeam());
                if (winnerIndex >= 0 && loserIndex >= 0)
                {
                    aPoints[winnerIndex] += 3;
                    aScoredGoals[winnerIndex] += match.getAwayTeamScore();
                    aTakenGoals[winnerIndex] += match.getHomeTeamScore();
                    aScoredGoals[loserIndex] += match.getHomeTeamScore();
                    aTakenGoals[loserIndex] += match.getAwayTeamScore();
                }
            } else if (match.doesHomeTeamWin())
            {
                const int winnerIndex = getTeamIndex(match.getHomeTeam());
                const int loserIndex = getTeamIndex(match.getAwayTeam());
                if (winnerIndex >= 0 && loserIndex >= 0)
                {
                    aPoints[winnerIndex] += 3;
                    aScoredGoals[winnerIndex] += match.getHomeTeamScore();
                    aTakenGoals[winnerIndex] += match.getAwayTeamScore();
                    aScoredGoals[loserIndex] += match.getAwayTeamScore();
                    aTakenGoals[loserIndex] += match.getHomeTeamScore();
                }
            } else {
                const int homeIndex = getTeamIndex(match.getHomeTeam());
                const int awayIndex = getTeamIndex(match.getAwayTeam());
                const int goals = match.getAwayTeamScore();
                if (homeIndex >= 0 && awayIndex >= 0)
                {
                    aPoints[homeIndex]++;
                    aPoints[awayIndex]++;
                    aScoredGoals[homeIndex] += goals;
                    aTakenGoals[homeIndex] += goals;
                    aScoredGoals[awayIndex] += goals;
                    aTakenGoals[awayIndex] += goals;
                }
            }
        }
    }

    // Compute the goal averages
    const int tSize = aTeam.size();
    for (int i = 0; i < tSize; i++)
    {
        aGoalAverages[i] = aScoredGoals.at(i) - aTakenGoals.at(i);
    }

    // Compute the rankings

}
