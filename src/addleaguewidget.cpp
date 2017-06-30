#include "addleaguewidget.h"
#include <QMessageBox>

AddLeagueWidget::AddLeagueWidget(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("Create League"));

    // Create the name label and line edit
    apNameLabel = new QLabel(tr("Name :"));
    apNameLE = new QLineEdit();

    // Create the buttons
    apCreateBtn = new QPushButton(tr("Create"));
    connect(apCreateBtn, SIGNAL(pressed()), this, SLOT(createBtnPressed()));
    apCancelBtn = new QPushButton(tr("Cancel"));
    connect(apCancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    // Create the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apNameLabel, 0, 0);
    apMainLayout->addWidget(apNameLE, 0, 1, 1, 2);
    apMainLayout->addWidget(apCancelBtn, 1, 1, 1, 1, Qt::AlignRight);
    apMainLayout->addWidget(apCreateBtn, 1, 2, 1, 1, Qt::AlignRight);
    setLayout(apMainLayout);
}

AddLeagueWidget::~AddLeagueWidget()
{
    delete apMainLayout;
    delete apNameLabel;
    delete apNameLE;
    delete apCreateBtn;
    delete apCancelBtn;
}

void AddLeagueWidget::createBtnPressed()
{
    if (!apNameLE->text().isEmpty())
    {
        emit leagueToBeCreated(apNameLE->text());
        close();
    } else {
        QMessageBox::critical(this, tr("Error creating a league"), tr("Please fill the name of the league."), QMessageBox::Ok);
    }
}
