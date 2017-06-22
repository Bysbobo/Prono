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
    /**
     * @brief Contructor that initializes the vector of teams from a txt file.
     * @param txtFileName : the file from which the teams will be initialized.
     * @param txtMatchesFileName : The file from which the matches will be initialized.
     */
    League(const QString& txtTeamsFileName, const QString& txtMatchesFileName)
    {
        retrieveTeamsFromFile(txtTeamsFileName);
        retrieveMatchsFromFile(txtMatchesFileName);
    }

    /**
     * @brief Verify that a team is available in the league.
     * @param teamName : The name of the team to be verified. It can be the full name or the short name of the team.
     * @return True if the team is in the league, false otherwise.
     */
    bool isTeamAvailable(const QString& teamName) const;
    /**
     * @brief This method returns the index of a given team in the vector of teams of the league.
     * @param teamName : The name of the team which index will be returned. It can be the short name or the full name.
     * @return The index of a given team in the vector of teams of the league. If the team does not exist -1 is returned.
     */
    int getTeamIndex(const QString& teamName) const;

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
     * @brief This method reads a file and creates the teams. The file should contain one team on each line.
     * @param fileName : The file name from which the teams will be retrieved.
     * @return True if the teams have been retrieved from the file, false otherwise.
     */
    bool retrieveTeamsFromFile(const QString& fileName);
    /**
     * @brief This method reads a file and creates the matches.
     * @param fileName : The file name from which the matches will be retrieved.
     * @return True if the matches have been retrieved from the file, false otherwise.
     */
    bool retrieveMatchsFromFile(const QString& fileName);

    /**
     * @brief aTeams : The vector of teams of the league.
     */
    QVector<Team> aTeams;
    /**
     * @brief aMatches : The vector of matches of the league.
     */
    QVector<Match> aMatches;
};

#endif // LEAGUE_H
