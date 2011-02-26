/****************************************************************************
** Meta object code from reading C++ file 'progManage.h'
**
** Created: Sat Feb 26 11:55:51 2011
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      25,   12,   12,   12, 0x0a,
      35,   12,   12,   12, 0x0a,
      45,   12,   12,   12, 0x0a,
      56,   12,   12,   12, 0x0a,
      65,   12,   12,   12, 0x0a,
      76,   12,   12,   12, 0x0a,
      86,   12,   12,   12, 0x0a,
      97,   12,   12,   12, 0x0a,
     108,   12,   12,   12, 0x0a,
     118,   12,   12,   12, 0x0a,
     127,   12,   12,   12, 0x0a,
     141,   12,   12,   12, 0x0a,
     152,   12,   12,   12, 0x0a,
     177,  165,   12,   12, 0x0a,
     226,  209,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CprogManage[] = {
    "CprogManage\0\0newScreen()\0newProg()\0"
    "newArea()\0newSText()\0newPic()\0newFlash()\0"
    "newTime()\0newTimer()\0newClock()\0"
    "newTemp()\0newLun()\0newHumidity()\0"
    "newNoise()\0deleteItem()\0item,column\0"
    "clickItem(QTreeWidgetItem*,int)\0"
    "current,previous\0"
    "currentItemChangedProc(QTreeWidgetItem*,QTreeWidgetItem*)\0"
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
        case 0: newScreen(); break;
        case 1: newProg(); break;
        case 2: newArea(); break;
        case 3: newSText(); break;
        case 4: newPic(); break;
        case 5: newFlash(); break;
        case 6: newTime(); break;
        case 7: newTimer(); break;
        case 8: newClock(); break;
        case 9: newTemp(); break;
        case 10: newLun(); break;
        case 11: newHumidity(); break;
        case 12: newNoise(); break;
        case 13: deleteItem(); break;
        case 14: clickItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: currentItemChangedProc((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
