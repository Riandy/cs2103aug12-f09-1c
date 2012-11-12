/****************************************************************************
** Meta object code from reading C++ file 'StandardView.h'
**
** Created: Mon 12. Nov 23:23:34 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeamPLE/StandardView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StandardView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StandardView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x05,
      47,   35,   13,   13, 0x05,
      90,   65,   13,   13, 0x05,
     126,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     147,   14,   13,   13, 0x08,
     164,   13,   13,   13, 0x08,
     181,   13,   13,   13, 0x08,
     203,   13,   13,   13, 0x08,
     219,   13,   13,   13, 0x08,
     235,   13,   13,   13, 0x08,
     250,   13,   13,   13, 0x08,
     266,   13,   13,   13, 0x08,
     287,   13,   13,   13, 0x08,
     306,   13,   13,   13, 0x08,
     324,   13,   13,   13, 0x08,
     340,   13,   13,   13, 0x08,
     357,   13,   13,   13, 0x08,
     372,   13,   13,   13, 0x08,
     388,   13,   13,   13, 0x08,
     406,   13,   13,   13, 0x08,
     426,   13,   13,   13, 0x08,
     451,   13,   13,   13, 0x08,
     495,  477,   13,   13, 0x08,
     567,   13,   13,   13, 0x08,
     593,   13,   13,   13, 0x08,
     614,   13,   13,   13, 0x08,
     637,   13,   13,   13, 0x08,
     653,   13,   13,   13, 0x08,
     670,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StandardView[] = {
    "StandardView\0\0input\0relay(QString)\0"
    "input,focus\0run(QString,bool)\0"
    "input,inputChecked,focus\0"
    "toSeampleView(QString,QString,bool)\0"
    "todayViewTriggered()\0recieve(QString)\0"
    "enterTriggered()\0changeViewTriggered()\0"
    "undoTriggered()\0redoTriggered()\0"
    "addTriggered()\0findTriggered()\0"
    "findFloatTriggered()\0displayTriggered()\0"
    "deleteTriggered()\0editTriggered()\0"
    "clearTriggered()\0fadeInChange()\0"
    "fadeOutChange()\0pageUpTriggered()\0"
    "pageDownTriggered()\0changeDisplayTriggered()\0"
    "changeViewModeTriggered()\0newState,oldState\0"
    "checkAnimationDone(QAbstractAnimation::State,QAbstractAnimation::State"
    ")\0"
    "calibrateCloseMechanism()\0"
    "screenTwoTriggered()\0screenThreeTriggered()\0"
    "markTriggered()\0todayTriggered()\0"
    "helpTriggered()\0"
};

void StandardView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StandardView *_t = static_cast<StandardView *>(_o);
        switch (_id) {
        case 0: _t->relay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->run((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->toSeampleView((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->todayViewTriggered(); break;
        case 4: _t->recieve((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->enterTriggered(); break;
        case 6: _t->changeViewTriggered(); break;
        case 7: _t->undoTriggered(); break;
        case 8: _t->redoTriggered(); break;
        case 9: _t->addTriggered(); break;
        case 10: _t->findTriggered(); break;
        case 11: _t->findFloatTriggered(); break;
        case 12: _t->displayTriggered(); break;
        case 13: _t->deleteTriggered(); break;
        case 14: _t->editTriggered(); break;
        case 15: _t->clearTriggered(); break;
        case 16: _t->fadeInChange(); break;
        case 17: _t->fadeOutChange(); break;
        case 18: _t->pageUpTriggered(); break;
        case 19: _t->pageDownTriggered(); break;
        case 20: _t->changeDisplayTriggered(); break;
        case 21: _t->changeViewModeTriggered(); break;
        case 22: _t->checkAnimationDone((*reinterpret_cast< QAbstractAnimation::State(*)>(_a[1])),(*reinterpret_cast< QAbstractAnimation::State(*)>(_a[2]))); break;
        case 23: _t->calibrateCloseMechanism(); break;
        case 24: _t->screenTwoTriggered(); break;
        case 25: _t->screenThreeTriggered(); break;
        case 26: _t->markTriggered(); break;
        case 27: _t->todayTriggered(); break;
        case 28: _t->helpTriggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StandardView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StandardView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StandardView,
      qt_meta_data_StandardView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StandardView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StandardView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StandardView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StandardView))
        return static_cast<void*>(const_cast< StandardView*>(this));
    if (!strcmp(_clname, "CommonView"))
        return static_cast< CommonView*>(const_cast< StandardView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StandardView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void StandardView::relay(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StandardView::run(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StandardView::toSeampleView(QString _t1, QString _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StandardView::todayViewTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
