#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

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

bool League::collectMatchs()
{
    // Read and stock all matches
    string firstTeam, secondTeam;
    unsigned int firstScore, secondScore;
    ifstream matchFlow(MATCHS, ios::in);
    if (!matchFlow)
    {
        // A bien definir dans les variables globales !!!
        cerr << "Failed to open Matchs.txt for reading!" << endl;
        return false;
    }
        
    string line;
    while (getline(matchFlow, line, '\n'))
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
                    cout << firstTeam << " ";
                    break;
                }
                case 3:
                {
                    firstScore  = atol(aString.c_str());
                    cout << firstScore;
                    break;
                }
                case 0:
                {
                    secondScore = atol(aString.c_str());
                    cout << " - " << secondScore << " ";
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
                            cout << "Trouve! " << firstTeam << "."<< endl;
                        }

                        if (itVect->getShortName() == secondTeam)
                        {
                            if (secondScore == firstScore) itVect->addPointsForRanking(1);
                            if (secondScore >  firstScore) itVect->addPointsForRanking(3);
                            cout << "Trouve! " << secondTeam << "."<< endl;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    
    vector<Team>::iterator itVect = _vectorOfTeams.begin();
    for (; itVect != _vectorOfTeams.end(); ++itVect)
        cout << itVect->getName() << " - " << itVect->getPointNbRanking() << endl;
    return true;
}

void League::addNewJourney(unsigned int journeyNb)
{
    ofstream myFlux(INFOS, ios::out | ios::app);
    if (!myFlux)
    {
        cerr << "Erreur d'ouverture pour écriture!" << endl;
        return;
    }

    myFlux << endl << "J:" << journeyNb;

    string teamName1, teamName2;
    unsigned int score1, score2;
    char c;
    unsigned int nbMatchsFilled = 0;

    cout << "A rentrer sous la forme: Team1 Score1 - Score2 Team2" << endl;
    do
    {
        cout << "Match a enregistrer: ";
        cin >> teamName1 >> score1 >> c >> score2 >> teamName2;
        if ( !(isTeamAvailable(teamName1) && isTeamAvailable(teamName2)) )
        {
            cout << "Saisie invalide! ";
            nbMatchsFilled--;
            continue;
        }

        myFlux << extractShortName(teamName1) << " " << score1 << "-" << score2 << " " << extractShortName(teamName2);
        if (nbMatchsFilled < NB_OF_MATCH)
            myFlux << " / ";
    }
    while ( ++nbMatchsFilled <= NB_OF_MATCH );
}

bool League::isTeamAvailable(string teamToCheck) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getName() == teamToCheck || _vectorOfTeams[i].getShortName() == teamToCheck)
            return true;
    return false;
}

string League::extractFullName(string shortTeamName) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getShortName() == shortTeamName)
            return _vectorOfTeams[i].getName();
    return shortTeamName;
}

string League::extractShortName(string teamName) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getName() == teamName)
            return _vectorOfTeams[i].getShortName();
    return teamName;
}

// Getters
vector<Team> League::getVectorOfTeams() const
{
    return _vectorOfTeams;
}

vector<Match> League::getVectorOfMatchs() const
{
    return _vectorOfMatchs;
}
