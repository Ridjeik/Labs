/****************************************************************************
** Meta object code from reading C++ file 'triangleviewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TriangleManipulator2/triangleviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'triangleviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TriangleViewer_t {
    const uint offsetsAndSize[22];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TriangleViewer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TriangleViewer_t qt_meta_stringdata_TriangleViewer = {
    {
QT_MOC_LITERAL(0, 14), // "TriangleViewer"
QT_MOC_LITERAL(15, 25), // "on_increaseButton_clicked"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 25), // "on_setSidesButton_clicked"
QT_MOC_LITERAL(68, 29), // "on_sidesCheckBox_stateChanged"
QT_MOC_LITERAL(98, 4), // "arg1"
QT_MOC_LITERAL(103, 31), // "on_mediansCheckBox_stateChanged"
QT_MOC_LITERAL(135, 27), // "on_actionTriangle_triggered"
QT_MOC_LITERAL(163, 32), // "on_verticesCheckBox_stateChanged"
QT_MOC_LITERAL(196, 25), // "on_multiplyButton_clicked"
QT_MOC_LITERAL(222, 28) // "on_actionTriangles_triggered"

    },
    "TriangleViewer\0on_increaseButton_clicked\0"
    "\0on_setSidesButton_clicked\0"
    "on_sidesCheckBox_stateChanged\0arg1\0"
    "on_mediansCheckBox_stateChanged\0"
    "on_actionTriangle_triggered\0"
    "on_verticesCheckBox_stateChanged\0"
    "on_multiplyButton_clicked\0"
    "on_actionTriangles_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TriangleViewer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    1,   64,    2, 0x08,    3 /* Private */,
       6,    1,   67,    2, 0x08,    5 /* Private */,
       7,    0,   70,    2, 0x08,    7 /* Private */,
       8,    1,   71,    2, 0x08,    8 /* Private */,
       9,    0,   74,    2, 0x08,   10 /* Private */,
      10,    0,   75,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TriangleViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TriangleViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_increaseButton_clicked(); break;
        case 1: _t->on_setSidesButton_clicked(); break;
        case 2: _t->on_sidesCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_mediansCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_actionTriangle_triggered(); break;
        case 5: _t->on_verticesCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_multiplyButton_clicked(); break;
        case 7: _t->on_actionTriangles_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject TriangleViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TriangleViewer.offsetsAndSize,
    qt_meta_data_TriangleViewer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TriangleViewer_t
, QtPrivate::TypeAndForceComplete<TriangleViewer, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TriangleViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TriangleViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TriangleViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TriangleViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
