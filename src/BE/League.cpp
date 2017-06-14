#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "League.hpp"

using namespace std;

// Default constructors
League::League()
{
}

bool League::collectTeams()
{
    // Read and stock all clubs
    ifstream teamFlow(INFOS, ios::in);
    if (!teamFlow)
    {
        cerr << "Failed to open " << INFOS << " for reading!" << endl;
        return false;
    }
        
    // Stock of club informations
    string teamName, teamShortName;
    for (int i = 0; i < NB_OF_TEAM; ++i)
    {
        teamFlow >> teamName >> teamShortName;
        _vectorOfTeams.push_back(Team(teamName, teamShortName));
    }

    teamFlow.close();

    return true;
}

bool League::collectMatchs(unsigned int untilThisJourney)
{
    // Read and stock all matches
    string firstTeam, secondTeam;
    unsigned int firstScore, secondScore;
    ifstream matchFlow(MATCHS, ios::in);
    if (!matchFlow)
    {
        // A bien definir dans les variables globales !!!
        cerr << "Failed to open " << MATCHS << " for reading!" << endl;
        return false;
    }
    
    unsigned int journeyNumberTreated = 0, test = 1;
    untilThisJourney = ((untilThisJourney < 10) ? 10 : untilThisJourney);
    string line;
    while (getline(matchFlow, line, '\n') && ++journeyNumberTreated <= untilThisJourney)
    {
        istringstream iss(line);
        string aString;
        int count(-1);
        while (getline(iss, aString, '/'))
        {
            count++;
            if (count == 0 || count == 1)
                continue;

            switch (count % 4)
            {
                case 2:
                {
                    firstTeam   =  aString;
                    cout << "N." << test++ << " - " << firstTeam << " ";
                    break;
                }
                case 3:
                {
                    firstScore  = atol(aString.c_str());
                    cout << firstScore << " - ";
                    break;
                }
                case 0:
                {
                    secondScore = atol(aString.c_str());
                    cout << secondScore << " ";
                    break;
                }
                case 1: 
                {
                    secondTeam  =  aString;
                    cout << secondTeam << endl;
                    // For each line, have to save collected datas
                    vector<Team>::iterator itVect = _vectorOfTeams.begin();
                    for (; itVect != _vectorOfTeams.end(); ++itVect)
                    {
                        if (itVect->getShortName() == firstTeam)
                        {
                            if (firstScore == secondScore) itVect->addPointsForRanking(1);
                            if (firstScore >  secondScore) itVect->addPointsForRanking(3);
                            itVect->updateGoals(firstScore, secondScore);
                            itVect->updateMatchCounter();
                        }
                        if (itVect->getShortName() == secondTeam)
                        {
                            if (secondScore == firstScore) itVect->addPointsForRanking(1);
                            if (secondScore >  firstScore) itVect->addPointsForRanking(3);
                            itVect->updateGoals(secondScore, firstScore);
                            itVect->updateMatchCounter();
                        }
                    }
                    _vectorOfMatchs.push_back(Match(stringToTeam(firstTeam), stringToTeam(secondTeam), firstScore, secondScore));
                }
            }
        }
    }
    
    sort(_vectorOfTeams.begin(), _vectorOfTeams.end());
    reverse(_vectorOfTeams.begin(), _vectorOfTeams.end());

    updateRanking();

    matchFlow.close();

    return true;
}

bool League::isTeamAvailable(const string teamToCheck) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getName() == teamToCheck || _vectorOfTeams[i].getShortName() == teamToCheck)
            return true;
    return false;
}

Team& League::stringToTeam(const std::string teamName)
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getName() == teamName || _vectorOfTeams[i].getShortName() == teamName)
            return _vectorOfTeams[i];
    // Undefined behaviour here...
    //return ???;
}

void League::updateRanking()
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        _vectorOfTeams[i].updateRanking(i);
    }
}

void League::teamsToString() const
{
    cout << "Nomber of teams: " << getVectorOfTeams().size() << endl;
    const unsigned int size = getVectorOfTeams().size();
    for (unsigned int i = 0; i < size; ++i)
    {
        cout.width(2);
        cout << left << i+1 << " - ";

        cout.width(14);
        cout << left << (getVectorOfTeams())[i].getName();
        cout.width(4);
        cout << left << (getVectorOfTeams())[i].getShortName();

        cout << " - Pts: ";
        cout.width(2);
        cout << (getVectorOfTeams())[i].getPointNbRanking();

        cout << " - Goals: ";
        cout.width(3);
        cout << (getVectorOfTeams())[i].getMarkedGoals() << "/";
        cout.width(2);
        cout << (getVectorOfTeams())[i].getTakenGoals();
        
        cout << " - Rate: ";
        cout.width(3);
        cout << (int)((getVectorOfTeams())[i].getMarkedGoals()) - (int)((getVectorOfTeams())[i].getTakenGoals());
        
        cout << " - Played: " << (getVectorOfTeams())[i].getPlayedGameNumber() << endl;
    }
}

void League::matchsToString() const
{
    cout << "Nomber of matchs: " << getVectorOfMatchs().size() << endl;
    const unsigned int size = getVectorOfMatchs().size();
    for (unsigned int i = 0; i < size; ++i)
    {
        cout.width(3);
        cout << left << i+1 << " - ";

        cout.width(14);
        cout << left << (getVectorOfMatchs())[i].getHomeTeam().getName();
        cout << "(";
        cout.width(4);
        cout << left << (getVectorOfMatchs())[i].getHomeTeam().getShortName();
        cout << ") ";
        cout.width(1);
        cout << (getVectorOfMatchs())[i].getHomeTeamScore();

        cout << " - ";
        cout.width(1);
        cout << (getVectorOfMatchs())[i].getOutsideTeamScore();
        cout << " (";
        cout.width(4);
        cout << (getVectorOfMatchs())[i].getOutsideTeam().getShortName();
        cout << ") ";
        cout.width(14);
        cout << (getVectorOfMatchs())[i].getOutsideTeam().getName();
        
        cout << "- Prono: ";
        //cout << "None for now, sorry ;) => ";
        cout << (getVectorOfMatchs())[i].prono().getName();

        cout << endl;
    }
}

void attributionOfPenality(const Team& teamToPenalize)
{
    
}

vector<Team> League::getVectorOfTeams() const
{
    return _vectorOfTeams;
}

vector<Match> League::getVectorOfMatchs() const
{
    return _vectorOfMatchs;
}
