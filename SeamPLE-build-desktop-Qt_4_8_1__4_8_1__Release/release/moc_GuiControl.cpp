/****************************************************************************
** Meta object code from reading C++ file 'GuiControl.h'
**
** Created: Mon 12. Nov 11:41:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeamPLE/GuiControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GuiControl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      56,   33,   11,   11, 0x08,
     120,   84,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GuiControl[] = {
    "GuiControl\0\0input\0check(QString)\0"
    "input,inputBarHasFocus\0"
    "passScheduler(QString,bool)\0"
    "input,inputChecked,inputBarHasFocus\0"
    "changeView(QString,QString,bool)\0"
    "showHelpView()\0getTodaysEvents()\0"
};

void GuiControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GuiControl *_t = static_cast<GuiControl *>(_o);
        switch (_id) {
        case 0: _t->check((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->passScheduler((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->changeView((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->showHelpView(); break;
        case 4: _t->getTodaysEvents(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GuiControl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GuiControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GuiControl,
      qt_meta_data_GuiControl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GuiControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GuiControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GuiControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuiControl))
        return static_cast<void*>(const_cast< GuiControl*>(this));
    return QObject::qt_metacast(_clname);
}

int GuiControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
