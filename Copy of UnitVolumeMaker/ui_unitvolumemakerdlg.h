/********************************************************************************
** Form generated from reading ui file 'UnitVolumeMakerDlg.ui'
**
** Created: Wed Oct 1 10:10:51 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UNITVOLUMEMAKERDLG_H
#define UI_UNITVOLUMEMAKERDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CUnitVolumeMakerDlgClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditWidth;
    QLabel *label_2;
    QLineEdit *lineEditLength;
    QLabel *label_3;
    QLineEdit *lineEditHeight;
    QLabel *label_4;
    QComboBox *comboBoxZoomOut;
    QPushButton *pushButtonGetVolume;
    QListWidget *listWidgetResult;

    void setupUi(QDialog *CUnitVolumeMakerDlgClass)
    {
    if (CUnitVolumeMakerDlgClass->objectName().isEmpty())
        CUnitVolumeMakerDlgClass->setObjectName(QString::fromUtf8("CUnitVolumeMakerDlgClass"));
    CUnitVolumeMakerDlgClass->resize(494, 426);
    layoutWidget = new QWidget(CUnitVolumeMakerDlgClass);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(12, 8, 471, 411));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setMargin(11);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(layoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    lineEditWidth = new QLineEdit(layoutWidget);
    lineEditWidth->setObjectName(QString::fromUtf8("lineEditWidth"));

    gridLayout->addWidget(lineEditWidth, 0, 1, 1, 1);

    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    lineEditLength = new QLineEdit(layoutWidget);
    lineEditLength->setObjectName(QString::fromUtf8("lineEditLength"));

    gridLayout->addWidget(lineEditLength, 1, 1, 1, 1);

    label_3 = new QLabel(layoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    lineEditHeight = new QLineEdit(layoutWidget);
    lineEditHeight->setObjectName(QString::fromUtf8("lineEditHeight"));

    gridLayout->addWidget(lineEditHeight, 2, 1, 1, 1);

    label_4 = new QLabel(layoutWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    comboBoxZoomOut = new QComboBox(layoutWidget);
    comboBoxZoomOut->setObjectName(QString::fromUtf8("comboBoxZoomOut"));

    gridLayout->addWidget(comboBoxZoomOut, 3, 1, 1, 1);


    horizontalLayout->addLayout(gridLayout);

    pushButtonGetVolume = new QPushButton(layoutWidget);
    pushButtonGetVolume->setObjectName(QString::fromUtf8("pushButtonGetVolume"));

    horizontalLayout->addWidget(pushButtonGetVolume);


    verticalLayout->addLayout(horizontalLayout);

    listWidgetResult = new QListWidget(layoutWidget);
    listWidgetResult->setObjectName(QString::fromUtf8("listWidgetResult"));

    verticalLayout->addWidget(listWidgetResult);


    retranslateUi(CUnitVolumeMakerDlgClass);

    QMetaObject::connectSlotsByName(CUnitVolumeMakerDlgClass);
    } // setupUi

    void retranslateUi(QDialog *CUnitVolumeMakerDlgClass)
    {
    CUnitVolumeMakerDlgClass->setWindowTitle(QApplication::translate("CUnitVolumeMakerDlgClass", "CGetVolumeDialog", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Index of Width", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Index of Length", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Index of Height", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "ZoomOut:", 0, QApplication::UnicodeUTF8));
    pushButtonGetVolume->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Get Volume", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CUnitVolumeMakerDlgClass);
    } // retranslateUi

};

namespace Ui {
    class CUnitVolumeMakerDlgClass: public Ui_CUnitVolumeMakerDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITVOLUMEMAKERDLG_H
