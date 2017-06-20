#ifndef MATCH_H
#define MATCH_H

#include <QString>

class Match
{
public:
    /**
     * @brief The default constructor.
     */
    Match() : aPlayed(false) {}
    /**
     * @brief A constructor that initialise the name of the home team and the away team.
     * @param homeTeam : The short name of the home team.
     * @param awayTeam : The short name of the away team.
     */
    Match(const QString &homeTeam, const QString &awayTeam);
    /**
     * @brief A constructor that initialise the name of the home team and the away team and the score if the game has been played.
     * @param homeTeam : The short name of the home team.
     * @param awayTeam : The short name of the away team.
     * @param homeScore : The score of the home team.
     * @param awayScore : The score of the away team.
     */
    Match(const QString &homeTeam, const QString &awayTeam, unsigned int homeScore, unsigned int awayScore);

    /**
     * @brief This method indicates whether the game has been played or not.
     * @return True if the gams has been played, false otherwise.
     */
    inline bool isGamePlayed() const { return aPlayed; }
    /**
     * @brief This method set the game as played or not played.
     * @param played : The given status of the game. By default this argument is set to true.
     */
    inline void setGamePlayed(bool played=true) { aPlayed = played; }

    /**
     * @brief This method indicates whether the home team won or not.
     * @return True if the home team won, false otherwise.
     */
    bool doesHomeTeamWin();
    /**
     * @brief This method indicates whether the away team won or not.
     * @return True if the away team won, false otherwise.
     */
    bool doesAwayTeamWin();
    /**
     * @brief This method indicates whether the game ended in a draw or not.
     * @return True if the game ended in a draw, false otherwise.
     */
    bool isADraw();

private:
    /**
     * @brief aPlayed : Indicates whether the game has been played or not.
     */
    bool aPlayed;
    /**
     * @brief aHomeTeam : The short name of the home team.
     */
    QString aHomeTeam;
    /**
     * @brief aAwayTeam : The short name of the away team.
     */
    QString aAwayTeam;

    /**
     * @brief aHomeScore : The score of the home team.
     */
    unsigned int aHomeScore;
    /**
     * @brief aAwayScore : The score of the away team.
     */
    unsigned int aAwayScore;
};

#endif // MATCH_H
