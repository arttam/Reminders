/****************************************************************************
** Meta object code from reading C++ file 'remainderdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UI/remainderdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remainderdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RemainderDlg_t {
    QByteArrayData data[10];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemainderDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemainderDlg_t qt_meta_stringdata_RemainderDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RemainderDlg"
QT_MOC_LITERAL(1, 13, 24), // "on_providersList_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "index"
QT_MOC_LITERAL(4, 45, 24), // "on_checkPassword_clicked"
QT_MOC_LITERAL(5, 70, 19), // "on_addEntry_clicked"
QT_MOC_LITERAL(6, 90, 20), // "on_editEntry_clicked"
QT_MOC_LITERAL(7, 111, 22), // "on_deleteEntry_clicked"
QT_MOC_LITERAL(8, 134, 25), // "on_dialogQuitBox_accepted"
QT_MOC_LITERAL(9, 160, 25) // "on_dialogQuitBox_rejected"

    },
    "RemainderDlg\0on_providersList_clicked\0"
    "\0index\0on_checkPassword_clicked\0"
    "on_addEntry_clicked\0on_editEntry_clicked\0"
    "on_deleteEntry_clicked\0on_dialogQuitBox_accepted\0"
    "on_dialogQuitBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemainderDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RemainderDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemainderDlg *_t = static_cast<RemainderDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_providersList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_checkPassword_clicked(); break;
        case 2: _t->on_addEntry_clicked(); break;
        case 3: _t->on_editEntry_clicked(); break;
        case 4: _t->on_deleteEntry_clicked(); break;
        case 5: _t->on_dialogQuitBox_accepted(); break;
        case 6: _t->on_dialogQuitBox_rejected(); break;
        default: ;
        }
    }
}

const QMetaObject RemainderDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RemainderDlg.data,
      qt_meta_data_RemainderDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RemainderDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemainderDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RemainderDlg.stringdata0))
        return static_cast<void*>(const_cast< RemainderDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int RemainderDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
