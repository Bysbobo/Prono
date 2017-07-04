#ifndef ADDTEAMWIDGET_H
#define ADDTEAMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>
#include "league.h"

class AddTeamWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructor of the AddTeamWidget class.
     * @param parent : The parent item of the widget.
     */
    explicit AddTeamWidget(QVector<League> leagues, QWidget *parent = 0);
    /**
     * @brief Destructor.
     */
    ~AddTeamWidget();

signals:
    /**
     * @brief This signal is emmitted when the create button is pressed.
     * @param shortName : The short name of the team to be created.
     * @param fullName : The full name of the team to be created.
     * @param lNames : The list of leagues names in which the team to be created will be.
     */
    void teamToBeCreated(const QString& shortName, const QString& fullName, const QVector<QString> lNames);

private slots:
    /**
     * @brief This slot emits the teamToBeCreated signal and closes the widget.
     */
    void createBtnPressed();

private:
    /**
     * @brief apMainLayout : The main layout of the widget.
     */
    QGridLayout *apMainLayout;

    /**
     * @brief apFullNameLabel : The full name label.
     */
    QLabel *apFullNameLabel;
    /**
     * @brief apFullNameLE : The line edit in wich the full name of the team should be inserted.
     */
    QLineEdit *apFullNameLE;
    /**
     * @brief apShortNameLabel : The short name label.
     */
    QLabel *apShortNameLabel;
    /**
     * @brief apShortNameLE : The line edit in wich the short name of the team should be inserted.
     */
    QLineEdit *apShortNameLE;

    /**
     * @brief apLeaguesLabel : The leagues label.
     */
    QLabel *apLeaguesLabel;
    /**
     * @brief apLeaguesListWidget : The widget in which the list of the leagues will be shown.
     */
    QListWidget *apLeaguesListWidget;

    /**
     * @brief apCreateBtn : The button to create the new team.
     */
    QPushButton *apCreateBtn;
    /**
     * @brief apCancelBtn : The buton to cancel the creation of the new team.
     */
    QPushButton *apCancelBtn;
};


#endif // ADDTEAMWIDGET_H
