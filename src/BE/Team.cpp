#include <iostream>

#include "Team.hpp"

using namespace std;

// Constructors
Team::Team() : _ranking(0), _rankingPointNb(0)
{
}

Team::Team(string name, string shortName) : _name(name), _shortName(shortName), _ranking(0), _rankingPointNb(0)
{
}

// Getters
string Team::getName() const
{
    return _name;
}

string Team::getShortName() const
{
    return _shortName;
}

int Team::getRanking() const
{
    return _ranking;
}

int Team::getPointNbRanking() const
{
	return _rankingPointNb;
}

std::vector<Team> Team::getMatchsHistory() const
{
    return _vectorOfMatchsHistory;
}

void Team::addPointsForRanking(int points)
{
	points = (points < 0) ? (points = 0): points;

	_rankingPointNb += points;
}