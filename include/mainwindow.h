#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QScrollArea>
#include <QDockWidget>
#include "about.h"
#include "dockwidget.h"
#include "centralwidget.h"

/**
 * @brief The MainWindow class defines the main window of the Prono application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief The constructor of the Main window.
     * @param parent : The parent of the main window widget.
     */
    MainWindow(QWidget *parent = 0);
    /**
     * @brief The destructor of the main window widget.
     */
    ~MainWindow();

private slots:
    // File Menu Actions
    /**
     * @brief This slot is used to open a file when the open action is clicked.
     */
    void open();
    /**
     * @brief This slot is used to save a file when the save action is clicked.
     */
    void save();
    /**
     * @brief This slot is used to save as a file when the save as action is clicked.
     */
    void saveAs();
    /**
     * @brief This slot is used to exit the application when the exit action is clicked.
     */
    void exit() { QApplication::quit(); }

    // League Menu Actions
    /**
     * @brief This slot is used to add a league when the add league action is clicked.
     */
    void addLeague();
    /**
     * @brief This slot is used to edit a league when the edit league action is clicked.
     */
    void editLeague();
    /**
     * @brief This slot is used to delete a league when the delete league action is clicked.
     */
    void deleteLeague();

    // Team Menu Actions
    /**
     * @brief This slot is used to add a team when the add team action is clicked.
     */
    void addTeam();
    /**
     * @brief This slot is used to edit a team when the edit team action is clicked.
     */
    void editTeam();
    /**
     * @brief This slot is used to delete a team when the delete team action is clicked.
     */
    void deleteTeam();

    // Match Menu Actions
    /**
     * @brief This slot is used to add a match when the add match action is clicked.
     */
    void addMatch();
    /**
     * @brief This slot is used to edit a match when the edit match action is clicked.
     */
    void editMatch();
    /**
     * @brief This slot is used to delete a match when the delete match action is clicked.
     */
    void deleteMatch();

    // Help Menu Action
    /**
     * @brief This slot is used to show the about widget when the about action is clicked.
     */
    void about();

private:
    /**
     * @brief This method creates the actions. It should be called before the createMenus() method.
     */
    void createActions();
    /**
     * @brief This method creates the menus. It should be called after the createActions() method.
     */
    void createMenus();

    // Menus
    /**
     * @brief m_fileMenu : The file menu.
     */
    QMenu *m_fileMenu;
    /**
     * @brief m_leagueMenu : The league menu.
     */
    QMenu *m_leagueMenu;
    /**
     * @brief m_teamMenu : The team menu.
     */
    QMenu *m_teamMenu;
    /**
     * @brief m_matchMenu : The match menu.
     */
    QMenu *m_matchMenu;
    /**
     * @brief m_helpMenu : The help menu.
     */
    QMenu *m_helpMenu;

    // File actions
    /**
     * @brief m_openAction : The open action.
     */
    QAction *m_openAction;
    /**
     * @brief m_saveAction : The save action.
     */
    QAction *m_saveAction;
    /**
     * @brief m_saveAsAction : The save as action.
     */
    QAction *m_saveAsAction;
    /**
     * @brief m_exitAction : The exit action.
     */
    QAction *m_exitAction;

    // League actions
    /**
     * @brief m_addLeagueAction : The add league action.
     */
    QAction *m_addLeagueAction;
    /**
     * @brief m_editLeagueAction : The edit league action.
     */
    QAction *m_editLeagueAction;
    /**
     * @brief m_deleteLeagueAction : The delete league action.
     */
    QAction *m_deleteLeagueAction;

    // Team actions
    /**
     * @brief m_addTeamAction : The add team action.
     */
    QAction *m_addTeamAction;
    /**
     * @brief m_editTeamAction : The edit team action.
     */
    QAction *m_editTeamAction;
    /**
     * @brief m_deleteTeamAction : The delete team action.
     */
    QAction *m_deleteTeamAction;

    // Match actions
    /**
     * @brief m_addMatchAction : The add match action.
     */
    QAction *m_addMatchAction;
    /**
     * @brief m_editMatchAction : The edit match action.
     */
    QAction *m_editMatchAction;
    /**
     * @brief m_deleteMatchAction : The delete match action.
     */
    QAction *m_deleteMatchAction;

    // Help action
    /**
     * @brief m_aboutAction : The about action.
     */
    QAction *m_aboutAction;

    /**
     * @brief m_aboutWdg : The about widget that is shown when the about action is clicked.
     */
    About *m_aboutWdg;

    // Central Widget
    /**
     * @brief m_centralWdg : The central widget of the main window.
     */
    CentralWidget *m_centralWdg;
};

#endif // MAINWINDOW_H
