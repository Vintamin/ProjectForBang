/****************************************************************************
** Meta object code from reading C++ file 'vrscenetreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../include/vrmine/vr_plugins/vrscenetreewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vrscenetreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VRSceneTreeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x09,
      37,   18,   18,   18, 0x09,
      58,   18,   18,   18, 0x09,
      77,   18,   18,   18, 0x09,
      94,   18,   18,   18, 0x09,
     112,   18,   18,   18, 0x09,
     127,   18,   18,   18, 0x09,
     142,   18,   18,   18, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VRSceneTreeWidget[] = {
    "VRSceneTreeWidget\0\0setLayerVisible()\0"
    "setDataSetProperty()\0setLayerProperty()\0"
    "setRemoveLayer()\0slotCreateScene()\0"
    "slotAddLayer()\0slotAddModel()\0"
    "slotModelProperty()\0"
};

void VRSceneTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VRSceneTreeWidget *_t = static_cast<VRSceneTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->setLayerVisible(); break;
        case 1: _t->setDataSetProperty(); break;
        case 2: _t->setLayerProperty(); break;
        case 3: _t->setRemoveLayer(); break;
        case 4: _t->slotCreateScene(); break;
        case 5: _t->slotAddLayer(); break;
        case 6: _t->slotAddModel(); break;
        case 7: _t->slotModelProperty(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VRSceneTreeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VRSceneTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_VRSceneTreeWidget,
      qt_meta_data_VRSceneTreeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VRSceneTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VRSceneTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VRSceneTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VRSceneTreeWidget))
        return static_cast<void*>(const_cast< VRSceneTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int VRSceneTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
