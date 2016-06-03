/****************************************************************************
** Meta object code from reading C++ file 'chatdialog.h'
**
** Created: Fri Jun 3 11:59:53 2016
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x05,
      56,   50,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   11,   11,   11, 0x0a,
     112,  104,   11,   11, 0x0a,
     144,  140,   11,   11, 0x0a,
     167,  104,   11,   11, 0x0a,
     202,   11,  194,   11, 0x0a,
     220,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     266,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChatDialog[] = {
    "ChatDialog\0\0filename\0signal_fileDown(QStringList)\0"
    "image\0signal_screenBroadcast(QImage)\0"
    "slotCreateChat()\0address\0"
    "slotRecvClientInfo(QString)\0msg\0"
    "slotUpdateMsg(QString)\0"
    "slotClientOffLine(QString)\0QString\0"
    "getLocalAddress()\0on_pbroadcast_clicked()\0"
    "on_psendDir_clicked()\0on_pSendBtn_clicked()\0"
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
        case 0: signal_fileDown((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: signal_screenBroadcast((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: slotCreateChat(); break;
        case 3: slotRecvClientInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: slotUpdateMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: slotClientOffLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { QString _r = getLocalAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: on_pbroadcast_clicked(); break;
        case 8: on_psendDir_clicked(); break;
        case 9: on_pSendBtn_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ChatDialog::signal_fileDown(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatDialog::signal_screenBroadcast(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
