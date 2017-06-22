#ifndef LEAGUE_H
#define LEAGUE_H

#include <QVector>

#include "team.h"
#include "match.h"

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

    League(const QString& txtFileName)
    {
        retrieveTeamsFromFile(txtFileName);
    }

    /**
     * @brief Verify that a team is available in the league.
     * @param teamName : The name of the team to be verified. It can be the full name or the short name of the team.
     * @return True if the team is in the league, false otherwise.
     */
    bool isTeamAvailable(const QString& teamName) const;

    /**
     * @brief A getter to the vector of teams.
     * @return The vector of teams in the league as a constant.
     */
    QVector<Team> getVectorOfTeams() const { return aTeams; }
    /**
     * @brief A getter to the vector of teams.
     * @return The reference to the vector of teams in the league.
     */
    QVector<Team>& getVectorOfTeams() { return aTeams; }

private:
    /**
     * @brief This method reads a file and creates the teams. The file should contain one
     * @param fileName : The file name from which the teams will be retrieved.
     * @return True if the teams have been retrieved from the file, false otherwise.
     */
    bool retrieveTeamsFromFile(const QString& fileName);

    bool retrieveMatchsFromFile(unsigned int untilThisJourney);

    /**
     * @brief aTeams : The vector of teams of the league.
     */
    QVector<Team> aTeams;
};

#endif // LEAGUE_H
