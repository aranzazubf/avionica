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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QVTKWidget *qvtkWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *load;
    QPushButton *back;
    QPushButton *save;
    QPushButton *fullScreen;
    QWidget *widget_3;
    QGroupBox *groupBox;
    QPushButton *free;
    QPushButton *line;
    QPushButton *circle;
    QPushButton *angle;
    QPushButton *rubber;
    QSlider *verticalSlider;
    QLabel *label;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *widget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QStringLiteral("Viewer"));
        Viewer->setWindowModality(Qt::ApplicationModal);
        Viewer->resize(1440, 900);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
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
        qvtkWidget = new QVTKWidget(Viewer);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(0, 0, 1100, 780));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy1);
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
        widget = new QWidget(Viewer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(0, 780, 1440, 120));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(1028, 120));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush11(QColor(255, 255, 255, 0));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        widget->setPalette(palette2);
        widget->setFocusPolicy(Qt::NoFocus);
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        load = new QPushButton(widget);
        load->setObjectName(QStringLiteral("load"));
        sizePolicy2.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy2);
        load->setMinimumSize(QSize(0, 0));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        load->setPalette(palette3);
        load->setAutoFillBackground(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/white/x48/ic_file_upload_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        load->setIcon(icon1);
        load->setIconSize(QSize(92, 92));
        load->setFlat(true);

        horizontalLayout->addWidget(load, 0, Qt::AlignLeft);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));
        sizePolicy2.setHeightForWidth(back->sizePolicy().hasHeightForWidth());
        back->setSizePolicy(sizePolicy2);
        back->setMinimumSize(QSize(50, 40));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        back->setPalette(palette4);
        back->setFocusPolicy(Qt::NoFocus);
        back->setAutoFillBackground(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/white/x48/photo@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/images/black/x48/photo@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        back->setIcon(icon2);
        back->setIconSize(QSize(92, 92));
        back->setFlat(true);

        horizontalLayout->addWidget(back, 0, Qt::AlignHCenter);

        save = new QPushButton(widget);
        save->setObjectName(QStringLiteral("save"));
        sizePolicy2.setHeightForWidth(save->sizePolicy().hasHeightForWidth());
        save->setSizePolicy(sizePolicy2);
        save->setMinimumSize(QSize(50, 40));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        save->setPalette(palette5);
        save->setFocusPolicy(Qt::NoFocus);
        save->setAutoFillBackground(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/white/x48/doc@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/images/black/x48/doc@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        save->setIcon(icon3);
        save->setIconSize(QSize(92, 92));
        save->setFlat(true);

        horizontalLayout->addWidget(save, 0, Qt::AlignHCenter);

        fullScreen = new QPushButton(widget);
        fullScreen->setObjectName(QStringLiteral("fullScreen"));
        sizePolicy2.setHeightForWidth(fullScreen->sizePolicy().hasHeightForWidth());
        fullScreen->setSizePolicy(sizePolicy2);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        fullScreen->setPalette(palette6);
        fullScreen->setAutoFillBackground(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/white/x48/ic_zoom_out_map_white_36dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        fullScreen->setIcon(icon4);
        fullScreen->setIconSize(QSize(92, 92));
        fullScreen->setAutoDefault(false);
        fullScreen->setFlat(true);

        horizontalLayout->addWidget(fullScreen, 0, Qt::AlignRight);

        widget_3 = new QWidget(Viewer);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(1119, 0, 321, 780));
        groupBox = new QGroupBox(widget_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 23, 301, 81));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        groupBox->setPalette(palette7);
        QFont font;
        font.setPointSize(1);
        font.setKerning(false);
        font.setStyleStrategy(QFont::NoAntialias);
        groupBox->setFont(font);
        groupBox->setAcceptDrops(false);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        groupBox->setFlat(true);
        free = new QPushButton(groupBox);
        free->setObjectName(QStringLiteral("free"));
        free->setGeometry(QRect(12, 44, 54, 34));
        free->setAutoFillBackground(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/white/x48/free@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/images/black/x48/free@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon5.addFile(QStringLiteral(":/images/black/x48/free@4x.png"), QSize(), QIcon::Selected, QIcon::On);
        free->setIcon(icon5);
        free->setIconSize(QSize(42, 42));
        free->setFlat(true);
        line = new QPushButton(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(72, 44, 54, 34));
        line->setAutoFillBackground(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/white/x48/line@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/images/black/x48/line@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon6.addFile(QStringLiteral(":/images/black/x48/line@4x.png"), QSize(), QIcon::Selected, QIcon::On);
        line->setIcon(icon6);
        line->setIconSize(QSize(42, 42));
        line->setAutoDefault(false);
        line->setFlat(true);
        circle = new QPushButton(groupBox);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(132, 44, 54, 34));
        circle->setAutoFillBackground(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/white/x48/circ@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QStringLiteral(":/images/black/x48/circ@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        circle->setIcon(icon7);
        circle->setIconSize(QSize(42, 42));
        circle->setFlat(true);
        angle = new QPushButton(groupBox);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setGeometry(QRect(192, 44, 54, 34));
        angle->setAutoFillBackground(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/white/x48/ang@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QStringLiteral(":/images/black/x48/ang@3x.png"), QSize(), QIcon::Selected, QIcon::Off);
        angle->setIcon(icon8);
        angle->setIconSize(QSize(42, 42));
        angle->setFlat(true);
        rubber = new QPushButton(groupBox);
        rubber->setObjectName(QStringLiteral("rubber"));
        rubber->setGeometry(QRect(252, 44, 54, 34));
        rubber->setAutoFillBackground(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/white/x48/ic_delete_sweep_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        rubber->setIcon(icon9);
        rubber->setIconSize(QSize(42, 42));
        rubber->setFlat(true);
        line->raise();
        circle->raise();
        angle->raise();
        rubber->raise();
        free->raise();
        verticalSlider = new QSlider(widget_3);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(280, 110, 16, 160));
        QFont font1;
        font1.setPointSize(18);
        verticalSlider->setFont(font1);
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(50);
        verticalSlider->setSingleStep(1);
        verticalSlider->setValue(50);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(true);
        verticalSlider->setTickInterval(0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 270, 118, 29));
        QPalette palette8;
        QBrush brush12(QColor(85, 170, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        label->setPalette(palette8);
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        label->setFont(font2);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(widget_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 350, 131, 271));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        listWidget->setPalette(palette9);
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        listWidget->setFont(font3);
        listWidget->setAutoFillBackground(false);
        listWidget->setDefaultDropAction(Qt::IgnoreAction);
        listWidget->setMovement(QListView::Free);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget_2 = new QListWidget(widget_3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(170, 350, 131, 271));
        sizePolicy3.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy3);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        listWidget_2->setPalette(palette10);
        listWidget_2->setFont(font3);
        listWidget_2->setAutoFillBackground(false);
        listWidget_2->setDefaultDropAction(Qt::IgnoreAction);
        listWidget_2->setMovement(QListView::Free);
        listWidget_2->setResizeMode(QListView::Adjust);
        radioButton = new QRadioButton(widget_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 140, 117, 22));
        radioButton_2 = new QRadioButton(widget_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 180, 117, 22));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush12);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        radioButton_2->setPalette(palette11);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(140, 150, 120, 41));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 41, 27));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 10, 41, 27));

        retranslateUi(Viewer);

        back->setDefault(false);
        fullScreen->setDefault(false);


        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QWidget *Viewer)
    {
        Viewer->setWindowTitle(QApplication::translate("Viewer", "Laboratory", 0));
#ifndef QT_NO_WHATSTHIS
        Viewer->setWhatsThis(QApplication::translate("Viewer", "<html><head/><body><p align=\"justify\"><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
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
        free->setToolTip(QApplication::translate("Viewer", "Area", 0));
#endif // QT_NO_TOOLTIP
        free->setText(QString());
#ifndef QT_NO_TOOLTIP
        line->setToolTip(QApplication::translate("Viewer", "Distance between two points", 0));
#endif // QT_NO_TOOLTIP
        line->setText(QString());
#ifndef QT_NO_TOOLTIP
        circle->setToolTip(QApplication::translate("Viewer", "Circle", 0));
#endif // QT_NO_TOOLTIP
        circle->setText(QString());
#ifndef QT_NO_TOOLTIP
        angle->setToolTip(QApplication::translate("Viewer", "Angles", 0));
#endif // QT_NO_TOOLTIP
        angle->setText(QString());
#ifndef QT_NO_TOOLTIP
        rubber->setToolTip(QApplication::translate("Viewer", "Delete", 0));
#endif // QT_NO_TOOLTIP
        rubber->setText(QString());
        label->setText(QApplication::translate("Viewer", "Points", 0));
#ifndef QT_NO_ACCESSIBILITY
        listWidget->setAccessibleName(QApplication::translate("Viewer", "Distances", 0));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        listWidget_2->setAccessibleName(QApplication::translate("Viewer", "Distances", 0));
#endif // QT_NO_ACCESSIBILITY
        radioButton->setText(QApplication::translate("Viewer", "Camara", 0));
        radioButton_2->setText(QApplication::translate("Viewer", "Objetos", 0));
        pushButton->setText(QApplication::translate("Viewer", "2D", 0));
        pushButton_2->setText(QApplication::translate("Viewer", "3D", 0));
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
