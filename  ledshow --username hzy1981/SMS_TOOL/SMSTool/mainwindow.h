#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_SMSTxt_Edit();
    void on_addSMSTxt_Edit();
    void on_adjTime_Button_Edit();
    void on_screenPara_Eidt();
    void on_stayTime_Edit();

    void on_advPara_Check();
    void copy2clipBoard();
    void showAboutDialog();

private:
    Ui::MainWindow *ui;

public:
    QString smsTxt;// = "";
    void setContextSMS();
};

#endif // MAINWINDOW_H
