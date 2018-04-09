/****************************************************************************
** Meta object code from reading C++ file 'reconstruction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/reconstruction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reconstruction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Reconstruction_t {
    QByteArrayData data[10];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Reconstruction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Reconstruction_t qt_meta_stringdata_Reconstruction = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Reconstruction"
QT_MOC_LITERAL(1, 15, 8), // "showHome"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "shootScreen"
QT_MOC_LITERAL(4, 37, 21), // "saveFileButtonPressed"
QT_MOC_LITERAL(5, 59, 21), // "loadFileButtonPressed"
QT_MOC_LITERAL(6, 81, 14), // "showFullScreen"
QT_MOC_LITERAL(7, 96, 20), // "loadInteractorCamera"
QT_MOC_LITERAL(8, 117, 19), // "loadInteractorActor"
QT_MOC_LITERAL(9, 137, 8) // "showHelp"

    },
    "Reconstruction\0showHome\0\0shootScreen\0"
    "saveFileButtonPressed\0loadFileButtonPressed\0"
    "showFullScreen\0loadInteractorCamera\0"
    "loadInteractorActor\0showHelp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Reconstruction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
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

void Reconstruction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Reconstruction *_t = static_cast<Reconstruction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showHome(); break;
        case 1: _t->shootScreen(); break;
        case 2: _t->saveFileButtonPressed(); break;
        case 3: _t->loadFileButtonPressed(); break;
        case 4: _t->showFullScreen(); break;
        case 5: _t->loadInteractorCamera(); break;
        case 6: _t->loadInteractorActor(); break;
        case 7: _t->showHelp(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Reconstruction::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Reconstruction.data,
      qt_meta_data_Reconstruction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Reconstruction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Reconstruction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Reconstruction.stringdata0))
        return static_cast<void*>(const_cast< Reconstruction*>(this));
    return QWidget::qt_metacast(_clname);
}

int Reconstruction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
