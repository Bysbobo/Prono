#include "mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window properties
    setWindowTitle(tr("Prono"));
    setMinimumWidth(800);
    setMinimumHeight(600);

    // Create the menus and their repective actions
    createActions();
    createMenus();

    // Create the central widget
    apCentralWdg = new CentralWidget();
    setCentralWidget(apCentralWdg);

    // Create the about widget
    apAboutWdg = new About();

    // Show the status bar
    statusBar()->showMessage(tr("Ready"), 2000);
}

MainWindow::~MainWindow()
{
    // File actions
    delete apOpenAction;
    delete apSaveAction;
    delete apSaveAsAction;
    delete apExitAction;

    // League actions
    delete apAddLeagueAction;
    delete apEditLeagueAction;
    delete apDeleteLeagueAction;

    // Team actions
    delete apAddTeamAction;
    delete apEditTeamAction;
    delete apDeleteTeamAction;

    // Match actions
    delete apAddMatchAction;
    delete apEditMatchAction;
    delete apDeleteMatchAction;

    // Help action
    delete apAboutAction;
    delete apAboutWdg;

    // Menus
    delete apFileMenu;
    delete apLeagueMenu;
    delete apTeamMenu;
    delete apMatchMenu;
    delete apHelpMenu;
}

void MainWindow::createActions()
{
    // File Menu Actions
    apOpenAction = new QAction(tr("Open..."));
    apOpenAction->setStatusTip(tr("Load a new file"));
    apOpenAction->setShortcut(QKeySequence::Open);
    QObject::connect(apOpenAction, SIGNAL(triggered(bool)), this, SLOT(open()));

    apSaveAction = new QAction(tr("Save"));
    apSaveAction->setStatusTip(tr("Save file"));
    apSaveAction->setShortcut(QKeySequence::Save);
    QObject::connect(apSaveAction, SIGNAL(triggered(bool)), this, SLOT(save()));

    apSaveAsAction = new QAction(tr("Save As..."));
    apSaveAsAction->setStatusTip(tr("Save file to another location/name"));
    apSaveAsAction->setShortcut(QKeySequence::SaveAs);
    QObject::connect(apSaveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));

    apExitAction = new QAction(tr("Exit"));
    apExitAction->setStatusTip(tr("Exit the application"));
    apExitAction->setShortcut(QKeySequence::Quit);
    QObject::connect(apExitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));

    // League Menu Actions
    apAddLeagueAction = new QAction(tr("Add League..."));
    apAddLeagueAction->setStatusTip(tr("Create a new league"));
    QObject::connect(apAddLeagueAction, SIGNAL(triggered(bool)), this, SLOT(addLeague()));

    apEditLeagueAction = new QAction(tr("Edit League..."));
    apEditLeagueAction->setStatusTip(tr("Edit an existing league"));
    QObject::connect(apEditLeagueAction, SIGNAL(triggered(bool)), this, SLOT(editLeague()));

    apDeleteLeagueAction = new QAction(tr("Delete League..."));
    apDeleteLeagueAction->setStatusTip(tr("Delete an existing league"));
    QObject::connect(apDeleteLeagueAction, SIGNAL(triggered(bool)), this, SLOT(deleteLeague()));

    // Team actions
    apAddTeamAction = new QAction(tr("Add Team..."));
    apAddTeamAction->setStatusTip(tr("Create a new team"));
    QObject::connect(apAddTeamAction, SIGNAL(triggered(bool)), this, SLOT(addTeam()));

    apEditTeamAction = new QAction(tr("Edit Team..."));
    apEditTeamAction->setStatusTip(tr("Edit an existing team"));
    QObject::connect(apEditTeamAction, SIGNAL(triggered(bool)), this, SLOT(editTeam()));

    apDeleteTeamAction = new QAction(tr("Delete Team..."));
    apDeleteTeamAction->setStatusTip(tr("Delete an existing team"));
    QObject::connect(apDeleteTeamAction, SIGNAL(triggered(bool)), this, SLOT(deleteTeam()));

    // Match actions
    apAddMatchAction = new QAction(tr("Add Match..."));
    apAddMatchAction->setStatusTip(tr("Create a new match"));
    QObject::connect(apAddMatchAction, SIGNAL(triggered(bool)), this, SLOT(addMatch()));

    apEditMatchAction = new QAction(tr("Edit Match..."));
    apEditMatchAction->setStatusTip(tr("Edit an existing match"));
    QObject::connect(apEditMatchAction, SIGNAL(triggered(bool)), this, SLOT(editMatch()));

    apDeleteMatchAction = new QAction(tr("Delete Match..."));
    apDeleteMatchAction->setStatusTip(tr("Delete an existing match"));
    QObject::connect(apDeleteMatchAction, SIGNAL(triggered(bool)), this, SLOT(deleteMatch()));

    // Help action
    apAboutAction = new QAction(tr("About..."));
    apAboutAction->setStatusTip(tr("About Prono application"));
    QObject::connect(apAboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));
}

void MainWindow::createMenus()
{
    // File Menu
    apFileMenu = menuBar()->addMenu(tr("File"));
    apFileMenu->addAction(apOpenAction);
    apFileMenu->addSeparator();
    apFileMenu->addAction(apSaveAction);
    apFileMenu->addAction(apSaveAsAction);
    apFileMenu->addSeparator();
    apFileMenu->addAction(apExitAction);

    // League Menu
    apLeagueMenu = menuBar()->addMenu(tr("League"));
    apLeagueMenu->addAction(apAddLeagueAction);
    apLeagueMenu->addAction(apEditLeagueAction);
    apLeagueMenu->addAction(apDeleteLeagueAction);

    // Team Menu
    apTeamMenu = menuBar()->addMenu(tr("Team"));
    apTeamMenu->addAction(apAddTeamAction);
    apTeamMenu->addAction(apEditTeamAction);
    apTeamMenu->addAction(apDeleteTeamAction);

    // Match Menu
    apMatchMenu = menuBar()->addMenu(tr("Match"));
    apMatchMenu->addAction(apAddMatchAction);
    apMatchMenu->addAction(apEditMatchAction);
    apMatchMenu->addAction(apDeleteMatchAction);

    // Help Menu
    apHelpMenu = menuBar()->addMenu(tr("Help"));
    apHelpMenu->addAction(apAboutAction);
}

void MainWindow::open()
{

}

void MainWindow::save()
{

}

void MainWindow::saveAs()
{

}

void MainWindow::addLeague()
{

}

void MainWindow::editLeague()
{

}

void MainWindow::deleteLeague()
{

}

void MainWindow::addTeam()
{

}

void MainWindow::editTeam()
{

}

void MainWindow::deleteTeam()
{

}

void MainWindow::addMatch()
{

}

void MainWindow::editMatch()
{

}

void MainWindow::deleteMatch()
{

}

void MainWindow::about()
{
    apAboutWdg->show();
}
