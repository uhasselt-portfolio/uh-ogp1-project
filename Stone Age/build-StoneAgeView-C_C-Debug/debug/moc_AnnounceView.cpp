/****************************************************************************
** Meta object code from reading C++ file 'AnnounceView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Stone Age - Qt Application/view/SideBoards/AnnounceView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnnounceView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnnounceView_t {
    QByteArrayData data[20];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnnounceView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnnounceView_t qt_meta_stringdata_AnnounceView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AnnounceView"
QT_MOC_LITERAL(1, 13, 15), // "r_announceSmall"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "text"
QT_MOC_LITERAL(4, 35, 19), // "r_announceResources"
QT_MOC_LITERAL(5, 55, 12), // "QVector<int>"
QT_MOC_LITERAL(6, 68, 4), // "dice"
QT_MOC_LITERAL(7, 73, 4), // "calc"
QT_MOC_LITERAL(8, 78, 7), // "resType"
QT_MOC_LITERAL(9, 86, 14), // "QVector<Tool*>"
QT_MOC_LITERAL(10, 101, 5), // "tools"
QT_MOC_LITERAL(11, 107, 22), // "r_announcePayResources"
QT_MOC_LITERAL(12, 130, 18), // "BuildingCardPlace*"
QT_MOC_LITERAL(13, 149, 6), // "bPlace"
QT_MOC_LITERAL(14, 156, 22), // "CivilisationCardPlace*"
QT_MOC_LITERAL(15, 179, 6), // "cPlace"
QT_MOC_LITERAL(16, 186, 9), // "resources"
QT_MOC_LITERAL(17, 196, 10), // "changeable"
QT_MOC_LITERAL(18, 207, 14), // "r_payResources"
QT_MOC_LITERAL(19, 222, 17) // "r_claimRescources"

    },
    "AnnounceView\0r_announceSmall\0\0text\0"
    "r_announceResources\0QVector<int>\0dice\0"
    "calc\0resType\0QVector<Tool*>\0tools\0"
    "r_announcePayResources\0BuildingCardPlace*\0"
    "bPlace\0CivilisationCardPlace*\0cPlace\0"
    "resources\0changeable\0r_payResources\0"
    "r_claimRescources"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnnounceView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    4,   47,    2, 0x0a /* Public */,
      11,    4,   56,    2, 0x0a /* Public */,
      11,    3,   65,    2, 0x2a /* Public | MethodCloned */,
      18,    0,   72,    2, 0x0a /* Public */,
      19,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString, 0x80000000 | 9,    6,    7,    8,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14, 0x80000000 | 5, QMetaType::Bool,   13,   15,   16,   17,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14, 0x80000000 | 5,   13,   15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnnounceView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnnounceView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->r_announceSmall((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->r_announceResources((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QVector<Tool*>(*)>(_a[4]))); break;
        case 2: _t->r_announcePayResources((*reinterpret_cast< BuildingCardPlace*(*)>(_a[1])),(*reinterpret_cast< CivilisationCardPlace*(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->r_announcePayResources((*reinterpret_cast< BuildingCardPlace*(*)>(_a[1])),(*reinterpret_cast< CivilisationCardPlace*(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3]))); break;
        case 4: _t->r_payResources(); break;
        case 5: _t->r_claimRescources(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AnnounceView::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AnnounceView.data,
    qt_meta_data_AnnounceView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AnnounceView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnnounceView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnnounceView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int AnnounceView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
