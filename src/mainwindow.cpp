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
    m_centralWdg = new CentralWidget();
    setCentralWidget(m_centralWdg);

    // Create the about widget
    m_aboutWdg = new About();

    // Show the status bar
    statusBar()->showMessage(tr("Ready"), 2000);
}

MainWindow::~MainWindow()
{
    // File actions
    delete m_openAction;
    delete m_saveAction;
    delete m_saveAsAction;
    delete m_exitAction;

    // League actions
    delete m_addLeagueAction;
    delete m_editLeagueAction;
    delete m_deleteLeagueAction;

    // Team actions
    delete m_addTeamAction;
    delete m_editTeamAction;
    delete m_deleteTeamAction;

    // Match actions
    delete m_addMatchAction;
    delete m_editMatchAction;
    delete m_deleteMatchAction;

    // Help action
    delete m_aboutAction;
    delete m_aboutWdg;

    // Menus
    delete m_fileMenu;
    delete m_leagueMenu;
    delete m_teamMenu;
    delete m_matchMenu;
    delete m_helpMenu;
}

void MainWindow::createActions()
{
    // File Menu Actions
    m_openAction = new QAction(tr("Open..."));
    m_openAction->setStatusTip(tr("Load a new file"));
    m_openAction->setShortcut(QKeySequence::Open);
    QObject::connect(m_openAction, SIGNAL(triggered(bool)), this, SLOT(open()));

    m_saveAction = new QAction(tr("Save"));
    m_saveAction->setStatusTip(tr("Save file"));
    m_saveAction->setShortcut(QKeySequence::Save);
    QObject::connect(m_saveAction, SIGNAL(triggered(bool)), this, SLOT(save()));

    m_saveAsAction = new QAction(tr("Save As..."));
    m_saveAsAction->setStatusTip(tr("Save file to another location/name"));
    m_saveAsAction->setShortcut(QKeySequence::SaveAs);
    QObject::connect(m_saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));

    m_exitAction = new QAction(tr("Exit"));
    m_exitAction->setStatusTip(tr("Exit the application"));
    m_exitAction->setShortcut(QKeySequence::Quit);
    QObject::connect(m_exitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));

    // League Menu Actions
    m_addLeagueAction = new QAction(tr("Add League..."));
    m_addLeagueAction->setStatusTip(tr("Create a new league"));
    QObject::connect(m_addLeagueAction, SIGNAL(triggered(bool)), this, SLOT(addLeague()));

    m_editLeagueAction = new QAction(tr("Edit League..."));
    m_editLeagueAction->setStatusTip(tr("Edit an existing league"));
    QObject::connect(m_editLeagueAction, SIGNAL(triggered(bool)), this, SLOT(editLeague()));

    m_deleteLeagueAction = new QAction(tr("Delete League..."));
    m_deleteLeagueAction->setStatusTip(tr("Delete an existing league"));
    QObject::connect(m_deleteLeagueAction, SIGNAL(triggered(bool)), this, SLOT(deleteLeague()));

    // Team actions
    m_addTeamAction = new QAction(tr("Add Team..."));
    m_addTeamAction->setStatusTip(tr("Create a new team"));
    QObject::connect(m_addTeamAction, SIGNAL(triggered(bool)), this, SLOT(addTeam()));

    m_editTeamAction = new QAction(tr("Edit Team..."));
    m_editTeamAction->setStatusTip(tr("Edit an existing team"));
    QObject::connect(m_editTeamAction, SIGNAL(triggered(bool)), this, SLOT(editTeam()));

    m_deleteTeamAction = new QAction(tr("Delete Team..."));
    m_deleteTeamAction->setStatusTip(tr("Delete an existing team"));
    QObject::connect(m_deleteTeamAction, SIGNAL(triggered(bool)), this, SLOT(deleteTeam()));

    // Match actions
    m_addMatchAction = new QAction(tr("Add Match..."));
    m_addMatchAction->setStatusTip(tr("Create a new match"));
    QObject::connect(m_addMatchAction, SIGNAL(triggered(bool)), this, SLOT(addMatch()));

    m_editMatchAction = new QAction(tr("Edit Match..."));
    m_editMatchAction->setStatusTip(tr("Edit an existing match"));
    QObject::connect(m_editMatchAction, SIGNAL(triggered(bool)), this, SLOT(editMatch()));

    m_deleteMatchAction = new QAction(tr("Delete Match..."));
    m_deleteMatchAction->setStatusTip(tr("Delete an existing match"));
    QObject::connect(m_deleteMatchAction, SIGNAL(triggered(bool)), this, SLOT(deleteMatch()));

    // Help action
    m_aboutAction = new QAction(tr("About..."));
    m_aboutAction->setStatusTip(tr("About Prono application"));
    QObject::connect(m_aboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));
}

void MainWindow::createMenus()
{
    // File Menu
    m_fileMenu = menuBar()->addMenu(tr("File"));
    m_fileMenu->addAction(m_openAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addAction(m_saveAsAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);

    // League Menu
    m_leagueMenu = menuBar()->addMenu(tr("League"));
    m_leagueMenu->addAction(m_addLeagueAction);
    m_leagueMenu->addAction(m_editLeagueAction);
    m_leagueMenu->addAction(m_deleteLeagueAction);

    // Team Menu
    m_teamMenu = menuBar()->addMenu(tr("Team"));
    m_teamMenu->addAction(m_addTeamAction);
    m_teamMenu->addAction(m_editTeamAction);
    m_teamMenu->addAction(m_deleteTeamAction);

    // Match Menu
    m_matchMenu = menuBar()->addMenu(tr("Match"));
    m_matchMenu->addAction(m_addMatchAction);
    m_matchMenu->addAction(m_editMatchAction);
    m_matchMenu->addAction(m_deleteMatchAction);

    // Help Menu
    m_helpMenu = menuBar()->addMenu(tr("Help"));
    m_helpMenu->addAction(m_aboutAction);
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
    m_aboutWdg->show();
}
