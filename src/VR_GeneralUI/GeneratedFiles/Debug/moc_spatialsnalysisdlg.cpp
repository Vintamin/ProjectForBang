/****************************************************************************
** Meta object code from reading C++ file 'spatialsnalysisdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/spatialsnalysisdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spatialsnalysisdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CSpaltialAnalysiDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      45,   44,   44,   44, 0x08,
      64,   44,   44,   44, 0x08,
      86,   44,   44,   44, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CSpaltialAnalysiDlg[] = {
    "VirtualMine::GeneralUI::CSpaltialAnalysiDlg\0"
    "\0slotPointMessure()\0slotDistanceMeasure()\0"
    "slotCleatMeasure()\0"
};

void VirtualMine::GeneralUI::CSpaltialAnalysiDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CSpaltialAnalysiDlg *_t = static_cast<CSpaltialAnalysiDlg *>(_o);
        switch (_id) {
        case 0: _t->slotPointMessure(); break;
        case 1: _t->slotDistanceMeasure(); break;
        case 2: _t->slotCleatMeasure(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CSpaltialAnalysiDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CSpaltialAnalysiDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CSpaltialAnalysiDlg,
      qt_meta_data_VirtualMine__GeneralUI__CSpaltialAnalysiDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CSpaltialAnalysiDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CSpaltialAnalysiDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CSpaltialAnalysiDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CSpaltialAnalysiDlg))
        return static_cast<void*>(const_cast< CSpaltialAnalysiDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CSpaltialAnalysiDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
