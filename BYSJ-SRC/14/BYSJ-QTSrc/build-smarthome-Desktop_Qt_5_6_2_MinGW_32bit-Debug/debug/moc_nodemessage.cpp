/****************************************************************************
** Meta object code from reading C++ file 'nodemessage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/nodemessage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodemessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nodeMessage_t {
    QByteArrayData data[13];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nodeMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nodeMessage_t qt_meta_stringdata_nodeMessage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "nodeMessage"
QT_MOC_LITERAL(1, 12, 10), // "exitSender"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "manCheck"
QT_MOC_LITERAL(4, 33, 4), // "flag"
QT_MOC_LITERAL(5, 38, 10), // "smokeCheck"
QT_MOC_LITERAL(6, 49, 9), // "tempCheck"
QT_MOC_LITERAL(7, 59, 4), // "data"
QT_MOC_LITERAL(8, 64, 8), // "humCheck"
QT_MOC_LITERAL(9, 73, 12), // "changeStatus"
QT_MOC_LITERAL(10, 86, 17), // "on_back_triggered"
QT_MOC_LITERAL(11, 104, 17), // "reveiceSensordata"
QT_MOC_LITERAL(12, 122, 10) // "sensorData"

    },
    "nodeMessage\0exitSender\0\0manCheck\0flag\0"
    "smokeCheck\0tempCheck\0data\0humCheck\0"
    "changeStatus\0on_back_triggered\0"
    "reveiceSensordata\0sensorData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nodeMessage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,
       8,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   12,

       0        // eod
};

void nodeMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        nodeMessage *_t = static_cast<nodeMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exitSender(); break;
        case 1: _t->manCheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->smokeCheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->tempCheck((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->humCheck((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->changeStatus(); break;
        case 6: _t->on_back_triggered(); break;
        case 7: _t->reveiceSensordata((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (nodeMessage::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nodeMessage::exitSender)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (nodeMessage::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nodeMessage::manCheck)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (nodeMessage::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nodeMessage::smokeCheck)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (nodeMessage::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nodeMessage::tempCheck)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (nodeMessage::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&nodeMessage::humCheck)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject nodeMessage::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_nodeMessage.data,
      qt_meta_data_nodeMessage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *nodeMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nodeMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_nodeMessage.stringdata0))
        return static_cast<void*>(const_cast< nodeMessage*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int nodeMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void nodeMessage::exitSender()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void nodeMessage::manCheck(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nodeMessage::smokeCheck(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void nodeMessage::tempCheck(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void nodeMessage::humCheck(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
