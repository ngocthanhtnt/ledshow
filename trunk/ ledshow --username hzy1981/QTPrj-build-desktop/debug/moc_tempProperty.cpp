/****************************************************************************
** Meta object code from reading C++ file 'tempProperty.h'
**
** Created: Wed Jan 19 22:04:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPrj/tempProperty.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tempProperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ctemp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Ctemp[] = {
    "Ctemp\0\0edited()\0"
};

const QMetaObject Ctemp::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_Ctemp,
      qt_meta_data_Ctemp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ctemp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ctemp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ctemp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ctemp))
        return static_cast<void*>(const_cast< Ctemp*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int Ctemp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Ctemp::edited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_CtempProperty[] = {

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

static const char qt_meta_stringdata_CtempProperty[] = {
    "CtempProperty\0\0edited()\0"
};

const QMetaObject CtempProperty::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CtempProperty,
      qt_meta_data_CtempProperty, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CtempProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CtempProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CtempProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CtempProperty))
        return static_cast<void*>(const_cast< CtempProperty*>(this));
    return QWidget::qt_metacast(_clname);
}

int CtempProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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