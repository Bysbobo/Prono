#include "widgets/rankingtableview.h"

RankingTableView::RankingTableView(const QVector<Team>& teams, const QVector<Match>& matches, QWidget *parent) :
    QTableView(parent),
    aTeams(teams),
    aMatches(matches)
{
}
