#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString num2str(int num, int bits)
{
    QString txt = "";

    for(int i = 0; i < bits; i ++)
    {
        txt.insert(0, '0' + (num % 10));
        num = num / 10;

    }

    return txt;
}

char index2asc(int index)
{
    if(index <= 9)
        return '0' + index;
    else if(index >= 10 && index < 10 + 26)
        return 'a' + index - 10;
    else
        return 'A' + index - (10 + 26);
}

void MainWindow::setContextSMS()
{
    QString smsTxt = "";
    //if(this->ui->smsTab->currentTabText EQ )
    int index = this->ui->smsTab->currentIndex();
    if(index == 0)
    {
        smsTxt += "#@";
        smsTxt += num2str(this->ui->spinBox->value(), 2) + "0";
    }

    smsTxt.append(index2asc(ui->comboBox->currentIndex())); //进入特效
    smsTxt.append(index2asc(ui->comboBox_2->currentIndex())); //退出特效
    smsTxt.append(index2asc(ui->comboBox_2->currentIndex()));

    ui->textEdit->setText(smsTxt);

}

void MainWindow::on_pushButton_clicked()
{
    setContextSMS();
}

void MainWindow::on_pushButton_2_clicked()
{

}
