/****************************************************************************
** Meta object code from reading C++ file 'areaProperty.h'
**
** Created: Mon Mar 14 22:38:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPrj/areaProperty.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'areaProperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Carea[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      17,    6,    6,    6, 0x0a,
      27,    6,    6,    6, 0x0a,
      40,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Carea[] = {
    "Carea\0\0xEdited()\0yEdited()\0xLenEdited()\0"
    "yLenEdited()\0"
};

const QMetaObject Carea::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_Carea,
      qt_meta_data_Carea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Carea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Carea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Carea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Carea))
        return static_cast<void*>(const_cast< Carea*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int Carea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: xEdited(); break;
        case 1: yEdited(); break;
        case 2: xLenEdited(); break;
        case 3: yLenEdited(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_CareaProperty[] = {

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
      15,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CareaProperty[] = {
    "CareaProperty\0\0edited()\0"
};

const QMetaObject CareaProperty::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CareaProperty,
      qt_meta_data_CareaProperty, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CareaProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CareaProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CareaProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CareaProperty))
        return static_cast<void*>(const_cast< CareaProperty*>(this));
    return QWidget::qt_metacast(_clname);
}

int CareaProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: edited(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
