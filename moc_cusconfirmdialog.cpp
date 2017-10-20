/****************************************************************************
** Meta object code from reading C++ file 'cusconfirmdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cusconfirmdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cusconfirmdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cusconfirmdialog_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cusconfirmdialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cusconfirmdialog_t qt_meta_stringdata_cusconfirmdialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "cusconfirmdialog"
QT_MOC_LITERAL(1, 17, 12), // "CusAnsPickup"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "aVehId"
QT_MOC_LITERAL(4, 38, 6), // "aCusId"
QT_MOC_LITERAL(5, 45, 7), // "aAnsStr"
QT_MOC_LITERAL(6, 53, 21), // "on_confirmBtn_clicked"
QT_MOC_LITERAL(7, 75, 20) // "on_rejectBtn_clicked"

    },
    "cusconfirmdialog\0CusAnsPickup\0\0aVehId\0"
    "aCusId\0aAnsStr\0on_confirmBtn_clicked\0"
    "on_rejectBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cusconfirmdialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   36,    2, 0x08 /* Private */,
       7,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cusconfirmdialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cusconfirmdialog *_t = static_cast<cusconfirmdialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CusAnsPickup((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->on_confirmBtn_clicked(); break;
        case 2: _t->on_rejectBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cusconfirmdialog::*_t)(qint64 , qint64 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cusconfirmdialog::CusAnsPickup)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject cusconfirmdialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_cusconfirmdialog.data,
      qt_meta_data_cusconfirmdialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cusconfirmdialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cusconfirmdialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cusconfirmdialog.stringdata0))
        return static_cast<void*>(const_cast< cusconfirmdialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int cusconfirmdialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void cusconfirmdialog::CusAnsPickup(qint64 _t1, qint64 _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
