/****************************************************************************
** Meta object code from reading C++ file 'vrptest_stkci_pub.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vrptest_stkci_pub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vrptest_stkci_pub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vrptest_stkci_pub_t {
    QByteArrayData data[7];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vrptest_stkci_pub_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vrptest_stkci_pub_t qt_meta_stringdata_vrptest_stkci_pub = {
    {
QT_MOC_LITERAL(0, 0, 17), // "vrptest_stkci_pub"
QT_MOC_LITERAL(1, 18, 16), // "RcvCusConfirmAns"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "aVehId"
QT_MOC_LITERAL(4, 43, 6), // "aCusId"
QT_MOC_LITERAL(5, 50, 7), // "aAnsStr"
QT_MOC_LITERAL(6, 58, 7) // "loopMsg"

    },
    "vrptest_stkci_pub\0RcvCusConfirmAns\0\0"
    "aVehId\0aCusId\0aAnsStr\0loopMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vrptest_stkci_pub[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x0a /* Public */,
       6,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,    3,    4,    5,
    QMetaType::Void,

       0        // eod
};

void vrptest_stkci_pub::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vrptest_stkci_pub *_t = static_cast<vrptest_stkci_pub *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RcvCusConfirmAns((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->loopMsg(); break;
        default: ;
        }
    }
}

const QMetaObject vrptest_stkci_pub::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vrptest_stkci_pub.data,
      qt_meta_data_vrptest_stkci_pub,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vrptest_stkci_pub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vrptest_stkci_pub::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vrptest_stkci_pub.stringdata0))
        return static_cast<void*>(const_cast< vrptest_stkci_pub*>(this));
    return QObject::qt_metacast(_clname);
}

int vrptest_stkci_pub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
