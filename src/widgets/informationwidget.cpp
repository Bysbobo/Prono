#include "widgets/informationwidget.h"

InformationWidget::InformationWidget(QWidget *parent) : QWidget(parent)
{
    apTitleLabel = new QLabel();
    apMainLayout = new QGridLayout();
}

InformationWidget::InformationWidget(const League &league, QWidget *parent) : QWidget(parent)
{
    // Create the title
    apTitleLabel = new QLabel(league.getName());
    QFont font = apTitleLabel->font();
    font.setBold(true);
    font.setPointSize(18);
    apTitleLabel->setFont(font);
    apTitleLabel->setAlignment(Qt::AlignCenter);

    // Create the main layout of the widget
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apTitleLabel, 0, 0, Qt::AlignTop);

    setLayout(apMainLayout);
}

InformationWidget::InformationWidget(const Team &team, QWidget *parent) : QWidget(parent)
{
    // Create the title
    apTitleLabel = new QLabel(team.getFullName().append(" (").append(team.getShortName()).append(')'));
    QFont font = apTitleLabel->font();
    font.setBold(true);
    font.setPointSize(18);
    apTitleLabel->setFont(font);
    apTitleLabel->setAlignment(Qt::AlignCenter);

    // Create the main layout of the widget
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apTitleLabel, 0, 0, Qt::AlignTop);

    setLayout(apMainLayout);
}

InformationWidget::InformationWidget(const Match &match, QWidget *parent) : QWidget(parent)
{
    // Create the title
    apTitleLabel = new QLabel(match.getHomeTeam().append("\t-\t").append(match.getAwayTeam()));
    QFont font = apTitleLabel->font();
    font.setBold(true);
    font.setPointSize(18);
    apTitleLabel->setFont(font);
    apTitleLabel->setAlignment(Qt::AlignCenter);

    // Create the main layout of the widget
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apTitleLabel, 0, 0, Qt::AlignTop);

    setLayout(apMainLayout);
}

InformationWidget::~InformationWidget()
{
    delete apTitleLabel;
    delete apMainLayout;
}
