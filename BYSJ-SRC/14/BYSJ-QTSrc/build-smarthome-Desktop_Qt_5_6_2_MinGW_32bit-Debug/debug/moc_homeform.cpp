/****************************************************************************
** Meta object code from reading C++ file 'homeform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/homeform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homeform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_homeForm_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_homeForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_homeForm_t qt_meta_stringdata_homeForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "homeForm"
QT_MOC_LITERAL(1, 9, 10), // "tempSender"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "temp"
QT_MOC_LITERAL(4, 26, 9), // "humSender"
QT_MOC_LITERAL(5, 36, 3), // "hum"
QT_MOC_LITERAL(6, 40, 12), // "setTemplabel"
QT_MOC_LITERAL(7, 53, 11) // "setHumlabel"

    },
    "homeForm\0tempSender\0\0temp\0humSender\0"
    "hum\0setTemplabel\0setHumlabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_homeForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void homeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        homeForm *_t = static_cast<homeForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tempSender((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->humSender((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setTemplabel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setHumlabel((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (homeForm::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&homeForm::tempSender)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (homeForm::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&homeForm::humSender)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject homeForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_homeForm.data,
      qt_meta_data_homeForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *homeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *homeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_homeForm.stringdata0))
        return static_cast<void*>(const_cast< homeForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int homeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void homeForm::tempSender(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void homeForm::humSender(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
