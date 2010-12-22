#ifndef SIMPLETEXTEDIT_H
#define SIMPLETEXTEDIT_H

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFontComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QSpinBox>
#include "colorCombo.h"
#include "progManage.h"
#include "..\Includes.h"

class CshowModeCombo:public QComboBox
{
public:
    CshowModeCombo(QWidget *parent = 0);
    ~CshowModeCombo();
};

class CshowSpeedCombo:public QComboBox
{
public:
    CshowSpeedCombo(QWidget *parent = 0);
    ~CshowSpeedCombo();
};

class CshowModeEdit:public QGroupBox
{
    Q_OBJECT
private:
    QLabel *showModeLabel; //显示模式
    QLabel *speedLabel; //运行速度
    QLabel *stayTimeLabel; //停留时间

    CshowModeCombo *showModeCombo;
    CshowSpeedCombo *speedCombo;
    QLineEdit *stayTimeEdit;
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CshowModeEdit(QWidget *parent);
    ~CshowModeEdit();
};

class CsmLineCombo:public QComboBox
{
  Q_OBJECT
//private:
  //QComboBox *smLineCombo;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CsmLineCombo(QWidget *parent =0);
    ~CsmLineCombo();

};

class CsmLineEdit:public QGroupBox
{
  Q_OBJECT
private:
  QComboBox *smLineCombo;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CsmLineEdit(QWidget *parent =0);
    ~CsmLineEdit();

};

class CdateEdit:public QWidget
{
    Q_OBJECT
private:
    QCheckBox *dateCheck;
    QComboBox *dateCombo;
    CcolorCombo *colorCombo;
    CsizeCombo *sizeCombo;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CdateEdit(QWidget *parent =0);
    ~CdateEdit();
};

class CweekEdit:public QWidget
{
    Q_OBJECT
private:
    QLabel *weekLabel;
    QCheckBox *weekCheck;
    QComboBox *weekCombo;
    CcolorCombo *colorCombo;
    CsizeCombo *sizeCombo;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CweekEdit(QWidget *parent =0);
    ~CweekEdit();
};

class CtimeEdit:public QWidget
{
    Q_OBJECT
private:
    QCheckBox *timeCheck;
    QComboBox *timeCombo;
    CcolorCombo *colorCombo;
    CsizeCombo *sizeCombo;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtimeEdit(QWidget *parent =0);
    ~CtimeEdit();
};

class CtimeDiffEdit:public QGroupBox
{
    Q_OBJECT
private:
    QComboBox *diffFlag;
    QSpinBox *hourEdit;
    QSpinBox *minEdit;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtimeDiffEdit(QWidget *parent =0);
    ~CtimeDiffEdit();
};

class CdateTimeEdit:public QGroupBox
{
    Q_OBJECT
private:
    QGroupBox *editGroup;
    CdateEdit *dateEdit;
    CweekEdit *weekEdit;
    CtimeEdit *timeEdit;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CdateTimeEdit(QWidget *parent =0);
    ~CdateTimeEdit();
};

class ClunEdit:public QGroupBox
{
  Q_OBJECT
private:

  QCheckBox *tianganCheck;
  QCheckBox *nongliCheck;
  QCheckBox *jieqiCheck;

  CcolorCombo *tianganColor;
  CcolorCombo *nongliColor;
  CcolorCombo *jieqiColor;

  CsizeCombo *tianganFont;
  CsizeCombo *nongliFont;
  CsizeCombo *jieqiFont;

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    ClunEdit(QWidget *parent =0);
    ~ClunEdit();

};

class CnameEdit:public QGroupBox
{
  Q_OBJECT
private:

  QGroupBox *group;
  QLineEdit *nameEdit;
  QLabel *nameLabel;
signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CnameEdit(QWidget *parent =0);
    ~CnameEdit();

};

class CsimpleTextEdit :public QGroupBox
{
    Q_OBJECT
private:
    QGroupBox *textGroup;
    QLabel *fontLabel; //字体
    QLabel *fontSizeLabel; //字体大小
    QLabel *colorLabel; //颜色

    QFontComboBox *fontCombo;
    QComboBox *fontSizeCombo;
    CcolorCombo *colorCombo;

    QPushButton *bButton; //加黑
    QPushButton *iButton; //斜体
    QPushButton *uButton; //划线
    //QPushButton *oButton; //打开

    QLineEdit *lineEdit; //编辑框

signals:
    void edited();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CsimpleTextEdit(QWidget *parent =0);
    ~CsimpleTextEdit();

};

QImage getLineTextImage(QString str);
QSize getTextShowData(QImage image, S_Show_Data *pDst, INT16U x, INT16U y);
#endif // SIMPLETEXTEDIT_H
