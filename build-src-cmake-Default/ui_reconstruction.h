/********************************************************************************
** Form generated from reading UI file 'reconstruction.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONSTRUCTION_H
#define UI_RECONSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Reconstruction
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *camara;
    QPushButton *actor;
    QVTKWidget *qvtkWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_2;
    QPushButton *load;
    QPushButton *back;
    QPushButton *save;
    QPushButton *fullScreen;
    QPushButton *help;

    void setupUi(QWidget *Reconstruction)
    {
        if (Reconstruction->objectName().isEmpty())
            Reconstruction->setObjectName(QStringLiteral("Reconstruction"));
        Reconstruction->resize(1500, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Reconstruction->sizePolicy().hasHeightForWidth());
        Reconstruction->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(48, 48, 48, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush1(QColor(255, 255, 255, 127));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Reconstruction->setPalette(palette);
        Reconstruction->setStyleSheet(QStringLiteral("background-color: rgb(48, 48, 48);"));
        verticalLayout = new QVBoxLayout(Reconstruction);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        camara = new QPushButton(Reconstruction);
        camara->setObjectName(QStringLiteral("camara"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(camara->sizePolicy().hasHeightForWidth());
        camara->setSizePolicy(sizePolicy1);
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        camara->setPalette(palette1);
        camara->setAutoFillBackground(false);
        camara->setStyleSheet(QLatin1String("background-color: rgb(48, 48, 48);\n"
"font: 75 14pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/white/photo@3x.png"), QSize(), QIcon::Normal, QIcon::Off);
        camara->setIcon(icon);
        camara->setIconSize(QSize(92, 92));

        horizontalLayout_5->addWidget(camara);

        actor = new QPushButton(Reconstruction);
        actor->setObjectName(QStringLiteral("actor"));
        sizePolicy1.setHeightForWidth(actor->sizePolicy().hasHeightForWidth());
        actor->setSizePolicy(sizePolicy1);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        actor->setPalette(palette2);
        actor->setAutoFillBackground(false);
        actor->setStyleSheet(QLatin1String("background-color: rgb(48, 48, 48);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 14pt \"Ubuntu\";"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/white/person@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        actor->setIcon(icon1);
        actor->setIconSize(QSize(92, 92));

        horizontalLayout_5->addWidget(actor);


        verticalLayout->addLayout(horizontalLayout_5);

        qvtkWidget = new QVTKWidget(Reconstruction);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy2);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        qvtkWidget->setPalette(palette3);
        qvtkWidget->setAutoFillBackground(false);
        qvtkWidget->setStyleSheet(QStringLiteral("background-color: rgb(48, 48, 48);"));

        verticalLayout->addWidget(qvtkWidget);

        widget = new QWidget(Reconstruction);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(1028, 120));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush5(QColor(0, 255, 191, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush5);
        QBrush brush6(QColor(0, 212, 159, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        QBrush brush7(QColor(0, 85, 63, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush7);
        QBrush brush8(QColor(0, 113, 84, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        QBrush brush9(QColor(127, 212, 191, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        QBrush brush10(QColor(0, 170, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        widget->setPalette(palette4);
        widget->setFocusPolicy(Qt::NoFocus);
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(48, 48, 48);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        back_2 = new QPushButton(widget);
        back_2->setObjectName(QStringLiteral("back_2"));
        sizePolicy1.setHeightForWidth(back_2->sizePolicy().hasHeightForWidth());
        back_2->setSizePolicy(sizePolicy1);
        back_2->setMinimumSize(QSize(0, 0));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        back_2->setPalette(palette5);
        back_2->setFocusPolicy(Qt::NoFocus);
        back_2->setAutoFillBackground(false);
        back_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 1);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/white/x48/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        back_2->setIcon(icon2);
        back_2->setIconSize(QSize(92, 92));
        back_2->setFlat(true);

        horizontalLayout->addWidget(back_2);

        load = new QPushButton(widget);
        load->setObjectName(QStringLiteral("load"));
        sizePolicy1.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy1);
        load->setMinimumSize(QSize(0, 0));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        load->setPalette(palette6);
        load->setAutoFillBackground(false);
        load->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 1);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/white/x48/ic_file_upload_white_48dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        load->setIcon(icon3);
        load->setIconSize(QSize(92, 92));
        load->setFlat(true);

        horizontalLayout->addWidget(load);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));
        sizePolicy1.setHeightForWidth(back->sizePolicy().hasHeightForWidth());
        back->setSizePolicy(sizePolicy1);
        back->setMinimumSize(QSize(50, 40));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        back->setPalette(palette7);
        back->setFocusPolicy(Qt::NoFocus);
        back->setAutoFillBackground(false);
        back->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 1);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/white/x48/photo@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/images/black/x48/photo@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        back->setIcon(icon4);
        back->setIconSize(QSize(92, 92));
        back->setFlat(true);

        horizontalLayout->addWidget(back);

        save = new QPushButton(widget);
        save->setObjectName(QStringLiteral("save"));
        sizePolicy1.setHeightForWidth(save->sizePolicy().hasHeightForWidth());
        save->setSizePolicy(sizePolicy1);
        save->setMinimumSize(QSize(50, 40));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        save->setPalette(palette8);
        save->setFocusPolicy(Qt::NoFocus);
        save->setAutoFillBackground(false);
        save->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 1);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/white/x48/doc@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/images/black/x48/doc@4x.png"), QSize(), QIcon::Selected, QIcon::Off);
        save->setIcon(icon5);
        save->setIconSize(QSize(92, 92));
        save->setFlat(true);

        horizontalLayout->addWidget(save);

        fullScreen = new QPushButton(widget);
        fullScreen->setObjectName(QStringLiteral("fullScreen"));
        sizePolicy1.setHeightForWidth(fullScreen->sizePolicy().hasHeightForWidth());
        fullScreen->setSizePolicy(sizePolicy1);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        fullScreen->setPalette(palette9);
        fullScreen->setAutoFillBackground(false);
        fullScreen->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 1);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/white/x48/ic_zoom_out_map_white_36dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        fullScreen->setIcon(icon6);
        fullScreen->setIconSize(QSize(92, 92));
        fullScreen->setAutoDefault(false);
        fullScreen->setFlat(true);

        horizontalLayout->addWidget(fullScreen);

        help = new QPushButton(widget);
        help->setObjectName(QStringLiteral("help"));
        sizePolicy1.setHeightForWidth(help->sizePolicy().hasHeightForWidth());
        help->setSizePolicy(sizePolicy1);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        help->setPalette(palette10);
        help->setAutoFillBackground(false);
        help->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 1);"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/white/x48/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon7);
        help->setIconSize(QSize(92, 92));
        help->setAutoDefault(false);
        help->setFlat(true);

        horizontalLayout->addWidget(help);


        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(1, 1);

        retranslateUi(Reconstruction);

        back->setDefault(false);
        fullScreen->setDefault(false);
        help->setDefault(false);


        QMetaObject::connectSlotsByName(Reconstruction);
    } // setupUi

    void retranslateUi(QWidget *Reconstruction)
    {
        Reconstruction->setWindowTitle(QApplication::translate("Reconstruction", "Form", 0));
        camara->setText(QApplication::translate("Reconstruction", "Move the scene", 0));
        actor->setText(QApplication::translate("Reconstruction", "Move the objects", 0));
#ifndef QT_NO_TOOLTIP
        back_2->setToolTip(QApplication::translate("Reconstruction", "generate documents", 0));
#endif // QT_NO_TOOLTIP
        back_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        load->setToolTip(QApplication::translate("Reconstruction", "upload a ply", 0));
#endif // QT_NO_TOOLTIP
        load->setText(QString());
#ifndef QT_NO_TOOLTIP
        back->setToolTip(QApplication::translate("Reconstruction", "snapshot", 0));
#endif // QT_NO_TOOLTIP
        back->setText(QString());
#ifndef QT_NO_TOOLTIP
        save->setToolTip(QApplication::translate("Reconstruction", "generate documents", 0));
#endif // QT_NO_TOOLTIP
        save->setText(QString());
#ifndef QT_NO_TOOLTIP
        fullScreen->setToolTip(QApplication::translate("Reconstruction", "fullscreen", 0));
#endif // QT_NO_TOOLTIP
        fullScreen->setText(QString());
#ifndef QT_NO_TOOLTIP
        help->setToolTip(QApplication::translate("Reconstruction", "fullscreen", 0));
#endif // QT_NO_TOOLTIP
        help->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Reconstruction: public Ui_Reconstruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_H
