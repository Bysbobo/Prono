#ifndef EQUIPE_H_INCLUDED
#define EQUIPE_H_INCLUDED

#include <vector>

#include "Variables.hpp"

class Equipe
{
public:
    /**
     * \fn Equipe(std::string name, std::string shortName)
     * \brief constructor.
     * \param name : nom de .
     * \param shortName : nom de .
     */
    Equipe();
    /**
     * \fn Equipe(std::string name, std::string shortName)
     * \brief constructor.
     * \param name : nom de .
     * \param shortName : nom de .
     */
    Equipe(std::string name, std::string shortName);

    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::string getName() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::string getShortName() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    int getRanking() const;
    /**
     * \fn std::vector<Equipe> getMatchsHistory() const
     * \brief This method is a getter of the vector of matches history.
     * \return The vector of matches history.
     */
    std::vector<Equipe> getMatchsHistory() const;

private:
    std::string _name;
    std::string _shortName;
    int _ranking;
    std::vector<Equipe> _vectorOfMatchsHistory;

};

#endif // EQUIPE_H_INCLUDED
