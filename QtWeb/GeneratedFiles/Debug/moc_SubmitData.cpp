/****************************************************************************
** Meta object code from reading C++ file 'SubmitData.h'
**
** Created: Mon Sep 15 17:30:02 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SubmitData.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SubmitData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SubmitData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SubmitData[] = {
    "SubmitData\0\0error\0on_http_done(bool)\0"
};

void SubmitData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SubmitData *_t = static_cast<SubmitData *>(_o);
        switch (_id) {
        case 0: _t->on_http_done((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SubmitData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SubmitData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SubmitData,
      qt_meta_data_SubmitData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SubmitData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SubmitData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SubmitData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SubmitData))
        return static_cast<void*>(const_cast< SubmitData*>(this));
    return QObject::qt_metacast(_clname);
}

int SubmitData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
