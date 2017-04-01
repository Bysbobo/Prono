#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <vector>

#include "Variables.hpp"

class Team
{
public:

    Team();
    Team(std::string name, std::string shortName);

    std::string getName() const;
    std::string getShortName() const;
    int getRanking() const;
    int getPointNbRanking() const;
    std::vector<Team> getMatchsHistory() const;

    void addPointsForRanking(int points);

private:
    std::string _name;
    std::string _shortName;
    int _ranking; // Creer un objet ranking avec toutes les stats serait pas du luxe
    int _rankingPointNb; // Va de pair avec au dessus...
    std::vector<Team> _vectorOfMatchsHistory;

};

#endif // TEAM_H_INCLUDED
