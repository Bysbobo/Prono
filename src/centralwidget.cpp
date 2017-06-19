#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    // Create the trees models
    apLeagueModel = new TreeModel(tr("Leagues"), tr("League 1"));
    apTeamModel = new TreeModel(tr("Teams"), tr("PSG\nLYO"));
    apMatchModel = new TreeModel(tr("Matches"), tr("PSG - LYO"));

    // Create the trees view
    apLeagueView = new QTreeView();
    apLeagueView->setModel(apLeagueModel);
    apTeamView = new QTreeView();
    apTeamView->setModel(apTeamModel);
    apMatchView = new QTreeView();
    apMatchView->setModel(apMatchModel);

    // Create the main layout
    apTreeViewLayout = new QVBoxLayout();
    apTreeViewLayout->addWidget(apLeagueView);
    apTreeViewLayout->addWidget(apTeamView);
    apTreeViewLayout->addWidget(apMatchView);

    apMainLayout = new QHBoxLayout();
    apMainLayout->addLayout(apTreeViewLayout);
    apMainLayout->addStretch();
    apMainLayout->addStretch();
    apMainLayout->addStretch();
    setLayout(apMainLayout);
}
