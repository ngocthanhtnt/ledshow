/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>
#include <QPalette>
#include <QSpinBox>
#include <QDialog>
#include "colorCombo.h"
#include "tablePropertyEdit.h"
#include "simpleTextEdit.h"

#define MAX_LINE_NUM 1000

QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QFontComboBox)
QT_FORWARD_DECLARE_CLASS(QTextEdit)
QT_FORWARD_DECLARE_CLASS(QTextCharFormat)
QT_FORWARD_DECLARE_CLASS(QMenu)

class CtextEdit : public QTextEdit
{
    Q_OBJECT
public:
    CtextEdit(QWidget *parent = 0);
protected:
    virtual void contextMenuEvent(QContextMenuEvent *e);
};

class TextEdit : public QMainWindow
{
    Q_OBJECT

public:
    int editMode; //编辑模式，0表示文本，1表示表格

    QAction *actionUndo,
    *actionRedo,
    *actionCut,
    *actionCopy,
    *actionPaste;

    QMenu *menuTable0;
    QMenu *menuRow;
    QMenu *menuColumn;
    QMenu *menuCell;

    QLabel *muLabel;

    CtablePropertyEdit *tablePropertyEdit;

    void screenCardParaChangeProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    TextEdit(QWidget *parent = 0, int mode = 0);
    QSpinBox *spinPage;
    QPalette *palette;
    QTextEdit *getEdit();
public slots:
    void tableNew();
    void tableInsert(int rows, int columns, QTextTableFormat format);
    void tableUpdate(int rows, int columns, QTextTableFormat tableFormat);

    void setupTableMenu();
    void tableProperties();
    void tableDelete();
    void rowInsertAbove();
    void rowInsertBelow();
    void rowDelete();
    void columnInsertLeft();
    void columnInsertRight();
    void columnDelete();
    void cellMerge();

    void edit();
    //void cellSplit();
    //void cellSplit(int rows, int columns);
protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void showEvent(QShowEvent * event);
    //virtual void contextMenuEvent(QContextMenuEvent *e);
private:
    void setupFileActions();
    void setupEditActions();
    void setupTextActions();
    void setupTableActions();
    bool load(const QString &f);
    bool maybeSave();
    void setCurrentFileName(const QString &fileName);
public slots:
        void showInit();
private slots:
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void filePrint();
    void filePrintPreview();
    void filePrintPdf();

    void textBold();
    void textUnderline();
    void textItalic();
    void textFamily(const QString &f);
    void textSize(const QString &p);
    void textStyle(int styleIndex);
    void textColor();
    void textAlign(QAction *a);

    void lineDisEdit(int dis);
    void currentCharFormatChanged(const QTextCharFormat &format);
    void cursorPositionChanged();

    void clipboardDataChanged();
    void about();
    void printPreview(QPrinter *);


private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void alignmentChanged(Qt::Alignment a);
    void lineDistanceChanged(const int dis);
    QAction *actionSave,
        *actionTextBold,
        *actionTextUnderline,
        *actionTextItalic,
        *actionTextColor,
        *actionAlignLeft,
        *actionAlignCenter,
        *actionAlignRight,
        *actionAlignJustify,


        *actionInsertTable, //插入表格
        *actionInsertRowAbove,
        *actionInsertRowBelow,
        *actionInsertColumnLeft,
        *actionInsertColumnRight,
        *actionSelectTable,
        *actionSelectRow,
        *actionSelectColumn,
        *actionDeleteTable,
        *actionDeleteRow,
        *actionDeleteColumn,
        *actionTableProperty;

        QMenu *menuTable;
        QMenu *menuInsert;
        QMenu *menuDelete;



    QComboBox *comboStyle;
    QFontComboBox *comboFont;
    QComboBox *comboSize;
    CcolorCombo *colorCombo;


    CsmLineCombo *smLineCombo; //单行字幕或多行文本

    QSpinBox *spinLineDis; //行距

    QToolBar *tb;
    QString fileName;
    CtextEdit *textEdit;
    QTextTableFormat tableFormat;
};

QImage getTextImage(int w, QString str, int *pLineNum, int linePosi[]);
QImage getTableImage(int w, int h, QString str, int *pPageNum);
QImage getTablePageImage(QImage &image, int w, int h, int page);
int getTextPageNum(int mode ,int moveFlag, int imageHeight, int w, int h, int lineNum, int linePosi[], int pagePosi[]);
QImage getTextPageImage(int mode, QImage &image, int w, int h, int page, int pagePosi[]);
QImage getSLineTextImage(QString str, int w, int h, int page);
int getSLineTextPageNum(QString str, int w);
//int getTextImagePageNum(int mode, int w, int h, QString str, int posi[]);
#endif
