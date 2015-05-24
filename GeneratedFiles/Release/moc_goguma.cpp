/****************************************************************************
** Meta object code from reading C++ file 'goguma.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../goguma.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goguma.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Goguma_t {
    QByteArrayData data[12];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Goguma_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Goguma_t qt_meta_stringdata_Goguma = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Goguma"
QT_MOC_LITERAL(1, 7, 16), // "workingDirectory"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "fmt"
QT_MOC_LITERAL(4, 29, 5), // "clean"
QT_MOC_LITERAL(5, 35, 5), // "build"
QT_MOC_LITERAL(6, 41, 8), // "cleanLog"
QT_MOC_LITERAL(7, 50, 12), // "buildStarted"
QT_MOC_LITERAL(8, 63, 14), // "readFromStdout"
QT_MOC_LITERAL(9, 78, 14), // "readFromStderr"
QT_MOC_LITERAL(10, 93, 8), // "finished"
QT_MOC_LITERAL(11, 102, 20) // "QProcess::ExitStatus"

    },
    "Goguma\0workingDirectory\0\0fmt\0clean\0"
    "build\0cleanLog\0buildStarted\0readFromStdout\0"
    "readFromStderr\0finished\0QProcess::ExitStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Goguma[] = {

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
      10,    2,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,    2,    2,

       0        // eod
};

void Goguma::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Goguma *_t = static_cast<Goguma *>(_o);
        switch (_id) {
        case 0: _t->workingDirectory(); break;
        case 1: _t->fmt(); break;
        case 2: _t->clean(); break;
        case 3: _t->build(); break;
        case 4: _t->cleanLog(); break;
        case 5: _t->buildStarted(); break;
        case 6: _t->readFromStdout(); break;
        case 7: _t->readFromStderr(); break;
        case 8: _t->finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Goguma::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Goguma.data,
      qt_meta_data_Goguma,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Goguma::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Goguma::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Goguma.stringdata))
        return static_cast<void*>(const_cast< Goguma*>(this));
    return QDialog::qt_metacast(_clname);
}

int Goguma::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
