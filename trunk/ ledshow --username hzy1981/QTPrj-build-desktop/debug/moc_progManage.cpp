/****************************************************************************
** Meta object code from reading C++ file 'progManage.h'
**
** Created: Fri Dec 10 01:07:28 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTPrj/progManage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progManage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CprogManage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      23,   12,   12,   12, 0x0a,
      33,   12,   12,   12, 0x0a,
      42,   12,   12,   12, 0x0a,
      53,   12,   12,   12, 0x0a,
      63,   12,   12,   12, 0x0a,
      74,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
      95,   12,   12,   12, 0x0a,
     104,   12,   12,   12, 0x0a,
     129,  117,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CprogManage[] = {
    "CprogManage\0\0newProg()\0newArea()\0"
    "newPic()\0newFlash()\0newTime()\0newTimer()\0"
    "newClock()\0newTemp()\0newLun()\0"
    "deleteItem()\0item,column\0"
    "clickItem(QTreeWidgetItem*,int)\0"
};

const QMetaObject CprogManage::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_CprogManage,
      qt_meta_data_CprogManage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CprogManage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CprogManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CprogManage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CprogManage))
        return static_cast<void*>(const_cast< CprogManage*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int CprogManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newProg(); break;
        case 1: newArea(); break;
        case 2: newPic(); break;
        case 3: newFlash(); break;
        case 4: newTime(); break;
        case 5: newTimer(); break;
        case 6: newClock(); break;
        case 7: newTemp(); break;
        case 8: newLun(); break;
        case 9: deleteItem(); break;
        case 10: clickItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
