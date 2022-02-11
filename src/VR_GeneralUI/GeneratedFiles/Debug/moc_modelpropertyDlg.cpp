/****************************************************************************
** Meta object code from reading C++ file 'modelpropertyDlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/modelpropertyDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelpropertyDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CModelPropertyDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      49,   43,   42,   42, 0x09,
      73,   43,   42,   42, 0x09,
      97,   43,   42,   42, 0x09,
     121,   43,   42,   42, 0x09,
     147,   43,   42,   42, 0x09,
     173,   43,   42,   42, 0x09,
     199,   43,   42,   42, 0x09,
     225,   43,   42,   42, 0x09,
     251,   43,   42,   42, 0x09,
     277,   42,   42,   42, 0x09,
     290,   42,   42,   42, 0x09,
     303,   42,   42,   42, 0x09,
     321,   42,   42,   42, 0x09,
     336,   42,   42,   42, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CModelPropertyDlg[] = {
    "VirtualMine::GeneralUI::CModelPropertyDlg\0"
    "\0value\0slotPosXChanged(double)\0"
    "slotPosYChanged(double)\0slotPosZChanged(double)\0"
    "slotRoateXChanged(double)\0"
    "slotRoateYChanged(double)\0"
    "slotRoateZChanged(double)\0"
    "slotScaleXChanged(double)\0"
    "slotScaleYChanged(double)\0"
    "slotScaleZChanged(double)\0slotHandIn()\0"
    "slotCancel()\0slotPosSelected()\0"
    "upatePosture()\0initialModelLibResource()\0"
};

void VirtualMine::GeneralUI::CModelPropertyDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CModelPropertyDlg *_t = static_cast<CModelPropertyDlg *>(_o);
        switch (_id) {
        case 0: _t->slotPosXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->slotPosYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->slotPosZChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->slotRoateXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->slotRoateYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->slotRoateZChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slotScaleXChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->slotScaleYChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->slotScaleZChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->slotHandIn(); break;
        case 10: _t->slotCancel(); break;
        case 11: _t->slotPosSelected(); break;
        case 12: _t->upatePosture(); break;
        case 13: _t->initialModelLibResource(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CModelPropertyDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CModelPropertyDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CModelPropertyDlg,
      qt_meta_data_VirtualMine__GeneralUI__CModelPropertyDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CModelPropertyDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CModelPropertyDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CModelPropertyDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CModelPropertyDlg))
        return static_cast<void*>(const_cast< CModelPropertyDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CModelPropertyDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
