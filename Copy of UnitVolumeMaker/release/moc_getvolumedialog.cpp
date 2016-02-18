/****************************************************************************
** Meta object code from reading C++ file 'getvolumedialog.h'
**
** Created: Thu Sep 4 19:50:12 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../getvolumedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getvolumedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CGetVolumeDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CGetVolumeDialog[] = {
    "CGetVolumeDialog\0\0on_pushButtonGetVolume_clicked()\0"
};

const QMetaObject CGetVolumeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CGetVolumeDialog,
      qt_meta_data_CGetVolumeDialog, 0 }
};

const QMetaObject *CGetVolumeDialog::metaObject() const
{
    return &staticMetaObject;
}

void *CGetVolumeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CGetVolumeDialog))
	return static_cast<void*>(const_cast< CGetVolumeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CGetVolumeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonGetVolume_clicked(); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
