#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <vector>

#include "Variables.hpp"

class Team
{
public:

    Team();
    Team(std::string name, std::string shortName);

    void addPointsForRanking(int points);
    void update();
    void updateRanking(unsigned int rankIndicator);
    void updateMatchCounter();
    void updateGoals(unsigned int nbMarkedGoals, unsigned int nbTakenGoals);

    bool operator< (const Team& other) const;

    std::string getName() const;
    std::string getShortName() const;
    unsigned int getRanking() const;
    unsigned int getPointNbRanking() const;
    unsigned int getPlayedGameNumber() const;
    unsigned int getMarkedGoals() const;
    unsigned int getTakenGoals() const;
    int getGoalAverage() const;
    std::vector<Team> getMatchsHistory() const;

private:
    std::string _name;
    std::string _shortName;

    int _ranking;
    int _rankingPointNb;
    unsigned int _playedGameNumber;
    unsigned int _markedGoals;
    unsigned int _takenGoals;
    int _goalAverage;

    std::vector<Team> _vectorOfMatchsHistory;

};

#endif // TEAM_H_INCLUDED
