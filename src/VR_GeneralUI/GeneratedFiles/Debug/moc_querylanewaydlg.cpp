/****************************************************************************
** Meta object code from reading C++ file 'querylanewaydlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/vrmine/vr_generalui/querylanewaydlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'querylanewaydlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VirtualMine__GeneralUI__CQueryLanewayDlg[] = {

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
      42,   41,   41,   41, 0x08,
      61,   41,   41,   41, 0x08,
      93,   41,   41,   41, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VirtualMine__GeneralUI__CQueryLanewayDlg[] = {
    "VirtualMine::GeneralUI::CQueryLanewayDlg\0"
    "\0slotQueryLaneway()\0slotLineditNamechanged(QString)\0"
    "slotLineditName(QString)\0"
};

void VirtualMine::GeneralUI::CQueryLanewayDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CQueryLanewayDlg *_t = static_cast<CQueryLanewayDlg *>(_o);
        switch (_id) {
        case 0: _t->slotQueryLaneway(); break;
        case 1: _t->slotLineditNamechanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->slotLineditName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VirtualMine::GeneralUI::CQueryLanewayDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VirtualMine::GeneralUI::CQueryLanewayDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VirtualMine__GeneralUI__CQueryLanewayDlg,
      qt_meta_data_VirtualMine__GeneralUI__CQueryLanewayDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VirtualMine::GeneralUI::CQueryLanewayDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VirtualMine::GeneralUI::CQueryLanewayDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VirtualMine::GeneralUI::CQueryLanewayDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualMine__GeneralUI__CQueryLanewayDlg))
        return static_cast<void*>(const_cast< CQueryLanewayDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int VirtualMine::GeneralUI::CQueryLanewayDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
