#include <iostream>

#include "Equipe.hpp"

using namespace std;

// Constructors
Equipe::Equipe() : _ranking(0)
{
}

Equipe::Equipe(string name, string shortName) : _name(name), _shortName(shortName), _ranking(0)
{
}

// Getters
string Equipe::getName() const
{
    return _name;
}

string Equipe::getShortName() const
{
    return _shortName;
}

int Equipe::getRanking() const
{
    return _ranking;
}

std::vector<Equipe> Equipe::getMatchsHistory() const
{
    return _vectorOfMatchsHistory;
}
