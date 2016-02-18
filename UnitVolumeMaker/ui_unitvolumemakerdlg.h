/********************************************************************************
** Form generated from reading ui file 'UnitVolumeMakerDlg.ui'
**
** Created: Thu Oct 2 14:01:20 2008
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
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CUnitVolumeMakerDlgClass
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditDataFolder;
    QPushButton *pushButtonDataFolder;
    QListWidget *listWidgetDataInfo;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *comboBoxZoomOutLevel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QComboBox *comboBoxWidth;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QComboBox *comboBoxLength;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QComboBox *comboBoxHeight;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QListWidget *listWidgetLog;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClearLog;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QProgressBar *progressBarImage;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QProgressBar *progressBarZoomOut;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QProgressBar *progressBarWidth;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QProgressBar *progressBarLength;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QProgressBar *progressBarHeight;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *CUnitVolumeMakerDlgClass)
    {
    if (CUnitVolumeMakerDlgClass->objectName().isEmpty())
        CUnitVolumeMakerDlgClass->setObjectName(QString::fromUtf8("CUnitVolumeMakerDlgClass"));
    CUnitVolumeMakerDlgClass->resize(556, 553);
    gridLayout = new QGridLayout(CUnitVolumeMakerDlgClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    graphicsView = new QGraphicsView(CUnitVolumeMakerDlgClass);
    graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
    graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/banner.jpg);"));

    gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_5 = new QLabel(CUnitVolumeMakerDlgClass);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    horizontalLayout_2->addWidget(label_5);

    lineEditDataFolder = new QLineEdit(CUnitVolumeMakerDlgClass);
    lineEditDataFolder->setObjectName(QString::fromUtf8("lineEditDataFolder"));

    horizontalLayout_2->addWidget(lineEditDataFolder);

    pushButtonDataFolder = new QPushButton(CUnitVolumeMakerDlgClass);
    pushButtonDataFolder->setObjectName(QString::fromUtf8("pushButtonDataFolder"));

    horizontalLayout_2->addWidget(pushButtonDataFolder);


    gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

    listWidgetDataInfo = new QListWidget(CUnitVolumeMakerDlgClass);
    listWidgetDataInfo->setObjectName(QString::fromUtf8("listWidgetDataInfo"));
    listWidgetDataInfo->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.jpg);"));

    gridLayout->addWidget(listWidgetDataInfo, 2, 0, 1, 1);

    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setSpacing(6);
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

    gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_4 = new QLabel(CUnitVolumeMakerDlgClass);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    horizontalLayout->addWidget(label_4);

    comboBoxZoomOutLevel = new QComboBox(CUnitVolumeMakerDlgClass);
    comboBoxZoomOutLevel->setObjectName(QString::fromUtf8("comboBoxZoomOutLevel"));

    horizontalLayout->addWidget(comboBoxZoomOutLevel);

    horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_4);

    label = new QLabel(CUnitVolumeMakerDlgClass);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout->addWidget(label);

    comboBoxWidth = new QComboBox(CUnitVolumeMakerDlgClass);
    comboBoxWidth->setObjectName(QString::fromUtf8("comboBoxWidth"));

    horizontalLayout->addWidget(comboBoxWidth);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_2);

    label_2 = new QLabel(CUnitVolumeMakerDlgClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    horizontalLayout->addWidget(label_2);

    comboBoxLength = new QComboBox(CUnitVolumeMakerDlgClass);
    comboBoxLength->setObjectName(QString::fromUtf8("comboBoxLength"));

    horizontalLayout->addWidget(comboBoxLength);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_3);

    label_3 = new QLabel(CUnitVolumeMakerDlgClass);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    horizontalLayout->addWidget(label_3);

    comboBoxHeight = new QComboBox(CUnitVolumeMakerDlgClass);
    comboBoxHeight->setObjectName(QString::fromUtf8("comboBoxHeight"));

    horizontalLayout->addWidget(comboBoxHeight);


    gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    label_6 = new QLabel(CUnitVolumeMakerDlgClass);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    verticalLayout->addWidget(label_6);

    listWidgetLog = new QListWidget(CUnitVolumeMakerDlgClass);
    listWidgetLog->setObjectName(QString::fromUtf8("listWidgetLog"));

    verticalLayout->addWidget(listWidgetLog);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer);

    pushButtonClearLog = new QPushButton(CUnitVolumeMakerDlgClass);
    pushButtonClearLog->setObjectName(QString::fromUtf8("pushButtonClearLog"));

    horizontalLayout_3->addWidget(pushButtonClearLog);


    verticalLayout->addLayout(horizontalLayout_3);


    gridLayout->addLayout(verticalLayout, 5, 0, 1, 1);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    horizontalLayout_10 = new QHBoxLayout();
    horizontalLayout_10->setSpacing(6);
    horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
    label_11 = new QLabel(CUnitVolumeMakerDlgClass);
    label_11->setObjectName(QString::fromUtf8("label_11"));

    horizontalLayout_10->addWidget(label_11);

    progressBarImage = new QProgressBar(CUnitVolumeMakerDlgClass);
    progressBarImage->setObjectName(QString::fromUtf8("progressBarImage"));
    progressBarImage->setValue(24);

    horizontalLayout_10->addWidget(progressBarImage);


    verticalLayout_2->addLayout(horizontalLayout_10);

    horizontalLayout_11 = new QHBoxLayout();
    horizontalLayout_11->setSpacing(6);
    horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
    label_10 = new QLabel(CUnitVolumeMakerDlgClass);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    horizontalLayout_11->addWidget(label_10);

    progressBarZoomOut = new QProgressBar(CUnitVolumeMakerDlgClass);
    progressBarZoomOut->setObjectName(QString::fromUtf8("progressBarZoomOut"));
    progressBarZoomOut->setValue(24);

    horizontalLayout_11->addWidget(progressBarZoomOut);


    verticalLayout_2->addLayout(horizontalLayout_11);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(6);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label_7 = new QLabel(CUnitVolumeMakerDlgClass);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    horizontalLayout_4->addWidget(label_7);

    progressBarWidth = new QProgressBar(CUnitVolumeMakerDlgClass);
    progressBarWidth->setObjectName(QString::fromUtf8("progressBarWidth"));
    progressBarWidth->setValue(24);

    horizontalLayout_4->addWidget(progressBarWidth);


    verticalLayout_2->addLayout(horizontalLayout_4);

    horizontalLayout_8 = new QHBoxLayout();
    horizontalLayout_8->setSpacing(6);
    horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
    label_8 = new QLabel(CUnitVolumeMakerDlgClass);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    horizontalLayout_8->addWidget(label_8);

    progressBarLength = new QProgressBar(CUnitVolumeMakerDlgClass);
    progressBarLength->setObjectName(QString::fromUtf8("progressBarLength"));
    progressBarLength->setValue(24);

    horizontalLayout_8->addWidget(progressBarLength);


    verticalLayout_2->addLayout(horizontalLayout_8);

    horizontalLayout_9 = new QHBoxLayout();
    horizontalLayout_9->setSpacing(6);
    horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
    label_9 = new QLabel(CUnitVolumeMakerDlgClass);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    horizontalLayout_9->addWidget(label_9);

    progressBarHeight = new QProgressBar(CUnitVolumeMakerDlgClass);
    progressBarHeight->setObjectName(QString::fromUtf8("progressBarHeight"));
    progressBarHeight->setValue(24);

    horizontalLayout_9->addWidget(progressBarHeight);


    verticalLayout_2->addLayout(horizontalLayout_9);


    gridLayout->addLayout(verticalLayout_2, 6, 0, 1, 1);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setSpacing(6);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_5->addItem(horizontalSpacer_5);

    pushButtonStart = new QPushButton(CUnitVolumeMakerDlgClass);
    pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

    horizontalLayout_5->addWidget(pushButtonStart);

    pushButtonStop = new QPushButton(CUnitVolumeMakerDlgClass);
    pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

    horizontalLayout_5->addWidget(pushButtonStop);

    horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_5->addItem(horizontalSpacer_6);


    gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 1);

    graphicsView->raise();
    listWidgetDataInfo->raise();
    label_11->raise();
    progressBarImage->raise();
    progressBarImage->raise();

    retranslateUi(CUnitVolumeMakerDlgClass);

    QMetaObject::connectSlotsByName(CUnitVolumeMakerDlgClass);
    } // setupUi

    void retranslateUi(QDialog *CUnitVolumeMakerDlgClass)
    {
    CUnitVolumeMakerDlgClass->setWindowTitle(QApplication::translate("CUnitVolumeMakerDlgClass", "KESM Unit Volume Maker", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Data Folder: ", 0, QApplication::UnicodeUTF8));
    pushButtonDataFolder->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Browse..", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Zoom Out Level:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "iWidth: ", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "iLength: ", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "iHeight: ", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Log:  ", 0, QApplication::UnicodeUTF8));
    pushButtonClearLog->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Clear Log", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Image:", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "ZoomOut: ", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Width: ", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Length: ", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Height:", 0, QApplication::UnicodeUTF8));
    pushButtonStart->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Start", 0, QApplication::UnicodeUTF8));
    pushButtonStop->setText(QApplication::translate("CUnitVolumeMakerDlgClass", "Stop", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CUnitVolumeMakerDlgClass);
    } // retranslateUi

};

namespace Ui {
    class CUnitVolumeMakerDlgClass: public Ui_CUnitVolumeMakerDlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITVOLUMEMAKERDLG_H
