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
     * @brief A constructor that initialise the name of the home team and the away team, the forfeit of one of the teams and
     * the team which is forfeited.
     * @param season : The season of the match.
     * @param day : The day number of the match.
     * @param homeTeam : The short name of the home team.
     * @param awayTeam : The short name of the away team.
     * @param forfeit : The status of the match.
     * @param teamForfeited : The team which is forfeited.
     */
    Match(const QString& season, uint8_t day, const QString &homeTeam, const QString &awayTeam, bool forfeit, const QString &teamForfeited);
    /**
     * @brief A constructor that initialise the name of the home team and the away team and the score if the game has been played.
     * @param season : The season of the match.
     * @param day : The day number of the match.
     * @param homeTeam : The short name of the home team.
     * @param awayTeam : The short name of the away team.
     * @param homeScore : The score of the home team.
     * @param awayScore : The score of the away team.
     */
    Match(const QString& season, uint8_t day, const QString &homeTeam, const QString &awayTeam, unsigned int homeScore, unsigned int awayScore);

    /**
     * @brief A getter to the ID of the match.
     * @return The ID of the match.
     */
    inline QString getID() const { return aID; }
    /**
     * @brief A getter to the season of the match.
     * @return The season of the match.
     */
    inline QString getSeason() const { return aSeason; }
    /**
     * @brief A setter to the season.
     * @param season : The season of the match.
     */
    inline void setSeason(const QString& season) { aSeason = season; }
    /**
     * @brief This method indicates whether the game has been played or not.
     * @return True if the game has been played, false otherwise.
     */
    inline bool isGamePlayed() const { return aPlayed; }
    /**
     * @brief This method indicates whether one team has been penalized.
     * @return True if the game has been stopped, false otherwise.
     */
    inline bool isGameForfeited() const { return aForfeit; }
    /**
     * @brief This method set the game as played or not played.
     * @param played : The given status of the game. By default this argument is set to true.
     */
    inline void setGamePlayed(bool played=true) { aPlayed = played; }
    /**
     * @brief A getter to the home team name.
     * @return A Qstring of the home team name.
     */
    inline QString getHomeTeam() const { return aHomeTeam; }
    /**
     * @brief A getter to the away team name.
     * @return A Qstring of the away team name.
     */
    inline QString getAwayTeam() const { return aAwayTeam; }
    /**
     * @brief A getter to the team forfeited.
     * @return A QString of the team forfeited
     */
    inline QString getForfeitTeam() const { return ( aForfeit ? aForfeitTeam : NULL ); }
    /**
     * @brief A getter to the home team score.
     * @return An unsigned int of the home team score.
     */
    inline unsigned int getHomeTeamScore() const { Q_ASSERT(aPlayed); return aHomeScore; }
    /**
     * @brief A getter to the away team score.
     * @return An unsigned int of the away team score.
     */
    inline unsigned int getAwayTeamScore() const { Q_ASSERT(aPlayed); return aAwayScore; }

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
    /**
     * @brief This method returns the way the match should be shown in the tree.
     * @return A QString of the way the match is shown in the tree.
     */
    QString shownLine() const;

private:
    /**
     * @brief aID : A unique ID.
     */
    QString aID;
    /**
     * @brief aSeason : The season of the match. Example : "2016-2017".
     */
    QString aSeason;
    /**
     * @brief aPlayed : Indicates whether the game has been played or not.
     */
    bool aPlayed;
    /**
     * @brief aForfeit : Indicates whether one team has been penalized.
     */
    bool aForfeit;
    /**
     * @brief aDay : The day number of the match.
     */
    uint8_t aDay;

    /**
     * @brief aHomeTeam : The short name of the home team.
     */
    QString aHomeTeam;
    /**
     * @brief aAwayTeam : The short name of the away team.
     */
    QString aAwayTeam;
    /**
     * @brief aForfeitTeam : The name of the team which has been penalized
     */
    QString aForfeitTeam;

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
