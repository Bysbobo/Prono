#include <iostream>
#include <string>

#include "Variables.hpp"
#include "League.hpp"
#include "Match.hpp"
#include "Team.hpp"

using namespace std;

int main()
{
    League ligue;

    if (!ligue.collectTeams())
        cerr << "Error during teams reading" << endl;

    if (!ligue.collectMatchs())
        cerr << "Error during matchs reading" << endl;

    cout << "Taille Teams" << ligue.getVectorOfTeams().size() << endl;
    cout << "Taille Matchs" << ligue.getVectorOfMatchs().size() << endl;

    vector<Team> v = ligue.getRankingPerJourney(50);
    for (int i = 0; i < v.size(); i++)
    {
        cout.width(2);
        cout << i+1;
        cout << " - " << v[i].getName() << endl;
    }

/*
    for (int i = 0; i < ligue.getVectorOfTeams().size(); i++)
        cout << i+1 << " " << ligue.getVectorOfTeams()[i].getName() << endl;

    for (int i = 0; i < ligue.getVectorOfMatchs().size(); i++)
        cout << i+1 << " " << ligue.getVectorOfMatchs()[i].getHomeTeam().getName() << " vs " << ligue.getVectorOfMatchs()[i].getOutsideTeam().getName() << endl;
*/
/*
    ligue.teamsToString();
    cout << endl;
    ligue.matchsToString();
*/
    return 0;
}
