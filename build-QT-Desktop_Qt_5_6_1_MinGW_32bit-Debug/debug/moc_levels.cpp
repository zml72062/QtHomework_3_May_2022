/****************************************************************************
** Meta object code from reading C++ file 'levels.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QT/levels.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'levels.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Levels_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Levels_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Levels_t qt_meta_stringdata_Levels = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Levels"
QT_MOC_LITERAL(1, 7, 10), // "gotoLevel1"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "gotoLevel2"
QT_MOC_LITERAL(4, 30, 10), // "gotoLevel3"
QT_MOC_LITERAL(5, 41, 10), // "gotoLevel4"
QT_MOC_LITERAL(6, 52, 10), // "gotoLevel5"
QT_MOC_LITERAL(7, 63, 10), // "gotoLevel6"
QT_MOC_LITERAL(8, 74, 10), // "gotoLevel7"
QT_MOC_LITERAL(9, 85, 10), // "gotoLevel8"
QT_MOC_LITERAL(10, 96, 18) // "finishAnotherLevel"

    },
    "Levels\0gotoLevel1\0\0gotoLevel2\0gotoLevel3\0"
    "gotoLevel4\0gotoLevel5\0gotoLevel6\0"
    "gotoLevel7\0gotoLevel8\0finishAnotherLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Levels[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void Levels::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Levels *_t = static_cast<Levels *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotoLevel1(); break;
        case 1: _t->gotoLevel2(); break;
        case 2: _t->gotoLevel3(); break;
        case 3: _t->gotoLevel4(); break;
        case 4: _t->gotoLevel5(); break;
        case 5: _t->gotoLevel6(); break;
        case 6: _t->gotoLevel7(); break;
        case 7: _t->gotoLevel8(); break;
        case 8: _t->finishAnotherLevel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Levels::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Levels.data,
      qt_meta_data_Levels,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Levels::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Levels::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Levels.stringdata0))
        return static_cast<void*>(const_cast< Levels*>(this));
    return QDialog::qt_metacast(_clname);
}

int Levels::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
