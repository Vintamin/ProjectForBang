/****************************************************************************
** Meta object code from reading C++ file 'touranalysisdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/touranalysisdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'touranalysisdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CTourAnalysisDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   41,   41,   41, 0x08,
      58,   41,   41,   41, 0x08,
      75,   41,   41,   41, 0x08,
      90,   41,   41,   41, 0x08,
     106,   41,   41,   41, 0x08,
     121,   41,   41,   41, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CTourAnalysisDlg[] = {
    "VirtualMine::GeneralUI::CTourAnalysisDlg\0"
    "\0slotLuzhiTour()\0slotJieshuTour()\0"
    "slotPlayTour()\0slotPauseTour()\0"
    "slotStopTour()\0slotClearTour()\0"
};

void VirtualMine::GeneralUI::CTourAnalysisDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CTourAnalysisDlg *_t = static_cast<CTourAnalysisDlg *>(_o);
        switch (_id) {
        case 0: _t->slotLuzhiTour(); break;
        case 1: _t->slotJieshuTour(); break;
        case 2: _t->slotPlayTour(); break;
        case 3: _t->slotPauseTour(); break;
        case 4: _t->slotStopTour(); break;
        case 5: _t->slotClearTour(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CTourAnalysisDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CTourAnalysisDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CTourAnalysisDlg,
      qt_meta_data_VirtualMine__GeneralUI__CTourAnalysisDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CTourAnalysisDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CTourAnalysisDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CTourAnalysisDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CTourAnalysisDlg))
        return static_cast<void*>(const_cast< CTourAnalysisDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CTourAnalysisDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
