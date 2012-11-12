/****************************************************************************
** Meta object code from reading C++ file 'TimeGetter.h'
**
** Created: Mon 12. Nov 13:04:39 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeamPLE/TimeGetter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimeGetter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TimeGetter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TimeGetter[] = {
    "TimeGetter\0\0dateAndTime\0"
    "relayStringDateAndTime(QString)\0"
    "getStringDateAndTime()\0"
};

void TimeGetter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimeGetter *_t = static_cast<TimeGetter *>(_o);
        switch (_id) {
        case 0: _t->relayStringDateAndTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getStringDateAndTime(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TimeGetter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TimeGetter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimeGetter,
      qt_meta_data_TimeGetter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimeGetter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimeGetter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimeGetter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimeGetter))
        return static_cast<void*>(const_cast< TimeGetter*>(this));
    return QObject::qt_metacast(_clname);
}

int TimeGetter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TimeGetter::relayStringDateAndTime(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
