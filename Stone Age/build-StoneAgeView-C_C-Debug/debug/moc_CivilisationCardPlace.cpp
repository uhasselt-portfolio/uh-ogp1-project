/****************************************************************************
** Meta object code from reading C++ file 'CivilisationCardPlace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Stone Age - Qt Application/model/Places/CivilisationCardPlace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CivilisationCardPlace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CivilisationCardPlace_t {
    QByteArrayData data[13];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CivilisationCardPlace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CivilisationCardPlace_t qt_meta_stringdata_CivilisationCardPlace = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CivilisationCardPlace"
QT_MOC_LITERAL(1, 22, 27), // "s_removeCivlisationCardView"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 25), // "s_addCivilisationCardView"
QT_MOC_LITERAL(4, 77, 9), // "imageName"
QT_MOC_LITERAL(5, 87, 22), // "s_announcePayResources"
QT_MOC_LITERAL(6, 110, 18), // "BuildingCardPlace*"
QT_MOC_LITERAL(7, 129, 6), // "bPlace"
QT_MOC_LITERAL(8, 136, 22), // "CivilisationCardPlace*"
QT_MOC_LITERAL(9, 159, 6), // "cPlace"
QT_MOC_LITERAL(10, 166, 12), // "QVector<int>"
QT_MOC_LITERAL(11, 179, 9), // "resources"
QT_MOC_LITERAL(12, 189, 10) // "changeable"

    },
    "CivilisationCardPlace\0s_removeCivlisationCardView\0"
    "\0s_addCivilisationCardView\0imageName\0"
    "s_announcePayResources\0BuildingCardPlace*\0"
    "bPlace\0CivilisationCardPlace*\0cPlace\0"
    "QVector<int>\0resources\0changeable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CivilisationCardPlace[] = {

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
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    4,   38,    2, 0x06 /* Public */,
       5,    3,   47,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10, QMetaType::Bool,    7,    9,   11,   12,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    7,    9,   11,

       0        // eod
};

void CivilisationCardPlace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CivilisationCardPlace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_removeCivlisationCardView(); break;
        case 1: _t->s_addCivilisationCardView((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->s_announcePayResources((*reinterpret_cast< BuildingCardPlace*(*)>(_a[1])),(*reinterpret_cast< CivilisationCardPlace*(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->s_announcePayResources((*reinterpret_cast< BuildingCardPlace*(*)>(_a[1])),(*reinterpret_cast< CivilisationCardPlace*(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CivilisationCardPlace* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CivilisationCardPlace* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CivilisationCardPlace::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CivilisationCardPlace::s_removeCivlisationCardView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CivilisationCardPlace::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CivilisationCardPlace::s_addCivilisationCardView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CivilisationCardPlace::*)(BuildingCardPlace * , CivilisationCardPlace * , QVector<int> , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CivilisationCardPlace::s_announcePayResources)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CivilisationCardPlace::staticMetaObject = { {
    &Place::staticMetaObject,
    qt_meta_stringdata_CivilisationCardPlace.data,
    qt_meta_data_CivilisationCardPlace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CivilisationCardPlace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CivilisationCardPlace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CivilisationCardPlace.stringdata0))
        return static_cast<void*>(this);
    return Place::qt_metacast(_clname);
}

int CivilisationCardPlace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Place::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CivilisationCardPlace::s_removeCivlisationCardView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CivilisationCardPlace::s_addCivilisationCardView(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CivilisationCardPlace::s_announcePayResources(BuildingCardPlace * _t1, CivilisationCardPlace * _t2, QVector<int> _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
