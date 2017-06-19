#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "treemodel.h"

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

private:
    // The tree widgets
    /**
     * @brief m_leagueModel : The tree model of the leagues.
     */
    TreeModel *m_leagueModel;
    /**
     * @brief m_teamModel : The tree model of the teams.
     */
    TreeModel *m_teamModel;
    /**
     * @brief m_matchModel : The tree model of the matches.
     */
    TreeModel *m_matchModel;

    /**
     * @brief m_leagueView : The view of the tree model of the leagues.
     */
    QTreeView *m_leagueView;
    /**
     * @brief m_teamView : The view of the tree model of the teams.
     */
    QTreeView *m_teamView;
    /**
     * @brief m_matchView : The view of the tree model of the matches.
     */
    QTreeView *m_matchView;
    /**
     * @brief m_treeViewLayout : The layout of the trees views.
     */
    QVBoxLayout *m_treeViewLayout;

    /**
     * @brief m_mainLayout : The main layout of the widget.
     */
    QHBoxLayout *m_mainLayout;
};

#endif // CENTRALWIDGET_H
