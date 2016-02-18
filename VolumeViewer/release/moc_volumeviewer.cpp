/****************************************************************************
** Meta object code from reading C++ file 'volumeviewer.h'
**
** Created: Fri Sep 26 23:08:37 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../volumeviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'volumeviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CVolumeViewer[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      52,   14,   14,   14, 0x08,
      82,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CVolumeViewer[] = {
    "CVolumeViewer\0\0on_pushButtonDisplayVolume_clicked()\0"
    "on_pushButtonBrowse_clicked()\0Test()\0"
};

const QMetaObject CVolumeViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CVolumeViewer,
      qt_meta_data_CVolumeViewer, 0 }
};

const QMetaObject *CVolumeViewer::metaObject() const
{
    return &staticMetaObject;
}

void *CVolumeViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CVolumeViewer))
	return static_cast<void*>(const_cast< CVolumeViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CVolumeViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonDisplayVolume_clicked(); break;
        case 1: on_pushButtonBrowse_clicked(); break;
        case 2: Test(); break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
