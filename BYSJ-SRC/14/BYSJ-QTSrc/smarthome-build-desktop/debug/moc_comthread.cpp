/****************************************************************************
** Meta object code from reading C++ file 'comthread.h'
**
** Created: Mon Oct 15 13:11:57 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smarthome/comthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_comThread[] = {

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
      11,   10,   10,   10, 0x05,
      39,   34,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_comThread[] = {
    "comThread\0\0sensorData(QByteArray)\0"
    "flag\0comStatesender(bool)\0comClose()\0"
};

const QMetaObject comThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_comThread,
      qt_meta_data_comThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &comThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *comThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *comThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_comThread))
        return static_cast<void*>(const_cast< comThread*>(this));
    return QThread::qt_metacast(_clname);
}

int comThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sensorData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: comStatesender((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: comClose(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void comThread::sensorData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void comThread::comStatesender(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
