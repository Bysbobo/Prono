#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QVector>
#include "match.h"

class Team
{
public:
    /**
     * @brief Default constructor.
     */
    Team() {}
    /**
     * @brief Constructor with the initialisation of the team.
     * @param fullName : The full name of the team.
     * @param shortName : The short name of the team.
     */
    Team(const QString &fullName, const QString &shortName);

    /**
     * @brief A getter for the full name of the team.
     * @return The full name of the team.
     */
    inline QString getFullName() const { return aFullName; }
    /**
     * @brief A getter for the short name of the team.
     * @return The short name of the team.
     */
    inline QString getShortName() const { return aShortName; }

    /**
     * @brief A getter for the vector of matches.
     * @return A constant vector of the matches.
     */
    inline QVector<Match> getMatches() const { return aMatches; }
    /**
     * @brief A getter for the vector of matches.
     * @return A reference to the vector of matches.
     */
    inline QVector<Match>& getMatches() { return aMatches; }

private:
    /**
     * @brief aFullName : The full name of the team.
     */
    QString aFullName;
    /**
     * @brief aShortName : The short name of the team.
     */
    QString aShortName;

    /**
     * @brief aMatches : The vector of matches of the team.
     */
    QVector<Match> aMatches;
};

#endif // TEAM_H
