/****************************************************************************
** Meta object code from reading C++ file 'vr_mapcontrolwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../include/vrmine/vr_plugins/vr_mapcontrolwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vr_mapcontrolwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VR_MapControlWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   21,   20,   20, 0x05,
      54,   21,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_VR_MapControlWidget[] = {
    "VR_MapControlWidget\0\0event\0"
    "keyPressSignal(QKeyEvent*)\0"
    "keyReleaseSignal(QKeyEvent*)\0"
};

void VR_MapControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VR_MapControlWidget *_t = static_cast<VR_MapControlWidget *>(_o);
        switch (_id) {
        case 0: _t->keyPressSignal((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->keyReleaseSignal((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VR_MapControlWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VR_MapControlWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VR_MapControlWidget,
      qt_meta_data_VR_MapControlWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VR_MapControlWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VR_MapControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VR_MapControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VR_MapControlWidget))
        return static_cast<void*>(const_cast< VR_MapControlWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int VR_MapControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void VR_MapControlWidget::keyPressSignal(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VR_MapControlWidget::keyReleaseSignal(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
