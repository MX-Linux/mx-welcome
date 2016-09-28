/****************************************************************************
** Meta object code from reading C++ file 'mxwelcome.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mxwelcome.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mxwelcome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mxwelcome_t {
    QByteArrayData data[16];
    char stringdata[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mxwelcome_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mxwelcome_t qt_meta_stringdata_mxwelcome = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 14),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 13),
QT_MOC_LITERAL(4, 40, 22),
QT_MOC_LITERAL(5, 63, 19),
QT_MOC_LITERAL(6, 83, 7),
QT_MOC_LITERAL(7, 91, 22),
QT_MOC_LITERAL(8, 114, 23),
QT_MOC_LITERAL(9, 138, 22),
QT_MOC_LITERAL(10, 161, 21),
QT_MOC_LITERAL(11, 183, 22),
QT_MOC_LITERAL(12, 206, 27),
QT_MOC_LITERAL(13, 234, 26),
QT_MOC_LITERAL(14, 261, 28),
QT_MOC_LITERAL(15, 290, 31)
    },
    "mxwelcome\0setConnections\0\0disconnectAll\0"
    "on_buttonAbout_clicked\0on_checkBox_clicked\0"
    "checked\0on_buttonTools_clicked\0"
    "on_buttonManual_clicked\0on_buttonForum_clicked\0"
    "on_buttonWiki_clicked\0on_buttonVideo_clicked\0"
    "on_buttonContribute_clicked\0"
    "on_buttonLogininfo_clicked\0"
    "on_buttonPanelOrient_clicked\0"
    "on_buttonPackageInstall_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mxwelcome[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
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

void mxwelcome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mxwelcome *_t = static_cast<mxwelcome *>(_o);
        switch (_id) {
        case 0: _t->setConnections(); break;
        case 1: _t->disconnectAll(); break;
        case 2: _t->on_buttonAbout_clicked(); break;
        case 3: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_buttonTools_clicked(); break;
        case 5: _t->on_buttonManual_clicked(); break;
        case 6: _t->on_buttonForum_clicked(); break;
        case 7: _t->on_buttonWiki_clicked(); break;
        case 8: _t->on_buttonVideo_clicked(); break;
        case 9: _t->on_buttonContribute_clicked(); break;
        case 10: _t->on_buttonLogininfo_clicked(); break;
        case 11: _t->on_buttonPanelOrient_clicked(); break;
        case 12: _t->on_buttonPackageInstall_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject mxwelcome::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mxwelcome.data,
      qt_meta_data_mxwelcome,  qt_static_metacall, 0, 0}
};


const QMetaObject *mxwelcome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mxwelcome::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mxwelcome.stringdata))
        return static_cast<void*>(const_cast< mxwelcome*>(this));
    return QDialog::qt_metacast(_clname);
}

int mxwelcome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
