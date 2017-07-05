#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include "Variables.hpp"
#include "Team.hpp"

class Match
{
public:
    Match();
    Match(unsigned int day, Team& teamIn, Team& teamOut, unsigned int scoreIn, unsigned int scoreOut);
    Match(unsigned int day, Team& teamIn, Team& teamOut, unsigned int forfait);

    void prono() const;

    Team& getHomeTeam();
    Team& getOutsideTeam();
    unsigned int getHomeTeamScore() const;
    unsigned int getOutsideTeamScore() const;
    unsigned int getJourney() const;

private:
    Team _homeTeam;
    Team _outsideTeam;
    unsigned int _homeTeamScore;
    unsigned int _outsideTeamScore;

    unsigned int _journey;
};

#endif // MATCH_H_INCLUDED
