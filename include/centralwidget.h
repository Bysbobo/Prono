#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "treemodel.h"
#include "league.h"

/**
 * @brief The CentralWidget class implements the central widget of the main window.
 */
class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief The constructor of CentralWidget class.
     * @param parent : The widget parent of the central widget.
     */
    explicit CentralWidget(QWidget *parent = 0);

public slots:
    /**
     * @brief This slot updates the teams list in the tree view following a change of a league.
     * @param index : The index of the league.
     */
    void setTeams(const QModelIndex &index);
    /**
     * @brief This slot updates the matches list in the tree view following a change of a league.
     * @param index : The index of the league.
     */
    void setMatches(const QModelIndex &index);

private:
    /**
     * @brief This method creates a QString in which the list of the leagues is defined as they should appear in the tree view.
     * @return A QString in which the list of the leagues is defined as they should appear in the tree view.
     */
    QString getListOfLeaguesForTree() const;
    // The tree widgets
    /**
     * @brief apLeagueModel : The tree model of the leagues.
     */
    TreeModel *apLeagueModel;
    /**
     * @brief apTeamModel : The tree model of the teams.
     */
    TreeModel *apTeamModel;
    /**
     * @brief apMatchModel : The tree model of the matches.
     */
    TreeModel *apMatchModel;

    /**
     * @brief apLeagueView : The view of the tree model of the leagues.
     */
    QTreeView *apLeagueView;
    /**
     * @brief apTeamView : The view of the tree model of the teams.
     */
    QTreeView *apTeamView;
    /**
     * @brief apMatchView : The view of the tree model of the matches.
     */
    QTreeView *apMatchView;
    /**
     * @brief apTreeViewLayout : The layout of the trees views.
     */
    QVBoxLayout *apTreeViewLayout;

    // The leagues.
    /**
     * @brief aLeagues : The vector of all the leagues.
     */
    QVector<League> aLeagues;

    // The main Layout
    /**
     * @brief apMainLayout : The main layout of the widget.
     */
    QHBoxLayout *apMainLayout;
};

#endif // CENTRALWIDGET_H
