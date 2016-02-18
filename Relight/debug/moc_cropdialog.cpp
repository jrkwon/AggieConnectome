/****************************************************************************
** Meta object code from reading C++ file 'cropdialog.h'
**
** Created: Fri Feb 5 15:12:51 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cropdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cropdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CCropDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      28,   12,   12,   12, 0x08,
      70,   12,   12,   12, 0x08,
     110,   12,   12,   12, 0x08,
     138,   12,   12,   12, 0x08,
     173,   12,   12,   12, 0x08,
     201,   12,   12,   12, 0x08,
     257,  236,   12,   12, 0x08,
     305,  299,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CCropDialog[] = {
    "CCropDialog\0\0UpdateOutput()\0"
    "on_pushButtonSourceFolderBrowse_clicked()\0"
    "on_pushButtonDestFolderBrowse_clicked()\0"
    "on_pushButtonCrop_clicked()\0"
    "on_pushButtonPauseResume_clicked()\0"
    "on_pushButtonStop_clicked()\0"
    "on_pushButtonClearOutput_clicked()\0"
    "nExitCode,ExitStatus\0"
    "ProcessFinished(int,QProcess::ExitStatus)\0"
    "Error\0ProcessError(QProcess::ProcessError)\0"
};

const QMetaObject CCropDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CCropDialog,
      qt_meta_data_CCropDialog, 0 }
};

const QMetaObject *CCropDialog::metaObject() const
{
    return &staticMetaObject;
}

void *CCropDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CCropDialog))
        return static_cast<void*>(const_cast< CCropDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CCropDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateOutput(); break;
        case 1: on_pushButtonSourceFolderBrowse_clicked(); break;
        case 2: on_pushButtonDestFolderBrowse_clicked(); break;
        case 3: on_pushButtonCrop_clicked(); break;
        case 4: on_pushButtonPauseResume_clicked(); break;
        case 5: on_pushButtonStop_clicked(); break;
        case 6: on_pushButtonClearOutput_clicked(); break;
        case 7: ProcessFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 8: ProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
