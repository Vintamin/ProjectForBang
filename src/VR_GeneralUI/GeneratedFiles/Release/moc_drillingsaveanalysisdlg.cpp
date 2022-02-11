/****************************************************************************
** Meta object code from reading C++ file 'drillingsaveanalysisdlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/drillingsaveanalysisdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drillingsaveanalysisdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CDrillingSaveAnalysiDlg[] = {

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
      49,   48,   48,   48, 0x08,
      61,   48,   48,   48, 0x08,
      83,   48,   48,   48, 0x08,
     103,   48,   48,   48, 0x08,
     126,   48,   48,   48, 0x08,
     145,   48,   48,   48, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CDrillingSaveAnalysiDlg[] = {
    "VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg\0"
    "\0slotBegin()\0slotSelectSavePoint()\0"
    "slotVerticalPoint()\0slotAnalysisOptPoint()\0"
    "slotDrillingSave()\0slotEndAnalysis()\0"
};

void VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDrillingSaveAnalysiDlg *_t = static_cast<CDrillingSaveAnalysiDlg *>(_o);
        switch (_id) {
        case 0: _t->slotBegin(); break;
        case 1: _t->slotSelectSavePoint(); break;
        case 2: _t->slotVerticalPoint(); break;
        case 3: _t->slotAnalysisOptPoint(); break;
        case 4: _t->slotDrillingSave(); break;
        case 5: _t->slotEndAnalysis(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CDrillingSaveAnalysiDlg,
      qt_meta_data_VirtualMine__GeneralUI__CDrillingSaveAnalysiDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CDrillingSaveAnalysiDlg))
        return static_cast<void*>(const_cast< CDrillingSaveAnalysiDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CDrillingSaveAnalysiDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
