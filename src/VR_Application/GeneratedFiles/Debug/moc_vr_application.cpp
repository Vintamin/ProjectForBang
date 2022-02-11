/****************************************************************************
** Meta object code from reading C++ file 'vr_application.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../vr_application.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vr_application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VR_Application[] = {

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
      16,   15,   15,   15, 0x08,
      29,   15,   15,   15, 0x08,
      45,   15,   15,   15, 0x08,
      62,   15,   15,   15, 0x08,
      79,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VR_Application[] = {
    "VR_Application\0\0slotPanMap()\0"
    "slotZoomInMap()\0slotZoomOutMap()\0"
    "slotFullScreen()\0slotReset()\0"
};

void VR_Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VR_Application *_t = static_cast<VR_Application *>(_o);
        switch (_id) {
        case 0: _t->slotPanMap(); break;
        case 1: _t->slotZoomInMap(); break;
        case 2: _t->slotZoomOutMap(); break;
        case 3: _t->slotFullScreen(); break;
        case 4: _t->slotReset(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VR_Application::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VR_Application::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VR_Application,
      qt_meta_data_VR_Application, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VR_Application::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VR_Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VR_Application::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VR_Application))
        return static_cast<void*>(const_cast< VR_Application*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VR_Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
