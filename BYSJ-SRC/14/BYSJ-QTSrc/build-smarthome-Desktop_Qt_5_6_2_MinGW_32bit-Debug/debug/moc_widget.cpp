/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[14];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 14), // "comClosesender"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 45, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(5, 68, 15), // "receviceMandata"
QT_MOC_LITERAL(6, 84, 4), // "flag"
QT_MOC_LITERAL(7, 89, 17), // "receviceSmokedata"
QT_MOC_LITERAL(8, 107, 15), // "receviceHumdata"
QT_MOC_LITERAL(9, 123, 4), // "data"
QT_MOC_LITERAL(10, 128, 16), // "receviceTempdata"
QT_MOC_LITERAL(11, 145, 13), // "receviceComNo"
QT_MOC_LITERAL(12, 159, 3), // "com"
QT_MOC_LITERAL(13, 163, 11) // "setComstate"

    },
    "Widget\0comClosesender\0\0on_pushButton_clicked\0"
    "on_startButton_clicked\0receviceMandata\0"
    "flag\0receviceSmokedata\0receviceHumdata\0"
    "data\0receviceTempdata\0receviceComNo\0"
    "com\0setComstate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,
      10,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->comClosesender(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_startButton_clicked(); break;
        case 3: _t->receviceMandata((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->receviceSmokedata((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->receviceHumdata((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->receviceTempdata((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->receviceComNo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setComstate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::comClosesender)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Widget::comClosesender()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
