/****************************************************************************
** Meta object code from reading C++ file 'AlanMultipleChoiceDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlanMultipleChoiceDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlanMultipleChoiceDialog_t {
    QByteArrayData data[5];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlanMultipleChoiceDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlanMultipleChoiceDialog_t qt_meta_stringdata_AlanMultipleChoiceDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "AlanMultipleChoiceDialog"
QT_MOC_LITERAL(1, 25, 22), // "onAdditionalButtonSlot"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 19), // "onClickedChoiceSlot"
QT_MOC_LITERAL(4, 69, 16) // "QListWidgetItem*"

    },
    "AlanMultipleChoiceDialog\0"
    "onAdditionalButtonSlot\0\0onClickedChoiceSlot\0"
    "QListWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlanMultipleChoiceDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x09 /* Protected */,
       3,    1,   25,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

       0        // eod
};

void AlanMultipleChoiceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlanMultipleChoiceDialog *_t = static_cast<AlanMultipleChoiceDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onAdditionalButtonSlot(); break;
        case 1: _t->onClickedChoiceSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AlanMultipleChoiceDialog::staticMetaObject = {
    { &AlanTwoButtonDialog::staticMetaObject, qt_meta_stringdata_AlanMultipleChoiceDialog.data,
      qt_meta_data_AlanMultipleChoiceDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AlanMultipleChoiceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlanMultipleChoiceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlanMultipleChoiceDialog.stringdata0))
        return static_cast<void*>(const_cast< AlanMultipleChoiceDialog*>(this));
    return AlanTwoButtonDialog::qt_metacast(_clname);
}

int AlanMultipleChoiceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AlanTwoButtonDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
