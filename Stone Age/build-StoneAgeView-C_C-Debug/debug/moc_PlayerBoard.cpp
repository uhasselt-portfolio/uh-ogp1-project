/****************************************************************************
** Meta object code from reading C++ file 'PlayerBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Stone Age - Qt Application/model/PlayerBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayerBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerBoard_t {
    QByteArrayData data[14];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerBoard_t qt_meta_stringdata_PlayerBoard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PlayerBoard"
QT_MOC_LITERAL(1, 12, 16), // "s_setActiveState"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "active"
QT_MOC_LITERAL(4, 37, 19), // "s_updatePlayerBoard"
QT_MOC_LITERAL(5, 57, 6), // "worker"
QT_MOC_LITERAL(6, 64, 4), // "food"
QT_MOC_LITERAL(7, 69, 5), // "score"
QT_MOC_LITERAL(8, 75, 4), // "wood"
QT_MOC_LITERAL(9, 80, 5), // "stone"
QT_MOC_LITERAL(10, 86, 5), // "brick"
QT_MOC_LITERAL(11, 92, 4), // "gold"
QT_MOC_LITERAL(12, 97, 6), // "Tools*"
QT_MOC_LITERAL(13, 104, 5) // "tools"

    },
    "PlayerBoard\0s_setActiveState\0\0active\0"
    "s_updatePlayerBoard\0worker\0food\0score\0"
    "wood\0stone\0brick\0gold\0Tools*\0tools"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerBoard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    8,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 12,    5,    6,    7,    8,    9,   10,   11,   13,

       0        // eod
};

void PlayerBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayerBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_setActiveState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->s_updatePlayerBoard((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< Tools*(*)>(_a[8]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayerBoard::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerBoard::s_setActiveState)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayerBoard::*)(QString , QString , QString , QString , QString , QString , QString , Tools * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerBoard::s_updatePlayerBoard)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayerBoard::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PlayerBoard.data,
    qt_meta_data_PlayerBoard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayerBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerBoard.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayerBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void PlayerBoard::s_setActiveState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayerBoard::s_updatePlayerBoard(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, QString _t7, Tools * _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
