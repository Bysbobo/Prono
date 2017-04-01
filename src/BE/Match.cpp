#include <iostream>

#include "Match.hpp"

using namespace std;

Match::Match(Team teamIn, Team teamOut, int scoreIn, int scoreOut) :
                _homeTeam(teamIn), _outsideTeam(teamOut),
                _homeTeamScore(scoreIn), _outsideTeamScore(scoreOut)
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
Team Match::getHomeTeam() const
{
    return _homeTeam;
}

Team Match::getOutsideTeam() const
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
