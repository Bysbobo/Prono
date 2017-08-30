#include "widgets/addteamwidget.h"
#include <QMessageBox>

AddTeamWidget::AddTeamWidget(QVector<League> leagues, QWidget *parent) : QWidget(parent)
{
    Q_ASSERT(leagues.size() > 0);

    // Set the window title
    setWindowTitle(tr("Create Team"));

    // Create the names labels and line edits
    apFullNameLabel = new QLabel(tr("Full Name :"));
    apFullNameLE = new QLineEdit();
    apShortNameLabel = new QLabel(tr("Short Name :"));
    apShortNameLE = new QLineEdit();

    // Create the leagues list and label
    apLeaguesLabel = new QLabel(tr("Leagues : "));
    apLeaguesListWidget = new QListWidget();
    apLeaguesListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Fill the leagues list
    const int size = leagues.size();
    for (int i = 0; i < size; ++i)
        new QListWidgetItem(leagues.at(i).getName(), apLeaguesListWidget);

    // Create the buttons
    apCreateBtn = new QPushButton(tr("Create"));
    connect(apCreateBtn, SIGNAL(pressed()), this, SLOT(createBtnPressed()));
    apCancelBtn = new QPushButton(tr("Cancel"));
    connect(apCancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    // Create the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apFullNameLabel, 0, 0);
    apMainLayout->addWidget(apFullNameLE, 0, 1, 1, 2);
    apMainLayout->addWidget(apShortNameLabel, 1, 0);
    apMainLayout->addWidget(apShortNameLE, 1, 1, 1, 2);
    apMainLayout->addWidget(apLeaguesLabel, 2, 0);
    apMainLayout->addWidget(apLeaguesListWidget, 3, 0, 1, 3);
    apMainLayout->addWidget(apCancelBtn, 4, 1, 1, 1, Qt::AlignRight);
    apMainLayout->addWidget(apCreateBtn, 4, 2, 1, 1, Qt::AlignRight);
    setLayout(apMainLayout);
}

AddTeamWidget::~AddTeamWidget()
{
    delete apFullNameLabel;
    delete apFullNameLE;
    delete apShortNameLabel;
    delete apShortNameLE;
    delete apCreateBtn;
    delete apCancelBtn;
    delete apMainLayout;
    delete apLeaguesLabel;
    const int size = apLeaguesListWidget->count();
    for (int i = size-1; i >= 0; --i)
    {
        delete apLeaguesListWidget->item(i);
    }
    delete apLeaguesListWidget;
}

void AddTeamWidget::createBtnPressed()
{
    if (!apShortNameLE->text().isEmpty())
    {
        if (!apFullNameLE->text().isEmpty())
        {
            if (!apLeaguesListWidget->selectedItems().isEmpty())
            {
                // Retrive the leagues names
                const QList<QListWidgetItem *> leagues = apLeaguesListWidget->selectedItems();
                QVector<QString> names;
                const int size = leagues.size();
                for (int i = 0; i < size; ++i)
                    names.push_back(leagues.at(i)->text());

                emit teamToBeCreated(apShortNameLE->text(), apFullNameLE->text(), names);
                close();
            } else
                QMessageBox::critical(this, tr("Error creating the Team"), tr("Please select the leagues in which the team will be."), QMessageBox::Ok);
        } else
            QMessageBox::critical(this, tr("Error creating the Team"), tr("Please fill the full name of the team."), QMessageBox::Ok);
    } else
        QMessageBox::critical(this, tr("Error creating the league"), tr("Please fill the short name of the team."), QMessageBox::Ok);
}
