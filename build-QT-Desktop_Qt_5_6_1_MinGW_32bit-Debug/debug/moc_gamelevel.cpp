/****************************************************************************
** Meta object code from reading C++ file 'gamelevel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QT/gamelevel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamelevel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameLevel_t {
    QByteArrayData data[6];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameLevel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameLevel_t qt_meta_stringdata_GameLevel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameLevel"
QT_MOC_LITERAL(1, 10, 3), // "win"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "clear"
QT_MOC_LITERAL(4, 21, 9), // "clearIcon"
QT_MOC_LITERAL(5, 31, 10) // "commentWin"

    },
    "GameLevel\0win\0\0clear\0clearIcon\0"
    "commentWin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameLevel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   35,    2, 0x0a /* Public */,
       4,    2,   42,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void GameLevel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameLevel *_t = static_cast<GameLevel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->win(); break;
        case 1: _t->clear((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->clearIcon((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->commentWin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameLevel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameLevel::win)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GameLevel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GameLevel.data,
      qt_meta_data_GameLevel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameLevel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameLevel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameLevel.stringdata0))
        return static_cast<void*>(const_cast< GameLevel*>(this));
    return QDialog::qt_metacast(_clname);
}

int GameLevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GameLevel::win()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
