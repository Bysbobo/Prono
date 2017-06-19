#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

/**
 * @brief The About class defines the about widget.
 */
class About : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief The constructor of this class.
     * @param parent : The parent of the About widget.
     */
    explicit About(QWidget *parent = 0);

private:
    /**
     * @brief apMainLayout : The main layout of the About widget.
     */
    QGridLayout *apMainLayout;

    /**
     * @brief apAppName : A label of the application name.
     */
    QLabel *apAppName;
    /**
     * @brief apBuiltOn : A label of the last building date.
     */
    QLabel *apBuiltOn;
    /**
     * @brief apCopyright : A label of the copyright.
     */
    QLabel *apCopyright;
    /**
     * @brief apLaw : A label of the law.
     */
    QLabel *apLaw;

    /**
     * @brief apCloseBtn : Button to close the About widget.
     */
    QPushButton *apCloseBtn;
};

#endif // ABOUT_H
