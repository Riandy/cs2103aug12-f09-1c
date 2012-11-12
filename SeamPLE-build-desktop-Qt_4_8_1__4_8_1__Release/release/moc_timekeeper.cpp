/****************************************************************************
** Meta object code from reading C++ file 'timekeeper.h'
**
** Created: Mon 12. Nov 23:23:34 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeamPLE/timekeeper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timekeeper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Timekeeper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Timekeeper[] = {
    "Timekeeper\0\0oneMinuteTrigger()\0"
    "reachOneMinute()\0getEventForPopUp()\0"
    "configureDone()\0"
};

void Timekeeper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Timekeeper *_t = static_cast<Timekeeper *>(_o);
        switch (_id) {
        case 0: _t->oneMinuteTrigger(); break;
        case 1: _t->reachOneMinute(); break;
        case 2: _t->getEventForPopUp(); break;
        case 3: _t->configureDone(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Timekeeper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Timekeeper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Timekeeper,
      qt_meta_data_Timekeeper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Timekeeper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Timekeeper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Timekeeper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Timekeeper))
        return static_cast<void*>(const_cast< Timekeeper*>(this));
    return QObject::qt_metacast(_clname);
}

int Timekeeper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Timekeeper::oneMinuteTrigger()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
