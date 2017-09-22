#ifndef STATISTICS_H
#define STATISTICS_H

#include "team.h"

/**
 * @brief The Statistics class implements the statistics of a team in a league.
 */
class Statistics
{
public:
    Statistics(const QVector<Team>& team, const QVector<Match>& matches);

private:
    /**
     * @brief This method returns the index of a team in the QVector.
     * @param name : The full name or the short name of the team which index will be returned.
     * @return The index of the given team name in aTeam vector.
     */
    int getTeamIndex(const QString& name) const;
    /**
     * @brief This method returns the index of a team in the QVector.
     * @param team : The team which index will be returned.
     * @return The index of the given team in aTeam vector.
     */
    inline int getTeamIndex(const Team &team) const { return getTeamIndex(team.getFullName()); }
    /**
     * @brief This method fill all the statistics for the teams of the played matches.
     */
    void computeStatistics();

    /**
     * @brief aTeam : The team which caracteristics should be determined.
     */
    QVector<Team> aTeam;
    /**
     * @brief aMatches : All the matches in the league.
     */
    QVector<Match> aMatches;
    /**
     * @brief aRankings : The rankings of the teams.
     */
    QVector<int> aRankings;
    /**
     * @brief aPoints : The points of the teams.
     */
    QVector<int> aPoints;
    /**
     * @brief aGoalAverages : The goal averages of the teams.
     */
    QVector<int> aGoalAverages;
    /**
     * @brief aScoredGoals : The scored goals of the teams.
     */
    QVector<int> aScoredGoals;
    /**
     * @brief aTakenGoals : The taken goals of the teams.
     */
    QVector<int> aTakenGoals;
};

#endif // STATISTICS_H
