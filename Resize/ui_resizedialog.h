/********************************************************************************
** Form generated from reading ui file 'resizedialog.ui'
**
** Created: Fri Sep 26 03:27:09 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RESIZEDIALOG_H
#define UI_RESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
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

class Ui_CResizeDialogClass
{
public:
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditDataFolder;
    QPushButton *pushButtonDataFolderBrowse;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *listWidgetDataInfo;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidgetOutput;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClearOutput;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QProgressBar *progressBarZoomOut;
    QLabel *label_5;
    QProgressBar *progressBarColumn;
    QLabel *label_6;
    QProgressBar *progressBarImage;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonResize;
    QPushButton *pushButtonPauseResume;
    QPushButton *pushButtonStop;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QComboBox *comboBoxZoomOutLevel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QComboBox *comboBoxColumnNum;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBoxAverage;

    void setupUi(QDialog *CResizeDialogClass)
    {
    if (CResizeDialogClass->objectName().isEmpty())
        CResizeDialogClass->setObjectName(QString::fromUtf8("CResizeDialogClass"));
    CResizeDialogClass->resize(578, 606);
    gridLayout_2 = new QGridLayout(CResizeDialogClass);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setMargin(11);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    graphicsView = new QGraphicsView(CResizeDialogClass);
    graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
    graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/images/banner.jpg);"));

    gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label = new QLabel(CResizeDialogClass);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout->addWidget(label);

    lineEditDataFolder = new QLineEdit(CResizeDialogClass);
    lineEditDataFolder->setObjectName(QString::fromUtf8("lineEditDataFolder"));

    horizontalLayout->addWidget(lineEditDataFolder);

    pushButtonDataFolderBrowse = new QPushButton(CResizeDialogClass);
    pushButtonDataFolderBrowse->setObjectName(QString::fromUtf8("pushButtonDataFolderBrowse"));

    horizontalLayout->addWidget(pushButtonDataFolderBrowse);


    gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    label_2 = new QLabel(CResizeDialogClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    verticalLayout->addWidget(label_2);

    listWidgetDataInfo = new QListWidget(CResizeDialogClass);
    listWidgetDataInfo->setObjectName(QString::fromUtf8("listWidgetDataInfo"));
    listWidgetDataInfo->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.jpg);"));
    listWidgetDataInfo->setSelectionMode(QAbstractItemView::ContiguousSelection);

    verticalLayout->addWidget(listWidgetDataInfo);


    gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 1);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_3 = new QLabel(CResizeDialogClass);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    verticalLayout_2->addWidget(label_3);

    listWidgetOutput = new QListWidget(CResizeDialogClass);
    listWidgetOutput->setObjectName(QString::fromUtf8("listWidgetOutput"));
    listWidgetOutput->setStyleSheet(QString::fromUtf8("background-image: url(:/images/bnl_logo_bg.jpg);"));
    listWidgetOutput->setSelectionMode(QAbstractItemView::ContiguousSelection);

    verticalLayout_2->addWidget(listWidgetOutput);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer);

    pushButtonClearOutput = new QPushButton(CResizeDialogClass);
    pushButtonClearOutput->setObjectName(QString::fromUtf8("pushButtonClearOutput"));

    horizontalLayout_2->addWidget(pushButtonClearOutput);


    verticalLayout_2->addLayout(horizontalLayout_2);


    gridLayout_2->addLayout(verticalLayout_2, 10, 0, 1, 1);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label_4 = new QLabel(CResizeDialogClass);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 0, 0, 1, 1);

    progressBarZoomOut = new QProgressBar(CResizeDialogClass);
    progressBarZoomOut->setObjectName(QString::fromUtf8("progressBarZoomOut"));
    progressBarZoomOut->setValue(24);

    gridLayout->addWidget(progressBarZoomOut, 0, 1, 1, 1);

    label_5 = new QLabel(CResizeDialogClass);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout->addWidget(label_5, 1, 0, 1, 1);

    progressBarColumn = new QProgressBar(CResizeDialogClass);
    progressBarColumn->setObjectName(QString::fromUtf8("progressBarColumn"));
    progressBarColumn->setValue(24);

    gridLayout->addWidget(progressBarColumn, 1, 1, 1, 1);

    label_6 = new QLabel(CResizeDialogClass);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout->addWidget(label_6, 2, 0, 1, 1);

    progressBarImage = new QProgressBar(CResizeDialogClass);
    progressBarImage->setObjectName(QString::fromUtf8("progressBarImage"));
    progressBarImage->setValue(24);

    gridLayout->addWidget(progressBarImage, 2, 1, 1, 1);


    gridLayout_2->addLayout(gridLayout, 11, 0, 1, 1);

    line = new QFrame(CResizeDialogClass);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    gridLayout_2->addWidget(line, 12, 0, 1, 1);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_2);

    pushButtonResize = new QPushButton(CResizeDialogClass);
    pushButtonResize->setObjectName(QString::fromUtf8("pushButtonResize"));

    horizontalLayout_3->addWidget(pushButtonResize);

    pushButtonPauseResume = new QPushButton(CResizeDialogClass);
    pushButtonPauseResume->setObjectName(QString::fromUtf8("pushButtonPauseResume"));

    horizontalLayout_3->addWidget(pushButtonPauseResume);

    pushButtonStop = new QPushButton(CResizeDialogClass);
    pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

    horizontalLayout_3->addWidget(pushButtonStop);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer_3);


    gridLayout_2->addLayout(horizontalLayout_3, 13, 0, 1, 1);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setSpacing(6);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    label_7 = new QLabel(CResizeDialogClass);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    horizontalLayout_5->addWidget(label_7);

    comboBoxZoomOutLevel = new QComboBox(CResizeDialogClass);
    comboBoxZoomOutLevel->setObjectName(QString::fromUtf8("comboBoxZoomOutLevel"));

    horizontalLayout_5->addWidget(comboBoxZoomOutLevel);

    horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_5->addItem(horizontalSpacer_4);

    label_8 = new QLabel(CResizeDialogClass);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setLayoutDirection(Qt::LeftToRight);
    label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

    horizontalLayout_5->addWidget(label_8);

    comboBoxColumnNum = new QComboBox(CResizeDialogClass);
    comboBoxColumnNum->setObjectName(QString::fromUtf8("comboBoxColumnNum"));

    horizontalLayout_5->addWidget(comboBoxColumnNum);

    horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_5->addItem(horizontalSpacer_5);

    checkBoxAverage = new QCheckBox(CResizeDialogClass);
    checkBoxAverage->setObjectName(QString::fromUtf8("checkBoxAverage"));

    horizontalLayout_5->addWidget(checkBoxAverage);


    gridLayout_2->addLayout(horizontalLayout_5, 4, 0, 1, 1);


    retranslateUi(CResizeDialogClass);

    QMetaObject::connectSlotsByName(CResizeDialogClass);
    } // setupUi

    void retranslateUi(QDialog *CResizeDialogClass)
    {
    CResizeDialogClass->setWindowTitle(QApplication::translate("CResizeDialogClass", "KESM Data Resizer", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CResizeDialogClass", "Data Folder:", 0, QApplication::UnicodeUTF8));
    pushButtonDataFolderBrowse->setText(QApplication::translate("CResizeDialogClass", "Browse", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CResizeDialogClass", "Data Information", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("CResizeDialogClass", "Console Output", 0, QApplication::UnicodeUTF8));
    pushButtonClearOutput->setText(QApplication::translate("CResizeDialogClass", "Clear Output", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("CResizeDialogClass", "Zoom Out:", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("CResizeDialogClass", "Column:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("CResizeDialogClass", "Image:", 0, QApplication::UnicodeUTF8));
    pushButtonResize->setText(QApplication::translate("CResizeDialogClass", "Resize", 0, QApplication::UnicodeUTF8));
    pushButtonPauseResume->setText(QApplication::translate("CResizeDialogClass", "Pause", 0, QApplication::UnicodeUTF8));
    pushButtonStop->setText(QApplication::translate("CResizeDialogClass", "Stop", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("CResizeDialogClass", "Zoom Out Level: ", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("CResizeDialogClass", "Column Num: ", 0, QApplication::UnicodeUTF8));
    checkBoxAverage->setText(QApplication::translate("CResizeDialogClass", "Average", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CResizeDialogClass);
    } // retranslateUi

};

namespace Ui {
    class CResizeDialogClass: public Ui_CResizeDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
