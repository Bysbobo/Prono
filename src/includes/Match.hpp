#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include "Variables.h"
#include "Equipe.h"

class Match
{
public:
    /**
     * \fn Equipe(std::string name, std::string shortName)
     * \brief constructor.
     * \param name : nom de .
     * \param shortName : nom de .
     */
    Match(Equipe teamIn, Equipe teamOut);

    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    int winnerEqualOrLoser() const;

    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    Equipe getHomeTeam() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    Equipe getOutsideTeam() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    unsigned int getHomeTeamScore() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    unsigned int getOutsideTeamScore() const;

private:
    Equipe _homeTeam;
    Equipe _outsideTeam;
    unsigned int _homeTeamScore;
    unsigned int _outsideTeamScore;
};

#endif // MATCH_H_INCLUDED
