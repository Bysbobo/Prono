#include <iostream>
#include <fstream>

#include "Ligue1.h"

using namespace std;

// Default constructors
Ligue1::Ligue1()
{
    ifstream myFlux(BDD, ios::in);
    if (!myFlux)
    {
        cerr << "Erreur d'ouverture pour lecture!" << endl;
        return;
    }

    string teamName, teamShortName;
    for (int i = 0; i < NB_OF_TEAM; ++i)
    {
        myFlux >> teamName >> teamShortName;
        _vectorOfTeams.push_back(Equipe(teamName, teamShortName));
    }

}

void Ligue1::addNewJourney(unsigned int journeyNb)
{
    ofstream myFlux(BDD, ios::out | ios::app);
    if (!myFlux)
    {
        cerr << "Erreur d'ouverture pour écriture!" << endl;
        return;
    }

    myFlux << endl << "J=" << journeyNb << ":";

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

bool Ligue1::isTeamAvailable(string teamToCheck) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getName() == teamToCheck || _vectorOfTeams[i].getShortName() == teamToCheck)
            return true;
    return false;
}

string Ligue1::extractFullName(string shortTeamName) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getShortName() == shortTeamName)
            return _vectorOfTeams[i].getName();
    return shortTeamName;
}

string Ligue1::extractShortName(string teamName) const
{
    const unsigned int size = _vectorOfTeams.size();
    for (unsigned int i = 0; i < size; ++i)
        if (_vectorOfTeams[i].getName() == teamName)
            return _vectorOfTeams[i].getShortName();
    return teamName;
}

// Getters
vector<Equipe> Ligue1::getVectorOfTeams() const
{
    return _vectorOfTeams;
}

vector<Match> Ligue1::getVectorOfMatchs() const
{
    return _vectorOfMatchs;
}
