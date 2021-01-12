/****************************************************************************
** Meta object code from reading C++ file 'dlgcv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dlgcv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgcv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgOpenCV_t {
    QByteArrayData data[20];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgOpenCV_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgOpenCV_t qt_meta_stringdata_DlgOpenCV = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DlgOpenCV"
QT_MOC_LITERAL(1, 10, 4), // "blur"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "bilater"
QT_MOC_LITERAL(4, 24, 5), // "gauss"
QT_MOC_LITERAL(5, 30, 3), // "box"
QT_MOC_LITERAL(6, 34, 8), // "fliter2d"
QT_MOC_LITERAL(7, 43, 5), // "sobel"
QT_MOC_LITERAL(8, 49, 6), // "median"
QT_MOC_LITERAL(9, 56, 7), // "laplace"
QT_MOC_LITERAL(10, 64, 4), // "down"
QT_MOC_LITERAL(11, 69, 2), // "up"
QT_MOC_LITERAL(12, 72, 4), // "mean"
QT_MOC_LITERAL(13, 77, 6), // "dilate"
QT_MOC_LITERAL(14, 84, 5), // "erode"
QT_MOC_LITERAL(15, 90, 6), // "scharr"
QT_MOC_LITERAL(16, 97, 9), // "sepfilter"
QT_MOC_LITERAL(17, 107, 6), // "sqrbox"
QT_MOC_LITERAL(18, 114, 7), // "pyramid"
QT_MOC_LITERAL(19, 122, 5) // "morph"

    },
    "DlgOpenCV\0blur\0\0bilater\0gauss\0box\0"
    "fliter2d\0sobel\0median\0laplace\0down\0"
    "up\0mean\0dilate\0erode\0scharr\0sepfilter\0"
    "sqrbox\0pyramid\0morph"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgOpenCV[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgOpenCV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgOpenCV *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->blur(); break;
        case 1: _t->bilater(); break;
        case 2: _t->gauss(); break;
        case 3: _t->box(); break;
        case 4: _t->fliter2d(); break;
        case 5: _t->sobel(); break;
        case 6: _t->median(); break;
        case 7: _t->laplace(); break;
        case 8: _t->down(); break;
        case 9: _t->up(); break;
        case 10: _t->mean(); break;
        case 11: _t->dilate(); break;
        case 12: _t->erode(); break;
        case 13: _t->scharr(); break;
        case 14: _t->sepfilter(); break;
        case 15: _t->sqrbox(); break;
        case 16: _t->pyramid(); break;
        case 17: _t->morph(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DlgOpenCV::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DlgOpenCV.data,
    qt_meta_data_DlgOpenCV,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgOpenCV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgOpenCV::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgOpenCV.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DlgOpenCV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
