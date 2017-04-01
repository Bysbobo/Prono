#ifndef EQUIPE_H_INCLUDED
#define EQUIPE_H_INCLUDED

#include <vector>

#include "Variables.hpp"

class Equipe
{
public:

    Equipe();
    Equipe(std::string name, std::string shortName);

    std::string getName() const;
    std::string getShortName() const;
    int getRanking() const;
    int getPointNbRanking() const;
    std::vector<Equipe> getMatchsHistory() const;

    void addPointsForRanking(int points);

private:
    std::string _name;
    std::string _shortName;
    int _ranking; // Creer un objet ranking avec toutes les stats serait pas du luxe
    int _rankingPointNb; // Va de pair avec au dessus...
    std::vector<Equipe> _vectorOfMatchsHistory;

};

#endif // EQUIPE_H_INCLUDED
