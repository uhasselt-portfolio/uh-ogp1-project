/****************************************************************************
** Meta object code from reading C++ file 'Place.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Stone Age - Qt Application/model/Place.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Place.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Place_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Place_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Place_t qt_meta_stringdata_Place = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Place"
QT_MOC_LITERAL(1, 6, 17), // "s_addWorkerToView"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "Team"
QT_MOC_LITERAL(4, 30, 4), // "team"
QT_MOC_LITERAL(5, 35, 10), // "s_announce"
QT_MOC_LITERAL(6, 46, 4), // "text"
QT_MOC_LITERAL(7, 51, 18), // "s_releasePlaceView"
QT_MOC_LITERAL(8, 70, 19), // "s_updateFarmerLevel"
QT_MOC_LITERAL(9, 90, 5) // "level"

    },
    "Place\0s_addWorkerToView\0\0Team\0team\0"
    "s_announce\0text\0s_releasePlaceView\0"
    "s_updateFarmerLevel\0level"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Place[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       7,    1,   40,    2, 0x06 /* Public */,
       8,    2,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    9,    4,

       0        // eod
};

void Place::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Place *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_addWorkerToView((*reinterpret_cast< Team(*)>(_a[1]))); break;
        case 1: _t->s_announce((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->s_releasePlaceView((*reinterpret_cast< Team(*)>(_a[1]))); break;
        case 3: _t->s_updateFarmerLevel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Team(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Place::*)(Team );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Place::s_addWorkerToView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Place::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Place::s_announce)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Place::*)(Team );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Place::s_releasePlaceView)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Place::*)(int , Team );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Place::s_updateFarmerLevel)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Place::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Place.data,
    qt_meta_data_Place,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Place::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Place::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Place.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Place::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Place::s_addWorkerToView(Team _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Place::s_announce(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Place::s_releasePlaceView(Team _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Place::s_updateFarmerLevel(int _t1, Team _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
