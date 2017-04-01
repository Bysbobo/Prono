#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include "Variables.hpp"
#include "Equipe.hpp"

class Match
{
public:
    Match(Equipe teamIn, Equipe teamOut);

    int winnerEqualOrLoser() const;

    Equipe getHomeTeam() const;
    Equipe getOutsideTeam() const;

    unsigned int getHomeTeamScore() const;
    unsigned int getOutsideTeamScore() const;

private:
    Equipe _homeTeam;
    Equipe _outsideTeam;
    unsigned int _homeTeamScore;
    unsigned int _outsideTeamScore;
};

#endif // MATCH_H_INCLUDED
