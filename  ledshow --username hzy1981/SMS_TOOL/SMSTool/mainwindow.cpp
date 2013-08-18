#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QMessageBox>

#define APP_NAME "LED控制器短信指令生成工具"
#define APP_VERSION "V1.0"

#define EQ ==
#define MAX_CHR_NUM 57
#define MAX_ADD_CHR_NUM 64

#define SET_SMS_INDEX  0
#define ADD_SMS_INDEX  1
#define DEL_SMS_INDEX  2
#define RD_SMS_IDEX    3
#define ADJ_TIME_INDEX 4
#define RD_OTHER_PARA_INDEX 5
#define CALL_SMS_INDEX 6
#define ADD_PHN_INDEX  7
#define DEL_PHN_INDEX  8
#define SET_SCREEN_PARA_INDEX 9


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString(tr(APP_NAME)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(copy2clipBoard()));
    connect(ui->textEdit_2, SIGNAL(textChanged()), this, SLOT(on_SMSTxt_Edit()));
    connect(ui->textEdit_3, SIGNAL(textChanged()), this, SLOT(on_addSMSTxt_Edit()));
    connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(on_adjTime_Button_Edit()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(on_adjTime_Button_Edit()));
    connect(ui->spinBox_8, SIGNAL(editingFinished()), this, SLOT(on_screenPara_Eidt()));
    connect(ui->spinBox_9, SIGNAL(editingFinished()), this, SLOT(on_screenPara_Eidt()));
    connect(ui->spinBox_5, SIGNAL(editingFinished()), this, SLOT(on_stayTime_Edit()));
    connect(ui->action_4, SIGNAL(changed()), this, SLOT(on_advPara_Check())),
    connect(ui->action_3, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
    //connect(ui->spinBox_5, SIGNAL()
    ui->textEdit->setTextColor(Qt::blue);
    smsTxt = "";
    //ui->textEdit->setFont();
    on_SMSTxt_Edit();
    on_addSMSTxt_Edit();
    /*
#define CALL_SMS_INDEX 5
#define ADD_PHN_INDEX  6
#define DEL_PHN_INDEX  7
#define SET_SCREEN_PARA_INDEX 8
*/
    ui->smsTab->removeTab(CALL_SMS_INDEX);//CALL_SMS_INDEX);//->setVisible(false);
    ui->smsTab->removeTab(CALL_SMS_INDEX);//->setVisible(false);
    ui->smsTab->removeTab(CALL_SMS_INDEX);//->setVisible(false);
    ui->smsTab->removeTab(CALL_SMS_INDEX);//->setVisible(false);
    //ui->smsTab->removeTab();
    //ui->smsTab->removeTab();
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

char borderIndex2asc(int index)
{
    if(index EQ 0)
        return '0';
    else if(index EQ 1)
        return '1';
    else if(index >= 2 && index < 6)
        return '6' + index - 2;
    else if(index >= 6 && index < 17)
        return 'a' +index - 6;
    else if(index EQ 17)
        return 'l';
    else if(index >= 18 && index < 18 + 15)
        return 'q' + index - 18;
    else if(index EQ 33)
        return 'F';
    else if(index >= 34 && index < 34 + 15)
        return 'K' + index - 34;
    else
        return '1';

}

void MainWindow::copy2clipBoard()
{
    if(smsTxt != "")
    {
        QClipboard *clipboard = QApplication::clipboard();
        //QString originalText = clipboard->text();
        //...
        clipboard->setText(smsTxt);
    }

}

//高级参数设置选择
void MainWindow::on_advPara_Check()
{
    if(ui->action_4->isChecked())
    {
        ui->smsTab->addTab(ui->tab_2, tr("启用预存文件"));
        ui->smsTab->addTab(ui->tab_9, tr("增加过滤号码"));
        ui->smsTab->addTab(ui->tab_3, tr("删除过滤号码"));
        ui->smsTab->addTab(ui->tab_8, tr("设置屏参"));
    }
    else
    {
        ui->smsTab->removeTab(CALL_SMS_INDEX);//CALL_SMS_INDEX);//->setVisible(false);
        ui->smsTab->removeTab(CALL_SMS_INDEX);//->setVisible(false);
        ui->smsTab->removeTab(CALL_SMS_INDEX);//->setVisible(false);
        ui->smsTab->removeTab(CALL_SMS_INDEX);//->setVisible(false);
    }

}

void MainWindow::on_SMSTxt_Edit()
{
    //计算字符串个数
    int num;
    QString txt;

    num = this->ui->textEdit_2->toPlainText().size();//textEdit2//this->te->toPlainText().toLocal8Bit().size();
    txt = tr("字符数(") + QString::number(num) + QString("/") + QString::number(MAX_CHR_NUM) + QString(")");

    if(num > MAX_CHR_NUM)
    {
      txt = txt + QString(tr("超,超过部分将不能显示!"));
      ui->label_24->setStyleSheet("color:red");
    }
    else
      ui->label_24->setStyleSheet("color:black");

    ui->label_24->setText(txt);
}

void MainWindow::on_screenPara_Eidt()
{
    if(ui->spinBox_8->value() % 8 != 0)
        ui->spinBox_8->setValue(ui->spinBox_8->value() / 8 * 8);

    if(ui->spinBox_9->value() % 8 != 0)
        ui->spinBox_9->setValue(ui->spinBox_9->value() / 8 * 8);
}

void MainWindow::on_stayTime_Edit()
{
    if(ui->spinBox_5->value() >= 10 && ui->spinBox_5->value() % 5 != 0)
    {
      ui->spinBox_5->setValue(ui->spinBox_5->value() / 5 * 5);
    }
}

void MainWindow::on_adjTime_Button_Edit()
{
    if(ui->radioButton->isChecked())
    {
        ui->dateTimeEdit->setEnabled(false);
    }
    else
    {
        //ui->dateTimeEdit->setEnabled(true);
        //temp =  ;
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
        ui->dateTimeEdit->setEnabled(true);
    }
}

void MainWindow::on_addSMSTxt_Edit()
{
    //计算字符串个数
    int num;
    QString txt;

    num = this->ui->textEdit_3->toPlainText().size();//textEdit2//this->te->toPlainText().toLocal8Bit().size();
    txt = tr("字符数(") + QString::number(num) + QString("/") + QString::number(MAX_ADD_CHR_NUM) + QString(")");

    if(num > MAX_ADD_CHR_NUM)
    {
      txt = txt + QString(tr("超,超过部分将不能显示!"));
      ui->label_25->setStyleSheet("color:red");
    }
    else
      ui->label_25->setStyleSheet("color:black");

    ui->label_25->setText(txt);
}

void MainWindow::setContextSMS()
{
    QDateTime dateTime;
    QString nullStr = "";

    smsTxt = "";
    //if(this->ui->smsTab->currentTabText EQ )
    int index = this->ui->smsTab->currentIndex();
    if(index EQ SET_SMS_INDEX)
    {
        smsTxt += "#@";
        smsTxt += num2str(this->ui->spinBox->value(), 2) + "0";

        smsTxt.append(index2asc(ui->comboBox->currentIndex())); //进入特效
        smsTxt.append(index2asc(ui->comboBox_2->currentIndex())); //退出特效
        smsTxt.append(index2asc(ui->comboBox_4->currentIndex())); //特效速度

        int stayTime = ui->spinBox_5->value();

        if(stayTime < 10)
            smsTxt.append(index2asc(stayTime)); //停留时间
        else if(stayTime < 10 + 26 * 5)
            smsTxt.append((stayTime - 10) / 5 + 'a');
        else if(stayTime < 140 + 26 * 5)
            smsTxt.append((stayTime - 140) / 5 + 'A');
        else
            smsTxt.append("10");

        smsTxt.append(index2asc(ui->comboBox_5->currentIndex())); //字体大小
        smsTxt.append(index2asc(ui->comboBox_7->currentIndex() + 1)); //颜色
        smsTxt.append(borderIndex2asc(ui->comboBox_3->currentIndex())); //边框特效

        smsTxt.append('+'); //颜色

        if(ui->textEdit_2->toPlainText().size() EQ 0)
        {
            nullStr = tr("(注意：显示内容为空)");
            //QMessageBox::information(0, QObject::tr("提示"),QObject::tr("增加的显示内容为空!"));
        }
        smsTxt.append(ui->textEdit_2->toPlainText()); //颜色
    }
    else if(index EQ ADD_SMS_INDEX) //追加短信
    {
        smsTxt += "#@";
        smsTxt += num2str(this->ui->spinBox_2->value(), 2);// + "0";
        smsTxt += num2str(this->ui->comboBox_8->currentIndex() + 1, 1);

        smsTxt.append('+'); //颜色
        if(ui->textEdit_3->toPlainText().size() EQ 0)
        {
            nullStr = tr("(注意：显示内容为空)");
            //QMessageBox::information(0, QObject::tr("提示"),QObject::tr("追加的显示内容为空!"));
        }
        smsTxt.append(ui->textEdit_3->toPlainText()); //颜色
    }
    else if(index EQ DEL_SMS_INDEX) //删除短信
    {
        smsTxt += "#DEL";
        smsTxt += num2str(this->ui->spinBox_3->value(), 2);// + "0";
    }
    else if(index EQ RD_SMS_IDEX) //读取短信内容
    {
        smsTxt += "?@";
        smsTxt += num2str(this->ui->spinBox_4->value(), 2);// + "0";

        if(ui->groupBox->isChecked())
          smsTxt += num2str(this->ui->comboBox_6->currentIndex() + 1, 1);
        else
          smsTxt += '0';
    }
    else if(index EQ ADJ_TIME_INDEX) //校准时间
    {
        //CadjTimeProperty::getDateTime()

        if(ui->radioButton->isChecked())
        {
          dateTime = QDateTime::currentDateTime();
        }
        else
        {
          dateTime = ui->dateTimeEdit->dateTime();
        }

        smsTxt += "#TIM";
        smsTxt.append(num2str(dateTime.date().year() - 2000, 2));
        smsTxt.append(num2str(dateTime.date().month(), 2));
        smsTxt.append(num2str(dateTime.date().day(), 2));
        smsTxt.append(num2str(dateTime.time().hour(), 2));
        smsTxt.append(num2str(dateTime.time().minute(), 2));
        smsTxt.append(num2str(dateTime.time().second(), 2));

        int week = dateTime.date().dayOfWeek();
        if(week EQ 7)
            week = 0;

        smsTxt.append(num2str(week, 1));
    }
    else if(index EQ CALL_SMS_INDEX)
    {
        smsTxt += "#@";
        smsTxt += num2str(this->ui->spinBox_6->value(), 2) + "!";
        smsTxt += num2str(this->ui->spinBox_7->value(), 2);
    }
    else if(index EQ ADD_PHN_INDEX) //增加过滤号码
    {
        smsTxt += "#MPN";
        smsTxt += num2str(this->ui->comboBox_11->currentIndex() + 1, 1);
        smsTxt += this->ui->lineEdit_2->text();
    }
    else if(index EQ DEL_PHN_INDEX) //删除过滤号码
    {
        smsTxt += "#MPN0";
        smsTxt += num2str(this->ui->comboBox_12->currentIndex(), 1);
    }
    else if(index EQ SET_SCREEN_PARA_INDEX) //设置屏幕参数
    {
        smsTxt += "#SCN";
        smsTxt += num2str(this->ui->spinBox_8->value(), 4);
        smsTxt += "X";
        smsTxt += num2str(this->ui->spinBox_9->value(), 3);
        smsTxt += ",";
        smsTxt += num2str(this->ui->comboBox_9->currentIndex() + 1, 1);
        smsTxt += num2str(this->ui->comboBox_10->currentIndex(), 1);
        smsTxt += num2str(this->ui->comboBox_13->currentIndex(), 1);
        smsTxt += ",";

        if(this->ui->comboBox_14->currentIndex() EQ 0)
            smsTxt +="0200";
        else if(this->ui->comboBox_14->currentIndex() EQ 1)
            smsTxt += "2213";
        else
            smsTxt += "1200";

    }
    else if(index EQ RD_OTHER_PARA_INDEX) //读取其他参数
    {
        if(ui->radioButton_3->isChecked())
        {
            smsTxt += "?MPN";
            nullStr = tr("(过滤号码)");
        }
        else if(ui->radioButton_4->isChecked())
        {
            smsTxt += "?SCN";
            nullStr = tr("(屏幕参数)");
        }
    }
    else
        return;


    //dateTime = currentDateTime();
    //dateTime.toString()
    if(smsTxt.size() > 70)
        smsTxt.truncate(70);

    if(ui->action->isChecked())
      ;//ui->textEdit->setText(this->ui->smsTab->tabText(index) + nullStr + ":" + smsTxt);
    else
    {
        if(smsTxt.at(0) EQ '#')
            smsTxt.replace(0, 1, "*");
    }

    ui->textEdit->setText(this->ui->smsTab->tabText(index) + nullStr + ":" + smsTxt);

}

void MainWindow::on_pushButton_clicked()
{
    setContextSMS();
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::showAboutDialog()
{
    QMessageBox::information(this, tr("关于"), tr(APP_NAME) + tr(" ") + tr(APP_VERSION) + tr("\r\n\r\n") + tr("编译时间 ")+QString(__TIME__) + QString(" ") + QString(__DATE__) +\
                             tr("\r\n\r\n") + tr("长沙爱朗电子科技有限公司\r\n    WWW.CSILUNE.COM"), tr("确定"));

}
