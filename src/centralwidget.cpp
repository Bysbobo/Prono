#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    // Create the trees models
    m_leagueModel = new TreeModel(tr("Leagues"), tr("League 1"));
    m_teamModel = new TreeModel(tr("Teams"), tr("PSG\nLYO"));
    m_matchModel = new TreeModel(tr("Matches"), tr("PSG - LYO"));

    // Create the trees view
    m_leagueView = new QTreeView();
    m_leagueView->setModel(m_leagueModel);
    m_teamView = new QTreeView();
    m_teamView->setModel(m_teamModel);
    m_matchView = new QTreeView();
    m_matchView->setModel(m_matchModel);

    // Create the main layout
    m_treeViewLayout = new QVBoxLayout();
    m_treeViewLayout->addWidget(m_leagueView);
    m_treeViewLayout->addWidget(m_teamView);
    m_treeViewLayout->addWidget(m_matchView);

    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addLayout(m_treeViewLayout);
    m_mainLayout->addStretch();
    m_mainLayout->addStretch();
    m_mainLayout->addStretch();
    setLayout(m_mainLayout);
}
