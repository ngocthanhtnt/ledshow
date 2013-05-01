#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//! [0]
#include "ui_mainwindow.h"
//! [0]


//! [1]
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = 0);


//private slots:


//public:
    Ui::MainWindow ui;
};
//! [1]


#endif // MAINWINDOW_H
