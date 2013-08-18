/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralWidget;
    QTabWidget *smsTab;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QTextEdit *textEdit_2;
    QLabel *label_6;
    QLabel *label_41;
    QSpinBox *spinBox;
    QLabel *label_42;
    QLabel *label_21;
    QComboBox *comboBox_4;
    QSpinBox *spinBox_5;
    QLabel *label_22;
    QComboBox *comboBox_5;
    QLabel *label_23;
    QComboBox *comboBox_7;
    QLabel *label_24;
    QLabel *label_33;
    QWidget *tab_4;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit_3;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *comboBox_8;
    QLabel *label_14;
    QSpinBox *spinBox_2;
    QLabel *label_25;
    QWidget *tab_6;
    QLabel *label_9;
    QSpinBox *spinBox_3;
    QLabel *label_43;
    QWidget *tab_5;
    QLabel *label_10;
    QGroupBox *groupBox;
    QLabel *label_11;
    QComboBox *comboBox_6;
    QLabel *label_44;
    QSpinBox *spinBox_4;
    QWidget *tab_7;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QDateTimeEdit *dateTimeEdit;
    QWidget *tab_10;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QWidget *tab_2;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QSpinBox *spinBox_6;
    QLabel *label_45;
    QSpinBox *spinBox_7;
    QWidget *tab_9;
    QLabel *label_18;
    QLineEdit *lineEdit_2;
    QLabel *label_19;
    QComboBox *comboBox_11;
    QWidget *tab_3;
    QLabel *label_20;
    QComboBox *comboBox_12;
    QLabel *label_26;
    QWidget *tab_8;
    QLabel *label_27;
    QLabel *label_28;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QLabel *label_29;
    QComboBox *comboBox_9;
    QLabel *label_30;
    QComboBox *comboBox_10;
    QLabel *label_31;
    QComboBox *comboBox_13;
    QLabel *label_32;
    QComboBox *comboBox_14;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 417);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_4->setCheckable(true);
        action_4->setChecked(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        smsTab = new QTabWidget(centralWidget);
        smsTab->setObjectName(QString::fromUtf8("smsTab"));
        smsTab->setGeometry(QRect(0, 0, 901, 280));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 49, 54, 12));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 79, 54, 12));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 109, 54, 12));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 172, 54, 12));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 44, 140, 22));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(70, 75, 140, 22));
        comboBox_3 = new QComboBox(tab);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(70, 135, 140, 22));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 170, 111, 20));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(230, 46, 441, 141));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 20, 101, 16));
        label_41 = new QLabel(tab);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 20, 54, 12));
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(71, 13, 42, 22));
        spinBox->setMinimum(1);
        label_42 = new QLabel(tab);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(120, 20, 54, 12));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 140, 54, 12));
        comboBox_4 = new QComboBox(tab);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(70, 105, 140, 22));
        spinBox_5 = new QSpinBox(tab);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(70, 168, 41, 22));
        spinBox_5->setMaximum(265);
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 199, 54, 20));
        comboBox_5 = new QComboBox(tab);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(70, 199, 61, 22));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(140, 202, 31, 16));
        comboBox_7 = new QComboBox(tab);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(170, 200, 41, 22));
        label_24 = new QLabel(tab);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(410, 200, 251, 20));
        label_33 = new QLabel(tab);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 230, 371, 16));
        smsTab->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 51, 16));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(250, 20, 91, 16));
        textEdit_3 = new QTextEdit(tab_4);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(250, 50, 461, 131));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(11, 56, 54, 12));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 20, 101, 16));
        comboBox_8 = new QComboBox(tab_4);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setGeometry(QRect(61, 51, 41, 22));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(114, 55, 101, 16));
        spinBox_2 = new QSpinBox(tab_4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(70, 19, 42, 22));
        spinBox_2->setMinimum(1);
        label_25 = new QLabel(tab_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(420, 190, 251, 20));
        smsTab->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 111, 16));
        spinBox_3 = new QSpinBox(tab_6);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(125, 19, 42, 22));
        spinBox_3->setMinimum(0);
        label_43 = new QLabel(tab_6);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(174, 21, 181, 16));
        smsTab->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 20, 81, 16));
        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 201, 71));
        groupBox->setCheckable(true);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 30, 61, 16));
        comboBox_6 = new QComboBox(groupBox);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(100, 30, 41, 22));
        label_44 = new QLabel(tab_5);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(160, 22, 54, 12));
        spinBox_4 = new QSpinBox(tab_5);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(112, 17, 42, 22));
        spinBox_4->setMinimum(1);
        smsTab->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        radioButton = new QRadioButton(tab_7);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 20, 89, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(tab_7);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 47, 89, 16));
        dateTimeEdit = new QDateTimeEdit(tab_7);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setGeometry(QRect(100, 44, 194, 22));
        smsTab->addTab(tab_7, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        radioButton_4 = new QRadioButton(tab_10);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 47, 89, 16));
        radioButton_3 = new QRadioButton(tab_10);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 17, 101, 21));
        radioButton_3->setChecked(true);
        smsTab->addTab(tab_10, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 52, 54, 12));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(120, 50, 101, 16));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 20, 54, 12));
        spinBox_6 = new QSpinBox(tab_2);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(72, 15, 42, 22));
        spinBox_6->setMinimum(1);
        label_45 = new QLabel(tab_2);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(120, 20, 54, 12));
        spinBox_7 = new QSpinBox(tab_2);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(70, 49, 42, 22));
        spinBox_7->setMinimum(1);
        spinBox_7->setMaximum(50);
        smsTab->addTab(tab_2, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        label_18 = new QLabel(tab_9);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 50, 54, 12));
        lineEdit_2 = new QLineEdit(tab_9);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 50, 161, 20));
        lineEdit_2->setMaxLength(30);
        label_19 = new QLabel(tab_9);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 16, 54, 21));
        comboBox_11 = new QComboBox(tab_9);
        comboBox_11->setObjectName(QString::fromUtf8("comboBox_11"));
        comboBox_11->setGeometry(QRect(70, 16, 41, 22));
        smsTab->addTab(tab_9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 20, 91, 16));
        comboBox_12 = new QComboBox(tab_3);
        comboBox_12->setObjectName(QString::fromUtf8("comboBox_12"));
        comboBox_12->setGeometry(QRect(100, 17, 41, 22));
        label_26 = new QLabel(tab_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(160, 20, 171, 16));
        smsTab->addTab(tab_3, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        label_27 = new QLabel(tab_8);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 20, 54, 12));
        label_28 = new QLabel(tab_8);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(180, 20, 54, 12));
        spinBox_8 = new QSpinBox(tab_8);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(70, 15, 81, 22));
        spinBox_8->setMaximum(9999);
        spinBox_8->setSingleStep(8);
        spinBox_9 = new QSpinBox(tab_8);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setGeometry(QRect(240, 15, 81, 22));
        spinBox_9->setMaximum(999);
        spinBox_9->setSingleStep(8);
        label_29 = new QLabel(tab_8);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(340, 20, 54, 12));
        comboBox_9 = new QComboBox(tab_8);
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));
        comboBox_9->setGeometry(QRect(400, 14, 51, 22));
        label_30 = new QLabel(tab_8);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 54, 54, 12));
        comboBox_10 = new QComboBox(tab_8);
        comboBox_10->setObjectName(QString::fromUtf8("comboBox_10"));
        comboBox_10->setGeometry(QRect(70, 50, 69, 22));
        label_31 = new QLabel(tab_8);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(181, 54, 54, 12));
        comboBox_13 = new QComboBox(tab_8);
        comboBox_13->setObjectName(QString::fromUtf8("comboBox_13"));
        comboBox_13->setGeometry(QRect(240, 50, 69, 22));
        label_32 = new QLabel(tab_8);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(10, 90, 54, 12));
        comboBox_14 = new QComboBox(tab_8);
        comboBox_14->setObjectName(QString::fromUtf8("comboBox_14"));
        comboBox_14->setGeometry(QRect(70, 86, 321, 22));
        smsTab->addTab(tab_8, QString());
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 320, 901, 41));
        textEdit->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\256\213\344\275\223\";"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 284, 141, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\256\213\344\275\223\";"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 284, 181, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\345\256\213\344\275\223\";"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_4);
        menu_2->addSeparator();
        menu_2->addAction(action_2);
        menu_2->addAction(action_3);

        retranslateUi(MainWindow);

        smsTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\346\211\213\345\206\214", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\253\230\347\272\247\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        tab->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\347\211\271\346\225\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\211\271\346\225\210", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\347\211\271\346\225\210\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\345\201\234\347\225\231\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\232\217\346\234\272\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\253\213\345\215\263\346\230\276\347\244\272\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\277\236\347\273\255\345\267\246\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\277\236\347\273\255\344\270\212\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\271\263\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\345\271\263\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\345\271\263\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\345\271\263\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\212\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\212\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\213\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\213\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\212\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\212\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\213\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\213\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\345\274\200\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\345\274\200\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\345\220\210\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\345\220\210\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\345\215\267\350\275\264\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\345\215\267\350\275\264\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\210\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\351\243\230\351\233\252", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\351\243\230\351\233\252", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\227\252\347\203\201\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\351\225\255\345\260\204\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\351\225\255\345\260\204\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\351\225\255\345\260\204\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\351\225\255\345\260\204\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\346\213\211\344\274\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\346\213\211\344\274\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\236\202\347\233\264\346\213\211\344\274\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\260\264\345\271\263\346\213\211\344\274\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\260\264\345\271\263\347\231\276\345\217\266\347\252\227\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\236\202\347\233\264\347\231\276\345\217\266\347\252\227\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\267\241\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\212\347\247\273\345\205\245", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\212\347\247\273\345\205\245", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\213\347\247\273\345\205\245", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\213\347\247\273\345\205\245", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\347\237\242\351\207\217\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\347\237\242\351\207\217\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\347\237\242\351\207\217\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\347\237\242\351\207\217\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\210\206\346\225\243\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\345\210\206\346\225\243\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\345\210\206\346\225\243\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\345\210\206\346\225\243\345\216\213\345\205\245\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\220\221\345\267\246\346\257\224\344\276\213\345\216\213\347\274\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\220\221\344\270\212\346\257\224\344\276\213\345\216\213\347\274\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\217\261\345\275\242\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\217\261\345\275\242\346\224\266\347\274\251", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\232\217\346\234\272\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\215\346\270\205\351\231\244\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\253\213\345\215\263\346\270\205\351\231\244\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\347\247\273\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\350\246\206\347\233\226\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\212\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\212\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\213\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\213\346\226\234\347\272\277\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\212\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\212\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\213\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\213\347\233\264\350\247\222\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\345\274\200\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\345\274\200\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\345\220\210\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\345\220\210\345\270\230\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\345\215\267\350\275\264\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\345\215\267\350\275\264\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\210\350\246\206\347\233\226", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\267\241\345\207\272\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\217\261\345\275\242\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\350\217\261\345\275\242\346\224\266\347\274\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\237\251\345\275\242\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\237\251\345\275\242\346\224\266\347\274\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\346\211\207\345\275\242\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\346\211\207\345\275\242\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\346\211\207\345\275\242\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\213\346\211\207\345\275\242\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\260\204\347\272\277\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\345\260\204\347\272\277\345\261\225\345\274\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\260\204\347\272\277\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\345\260\204\347\272\277\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\212\345\260\204\347\201\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\212\345\260\204\347\201\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\344\270\213\345\260\204\347\201\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\217\263\344\270\213\345\260\204\347\201\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\344\272\244\345\217\211\346\213\211\345\271\225\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\344\272\244\345\217\211\346\213\211\345\271\225\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\210\351\243\216\350\275\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\210\351\243\216\350\275\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\267\246\345\217\263\344\270\255\351\227\264\347\247\273\345\207\272\342\210\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\344\270\212\344\270\213\344\270\255\351\227\264\347\247\273\345\207\272\342\210\232", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\235\231\346\200\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\235\231\346\200\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\235\231\346\200\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\227\252\347\203\201\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\241\272\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\344\270\255", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\205\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204\350\211\262\351\200\206\346\227\266\351\222\210\351\200\237\345\272\246\346\234\200\346\205\242", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "\347\247\222(>10\345\220\216\351\241\273\344\270\2725\345\200\215\346\225\260)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\347\232\204\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MainWindow", "(1-99)", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "\350\276\271\346\241\206\347\211\271\346\225\210", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9\346\234\200\345\277\253", 0, QApplication::UnicodeUTF8)
        );
        label_22->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "16X16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "24X24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "32X32", 0, QApplication::UnicodeUTF8)
        );
        label_23->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\272\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\273\204", 0, QApplication::UnicodeUTF8)
        );
        label_24->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\346\225\260", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MainWindow", "\346\263\250\346\204\217\357\274\232\345\261\217\345\271\225\350\276\203\345\244\247\357\274\210\344\270\200\350\210\254\345\244\247\344\272\216512*32)\346\227\266\345\273\272\350\256\256\351\200\211\346\213\251\346\211\223\351\222\251\347\232\204\350\277\233\345\205\245\345\222\214\351\200\200\345\207\272\347\211\271\346\225\210", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab), QApplication::translate("MainWindow", "\345\242\236\345\212\240\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\345\234\250\345\272\217\345\217\267\344\270\272", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\350\277\275\345\212\240\347\232\204\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\350\277\231\346\230\257\347\254\254", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\347\232\204\346\230\276\347\244\272\345\206\205\345\256\271\344\270\212\350\277\275\345\212\240", 0, QApplication::UnicodeUTF8));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("MainWindow", "\346\235\241\350\277\275\345\212\240\347\232\204\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\346\225\260", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_4), QApplication::translate("MainWindow", "\350\277\275\345\212\240\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\232\204\346\230\276\347\244\272\345\206\205\345\256\271\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MainWindow", "(0-99,0\350\241\250\347\244\272\345\210\240\351\231\244\345\205\250\351\203\250\346\230\276\347\244\272\345\206\205\345\256\271)", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_6), QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\206\205\345\256\271\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\257\273\345\217\226\350\277\275\345\212\240\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\350\277\275\345\212\240\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
        );
        label_44->setText(QApplication::translate("MainWindow", "(1-99)", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_5), QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\230\276\347\244\272\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_7), QApplication::translate("MainWindow", "\346\240\241\346\227\266", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\345\261\217\345\271\225\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\350\277\207\346\273\244\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_10), QApplication::translate("MainWindow", "\350\257\273\345\217\226\345\205\266\344\273\226\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\347\254\254", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\344\270\252\351\242\204\345\255\230\346\230\276\347\244\272\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\272\217\345\217\267", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "(1-99)", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_2), QApplication::translate("MainWindow", "\345\220\257\347\224\250\351\242\204\345\255\230\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\345\217\267\347\240\201\347\264\242\345\274\225</p></body></html>", 0, QApplication::UnicodeUTF8));
        comboBox_11->clear();
        comboBox_11->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8)
        );
        smsTab->setTabText(smsTab->indexOf(tab_9), QApplication::translate("MainWindow", "\345\242\236\345\212\240\350\277\207\346\273\244\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\217\267\347\240\201\347\264\242\345\274\225", 0, QApplication::UnicodeUTF8));
        comboBox_12->clear();
        comboBox_12->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8)
        );
        label_26->setText(QApplication::translate("MainWindow", "<html><head/><body><p>(0-9,0\350\241\250\347\244\272\345\210\240\351\231\244\346\211\200\346\234\211\345\217\267\347\240\201)</p></body></html>", 0, QApplication::UnicodeUTF8));
        smsTab->setTabText(smsTab->indexOf(tab_3), QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\277\207\346\273\244\345\217\267\347\240\201", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "\345\261\217\345\271\225\345\256\275\345\272\246", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "\345\261\217\345\271\225\351\253\230\345\272\246", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "\345\261\217\345\271\225\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
        comboBox_9->clear();
        comboBox_9->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\272\242", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\273\277", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\272\242+\347\273\277", 0, QApplication::UnicodeUTF8)
        );
        label_30->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\236\201\346\200\247", 0, QApplication::UnicodeUTF8));
        comboBox_10->clear();
        comboBox_10->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\275\216\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        label_31->setText(QApplication::translate("MainWindow", "OE\346\236\201\346\200\247", 0, QApplication::UnicodeUTF8));
        comboBox_13->clear();
        comboBox_13->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\275\216\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\351\253\230\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        label_32->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        comboBox_14->clear();
        comboBox_14->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0200,1/16\346\211\253,\345\217\263\345\205\245\347\233\264\350\241\214\344\270\200\350\267\257\345\270\24616\350\241\214\346\225\260\346\215\256(\345\256\244\345\206\205\345\261\217\345\270\270\350\247\204)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2213,1/4\346\211\253,\345\217\263\345\205\245\346\257\2178\347\202\271\345\220\221\344\270\213\346\211\223\346\212\230,\346\211\223\346\212\2303\346\254\241(P10\346\250\241\347\273\204\345\270\270\350\247\204)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1200,1/8\346\211\253,\345\217\263\345\205\245\347\233\264\350\241\214\344\270\200\350\267\257\345\270\2468\350\241\214\346\225\260\346\215\256(P6\346\250\241\347\273\204\345\270\270\350\247\204)", 0, QApplication::UnicodeUTF8)
        );
        smsTab->setTabText(smsTab->indexOf(tab_8), QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\261\217\345\217\202", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\347\237\255\344\277\241\345\206\205\345\256\271", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266\347\237\255\344\277\241\345\206\205\345\256\271\345\210\260\347\262\230\350\264\264\346\235\277", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
