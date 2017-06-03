#include <iostream>

#include "Team.hpp"

using namespace std;

// Constructors
Team::Team() : _ranking(0), _rankingPointNb(0), _playedGameNumber(0), _markedGoals(0), _takenGoals(0)
{
}

Team::Team(string name, string shortName) : _name(name), _shortName(shortName), _ranking(0), _rankingPointNb(0),
											_playedGameNumber(0), _markedGoals(0), _takenGoals(0)
{
}

void Team::addPointsForRanking(int points)
{
	points = (points < 0) ? 0 : points;
	_rankingPointNb += points;
}

void Team::updateMatchCounter()
{
	_playedGameNumber++;
}

void Team::updateRanking(unsigned int rankIndicator)
{
	_ranking = rankIndicator;
}

void Team::updateGoals(unsigned int nbMarkedGoals, unsigned int nbTakenGoals)
{
    _markedGoals += nbMarkedGoals;
    _takenGoals += nbTakenGoals;
    _goalAverage = (int)(_markedGoals - _takenGoals);
}

bool Team::operator< (const Team& other) const
{
	if (_rankingPointNb == other._rankingPointNb)
	{
		if (_goalAverage == other._goalAverage)
			return _markedGoals < other._markedGoals;
		else
			return _goalAverage < other._goalAverage;
	}
	else 
		return _rankingPointNb < other._rankingPointNb;
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

unsigned int Team::getRanking() const
{
    return _ranking;
}

unsigned int Team::getPointNbRanking() const
{
	return _rankingPointNb;
}

unsigned int Team::getPlayedGameNumber() const
{
	return _playedGameNumber;
}

unsigned int Team::getMarkedGoals() const
{
	return _markedGoals;
}

unsigned int Team::getTakenGoals() const
{
	return _takenGoals;
}

int Team::getGoalAverage() const
{
	return _goalAverage;
}

std::vector<Team> Team::getMatchsHistory() const
{
    return _vectorOfMatchsHistory;
}
