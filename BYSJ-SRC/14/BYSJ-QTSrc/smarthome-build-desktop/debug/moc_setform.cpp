/****************************************************************************
** Meta object code from reading C++ file 'setform.h'
**
** Created: Mon Oct 15 13:12:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/setform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_setForm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    9,    8,    8, 0x05,
      30,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_setForm[] = {
    "setForm\0\0num\0comNosender(int)\0"
    "comClosesender()\0on_pushButton_clicked()\0"
};

const QMetaObject setForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_setForm,
      qt_meta_data_setForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &setForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *setForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *setForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_setForm))
        return static_cast<void*>(const_cast< setForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int setForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: comNosender((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: comClosesender(); break;
        case 2: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void setForm::comNosender(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void setForm::comClosesender()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
