#ifndef RANKINGTABLEVIEW_H
#define RANKINGTABLEVIEW_H

#include <QTableView>
#include <QVector>

#include "team.h"
#include "match.h"

/**
 * @brief The RankingTableView class implements the table view of the rankings for a league.
 */
class RankingTableView : public QTableView
{
    Q_OBJECT

public:
    /**
     * @brief The constructor of RankingTableView class.
     * @param parent : The parent widget.
     */
    explicit RankingTableView(const QVector<Team>& teams, const QVector<Match>& matches, QWidget * parent = 0);

private:
    /**
     * @brief aTeams : The vector of teams of the league.
     */
    QVector<Team> aTeams;
    /**
     * @brief aMatches : The vector of matches of the league.
     */
    QVector<Match> aMatches;
};

#endif // RANKINGTABLEVIEW_H
