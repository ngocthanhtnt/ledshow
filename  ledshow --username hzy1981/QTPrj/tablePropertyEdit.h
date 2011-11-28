#ifndef TABLEPROPERTYEDIT_H
#define TABLEPROPERTYEDIT_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QInputDialog>
#include <QRadioButton>
#include "colorCombo.h"

class CtablePropertyEdit:public QDialog
{
    Q_OBJECT
signals:
        void createTable(int rows, int colums, QTextTableFormat tableFormat);
        void updateTable(int rows, int colums, QTextTableFormat tableFormat);

public slots:
        void accept();
        void reject();
        void setProperties(int rows, int colums, QTextTableFormat tableFormat, bool newTable);

        void apply();
        //void changeColorTable();
        //void changeColorBorder();

private:
        void getTableFormat();
        bool modeNewTable;
        QTextTableFormat tFormat;
        QColor colorTable, colorBorder;
public:
   QSpinBox *rowsEdit;  //行数
   QSpinBox *colsEdit;  //列数
   QSpinBox *widthEdit; //宽度

   QComboBox *alignCombo; //对齐方式

   QSpinBox *borderWidth; //内边框宽度
   CcolorCombo *borderColor; //边框颜色
   QComboBox *borderStyle; //边框式样

   //QSpinBox *marginWidth; //外边框宽度
   //CcolorCombo *marginColor;

   QSpinBox *marginBetweenCells;
   QSpinBox *marginInCells;

   QPushButton *applyButton;
   QPushButton *okButton;
   QPushButton *cancelButton;

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtablePropertyEdit(QWidget *parent=0);
    ~CtablePropertyEdit();
};

#endif // TABLEPROPERTYEDIT_H
