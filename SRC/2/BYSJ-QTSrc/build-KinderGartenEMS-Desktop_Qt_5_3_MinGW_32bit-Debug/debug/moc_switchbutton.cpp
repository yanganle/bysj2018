/****************************************************************************
** Meta object code from reading C++ file 'switchbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../KinderGartenEMS/switchbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'switchbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SwitchButton_t {
    QByteArrayData data[28];
    char stringdata[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchButton_t qt_meta_stringdata_SwitchButton = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 7),
QT_MOC_LITERAL(4, 37, 11),
QT_MOC_LITERAL(5, 49, 10),
QT_MOC_LITERAL(6, 60, 14),
QT_MOC_LITERAL(7, 75, 11),
QT_MOC_LITERAL(8, 87, 11),
QT_MOC_LITERAL(9, 99, 10),
QT_MOC_LITERAL(10, 110, 10),
QT_MOC_LITERAL(11, 121, 9),
QT_MOC_LITERAL(12, 131, 14),
QT_MOC_LITERAL(13, 146, 14),
QT_MOC_LITERAL(14, 161, 13),
QT_MOC_LITERAL(15, 175, 12),
QT_MOC_LITERAL(16, 188, 12),
QT_MOC_LITERAL(17, 201, 11),
QT_MOC_LITERAL(18, 213, 7),
QT_MOC_LITERAL(19, 221, 7),
QT_MOC_LITERAL(20, 229, 6),
QT_MOC_LITERAL(21, 236, 8),
QT_MOC_LITERAL(22, 245, 8),
QT_MOC_LITERAL(23, 254, 7),
QT_MOC_LITERAL(24, 262, 8),
QT_MOC_LITERAL(25, 271, 5),
QT_MOC_LITERAL(26, 277, 13),
QT_MOC_LITERAL(27, 291, 10)
    },
    "SwitchButton\0checkedChanged\0\0checked\0"
    "updateValue\0setChecked\0setButtonStyle\0"
    "ButtonStyle\0buttonStyle\0setBgColor\0"
    "bgColorOff\0bgColorOn\0setSliderColor\0"
    "sliderColorOff\0sliderColorOn\0setTextColor\0"
    "textColorOff\0textColorOn\0setText\0"
    "textOff\0textOn\0setImage\0imageOff\0"
    "imageOn\0setSpace\0space\0setRectRadius\0"
    "rectRadius"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   72,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x0a /* Public */,
       6,    1,   76,    2, 0x0a /* Public */,
       9,    2,   79,    2, 0x0a /* Public */,
      12,    2,   84,    2, 0x0a /* Public */,
      15,    2,   89,    2, 0x0a /* Public */,
      18,    2,   94,    2, 0x0a /* Public */,
      21,    2,   99,    2, 0x0a /* Public */,
      24,    1,  104,    2, 0x0a /* Public */,
      26,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QColor, QMetaType::QColor,   10,   11,
    QMetaType::Void, QMetaType::QColor, QMetaType::QColor,   13,   14,
    QMetaType::Void, QMetaType::QColor, QMetaType::QColor,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   22,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   27,

       0        // eod
};

void SwitchButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SwitchButton *_t = static_cast<SwitchButton *>(_o);
        switch (_id) {
        case 0: _t->checkedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateValue(); break;
        case 2: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setButtonStyle((*reinterpret_cast< ButtonStyle(*)>(_a[1]))); break;
        case 4: _t->setBgColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 5: _t->setSliderColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 6: _t->setTextColor((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 7: _t->setText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->setImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->setSpace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setRectRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SwitchButton::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SwitchButton::checkedChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SwitchButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SwitchButton.data,
      qt_meta_data_SwitchButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *SwitchButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchButton.stringdata))
        return static_cast<void*>(const_cast< SwitchButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int SwitchButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SwitchButton::checkedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
