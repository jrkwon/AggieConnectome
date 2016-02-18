/********************************************************************************
** Form generated from reading ui file 'registrationdlg.ui'
**
** Created: Mon Sep 15 17:50:52 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_REGISTRATIONDLG_H
#define UI_REGISTRATIONDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CRegistrationDlgClass
{
public:

    void setupUi(QDialog *CRegistrationDlgClass)
    {
    if (CRegistrationDlgClass->objectName().isEmpty())
        CRegistrationDlgClass->setObjectName(QString::fromUtf8("CRegistrationDlgClass"));
    CRegistrationDlgClass->resize(400, 300);

    retranslateUi(CRegistrationDlgClass);

    QMetaObject::connectSlotsByName(CRegistrationDlgClass);
    } // setupUi

    void retranslateUi(QDialog *CRegistrationDlgClass)
    {
    CRegistrationDlgClass->setWindowTitle(QApplication::translate("CRegistrationDlgClass", "CRegistrationDlg", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CRegistrationDlgClass);
    } // retranslateUi

};

namespace Ui {
    class CRegistrationDlgClass: public Ui_CRegistrationDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONDLG_H
