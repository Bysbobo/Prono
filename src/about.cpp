#include "about.h"
#include <QDate>

About::About(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("About"));

    // Create the labels
    apAppName = new QLabel(tr("Prono"));
    QFont appNameFont;
    appNameFont.setBold(true);
    apAppName->setFont(appNameFont);
    apBuiltOn = new QLabel(tr("Built on %1T%2").arg(__DATE__).arg(__TIME__));
    apCopyright = new QLabel(tr("Copyright 2017 P. BOIX and E. MOUSSY. All rights reserved."));
    apLaw = new QLabel(tr("The program is provided AS IS with NO WARRANTY OF ANY KIND,\n"
                        "INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS\n"
                        "FOR A PARTICULAR PURPOSE."));

    // Create the close button
    apCloseBtn = new QPushButton(tr("Close"));
    QObject::connect(apCloseBtn, SIGNAL(clicked(bool)), this, SLOT(hide()));

    // Create and set the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apAppName, 0,0);
    apMainLayout->addWidget(apBuiltOn, 1,0);
    apMainLayout->addWidget(apCopyright, 2,0);
    apMainLayout->addWidget(apLaw, 3,0);
    apMainLayout->addWidget(apCloseBtn, 4, 0, Qt::AlignRight);
    setLayout(apMainLayout);
}
