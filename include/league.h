#ifndef LEAGUE_H
#define LEAGUE_H

#include <QObject>
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
     * @param name : the name of the league.
     * @param txtFileName : the file from which the teams will be initialized.
     * @param txtMatchesFileName : The file from which the matches will be initialized.
     */
    League(const QString& name, const QString& txtTeamsFileName, const QString& txtMatchesFileName) :
        aName(name)
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
     * @brief This method returns the team from its given name in the vector of teams of the league.
     * @param teamName : The name of the team which will be returned. It can be the short name or the full name.
     * @return The team from its given name in the vector of teams of the league.
     */
    const Team getTeam(const QString& teamName) const;
    /**
     * @brief A getter to the name of the league.
     * @return The name of the league.
     */
    inline QString getName() const { return aName; }
    /**
     * @brief A setter to the name of the league.
     * @param name : The name of the league.
     */
    inline void setName(const QString& name) { aName = name; }

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
    /**
     * @brief This method creates a QString in which the list of the league teams is defined as they should appear in the tree view.
     * @return A QString in which the list of the league teams is defined as they should appear in the tree view.
     */
    QString getListOfTeamsForTree() const;

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
     * @brief aName : The name of the league.
     */
    QString aName;
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
