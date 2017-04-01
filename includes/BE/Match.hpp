#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include "Variables.hpp"
#include "Team.hpp"

class Match
{
public:
    Match(Team teamIn, Team teamOut, int scoreIn, int scoreOut);

    int winnerEqualOrLoser() const;

    Team getHomeTeam() const;
    Team getOutsideTeam() const;

    unsigned int getHomeTeamScore() const;
    unsigned int getOutsideTeamScore() const;

private:
    Team _homeTeam;
    Team _outsideTeam;
    unsigned int _homeTeamScore;
    unsigned int _outsideTeamScore;
};

#endif // MATCH_H_INCLUDED
