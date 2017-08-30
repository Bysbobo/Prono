#ifndef INFORMATIONWIDGET_H
#define INFORMATIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include "league.h"
#include "team.h"
#include "match.h"

/**
 * @brief The InformationWidget class shows information on a league, a team or a match.
 */
class InformationWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Default constructor for InformationWidget class. This constructor do not display anything.
     * @param parent : The parent widget.
     */
    explicit InformationWidget(QWidget *parent = 0);
    /**
     * @brief Constructor to show information on a league.
     * @param league : The input league which information will be shown.
     * @param parent : The parent widget.
     */
    explicit InformationWidget(const League& league, QWidget *parent = 0);
    /**
     * @brief Constructor to show information on a team.
     * @param team : The input team which information will be shown.
     * @param parent : The parent widget.
     */
    explicit InformationWidget(const Team& team, QWidget *parent = 0);
    /**
     * @brief Constructor to show information on a match.
     * @param match : The input team which information will be shown.
     * @param parent : The parent widget.
     */
    explicit InformationWidget(const Match& match, QWidget *parent = 0);

    /**
     * @brief Destructor.
     */
    ~InformationWidget();

private:
    /**
     * @brief apTitleLabel : The title label that will be shown differently for a league, a team or a match.
     */
    QLabel *apTitleLabel;
    /**
     * @brief apMainLayout : The main layout of the widget.
     */
    QGridLayout *apMainLayout;
};

#endif // INFORMATIONWIDGET_H
