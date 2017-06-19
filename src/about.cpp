#include "about.h"
#include <QDate>

About::About(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("About"));

    // Create the labels
    m_appName = new QLabel(tr("Prono"));
    QFont appNameFont;
    appNameFont.setBold(true);
    m_appName->setFont(appNameFont);
    m_builtOn = new QLabel(tr("Built on %1T%2").arg(__DATE__).arg(__TIME__));
    m_copyright = new QLabel(tr("Copyright 2017 P. BOIX and E. MOUSSY. All rights reserved."));
    m_law = new QLabel(tr("The program is provided AS IS with NO WARRANTY OF ANY KIND,\n"
                        "INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS\n"
                        "FOR A PARTICULAR PURPOSE."));

    // Create the close button
    m_closeBtn = new QPushButton(tr("Close"));
    QObject::connect(m_closeBtn, SIGNAL(clicked(bool)), this, SLOT(hide()));

    // Create and set the main layout
    m_mainLayout = new QGridLayout();
    m_mainLayout->addWidget(m_appName, 0,0);
    m_mainLayout->addWidget(m_builtOn, 1,0);
    m_mainLayout->addWidget(m_copyright, 2,0);
    m_mainLayout->addWidget(m_law, 3,0);
    m_mainLayout->addWidget(m_closeBtn, 4, 0, Qt::AlignRight);
    setLayout(m_mainLayout);
}
