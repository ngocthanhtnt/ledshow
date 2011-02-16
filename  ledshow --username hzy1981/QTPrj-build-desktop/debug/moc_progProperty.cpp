/****************************************************************************
** Meta object code from reading C++ file 'progProperty.h'
**
** Created: Wed Feb 16 23:54:28 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPrj/progProperty.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progProperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CprogProperty[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   15,   14,   14, 0x0a,
      46,   15,   14,   14, 0x0a,
      70,   15,   14,   14, 0x0a,
      94,   15,   14,   14, 0x0a,
     113,   15,   14,   14, 0x0a,
     136,   15,   14,   14, 0x0a,
     160,   15,   14,   14, 0x0a,
     181,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CprogProperty[] = {
    "CprogProperty\0\0state\0allWeekDayCheckProc(int)\0"
    "dateTimerCheckProc(int)\0weekTimerCheckProc(int)\0"
    "timeCheckProc(int)\0playTimeCheckProc(int)\0"
    "playCountCheckProc(int)\0borderCheckProc(int)\0"
    "edited()\0"
};

const QMetaObject CprogProperty::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CprogProperty,
      qt_meta_data_CprogProperty, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CprogProperty::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CprogProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CprogProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CprogProperty))
        return static_cast<void*>(const_cast< CprogProperty*>(this));
    return QWidget::qt_metacast(_clname);
}

int CprogProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: allWeekDayCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: dateTimerCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: weekTimerCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: timeCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: playTimeCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: playCountCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: borderCheckProc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: edited(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
