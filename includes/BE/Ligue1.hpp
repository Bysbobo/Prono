#ifndef LIGUE1_H_INCLUDED
#define LIGUE1_H_INCLUDED

#include <vector>

#include "Variables.h"
#include "Equipe.h"
#include "Match.h"

class Ligue1
{
public:
    /**
     * \fn Equipe(std::string name, std::string shortName)
     * \brief constructor.
     * \param name : nom de .
     * \param shortName : nom de .
     */
    Ligue1();

    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    void addNewJourney(unsigned int journeyNb);
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    bool isTeamAvailable(std::string teamToCheck) const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::string extractFullName(std::string shortTeamName) const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::string extractShortName(std::string shortTeamName) const;

    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::vector<Equipe> getVectorOfTeams() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::vector<Match>  getVectorOfMatchs() const;

private:
    std::vector<Equipe> _vectorOfTeams;
    std::vector<Match>  _vectorOfMatchs;
};

#endif // LIGUE1_H_INCLUDED
