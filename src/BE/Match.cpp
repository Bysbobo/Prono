#include <iostream>

#include "Match.hpp"

using namespace std;

Match::Match()
{
}

Match::Match(Team teamIn, Team teamOut, unsigned int scoreIn, unsigned int scoreOut) :
                _homeTeam(teamIn), _outsideTeam(teamOut),
                _homeTeamScore(scoreIn), _outsideTeamScore(scoreOut)
{
}

Team Match::prono() const
{
    return _homeTeam; // Have to finish this !!!!!!
}

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
