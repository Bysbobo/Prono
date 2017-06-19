#ifndef MATCH_H
#define MATCH_H

#include <QString>

class Match
{
public:
    Match() : aPlayed(false) {}
    Match(const QString &homeTeam, const QString &awayTeam);
    Match(const QString &homeTeam, const QString &awayTeam, unsigned int homeScore, unsigned int awayScore);

    inline bool isGamePlayed() const { return aPlayed; }
    inline void setGamePlayed(bool played=true) { aPlayed = played; }

    bool doesHomeTeamWin();
    bool doesAwayTeamWin();
    bool isADraw();

private:
    bool aPlayed;
    QString aHomeTeam;
    QString aAwayTeam;

    unsigned int aHomeScore;
    unsigned int aAwayScore;
};

#endif // MATCH_H
