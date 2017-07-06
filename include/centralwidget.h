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
    /**
     * @brief A getter to the vector of leagues.
     * @return A QVector containing the leagues.
     */
    QVector<League> getLeagues() const { return aLeagues; }

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
    /**
     * @brief This slot creates a new league.
     * @param name : The name of the new league to be created.
     */
    void createLeague(const QString &name);
    /**
     * @brief This slot creates a new team.
     * @param shortName : The short name of the team to be created.
     * @param fullName : The full name of the team to be created.
     * @param lNames : The list of leagues names in which the team to be created will be.
     */
    void createTeam(const QString& shortName, const QString& fullName, const QVector<QString> lNames);

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
