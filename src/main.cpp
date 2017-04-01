#include <iostream>
#include <string>

#include "Variables.hpp"
#include "League.hpp"
#include "Match.hpp"
#include "Team.hpp"

using namespace std;

int main()
{
    cout << BDD << endl;
    League ligue;
    if (!ligue.collectTeams())
        cerr << "Putain de mardi..." << endl;
    if (!ligue.collectMatchs())
        cerr << "Purin de mardi..." << endl;

    cout << "Taille du tableau: " << ligue.getVectorOfTeams().size() << endl << endl;

    for (unsigned int i = 0; i < ligue.getVectorOfTeams().size(); ++i)
    {
        cout << "Team: ";
        cout.width(14);
        cout << left << (ligue.getVectorOfTeams())[i].getName();
        cout.width(4);
        cout << left << (ligue.getVectorOfTeams())[i].getShortName();
        cout << " - Classement: " << (ligue.getVectorOfTeams())[i].getPointNbRanking() << endl;
    }

// Pour rajouter une ligne de match ensuite
/*
    string matchsToFill;
    cout << "Voulez-vous remplir les matchs? (Y / N) ";
    cin >> matchsToFill;
    while (matchsToFill == "Y")
    {
        cout << "Quelle journee? ";
        int journeyNumber;
        cin >> journeyNumber;
        ligue.addNewJourney(journeyNumber);

        cout << "Voulez-vous remplir une autre journee? (Y / N) ";
        cin >> matchsToFill;
    }
*/



    return 0;
}
