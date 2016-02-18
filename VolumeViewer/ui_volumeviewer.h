/********************************************************************************
** Form generated from reading ui file 'volumeviewer.ui'
**
** Created: Thu Mar 26 22:59:48 2009
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VOLUMEVIEWER_H
#define UI_VOLUMEVIEWER_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CVolumeViewerClass
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QLineEdit *lineEditDataFolder;
    QPushButton *pushButtonBrowse;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *comboBoxZoomOutLevel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBoxWidth;
    QComboBox *comboBoxLength;
    QComboBox *comboBoxHeight;
    QPushButton *pushButtonDisplayVolume;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonSaveToVTK;
    QPushButton *pushButtonSaveToVol;
    QProgressBar *progressBar;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_14;
    QLineEdit *lineEditValue;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QVTKWidget *vtkWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CVolumeViewerClass)
    {
    if (CVolumeViewerClass->objectName().isEmpty())
        CVolumeViewerClass->setObjectName(QString::fromUtf8("CVolumeViewerClass"));
    CVolumeViewerClass->resize(878, 700);
    centralwidget = new QWidget(CVolumeViewerClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 33, 878, 648));
    gridLayout_3 = new QGridLayout(centralwidget);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_13 = new QLabel(centralwidget);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setMaximumSize(QSize(70, 16777215));

    horizontalLayout->addWidget(label_13);

    lineEditDataFolder = new QLineEdit(centralwidget);
    lineEditDataFolder->setObjectName(QString::fromUtf8("lineEditDataFolder"));
    lineEditDataFolder->setMaximumSize(QSize(150, 16777215));

    horizontalLayout->addWidget(lineEditDataFolder);

    pushButtonBrowse = new QPushButton(centralwidget);
    pushButtonBrowse->setObjectName(QString::fromUtf8("pushButtonBrowse"));
    pushButtonBrowse->setMaximumSize(QSize(75, 16777215));

    horizontalLayout->addWidget(pushButtonBrowse);


    verticalLayout->addLayout(horizontalLayout);

    groupBox_2 = new QGroupBox(centralwidget);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setMinimumSize(QSize(100, 0));
    groupBox_2->setMaximumSize(QSize(300, 16777215));
    gridLayout_2 = new QGridLayout(groupBox_2);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    label_4 = new QLabel(groupBox_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

    comboBoxZoomOutLevel = new QComboBox(groupBox_2);
    comboBoxZoomOutLevel->setObjectName(QString::fromUtf8("comboBoxZoomOutLevel"));

    gridLayout_2->addWidget(comboBoxZoomOutLevel, 0, 1, 1, 1);


    verticalLayout->addWidget(groupBox_2);

    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setMinimumSize(QSize(250, 0));
    groupBox->setMaximumSize(QSize(300, 16777215));
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setMaximumSize(QSize(40, 21));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setMaximumSize(QSize(40, 21));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setMaximumSize(QSize(40, 21));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    comboBoxWidth = new QComboBox(groupBox);
    comboBoxWidth->setObjectName(QString::fromUtf8("comboBoxWidth"));

    gridLayout->addWidget(comboBoxWidth, 0, 2, 1, 1);

    comboBoxLength = new QComboBox(groupBox);
    comboBoxLength->setObjectName(QString::fromUtf8("comboBoxLength"));

    gridLayout->addWidget(comboBoxLength, 1, 2, 1, 1);

    comboBoxHeight = new QComboBox(groupBox);
    comboBoxHeight->setObjectName(QString::fromUtf8("comboBoxHeight"));

    gridLayout->addWidget(comboBoxHeight, 2, 2, 1, 1);


    verticalLayout->addWidget(groupBox);

    pushButtonDisplayVolume = new QPushButton(centralwidget);
    pushButtonDisplayVolume->setObjectName(QString::fromUtf8("pushButtonDisplayVolume"));
    pushButtonDisplayVolume->setMaximumSize(QSize(300, 16777215));

    verticalLayout->addWidget(pushButtonDisplayVolume);

    pushButtonReset = new QPushButton(centralwidget);
    pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
    pushButtonReset->setMaximumSize(QSize(300, 16777215));

    verticalLayout->addWidget(pushButtonReset);

    pushButtonSaveToVTK = new QPushButton(centralwidget);
    pushButtonSaveToVTK->setObjectName(QString::fromUtf8("pushButtonSaveToVTK"));
    pushButtonSaveToVTK->setMaximumSize(QSize(300, 16777215));

    verticalLayout->addWidget(pushButtonSaveToVTK);

    pushButtonSaveToVol = new QPushButton(centralwidget);
    pushButtonSaveToVol->setObjectName(QString::fromUtf8("pushButtonSaveToVol"));
    pushButtonSaveToVol->setMaximumSize(QSize(300, 16777215));

    verticalLayout->addWidget(pushButtonSaveToVol);

    progressBar = new QProgressBar(centralwidget);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setMaximumSize(QSize(300, 16777215));
    progressBar->setValue(24);

    verticalLayout->addWidget(progressBar);

    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setMinimumSize(QSize(100, 0));
    tabWidget->setMaximumSize(QSize(300, 16777215));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    tab->setGeometry(QRect(0, 0, 244, 254));
    label_14 = new QLabel(tab);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setGeometry(QRect(11, 11, 85, 20));
    lineEditValue = new QLineEdit(tab);
    lineEditValue->setObjectName(QString::fromUtf8("lineEditValue"));
    lineEditValue->setGeometry(QRect(102, 11, 133, 20));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tab_2->setGeometry(QRect(4, 30, 244, 282));
    tabWidget->addTab(tab_2, QString());

    verticalLayout->addWidget(tabWidget);


    gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    vtkWidget = new QVTKWidget(centralwidget);
    vtkWidget->setObjectName(QString::fromUtf8("vtkWidget"));
    vtkWidget->setMinimumSize(QSize(600, 0));

    horizontalLayout_2->addWidget(vtkWidget);


    gridLayout_3->addLayout(horizontalLayout_2, 0, 1, 1, 1);

    CVolumeViewerClass->setCentralWidget(centralwidget);
    menubar = new QMenuBar(CVolumeViewerClass);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 878, 21));
    CVolumeViewerClass->setMenuBar(menubar);
    statusbar = new QStatusBar(CVolumeViewerClass);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 681, 878, 19));
    CVolumeViewerClass->setStatusBar(statusbar);
    toolBar = new QToolBar(CVolumeViewerClass);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setGeometry(QRect(0, 21, 878, 12));
    CVolumeViewerClass->addToolBar(Qt::TopToolBarArea, toolBar);

    retranslateUi(CVolumeViewerClass);

    QMetaObject::connectSlotsByName(CVolumeViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CVolumeViewerClass)
    {
    CVolumeViewerClass->setWindowTitle(QApplication::translate("CVolumeViewerClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("CVolumeViewerClass", "Data Folder:", 0, QApplication::UnicodeUTF8));
    pushButtonBrowse->setText(QApplication::translate("CVolumeViewerClass", "Browse", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("CVolumeViewerClass", "Zoom Out Level", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("CVolumeViewerClass", "Zoom Out Level:", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("CVolumeViewerClass", "Volume Index", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CVolumeViewerClass", "iWidth:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CVolumeViewerClass", "iLength:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("CVolumeViewerClass", "iHeight:", 0, QApplication::UnicodeUTF8));
    pushButtonDisplayVolume->setText(QApplication::translate("CVolumeViewerClass", "Display the Volume", 0, QApplication::UnicodeUTF8));
    pushButtonReset->setText(QApplication::translate("CVolumeViewerClass", "Reset", 0, QApplication::UnicodeUTF8));
    pushButtonSaveToVTK->setText(QApplication::translate("CVolumeViewerClass", "Save to VTK", 0, QApplication::UnicodeUTF8));
    pushButtonSaveToVol->setText(QApplication::translate("CVolumeViewerClass", "Save to Vol", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("CVolumeViewerClass", "iso Surface Value:", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CVolumeViewerClass", "Tab 1", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CVolumeViewerClass", "Tab 2", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("CVolumeViewerClass", "toolBar", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CVolumeViewerClass);
    } // retranslateUi

};

namespace Ui {
    class CVolumeViewerClass: public Ui_CVolumeViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMEVIEWER_H
