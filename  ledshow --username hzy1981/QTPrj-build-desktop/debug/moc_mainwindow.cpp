/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Mar 11 23:37:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPrj/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x0a,
     124,   11,   11,   11, 0x0a,
     139,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     164,   11,   11,   11, 0x0a,
     182,   11,   11,   11, 0x0a,
     201,   11,   11,   11, 0x0a,
     211,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0fileSaveAs()\0fileSave()\0"
    "fileNew()\0fileOpen()\0settingsInit()\0"
    "updateTreeWidget(QMdiSubWindow*)\0"
    "modifyScreenPara()\0setLightness()\0"
    "adjTime()\0sendDataProc()\0exportUdsikProc()\0"
    "setOpenCloseTime()\0preview()\0previewProc()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileSaveAs(); break;
        case 1: fileSave(); break;
        case 2: fileNew(); break;
        case 3: fileOpen(); break;
        case 4: settingsInit(); break;
        case 5: updateTreeWidget((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 6: modifyScreenPara(); break;
        case 7: setLightness(); break;
        case 8: adjTime(); break;
        case 9: sendDataProc(); break;
        case 10: exportUdsikProc(); break;
        case 11: setOpenCloseTime(); break;
        case 12: preview(); break;
        case 13: previewProc(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
static const uint qt_meta_data_CinputPSWDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CinputPSWDialog[] = {
    "CinputPSWDialog\0\0okClickProc()\0"
};

const QMetaObject CinputPSWDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CinputPSWDialog,
      qt_meta_data_CinputPSWDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CinputPSWDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CinputPSWDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CinputPSWDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CinputPSWDialog))
        return static_cast<void*>(const_cast< CinputPSWDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CinputPSWDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: okClickProc(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
