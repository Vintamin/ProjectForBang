/****************************************************************************
** Meta object code from reading C++ file 'floodanalysisDlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/floodanalysisDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'floodanalysisDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CFloodAnalysisDlg[] = {

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
      43,   42,   42,   42, 0x08,
      72,   66,   42,   42, 0x08,
      99,   42,   42,   42, 0x08,
     112,   66,   42,   42, 0x08,
     139,   66,   42,   42, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CFloodAnalysisDlg[] = {
    "VirtualMine::GeneralUI::CFloodAnalysisDlg\0"
    "\0slotSelectWaterColor()\0value\0"
    "slotSetWaterHeight(double)\0slotHandIn()\0"
    "slotShowWaterSurface(bool)\0"
    "slotWaterSurfaceEffect(bool)\0"
};

void VirtualMine::GeneralUI::CFloodAnalysisDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CFloodAnalysisDlg *_t = static_cast<CFloodAnalysisDlg *>(_o);
        switch (_id) {
        case 0: _t->slotSelectWaterColor(); break;
        case 1: _t->slotSetWaterHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->slotHandIn(); break;
        case 3: _t->slotShowWaterSurface((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slotWaterSurfaceEffect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CFloodAnalysisDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CFloodAnalysisDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CFloodAnalysisDlg,
      qt_meta_data_VirtualMine__GeneralUI__CFloodAnalysisDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CFloodAnalysisDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CFloodAnalysisDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CFloodAnalysisDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CFloodAnalysisDlg))
        return static_cast<void*>(const_cast< CFloodAnalysisDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CFloodAnalysisDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_VirtualMine__GeneralUI__CTourPropertyDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   41,   41,   41, 0x09,
      59,   41,   41,   41, 0x09,
      74,   41,   41,   41, 0x09,
      91,   41,   41,   41, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CTourPropertyDlg[] = {
    "VirtualMine::GeneralUI::CTourPropertyDlg\0"
    "\0slotSelectPath()\0slotLoadTour()\0"
    "slotUnloadTour()\0slotClose()\0"
};

void VirtualMine::GeneralUI::CTourPropertyDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CTourPropertyDlg *_t = static_cast<CTourPropertyDlg *>(_o);
        switch (_id) {
        case 0: _t->slotSelectPath(); break;
        case 1: _t->slotLoadTour(); break;
        case 2: _t->slotUnloadTour(); break;
        case 3: _t->slotClose(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CTourPropertyDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CTourPropertyDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CTourPropertyDlg,
      qt_meta_data_VirtualMine__GeneralUI__CTourPropertyDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CTourPropertyDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CTourPropertyDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CTourPropertyDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CTourPropertyDlg))
        return static_cast<void*>(const_cast< CTourPropertyDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CTourPropertyDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
