#ifndef ADDLEAGUEWIDGET_H
#define ADDLEAGUEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

/**
 * @brief The AddLeagueWidget class is a widget allowing to create a new league.
 */
class AddLeagueWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructor of the AddLeagueWidget class.
     * @param parent : The parent item of the widget.
     */
    explicit AddLeagueWidget(QWidget *parent = 0);
    /**
     * @brief Destructor.
     */
    ~AddLeagueWidget();

signals:
    /**
     * @brief This signal is emmitted when the create button is pressed.
     */
    void leagueToBeCreated(const QString&);

private slots:
    /**
     * @brief This slot emits the leagueToBeCreated signal and closes the widget.
     */
    void createBtnPressed();

private:
    /**
     * @brief apMainLayout : The main layout of the widget.
     */
    QGridLayout *apMainLayout;

    /**
     * @brief apNameLabel : The name label.
     */
    QLabel *apNameLabel;
    /**
     * @brief apNameLE : The line edit in wich the name of the league should be inserted.
     */
    QLineEdit *apNameLE;

    /**
     * @brief apCreateBtn : The button to create the new league.
     */
    QPushButton *apCreateBtn;
    /**
     * @brief apCancelBtn : The buton to cancel the creation of the new league.
     */
    QPushButton *apCancelBtn;

};

#endif // ADDLEAGUEWIDGET_H
