/****************************************************************************
** Meta object code from reading C++ file 'homeform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/homeform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homeform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_homeForm_t {
    QByteArrayData data[22];
    char stringdata[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_homeForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_homeForm_t qt_meta_stringdata_homeForm = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 9),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 5),
QT_MOC_LITERAL(4, 26, 9),
QT_MOC_LITERAL(5, 36, 10),
QT_MOC_LITERAL(6, 47, 4),
QT_MOC_LITERAL(7, 52, 11),
QT_MOC_LITERAL(8, 64, 13),
QT_MOC_LITERAL(9, 78, 11),
QT_MOC_LITERAL(10, 90, 10),
QT_MOC_LITERAL(11, 101, 18),
QT_MOC_LITERAL(12, 120, 11),
QT_MOC_LITERAL(13, 132, 18),
QT_MOC_LITERAL(14, 151, 14),
QT_MOC_LITERAL(15, 166, 11),
QT_MOC_LITERAL(16, 178, 12),
QT_MOC_LITERAL(17, 191, 14),
QT_MOC_LITERAL(18, 206, 9),
QT_MOC_LITERAL(19, 216, 21),
QT_MOC_LITERAL(20, 238, 21),
QT_MOC_LITERAL(21, 260, 20)
    },
    "homeForm\0tempcheck\0\0value\0humicheck\0"
    "lightcheck\0flag\0sensorCtrol\0sensorCmdData\0"
    "reveiceData\0sensorData\0button1CheckHandle\0"
    "buttonstate\0button2CheckHandle\0"
    "saveDatatoList\0QByteArray&\0changeStatus\0"
    "switchRunModle\0modelflag\0on_tempButton_clicked\0"
    "on_humiButton_clicked\0on_gasButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_homeForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       7,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   91,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,
      14,    1,  100,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,
      17,    1,  104,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x08 /* Private */,
      20,    0,  108,    2, 0x08 /* Private */,
      21,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Bool, 0x80000000 | 15,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void homeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        homeForm *_t = static_cast<homeForm *>(_o);
        switch (_id) {
        case 0: _t->tempcheck((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->humicheck((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->lightcheck((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sensorCtrol((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->reveiceData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->button1CheckHandle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->button2CheckHandle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: { bool _r = _t->saveDatatoList((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->changeStatus(); break;
        case 9: _t->switchRunModle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_tempButton_clicked(); break;
        case 11: _t->on_humiButton_clicked(); break;
        case 12: _t->on_gasButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (homeForm::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&homeForm::tempcheck)) {
                *result = 0;
            }
        }
        {
            typedef void (homeForm::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&homeForm::humicheck)) {
                *result = 1;
            }
        }
        {
            typedef void (homeForm::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&homeForm::lightcheck)) {
                *result = 2;
            }
        }
        {
            typedef void (homeForm::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&homeForm::sensorCtrol)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject homeForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_homeForm.data,
      qt_meta_data_homeForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *homeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *homeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_homeForm.stringdata))
        return static_cast<void*>(const_cast< homeForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int homeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void homeForm::tempcheck(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void homeForm::humicheck(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void homeForm::lightcheck(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void homeForm::sensorCtrol(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE