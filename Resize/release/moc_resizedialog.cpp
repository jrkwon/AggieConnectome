/****************************************************************************
** Meta object code from reading C++ file 'resizedialog.h'
**
** Created: Wed Oct 1 01:25:38 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../resizedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resizedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CResizeDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      55,   14,   14,   14, 0x08,
      90,   14,   14,   14, 0x08,
     125,   14,   14,   14, 0x08,
     153,   14,   14,   14, 0x08,
     204,  183,   14,   14, 0x08,
     252,  246,   14,   14, 0x08,
     289,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CResizeDialog[] = {
    "CResizeDialog\0\0on_pushButtonDataFolderBrowse_clicked()\0"
    "on_pushButtonClearOutput_clicked()\0"
    "on_pushButtonPauseResume_clicked()\0"
    "on_pushButtonStop_clicked()\0"
    "on_pushButtonResize_clicked()\0"
    "nExitCode,ExitStatus\0"
    "ProcessFinished(int,QProcess::ExitStatus)\0"
    "Error\0ProcessError(QProcess::ProcessError)\0"
    "UpdateOutput()\0"
};

const QMetaObject CResizeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CResizeDialog,
      qt_meta_data_CResizeDialog, 0 }
};

const QMetaObject *CResizeDialog::metaObject() const
{
    return &staticMetaObject;
}

void *CResizeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CResizeDialog))
	return static_cast<void*>(const_cast< CResizeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CResizeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonDataFolderBrowse_clicked(); break;
        case 1: on_pushButtonClearOutput_clicked(); break;
        case 2: on_pushButtonPauseResume_clicked(); break;
        case 3: on_pushButtonStop_clicked(); break;
        case 4: on_pushButtonResize_clicked(); break;
        case 5: ProcessFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 6: ProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 7: UpdateOutput(); break;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
