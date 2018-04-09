/****************************************************************************
** Meta object code from reading C++ file 'qdatabase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qdatabase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QDataBase_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDataBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDataBase_t qt_meta_stringdata_QDataBase = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QDataBase"
QT_MOC_LITERAL(1, 10, 10), // "addElement"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "deleteFirst"
QT_MOC_LITERAL(4, 34, 10), // "deleteLast"
QT_MOC_LITERAL(5, 45, 9), // "deleteSel"
QT_MOC_LITERAL(6, 55, 6), // "update"
QT_MOC_LITERAL(7, 62, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(8, 80, 8) // "showHome"

    },
    "QDataBase\0addElement\0\0deleteFirst\0"
    "deleteLast\0deleteSel\0update\0"
    "QTableWidgetItem*\0showHome"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDataBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,

       0        // eod
};

void QDataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDataBase *_t = static_cast<QDataBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addElement(); break;
        case 1: _t->deleteFirst(); break;
        case 2: _t->deleteLast(); break;
        case 3: _t->deleteSel(); break;
        case 4: _t->update((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->showHome(); break;
        default: ;
        }
    }
}

const QMetaObject QDataBase::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QDataBase.data,
      qt_meta_data_QDataBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QDataBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDataBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QDataBase.stringdata0))
        return static_cast<void*>(const_cast< QDataBase*>(this));
    return QWidget::qt_metacast(_clname);
}

int QDataBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
