/****************************************************************************
** Meta object code from reading C++ file 'sc17r2jbWidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sc17r2jbWidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sc17r2jbWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
<<<<<<< HEAD
struct qt_meta_stringdata_NameButton_t {
    QByteArrayData data[1];
    char stringdata[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NameButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NameButton_t qt_meta_stringdata_NameButton = {
    {
QT_MOC_LITERAL(0, 0, 10)
    },
    "NameButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NameButton[] = {
=======
struct qt_meta_stringdata_NameEdit_t {
    QByteArrayData data[1];
    char stringdata[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NameEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NameEdit_t qt_meta_stringdata_NameEdit = {
    {
QT_MOC_LITERAL(0, 0, 8)
    },
    "NameEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NameEdit[] = {
>>>>>>> 140eb38a789693ad4d4b0bdc85ff75b1ddbf28ab

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

<<<<<<< HEAD
void NameButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
=======
void NameEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
>>>>>>> 140eb38a789693ad4d4b0bdc85ff75b1ddbf28ab
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

<<<<<<< HEAD
const QMetaObject NameButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_NameButton.data,
      qt_meta_data_NameButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *NameButton::metaObject() const
=======
const QMetaObject NameEdit::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_NameEdit.data,
      qt_meta_data_NameEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *NameEdit::metaObject() const
>>>>>>> 140eb38a789693ad4d4b0bdc85ff75b1ddbf28ab
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

<<<<<<< HEAD
void *NameButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NameButton.stringdata))
        return static_cast<void*>(const_cast< NameButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int NameButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
=======
void *NameEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NameEdit.stringdata))
        return static_cast<void*>(const_cast< NameEdit*>(this));
    return QPushButton::qt_metacast(_clname);
}

int NameEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
>>>>>>> 140eb38a789693ad4d4b0bdc85ff75b1ddbf28ab
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
