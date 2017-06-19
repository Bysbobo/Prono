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
     * @brief m_mainLayout : The main layout of the About widget.
     */
    QGridLayout *m_mainLayout;

    /**
     * @brief m_appName : A label of the application name.
     */
    QLabel *m_appName;
    /**
     * @brief m_builtOn : A label of the last building date.
     */
    QLabel *m_builtOn;
    /**
     * @brief m_copyright : A label of the copyright.
     */
    QLabel *m_copyright;
    /**
     * @brief m_law : A label of the law.
     */
    QLabel *m_law;

    /**
     * @brief m_closeBtn : Button to close the About widget.
     */
    QPushButton *m_closeBtn;
};

#endif // ABOUT_H
