/****************************************************************************
** Meta object code from reading C++ file 'qihttp.h'
**
** Created: Tue Sep 9 15:43:37 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qihttp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qihttp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIHttp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,    7,    7,    7, 0x08,
      39,    7,    7,    7, 0x08,
      61,   51,    7,    7, 0x08,
     104,    8,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIHttp[] = {
    "QIHttp\0\0aError\0allIsDone(bool)\0abort()\0"
    "timeouted()\0aResponse\0"
    "processResponseHeader(QHttpResponseHeader)\0"
    "processDone(bool)\0"
};

void QIHttp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIHttp *_t = static_cast<QIHttp *>(_o);
        switch (_id) {
        case 0: _t->allIsDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->abort(); break;
        case 2: _t->timeouted(); break;
        case 3: _t->processResponseHeader((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 4: _t->processDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIHttp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIHttp::staticMetaObject = {
    { &QHttp::staticMetaObject, qt_meta_stringdata_QIHttp,
      qt_meta_data_QIHttp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIHttp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIHttp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIHttp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIHttp))
        return static_cast<void*>(const_cast< QIHttp*>(this));
    return QHttp::qt_metacast(_clname);
}

int QIHttp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHttp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QIHttp::allIsDone(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
