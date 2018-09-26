/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_setting_t {
    QByteArrayData data[12];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setting_t qt_meta_stringdata_setting = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 14),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 15),
QT_MOC_LITERAL(4, 40, 13),
QT_MOC_LITERAL(5, 54, 3),
QT_MOC_LITERAL(6, 58, 16),
QT_MOC_LITERAL(7, 75, 11),
QT_MOC_LITERAL(8, 87, 4),
QT_MOC_LITERAL(9, 92, 21),
QT_MOC_LITERAL(10, 114, 21),
QT_MOC_LITERAL(11, 136, 24)
    },
    "setting\0comClosesender\0\0wifiClosesender\0"
    "receviceComNo\0com\0receviceWifiData\0"
    "setComstate\0flag\0on_wifiButton_clicked\0"
    "on_uartButton_clicked\0on_connectButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   56,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setting *_t = static_cast<setting *>(_o);
        switch (_id) {
        case 0: _t->comClosesender(); break;
        case 1: _t->wifiClosesender(); break;
        case 2: _t->receviceComNo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->receviceWifiData(); break;
        case 4: _t->setComstate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_wifiButton_clicked(); break;
        case 6: _t->on_uartButton_clicked(); break;
        case 7: _t->on_connectButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (setting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setting::comClosesender)) {
                *result = 0;
            }
        }
        {
            typedef void (setting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setting::wifiClosesender)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject setting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_setting.data,
      qt_meta_data_setting,  qt_static_metacall, 0, 0}
};


const QMetaObject *setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_setting.stringdata))
        return static_cast<void*>(const_cast< setting*>(this));
    return QDialog::qt_metacast(_clname);
}

int setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void setting::comClosesender()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void setting::wifiClosesender()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
