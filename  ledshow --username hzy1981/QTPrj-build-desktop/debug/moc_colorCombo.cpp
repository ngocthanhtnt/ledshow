/****************************************************************************
** Meta object code from reading C++ file 'colorCombo.h'
**
** Created: Mon Mar 14 21:35:35 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPrj/colorCombo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorCombo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CsizeCombo[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CsizeCombo[] = {
    "CsizeCombo\0\0indexChangeSignal()\0"
    "setItems()\0"
};

const QMetaObject CsizeCombo::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_CsizeCombo,
      qt_meta_data_CsizeCombo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CsizeCombo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CsizeCombo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CsizeCombo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CsizeCombo))
        return static_cast<void*>(const_cast< CsizeCombo*>(this));
    return QComboBox::qt_metacast(_clname);
}

int CsizeCombo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: indexChangeSignal(); break;
        case 1: setItems(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CsizeCombo::indexChangeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_CcolorCombo[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CcolorCombo[] = {
    "CcolorCombo\0\0indexChangeSignal()\0"
    "setItems()\0"
};

const QMetaObject CcolorCombo::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_CcolorCombo,
      qt_meta_data_CcolorCombo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CcolorCombo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CcolorCombo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CcolorCombo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CcolorCombo))
        return static_cast<void*>(const_cast< CcolorCombo*>(this));
    return QComboBox::qt_metacast(_clname);
}

int CcolorCombo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: indexChangeSignal(); break;
        case 1: setItems(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CcolorCombo::indexChangeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
