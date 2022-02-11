/****************************************************************************
** Meta object code from reading C++ file 'basedialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/basedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CUiBaseDialog[] = {

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
      39,   38,   38,   38, 0x09,
      57,   38,   38,   38, 0x09,
      75,   38,   38,   38, 0x09,
      95,   38,   38,   38, 0x09,
     113,   38,   38,   38, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CUiBaseDialog[] = {
    "VirtualMine::GeneralUI::CUiBaseDialog\0"
    "\0doToolButtonMax()\0doToolButtonNor()\0"
    "doToolButtonClose()\0doToolButtonSet()\0"
    "doToolButtonSkin()\0"
};

void VirtualMine::GeneralUI::CUiBaseDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CUiBaseDialog *_t = static_cast<CUiBaseDialog *>(_o);
        switch (_id) {
        case 0: _t->doToolButtonMax(); break;
        case 1: _t->doToolButtonNor(); break;
        case 2: _t->doToolButtonClose(); break;
        case 3: _t->doToolButtonSet(); break;
        case 4: _t->doToolButtonSkin(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CUiBaseDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CUiBaseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CUiBaseDialog,
      qt_meta_data_VirtualMine__GeneralUI__CUiBaseDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CUiBaseDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CUiBaseDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CUiBaseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CUiBaseDialog))
        return static_cast<void*>(const_cast< CUiBaseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CUiBaseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
