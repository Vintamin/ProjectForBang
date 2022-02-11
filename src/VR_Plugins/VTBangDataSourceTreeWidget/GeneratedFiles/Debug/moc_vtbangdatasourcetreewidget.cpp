/****************************************************************************
** Meta object code from reading C++ file 'vtbangdatasourcetreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../include/vrmine/vr_plugins/vtbangdatasourcetreewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vtbangdatasourcetreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VRPropertyWidget[] = {

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
      38,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   18,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VRPropertyWidget[] = {
    "VRPropertyWidget\0\0topLeft,bottomRight\0"
    "itemDataChanged(QModelIndex,QModelIndex)\0"
    "dataChanged(QModelIndex,QModelIndex)\0"
};

void VRPropertyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VRPropertyWidget *_t = static_cast<VRPropertyWidget *>(_o);
        switch (_id) {
        case 0: _t->itemDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->dataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VRPropertyWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VRPropertyWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_VRPropertyWidget,
      qt_meta_data_VRPropertyWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VRPropertyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VRPropertyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VRPropertyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VRPropertyWidget))
        return static_cast<void*>(const_cast< VRPropertyWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int VRPropertyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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
void VRPropertyWidget::itemDataChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_VTBangDataSourceTreeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x08,
      38,   27,   27,   27, 0x08,
      51,   27,   27,   27, 0x08,
      64,   27,   27,   27, 0x08,
      75,   27,   27,   27, 0x08,
      85,   27,   27,   27, 0x08,
      97,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VTBangDataSourceTreeWidget[] = {
    "VTBangDataSourceTreeWidget\0\0slotAdd()\0"
    "slotModify()\0slotDelete()\0slotCope()\0"
    "slotCut()\0slotPaste()\0slotItemPress()\0"
};

void VTBangDataSourceTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VTBangDataSourceTreeWidget *_t = static_cast<VTBangDataSourceTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->slotAdd(); break;
        case 1: _t->slotModify(); break;
        case 2: _t->slotDelete(); break;
        case 3: _t->slotCope(); break;
        case 4: _t->slotCut(); break;
        case 5: _t->slotPaste(); break;
        case 6: _t->slotItemPress(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VTBangDataSourceTreeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VTBangDataSourceTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_VTBangDataSourceTreeWidget,
      qt_meta_data_VTBangDataSourceTreeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VTBangDataSourceTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VTBangDataSourceTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VTBangDataSourceTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VTBangDataSourceTreeWidget))
        return static_cast<void*>(const_cast< VTBangDataSourceTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int VTBangDataSourceTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
