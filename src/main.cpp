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

    cout << "Match until which journey?? (10 < J < 38) ";
    unsigned int val;
    cin >> val;

    if (!ligue.collectMatchs(val))
        cerr << "Error during matchs reading" << endl;

    ligue.teamsToString();
    cout << endl;
    ligue.matchsToString();

    return 0;
}
