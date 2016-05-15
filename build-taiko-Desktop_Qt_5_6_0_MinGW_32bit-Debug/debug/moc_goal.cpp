/****************************************************************************
** Meta object code from reading C++ file 'goal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../taiko/goal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Goal_t {
    QByteArrayData data[12];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Goal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Goal_t qt_meta_stringdata_Goal = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Goal"
QT_MOC_LITERAL(1, 5, 6), // "score1"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 6), // "score2"
QT_MOC_LITERAL(4, 20, 8), // "noscore1"
QT_MOC_LITERAL(5, 29, 8), // "noscore2"
QT_MOC_LITERAL(6, 38, 4), // "tar1"
QT_MOC_LITERAL(7, 43, 4), // "tar2"
QT_MOC_LITERAL(8, 48, 8), // "hitGoal1"
QT_MOC_LITERAL(9, 57, 8), // "hitGoal2"
QT_MOC_LITERAL(10, 66, 10), // "nohitGoal1"
QT_MOC_LITERAL(11, 77, 10) // "nohitGoal2"

    },
    "Goal\0score1\0\0score2\0noscore1\0noscore2\0"
    "tar1\0tar2\0hitGoal1\0hitGoal2\0nohitGoal1\0"
    "nohitGoal2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Goal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Goal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Goal *_t = static_cast<Goal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->score1(); break;
        case 1: _t->score2(); break;
        case 2: _t->noscore1(); break;
        case 3: _t->noscore2(); break;
        case 4: _t->tar1(); break;
        case 5: _t->tar2(); break;
        case 6: _t->hitGoal1(); break;
        case 7: _t->hitGoal2(); break;
        case 8: _t->nohitGoal1(); break;
        case 9: _t->nohitGoal2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Goal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goal::score1)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Goal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goal::score2)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Goal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goal::noscore1)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Goal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Goal::noscore2)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Goal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Goal.data,
      qt_meta_data_Goal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Goal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Goal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Goal.stringdata0))
        return static_cast<void*>(const_cast< Goal*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Goal*>(this));
    return QObject::qt_metacast(_clname);
}

int Goal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Goal::score1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Goal::score2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Goal::noscore1()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Goal::noscore2()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
