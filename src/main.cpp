#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Create the application
    QApplication a(argc, argv);

    // Initialise the ressources
    Q_INIT_RESOURCE(resources);

    // Create the main window and show it
    MainWindow w;
    w.show();

    return a.exec();
}
