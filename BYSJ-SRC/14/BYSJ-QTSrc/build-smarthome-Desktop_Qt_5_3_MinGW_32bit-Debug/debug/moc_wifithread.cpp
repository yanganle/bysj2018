/****************************************************************************
** Meta object code from reading C++ file 'wifithread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/wifithread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifithread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WifiThread_t {
    QByteArrayData data[9];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WifiThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WifiThread_t qt_meta_stringdata_WifiThread = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 15),
QT_MOC_LITERAL(4, 43, 4),
QT_MOC_LITERAL(5, 48, 9),
QT_MOC_LITERAL(6, 58, 20),
QT_MOC_LITERAL(7, 79, 12),
QT_MOC_LITERAL(8, 92, 3)
    },
    "WifiThread\0sensorWifiData\0\0wifiStatesender\0"
    "flag\0wifiClose\0readPendingDatagrams\0"
    "SendWifiData\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WifiThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   45,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,

       0        // eod
};

void WifiThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WifiThread *_t = static_cast<WifiThread *>(_o);
        switch (_id) {
        case 0: _t->sensorWifiData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->wifiStatesender((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->wifiClose(); break;
        case 3: _t->readPendingDatagrams(); break;
        case 4: _t->SendWifiData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WifiThread::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WifiThread::sensorWifiData)) {
                *result = 0;
            }
        }
        {
            typedef void (WifiThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WifiThread::wifiStatesender)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WifiThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WifiThread.data,
      qt_meta_data_WifiThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *WifiThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WifiThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WifiThread.stringdata))
        return static_cast<void*>(const_cast< WifiThread*>(this));
    return QThread::qt_metacast(_clname);
}

int WifiThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WifiThread::sensorWifiData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WifiThread::wifiStatesender(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
