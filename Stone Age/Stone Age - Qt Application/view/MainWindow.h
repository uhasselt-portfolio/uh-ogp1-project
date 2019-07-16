#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        // Constructor
        MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H
