#include <iostream>

#include "Match.h"

using namespace std;

Match::Match(Equipe teamIn, Equipe teamOut) : _homeTeam(teamIn), _outsideTeam(teamOut)
{
}

int Match::winnerEqualOrLoser() const
{
    if (_homeTeamScore > _outsideTeamScore)
        return -1;
    else if (_homeTeamScore == _outsideTeamScore)
        return 0;
    else
        return 1;
}

// Getters
Equipe Match::getHomeTeam() const
{
    return _homeTeam;
}

Equipe Match::getOutsideTeam() const
{
    return _outsideTeam;
}

unsigned int Match::getHomeTeamScore() const
{
    return _homeTeamScore;
}

unsigned int Match::getOutsideTeamScore() const
{
    return _outsideTeamScore;
}
