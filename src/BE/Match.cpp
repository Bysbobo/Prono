#include <iostream>
#include <cmath>

#include "Match.hpp"

using namespace std;

Match::Match()
{
}

Match::Match(unsigned int day, Team& teamIn, Team& teamOut, unsigned int scoreIn, unsigned int scoreOut) :
                _journey(day),
                _homeTeam(teamIn), _outsideTeam(teamOut),
                _homeTeamScore(scoreIn), _outsideTeamScore(scoreOut)
{
}

Match::Match(unsigned int day, Team& teamIn, Team& teamOut, unsigned int forfait) :
                _journey(day),
                _homeTeam(teamIn), _outsideTeam(teamOut)
{
}

Team& Match::getHomeTeam()
{
    return _homeTeam;
}

Team& Match::getOutsideTeam() 
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

unsigned int Match::getJourney() const
{
    return _journey;
}

// Not his real and final spot!! -> Use of Prono class after discussion with teammate
void Match::prono() const
{
    cout << _homeTeam.getRanking() << "er vs " << _outsideTeam.getRanking() << "er -> diff: " << abs(_homeTeam.getRanking() - _outsideTeam.getRanking() ) << " => ";

    if (abs(_homeTeam.getRanking() - _outsideTeam.getRanking() ) < 6)
        cout << "1N"; 
    else if (abs(_homeTeam.getRanking() - _outsideTeam.getRanking() ) < 8)
        cout << "1";
    else if (abs(_homeTeam.getRanking() - _outsideTeam.getRanking() ) < 10)
        cout << "N2";
    else
        cout << "2";
    // Have to finish this !!!!!!
}