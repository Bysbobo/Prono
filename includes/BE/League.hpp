#ifndef LEAGUE_H_INCLUDED
#define LEAGUE_H_INCLUDED

#include <vector>

#include "Variables.hpp"
#include "Team.hpp"
#include "Match.hpp"

class League
{
public:

    League();

    bool collectTeams();
    bool collectMatchs();
    bool isTeamAvailable(const std::string teamToCheck) const;
    Team& stringToTeam(const std::string teamName);
    void updateRanking();
    void teamsToString() const;
    void matchsToString() const;

    std::vector<Team>& getRankingPerJourney(unsigned int day);

    std::vector<Team> getVectorOfTeams() const;
    std::vector<Match> getVectorOfMatchs() const;

private:
    std::vector<Team> _vectorOfTeams;
    std::vector<Match>  _vectorOfMatchs;
};

#endif // LEAGUE_H_INCLUDED
