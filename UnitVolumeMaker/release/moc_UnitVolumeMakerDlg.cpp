/****************************************************************************
** Meta object code from reading C++ file 'UnitVolumeMakerDlg.h'
**
** Created: Mon Nov 3 23:14:44 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UnitVolumeMakerDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UnitVolumeMakerDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CUnitVolumeMakerDlg[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      55,   20,   20,   20, 0x08,
      84,   20,   20,   20, 0x08,
     112,   20,   20,   20, 0x08,
     144,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CUnitVolumeMakerDlg[] = {
    "CUnitVolumeMakerDlg\0\0"
    "on_pushButtonDataFolder_clicked()\0"
    "on_pushButtonStart_clicked()\0"
    "on_pushButtonStop_clicked()\0"
    "on_pushButtonClearLog_clicked()\0"
    "RedoIndexes()\0"
};

const QMetaObject CUnitVolumeMakerDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CUnitVolumeMakerDlg,
      qt_meta_data_CUnitVolumeMakerDlg, 0 }
};

const QMetaObject *CUnitVolumeMakerDlg::metaObject() const
{
    return &staticMetaObject;
}

void *CUnitVolumeMakerDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CUnitVolumeMakerDlg))
	return static_cast<void*>(const_cast< CUnitVolumeMakerDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CUnitVolumeMakerDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonDataFolder_clicked(); break;
        case 1: on_pushButtonStart_clicked(); break;
        case 2: on_pushButtonStop_clicked(); break;
        case 3: on_pushButtonClearLog_clicked(); break;
        case 4: RedoIndexes(); break;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
