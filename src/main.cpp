#include <iostream>
#include <string>

#include "Variables.hpp"
#include "Ligue1.hpp"
#include "Match.hpp"
#include "Equipe.hpp"

using namespace std;

int main()
{
    cout << BDD << endl;
    Ligue1 ligue;

    cout << "Taille du bordel: " << ligue.getVectorOfTeams().size() << endl << endl;

    for (unsigned int i = 0; i < ligue.getVectorOfTeams().size(); ++i)
    {
        cout << "Equipe: ";
        cout.width(14);
        cout << left << (ligue.getVectorOfTeams())[i].getName();
        cout.width(4);
        cout << left << (ligue.getVectorOfTeams())[i].getShortName();
        cout << " - Classement: " << (ligue.getVectorOfTeams())[i].getRanking() << endl;
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
