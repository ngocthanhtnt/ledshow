#ifndef SIMPLETEXTEDIT_H
#define SIMPLETEXTEDIT_H

#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFontComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QSpinBox>
#include <QDialog>
#include "colorCombo.h"
#include "progManage.h"
#include "..\Stm32\usr\app\Includes.h"


#define MOVE_LEFT_CONTINUOUS_INDEX 2
#define MOVE_UP_CONTINUOUS_INDEX 3

class CshowModeCombo:public QComboBox
{
    Q_OBJECT
    bool type;
public slots:
    void setItems();
signals:
    void indexChangeSignal();
public:
    CshowModeCombo(bool flag, QWidget *parent = 0);
    ~CshowModeCombo();
};

class CshowSpeedCombo:public QComboBox
{
    Q_OBJECT
public:
    CshowSpeedCombo(QWidget *parent = 0);
    ~CshowSpeedCombo();
};

class CshowModeEdit:public QGroupBox
{
    Q_OBJECT
signals:
    void edited();
public slots:
    void inModeChanged();
    void outModeChanged();
private:
    QLabel *inModeLabel; //引入模式
    QLabel *outModeLabel; //退出模式
    QLabel *stayTimeLabel; //停留时间

    CshowModeCombo *inModeCombo;
    CshowModeCombo *outModeCombo;
    //CshowSpeedCombo *speedCombo;

    QComboBox *inSpeedEdit; //引入时间
    QLineEdit *stayTimeEdit; //停留时间
    QComboBox *outSpeedEdit; //引出时间
    QLineEdit *playCountsEdit; //播放次数

    QLabel *inSpeedLabel;
    QLabel *stayTimeUnitLabel;
    QLabel *outSpeedLabel; //引出时间
    QLabel *playCountsLabel; //播放次数
    QLabel *playCountsUnitLabel;
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    void connectSignal();
    void disconnectSignal();
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
  QSpinBox *lineSpaceEdit;
signals:
    void edited();
public slots:
    void smLineChanged(int index);
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CsmLineEdit(QWidget *parent =0);
    ~CsmLineEdit();

};

class CdateEdit:public QGroupBox
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
    void screenCardParaChangeProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CdateEdit(QWidget *parent =0);
    ~CdateEdit();
};

class CweekEdit:public QGroupBox
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
    void screenCardParaChangeProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CweekEdit(QWidget *parent =0);
    ~CweekEdit();
};

class CtimeEdit:public QGroupBox
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
    void screenCardParaChangeProc();
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
    void screenCardParaChangeProc();
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
    void screenCardParaChangeProc();
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
public slots:
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
    QCheckBox *editCheck;
    //QPushButton *oButton; //打开

    QLineEdit *lineEdit; //编辑框

signals:
    void edited();
public:
    void screenCardParaChangeProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CsimpleTextEdit(QWidget *parent =0);
    ~CsimpleTextEdit();

};

class CborderEdit:public QGroupBox
{
  Q_OBJECT
private:
    //QCheckBox *borderCheck;
    QGroupBox *borderGroup; //边框
    QCheckBox *borderCheck;

    QLabel *stepLabel,*styleLabel,*modeLabel,*speedLabel,*colorLabel;
    QLabel *pointsLabel,*usLabel;
    QComboBox *stepCombo,*speedCombo;
    QComboBox *styleCombo;
    QComboBox *modeCombo;
    CcolorCombo *colorCombo;

    //QPixmap borderPixmap[MAX_BORDER_TYPE];
signals:
    void editSignal();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CborderEdit(QWidget *parent =0);
    ~CborderEdit();

};

class CimageSize:public QGroupBox
{
    Q_OBJECT
  private:
    QSpinBox *widthEdit;
    QSpinBox *heighEdit;
signals:
    void editSignal();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CimageSize(QWidget *parent =0);
    ~CimageSize();
};

int getBorderWidth(int index);
int getBorderHeight(int index);
void getBorderData(QString str, INT8U Dst[], INT16U DstLen);
void getBorderParaFromeSettings(QString str, U_File_Para &para);
void getShowModeParaFromSettings(QString str, U_File_Para &para);
QImage getLineTextImage(QString str);
QSize getTextShowData(QImage image, S_Show_Data *pDst, INT16U x, INT16U y);
#endif // SIMPLETEXTEDIT_H
