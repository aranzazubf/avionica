/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter;
    QVTKWidget *qvtkWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *x;
    QPushButton *y;
    QPushButton *z;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QGroupBox *Mesh;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *angle;
    QPushButton *line;
    QPushButton *rubber;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QListWidget *listWidget_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_2;
    QPushButton *load;
    QPushButton *back;
    QPushButton *save;
    QPushButton *fullScreen;
    QPushButton *help;

    void setupUi(QWidget *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QStringLiteral("Viewer"));
        Viewer->setWindowModality(Qt::ApplicationModal);
        Viewer->resize(1551, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Viewer->sizePolicy().hasHeightForWidth());
        Viewer->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 170, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 255, 191, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(0, 212, 159, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 85, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 113, 84, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(0, 222, 163, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush7);
        QBrush brush8(QColor(0, 111, 81, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush8);
        QBrush brush9(QColor(127, 212, 191, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Viewer->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/white/settings@3x.png"), QSize(), QIcon::Normal, QIcon::Off);
        Viewer->setWindowIcon(icon);
        verticalLayout_7 = new QVBoxLayout(Viewer);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Viewer);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setEnabled(true);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setLayoutDirection(Qt::LeftToRight);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(1);
        splitter->setChildrenCollapsible(true);
        qvtkWidget = new QVTKWidget(splitter);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy1);
        qvtkWidget->setMinimumSize(QSize(1000, 800));
        qvtkWidget->setBaseSize(QSize(0, 747));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        qvtkWidget->setPalette(palette1);
        qvtkWidget->setAutoFillBackground(false);
        splitter->addWidget(qvtkWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        groupBox_2->setPalette(palette2);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        x = new QPushButton(groupBox_2);
        x->setObjectName(QStringLiteral("x"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(x->sizePolicy().hasHeightForWidth());
        x->setSizePolicy(sizePolicy3);
        x->setAcceptDrops(true);

        horizontalLayout_2->addWidget(x);

        y = new QPushButton(groupBox_2);
        y->setObjectName(QStringLiteral("y"));
        sizePolicy3.setHeightForWidth(y->sizePolicy().hasHeightForWidth());
        y->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(y);

        z = new QPushButton(groupBox_2);
        z->setObjectName(QStringLiteral("z"));
        sizePolicy3.setHeightForWidth(z->sizePolicy().hasHeightForWidth());
        z->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(z);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        sizePolicy3.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy3);
        horizontalSlider->setAutoFillBackground(true);
        horizontalSlider->setMinimum(-100000);
        horizontalSlider->setMaximum(100000);
        horizontalSlider->setPageStep(2);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_5->addLayout(verticalLayout);


        verticalLayout_6->addWidget(groupBox_2);

        Mesh = new QGroupBox(layoutWidget);
        Mesh->setObjectName(QStringLiteral("Mesh"));
        sizePolicy2.setHeightForWidth(Mesh->sizePolicy().hasHeightForWidth());
        Mesh->setSizePolicy(sizePolicy2);
        Mesh->setMouseTracking(false);
        verticalLayout_3 = new QVBoxLayout(Mesh);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        angle = new QPushButton(Mesh);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setAutoFillBackground(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/white/x48/ang@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/images/black/x48/ang@3x.png"), QSize(), QIcon::Selected, QIcon::Off);
        angle->setIcon(icon1);
        angle->setIconSize(QSize(42, 42));
        angle->setFlat(true);

        horizontalLayout_6->addWidget(angle);

        line = new QPushButton(Mesh);
        line->setObjectName(QStringLiteral("line"));
        line->setAutoFillBackground(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/white/x48/line@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/images/black/x48/line@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QStringLiteral(":/images/black/x48/line@4x.png"), QSize(), QIcon::Selected, QIcon::On);
        line->setIcon(icon2);
        line->setIconSize(QSize(42, 42));
        line->setAutoDefault(false);
        line->setFlat(true);

        horizontalLayout_6->addWidget(line);

        rubber = new QPushButton(Mesh);
        rubber->setObjectName(QStringLiteral("rubber"));
        rubber->setAutoFillBackground(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/white/x48/ic_delete_sweep_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        rubber->setIcon(icon3);
        rubber->setIconSize(QSize(42, 42));
        rubber->setFlat(true);

        horizontalLayout_6->addWidget(rubber);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(Mesh);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        label_2->setPalette(palette3);
        label_2->setAutoFillBackground(false);

        verticalLayout_2->addWidget(label_2);

        listWidget = new QListWidget(Mesh);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        listWidget->setPalette(palette4);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        listWidget->setFont(font);
        listWidget->setAutoFillBackground(false);
        listWidget->setDefaultDropAction(Qt::IgnoreAction);
        listWidget->setMovement(QListView::Free);
        listWidget->setResizeMode(QListView::Adjust);

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(Mesh);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        label_4->setPalette(palette5);
        label_4->setAutoFillBackground(false);

        verticalLayout_4->addWidget(label_4);

        listWidget_3 = new QListWidget(Mesh);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        sizePolicy4.setHeightForWidth(listWidget_3->sizePolicy().hasHeightForWidth());
        listWidget_3->setSizePolicy(sizePolicy4);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        listWidget_3->setPalette(palette6);
        listWidget_3->setFont(font);
        listWidget_3->setAutoFillBackground(false);
        listWidget_3->setDefaultDropAction(Qt::IgnoreAction);
        listWidget_3->setMovement(QListView::Free);
        listWidget_3->setResizeMode(QListView::Adjust);

        verticalLayout_4->addWidget(listWidget_3);

        verticalLayout_4->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(Mesh);

        splitter->addWidget(layoutWidget);

        verticalLayout_7->addWidget(splitter);

        widget = new QWidget(Viewer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);
        widget->setMinimumSize(QSize(1500, 120));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush11(QColor(48, 48, 48, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        widget->setPalette(palette7);
        widget->setFocusPolicy(Qt::NoFocus);
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(48, 48, 48);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        back_2 = new QPushButton(widget);
        back_2->setObjectName(QStringLiteral("back_2"));
        sizePolicy5.setHeightForWidth(back_2->sizePolicy().hasHeightForWidth());
        back_2->setSizePolicy(sizePolicy5);
        back_2->setMinimumSize(QSize(50, 40));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        back_2->setPalette(palette8);
        back_2->setFocusPolicy(Qt::NoFocus);
        back_2->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/white/x48/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        back_2->setIcon(icon4);
        back_2->setIconSize(QSize(92, 92));
        back_2->setFlat(true);

        horizontalLayout->addWidget(back_2);

        load = new QPushButton(widget);
        load->setObjectName(QStringLiteral("load"));
        sizePolicy5.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy5);
        load->setMinimumSize(QSize(0, 0));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        load->setPalette(palette9);
        load->setAutoFillBackground(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/white/x48/ic_file_upload_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        load->setIcon(icon5);
        load->setIconSize(QSize(92, 92));
        load->setFlat(true);

        horizontalLayout->addWidget(load);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));
        sizePolicy5.setHeightForWidth(back->sizePolicy().hasHeightForWidth());
        back->setSizePolicy(sizePolicy5);
        back->setMinimumSize(QSize(50, 40));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        back->setPalette(palette10);
        back->setFocusPolicy(Qt::NoFocus);
        back->setAutoFillBackground(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/white/x48/photo@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/images/black/x48/photo@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        back->setIcon(icon6);
        back->setIconSize(QSize(92, 92));
        back->setFlat(true);

        horizontalLayout->addWidget(back);

        save = new QPushButton(widget);
        save->setObjectName(QStringLiteral("save"));
        sizePolicy5.setHeightForWidth(save->sizePolicy().hasHeightForWidth());
        save->setSizePolicy(sizePolicy5);
        save->setMinimumSize(QSize(50, 40));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        save->setPalette(palette11);
        save->setFocusPolicy(Qt::NoFocus);
        save->setAutoFillBackground(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/white/x48/doc@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QStringLiteral(":/images/black/x48/doc@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        save->setIcon(icon7);
        save->setIconSize(QSize(92, 92));
        save->setFlat(true);

        horizontalLayout->addWidget(save);

        fullScreen = new QPushButton(widget);
        fullScreen->setObjectName(QStringLiteral("fullScreen"));
        sizePolicy5.setHeightForWidth(fullScreen->sizePolicy().hasHeightForWidth());
        fullScreen->setSizePolicy(sizePolicy5);
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        fullScreen->setPalette(palette12);
        fullScreen->setAutoFillBackground(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/white/x48/ic_zoom_out_map_white_36dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        fullScreen->setIcon(icon8);
        fullScreen->setIconSize(QSize(92, 92));
        fullScreen->setAutoDefault(false);
        fullScreen->setFlat(true);

        horizontalLayout->addWidget(fullScreen);

        help = new QPushButton(widget);
        help->setObjectName(QStringLiteral("help"));
        sizePolicy5.setHeightForWidth(help->sizePolicy().hasHeightForWidth());
        help->setSizePolicy(sizePolicy5);
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        help->setPalette(palette13);
        help->setAutoFillBackground(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/white/x48/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon9);
        help->setIconSize(QSize(92, 92));
        help->setAutoDefault(false);
        help->setFlat(true);

        horizontalLayout->addWidget(help);


        verticalLayout_7->addWidget(widget);


        retranslateUi(Viewer);

        back->setDefault(false);
        fullScreen->setDefault(false);
        help->setDefault(false);


        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QWidget *Viewer)
    {
        Viewer->setWindowTitle(QApplication::translate("Viewer", "Laboratory", 0));
#ifndef QT_NO_WHATSTHIS
        Viewer->setWhatsThis(QApplication::translate("Viewer", "<html><head/><body><p align=\"justify\"><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox_2->setTitle(QApplication::translate("Viewer", "Cross Section", 0));
        x->setText(QApplication::translate("Viewer", "X", 0));
        y->setText(QApplication::translate("Viewer", "Y", 0));
        z->setText(QApplication::translate("Viewer", "Z", 0));
        pushButton->setText(QApplication::translate("Viewer", "SLICE", 0));
        Mesh->setTitle(QApplication::translate("Viewer", "Mesh", 0));
#ifndef QT_NO_TOOLTIP
        angle->setToolTip(QApplication::translate("Viewer", "Angles", 0));
#endif // QT_NO_TOOLTIP
        angle->setText(QString());
#ifndef QT_NO_TOOLTIP
        line->setToolTip(QApplication::translate("Viewer", "Distance between two points", 0));
#endif // QT_NO_TOOLTIP
        line->setText(QString());
#ifndef QT_NO_TOOLTIP
        rubber->setToolTip(QApplication::translate("Viewer", "Delete", 0));
#endif // QT_NO_TOOLTIP
        rubber->setText(QString());
        label_2->setText(QApplication::translate("Viewer", "<html><head/><body><p><span style=\" color:#ffffff;\">Distances</span></p></body></html>", 0));
#ifndef QT_NO_ACCESSIBILITY
        listWidget->setAccessibleName(QApplication::translate("Viewer", "Distances", 0));
#endif // QT_NO_ACCESSIBILITY
        label_4->setText(QApplication::translate("Viewer", "<html><head/><body><p><span style=\" color:#ffffff;\">Angles</span></p></body></html>", 0));
#ifndef QT_NO_ACCESSIBILITY
        listWidget_3->setAccessibleName(QApplication::translate("Viewer", "Distances", 0));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_TOOLTIP
        back_2->setToolTip(QApplication::translate("Viewer", "generate documents", 0));
#endif // QT_NO_TOOLTIP
        back_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        load->setToolTip(QApplication::translate("Viewer", "upload a ply", 0));
#endif // QT_NO_TOOLTIP
        load->setText(QString());
#ifndef QT_NO_TOOLTIP
        back->setToolTip(QApplication::translate("Viewer", "snapshot", 0));
#endif // QT_NO_TOOLTIP
        back->setText(QString());
#ifndef QT_NO_TOOLTIP
        save->setToolTip(QApplication::translate("Viewer", "generate documents", 0));
#endif // QT_NO_TOOLTIP
        save->setText(QString());
#ifndef QT_NO_TOOLTIP
        fullScreen->setToolTip(QApplication::translate("Viewer", "fullscreen", 0));
#endif // QT_NO_TOOLTIP
        fullScreen->setText(QString());
#ifndef QT_NO_TOOLTIP
        help->setToolTip(QApplication::translate("Viewer", "fullscreen", 0));
#endif // QT_NO_TOOLTIP
        help->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
