#include "view/MainWindow.h"
#include "view/SideBoards/BoardView.h"

#include <QApplication>
#include <QObject>

/**
* Created by Qt Creator
*/
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
