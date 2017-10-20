/****************************************************************************
** Meta object code from reading C++ file 'vrptest_stkci_sub.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vrptest_stkci_sub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vrptest_stkci_sub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vrptest_stkci_sub_t {
    QByteArrayData data[12];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vrptest_stkci_sub_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vrptest_stkci_sub_t qt_meta_stringdata_vrptest_stkci_sub = {
    {
QT_MOC_LITERAL(0, 0, 17), // "vrptest_stkci_sub"
QT_MOC_LITERAL(1, 18, 17), // "sendCusConfirmAns"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "aVehId"
QT_MOC_LITERAL(4, 44, 6), // "aCusId"
QT_MOC_LITERAL(5, 51, 7), // "aAnsStr"
QT_MOC_LITERAL(6, 59, 24), // "createArrAnsDialogSignal"
QT_MOC_LITERAL(7, 84, 9), // "aWaitTime"
QT_MOC_LITERAL(8, 94, 24), // "deleteArrAnsDialogSignal"
QT_MOC_LITERAL(9, 119, 14), // "starttimerslot"
QT_MOC_LITERAL(10, 134, 6), // "listen"
QT_MOC_LITERAL(11, 141, 16) // "rcvCusAnsArrival"

    },
    "vrptest_stkci_sub\0sendCusConfirmAns\0"
    "\0aVehId\0aCusId\0aAnsStr\0createArrAnsDialogSignal\0"
    "aWaitTime\0deleteArrAnsDialogSignal\0"
    "starttimerslot\0listen\0rcvCusAnsArrival"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vrptest_stkci_sub[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    3,   51,    2, 0x06 /* Public */,
       8,    2,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    3,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::LongLong,    3,    4,    7,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void vrptest_stkci_sub::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vrptest_stkci_sub *_t = static_cast<vrptest_stkci_sub *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCusConfirmAns((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->createArrAnsDialogSignal((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 2: _t->deleteArrAnsDialogSignal((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->starttimerslot(); break;
        case 4: _t->listen(); break;
        case 5: _t->rcvCusAnsArrival((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vrptest_stkci_sub::*_t)(qint64 , qint64 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vrptest_stkci_sub::sendCusConfirmAns)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (vrptest_stkci_sub::*_t)(qint64 , qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vrptest_stkci_sub::createArrAnsDialogSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (vrptest_stkci_sub::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vrptest_stkci_sub::deleteArrAnsDialogSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject vrptest_stkci_sub::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vrptest_stkci_sub.data,
      qt_meta_data_vrptest_stkci_sub,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vrptest_stkci_sub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vrptest_stkci_sub::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vrptest_stkci_sub.stringdata0))
        return static_cast<void*>(const_cast< vrptest_stkci_sub*>(this));
    return QObject::qt_metacast(_clname);
}

int vrptest_stkci_sub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void vrptest_stkci_sub::sendCusConfirmAns(qint64 _t1, qint64 _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vrptest_stkci_sub::createArrAnsDialogSignal(qint64 _t1, qint64 _t2, qint64 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vrptest_stkci_sub::deleteArrAnsDialogSignal(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
