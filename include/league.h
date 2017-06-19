#ifndef LEAGUE_H
#define LEAGUE_H

//#define NB_OF_TEAM      20
//#define NB_OF_MATCH     (NB_OF_TEAM-1)*20
//#define MATCHS          ":/Matches.txt"
//#define INFOS           ":/Infos.txt"

#include <QVector>

#include "Team.h"
#include "Match.h"

/**
 * @brief The League class implements a league.
 */
class League
{
public:
    /**
     * @brief The default constructor of the League.
     */
    League() {}

    /**
     * @brief Verify that a team is available in the league.
     * @param teamName : The name of the team to be verified. It can be the full name or the short name of the team.
     * @return True if the team is in the league, false otherwise.
     */
    bool isTeamAvailable(const QString& teamName) const;
    /**
     * @brief Transform a team name into a team. The team should be in the league.
     * @param teamName : The team name to be transformed.
     * @return A Team object that correspond to the team name.
     */
    Team& stringToTeam(const QString& teamName);
    void updateRanking();
    void teamsToString() const;
    void matchsToString() const;

    /**
     * @brief A getter to the vector of teams.
     * @return The vector of teams in the league as a constant.
     */
    QVector<Team> getVectorOfTeams() const { return m_vectorOfTeams; }
    /**
     * @brief A getter to the vector of teams.
     * @return The reference to the vector of teams in the league.
     */
    QVector<Team>& getVectorOfTeams() { return m_vectorOfTeams; }

private:
    /**
     * @brief This method reads a file and creates the teams. The file should contain one
     * @param fileName : The file name from which the teams will be retrieved.
     * @return True if the teams have been retrieved from the file, false otherwise.
     */
    bool retrieveTeamsFromFile(const QString& fileName);

    bool retrieveMatchsFromFile(unsigned int untilThisJourney);

    QVector<Team> m_vectorOfTeams;
};

#endif // LEAGUE_H
