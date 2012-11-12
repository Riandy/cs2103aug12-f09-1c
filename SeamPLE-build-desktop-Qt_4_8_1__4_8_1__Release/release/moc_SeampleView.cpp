/****************************************************************************
** Meta object code from reading C++ file 'SeampleView.h'
**
** Created: Mon 12. Nov 11:41:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeamPLE/SeampleView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SeampleView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SeampleView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      46,   34,   12,   12, 0x05,
      89,   64,   12,   12, 0x05,
     126,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     140,   13,   12,   12, 0x08,
     157,   12,   12,   12, 0x08,
     174,   12,   12,   12, 0x08,
     196,   12,   12,   12, 0x08,
     212,   12,   12,   12, 0x08,
     228,   12,   12,   12, 0x08,
     243,   12,   12,   12, 0x08,
     259,   12,   12,   12, 0x08,
     280,   12,   12,   12, 0x08,
     299,   12,   12,   12, 0x08,
     317,   12,   12,   12, 0x08,
     333,   12,   12,   12, 0x08,
     350,   12,   12,   12, 0x08,
     368,  366,   12,   12, 0x08,
     443,  366,   12,   12, 0x08,
     518,   12,   12,   12, 0x08,
     534,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SeampleView[] = {
    "SeampleView\0\0input\0relay(QString)\0"
    "input,focus\0run(QString,bool)\0"
    "input,inputChecked,focus\0"
    "toStandardView(QString,QString,bool)\0"
    "getHelpView()\0recieve(QString)\0"
    "enterTriggered()\0changeViewTriggered()\0"
    "undoTriggered()\0redoTriggered()\0"
    "addTriggered()\0findTriggered()\0"
    "findFloatTriggered()\0displayTriggered()\0"
    "deleteTriggered()\0editTriggered()\0"
    "clearTriggered()\0helpTriggered()\0,\0"
    "checkHideViewFinished(QAbstractAnimation::State,QAbstractAnimation::St"
    "ate)\0"
    "checkShowViewFinished(QAbstractAnimation::State,QAbstractAnimation::St"
    "ate)\0"
    "markTriggered()\0todayTriggered()\0"
};

void SeampleView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SeampleView *_t = static_cast<SeampleView *>(_o);
        switch (_id) {
        case 0: _t->relay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->run((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->toStandardView((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->getHelpView(); break;
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
        case 16: _t->helpTriggered(); break;
        case 17: _t->checkHideViewFinished((*reinterpret_cast< QAbstractAnimation::State(*)>(_a[1])),(*reinterpret_cast< QAbstractAnimation::State(*)>(_a[2]))); break;
        case 18: _t->checkShowViewFinished((*reinterpret_cast< QAbstractAnimation::State(*)>(_a[1])),(*reinterpret_cast< QAbstractAnimation::State(*)>(_a[2]))); break;
        case 19: _t->markTriggered(); break;
        case 20: _t->todayTriggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SeampleView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SeampleView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SeampleView,
      qt_meta_data_SeampleView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SeampleView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SeampleView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SeampleView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SeampleView))
        return static_cast<void*>(const_cast< SeampleView*>(this));
    if (!strcmp(_clname, "CommonView"))
        return static_cast< CommonView*>(const_cast< SeampleView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SeampleView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SeampleView::relay(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SeampleView::run(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SeampleView::toStandardView(QString _t1, QString _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SeampleView::getHelpView()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
