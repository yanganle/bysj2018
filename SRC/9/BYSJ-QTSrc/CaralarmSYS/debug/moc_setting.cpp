/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../setting.h"
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
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setting_t qt_meta_stringdata_setting = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 13),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 3),
QT_MOC_LITERAL(4, 27, 14),
QT_MOC_LITERAL(5, 42, 14),
QT_MOC_LITERAL(6, 57, 15),
QT_MOC_LITERAL(7, 73, 11),
QT_MOC_LITERAL(8, 85, 4),
QT_MOC_LITERAL(9, 90, 21),
QT_MOC_LITERAL(10, 112, 21),
QT_MOC_LITERAL(11, 134, 24)
    },
    "setting\0comInitsender\0\0com\0wifiInitsender\0"
    "comClosesender\0wifiClosesender\0"
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
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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
        case 0: _t->comInitsender((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->wifiInitsender(); break;
        case 2: _t->comClosesender(); break;
        case 3: _t->wifiClosesender(); break;
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
            typedef void (setting::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setting::comInitsender)) {
                *result = 0;
            }
        }
        {
            typedef void (setting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setting::wifiInitsender)) {
                *result = 1;
            }
        }
        {
            typedef void (setting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setting::comClosesender)) {
                *result = 2;
            }
        }
        {
            typedef void (setting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setting::wifiClosesender)) {
                *result = 3;
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
void setting::comInitsender(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void setting::wifiInitsender()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void setting::comClosesender()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void setting::wifiClosesender()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
