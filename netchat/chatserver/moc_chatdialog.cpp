/****************************************************************************
** Meta object code from reading C++ file 'chatdialog.h'
**
** Created: Wed May 11 17:13:45 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chatdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      37,   29,   11,   11, 0x0a,
      69,   65,   11,   11, 0x0a,
      92,   29,   11,   11, 0x0a,
     127,   11,  119,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChatDialog[] = {
    "ChatDialog\0\0slotCreateChat()\0address\0"
    "slotRecvClientInfo(QString)\0msg\0"
    "slotUpdateMsg(QString)\0"
    "slotClientOffLine(QString)\0QString\0"
    "getLocalAddress()\0"
};

const QMetaObject ChatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChatDialog,
      qt_meta_data_ChatDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatDialog))
        return static_cast<void*>(const_cast< ChatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotCreateChat(); break;
        case 1: slotRecvClientInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: slotUpdateMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: slotClientOffLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { QString _r = getLocalAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
