#ifndef SIMPLETEXTEDIT_H
#define SIMPLETEXTEDIT_H

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFontComboBox>
#include "colorCombo.h"
#include "..\Includes.h"

class CsimpleTextEdit :public QWidget
{
    Q_OBJECT
private:
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
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CsimpleTextEdit(QWidget *parent =0);
    ~CsimpleTextEdit();

};

QImage getTextImage(QString str);
QSize getTextShowData(QImage image, S_Show_Data *pDst, INT16U x, INT16U y);
#endif // SIMPLETEXTEDIT_H
