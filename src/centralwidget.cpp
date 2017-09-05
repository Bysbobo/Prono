#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    // Create a league and add it to the list
    League league(tr("League 1"), tr(":/database/Infos.txt"), tr(":/database/Matches.txt"));
    aLeagues.push_back(league);

    // Create the trees models
    apLeagueModel = new TreeModel(tr("Leagues"), getListOfLeaguesForTree());
    apTeamModel = new TreeModel(tr("Teams"), tr(""));
    apMatchModel = new TreeModel(tr("Matches"), tr(""));

    // Create the trees view
    apLeagueView = new QTreeView();
    apLeagueView->setModel(apLeagueModel);
    connect(apLeagueView, SIGNAL(clicked(QModelIndex)), this, SLOT(setTeams(QModelIndex)));
    connect(apLeagueView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(updateInfoWidgetToLeague(QModelIndex)));
    apTeamView = new QTreeView();
    apTeamView->setModel(apTeamModel);
    connect(apTeamView, SIGNAL(clicked(QModelIndex)), this, SLOT(setMatches(QModelIndex)));
    connect(apTeamView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(updateInfoWidgetToTeam(QModelIndex)));
    apMatchView = new QTreeView();
    apMatchView->setModel(apMatchModel);
    connect(apMatchView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(updateInfoWidgetToMatch(QModelIndex)));

    // Create information widget
    apInfoWdg = new InformationWidget();

    // Create the main layout
    apTreeViewLayout = new QVBoxLayout();
    apTreeViewLayout->addWidget(apLeagueView);
    apTreeViewLayout->addWidget(apTeamView);
    apTreeViewLayout->addWidget(apMatchView);

    apMainLayout = new QHBoxLayout();
    apMainLayout->addLayout(apTreeViewLayout, 1);
    apMainLayout->addWidget(apInfoWdg, 3);
    setLayout(apMainLayout);
}

void CentralWidget::setTeams(const QModelIndex &index)
{
    const QString leagueName = apLeagueModel->data(index, Qt::DisplayRole).toString();
    const int size = aLeagues.size();
    for (int i = 0; i < size; ++i)
    {
        if (aLeagues[i].getName() == leagueName)
        {
            // Update the team tree model
            TreeModel* oldTeamModel = apTeamModel;
            apTeamModel = new TreeModel(tr("Teams"), aLeagues[i].getListOfTeamsForTree());
            apTeamView->setModel(apTeamModel);
            delete oldTeamModel;

            // Reset the team  tree model
            TreeModel* oldMatchModel = apMatchModel;
            apMatchModel = new TreeModel(tr("Matches"), tr(""));
            apMatchView->setModel(apMatchModel);
            delete oldMatchModel;
            return;
        }
    }
}

void CentralWidget::setMatches(const QModelIndex &index)
{
    const QString leagueName = apLeagueModel->data(apLeagueView->currentIndex(), Qt::DisplayRole).toString();
    const int size = aLeagues.size();
    for (int i = 0; i < size; ++i)
    {
        if (aLeagues[i].getName() == leagueName)
        {
            // Update the match tree model
            TreeModel* oldMatchModel = apMatchModel;
            const QString teamName = apTeamModel->data(index, Qt::DisplayRole).toString().split(tr(" ")).at(0);
            const int teamIndex = aLeagues[i].getTeamIndex(teamName);
            apMatchModel = new TreeModel(tr("Matches"), aLeagues[i].getVectorOfTeams()
                                         .at(teamIndex)
                                         .getListOfMatchesForTree());
            apMatchView->setModel(apMatchModel);
            delete oldMatchModel;
            return;
        }
    }
}

void CentralWidget::createLeague(const QString &name)
{
    // Create the new league and add it to the vector
    League l;
    l.setName(name);
    aLeagues.push_back(l);

    // Refresh the league model
    TreeModel *oldModel = apLeagueModel;
    apLeagueModel = new TreeModel(tr("Leagues"), getListOfLeaguesForTree());
    apLeagueView->setModel(apLeagueModel);
    delete oldModel;
}

void CentralWidget::createTeam(const QString &shortName, const QString &fullName, const QVector<QString> lNames)
{
    // Create the new team and add it to the leagues
    Team t(fullName, shortName);
    const int size = lNames.size();
    for (int i = 0; i < size; ++i)
    {
        int j = 0;
        const int lSize = aLeagues.size();
        bool found = false;
        while (j < lSize && !found) {
            if (lNames.at(i) == aLeagues.at(j).getName())
            {
                aLeagues[j].getVectorOfTeams().push_back(t);
                found = true;
            }
            ++j;
        }
    }

    // Refresh the team model
    if (lNames.contains(apLeagueModel->data(apLeagueView->currentIndex(), Qt::DisplayRole).toString()))
    {
        const QModelIndex selectedIndex = apTeamView->currentIndex();
        setTeams(apLeagueView->currentIndex());
        apTeamView->setCurrentIndex(selectedIndex);
    }
}

void CentralWidget::updateInfoWidgetToLeague(const QModelIndex &index)
{
    Q_UNUSED(index)
    const QString leagueName = apLeagueModel->data(apLeagueView->currentIndex(), Qt::DisplayRole).toString();
    const int size = aLeagues.size();
    for (int i = 0; i < size; ++i)
    {
        if (aLeagues[i].getName() == leagueName)
        {
            // Refresh the info widget
            QWidget *old = apInfoWdg;
            apInfoWdg = new InformationWidget(aLeagues[i]);
            apMainLayout->removeItem(apMainLayout->itemAt(apMainLayout->indexOf(old)));
            apMainLayout->addWidget(apInfoWdg, 3);
            delete old;
            return;
        }
    }
}

void CentralWidget::updateInfoWidgetToTeam(const QModelIndex &index)
{
    const QString leagueName = apLeagueModel->data(apLeagueView->currentIndex(), Qt::DisplayRole).toString();
    const int size = aLeagues.size();
    for (int i = 0; i < size; ++i)
    {
        if (aLeagues[i].getName() == leagueName)
        {
            const QString teamName = apTeamModel->data(index, Qt::DisplayRole).toString().split(tr(" ")).at(0);
            // Refresh the info widget
            QWidget *old = apInfoWdg;
            apInfoWdg = new InformationWidget(aLeagues[i].getTeam(teamName));
            apMainLayout->removeItem(apMainLayout->itemAt(apMainLayout->indexOf(old)));
            apMainLayout->addWidget(apInfoWdg, 3);
            delete old;
            return;
        }
    }
}

void CentralWidget::updateInfoWidgetToMatch(const QModelIndex &index)
{
    const QString leagueName = apLeagueModel->data(apLeagueView->currentIndex(), Qt::DisplayRole).toString();
    const int size = aLeagues.size();
    for (int i = 0; i < size; ++i)
    {
        if (aLeagues[i].getName() == leagueName)
        {
            const QString teamName = apTeamModel->data(apTeamView->currentIndex(), Qt::DisplayRole).toString().split(tr(" ")).at(0);
            const QString matchString = apMatchModel->data(index, Qt::DisplayRole).toString();
            const QVector<Match>& matches = aLeagues[i].getTeam(teamName).getMatches();
            const int size1 = matches.size();
            for (int j = 0; j < size1; ++j)
            {
                if (matchString == matches[j].shownLine())
                {
                    // Refresh the info widget
                    QWidget *old = apInfoWdg;
                    apInfoWdg = new InformationWidget(matches[j]);
                    apMainLayout->removeItem(apMainLayout->itemAt(apMainLayout->indexOf(old)));
                    apMainLayout->addWidget(apInfoWdg, 3);
                    delete old;
                    return;
                }
            }
        }
    }
}

QString CentralWidget::getListOfLeaguesForTree() const
{
    QString ret("");
    if (aLeagues.size() > 0)
        ret.append(aLeagues.at(0).getName());
    const int size = aLeagues.size();
    for (int i = 1; i < size; ++i)
        ret.append(QString("\n")).append(aLeagues.at(i).getName());
    return ret;
}
