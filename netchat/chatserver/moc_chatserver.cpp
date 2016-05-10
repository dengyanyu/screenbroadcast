/****************************************************************************
** Meta object code from reading C++ file 'chatserver.h'
**
** Created: Thu Mar 31 14:54:45 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chatserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x05,
      50,   46,   11,   11, 0x05,
      75,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     112,  104,   11,   11, 0x0a,
     142,  139,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChatServer[] = {
    "ChatServer\0\0address\0signalClientInfo(QString)\0"
    "msg\0signalUpdataMsg(QString)\0"
    "signalClientOffLine(QString)\0msg,len\0"
    "slotReadyRead(QString,int)\0fd\0"
    "slotDisconnect(int)\0"
};

const QMetaObject ChatServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_ChatServer,
      qt_meta_data_ChatServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatServer))
        return static_cast<void*>(const_cast< ChatServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int ChatServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalClientInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: signalUpdataMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: signalClientOffLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: slotReadyRead((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: slotDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ChatServer::signalClientInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatServer::signalUpdataMsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatServer::signalClientOffLine(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
