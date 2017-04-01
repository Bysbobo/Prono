#ifndef LIGUE1_H_INCLUDED
#define LIGUE1_H_INCLUDED

#include <vector>

#include "Variables.hpp"
#include "Equipe.hpp"
#include "Match.hpp"

class Ligue1
{
public:

    Ligue1();

    bool collectTeams();
    bool collectMatchs();
    void addNewJourney(unsigned int journeyNb);
    bool isTeamAvailable(std::string teamToCheck) const;
    std::string extractFullName(std::string shortTeamName) const;
    std::string extractShortName(std::string shortTeamName) const;

    std::vector<Equipe> getVectorOfTeams() const;
    std::vector<Match>  getVectorOfMatchs() const;


private:
    std::vector<Equipe> _vectorOfTeams;
    std::vector<Match>  _vectorOfMatchs;
};

#endif // LIGUE1_H_INCLUDED
