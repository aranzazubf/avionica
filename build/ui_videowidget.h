/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *home;
    QPushButton *icon;
    QTextEdit *url;
    QPushButton *play;
    QPushButton *mute;
    QSlider *volume;
    QPushButton *screenshot;
    QPushButton *fullscreen;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QStringLiteral("VideoWidget"));
        VideoWidget->resize(1514, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoWidget->sizePolicy().hasHeightForWidth());
        VideoWidget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(67, 67, 67, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 127));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        VideoWidget->setPalette(palette);
        VideoWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(VideoWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 1000, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        home = new QPushButton(VideoWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/white/home@4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        home->setIcon(icon1);
        home->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(home);

        icon = new QPushButton(VideoWidget);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setEnabled(true);
        icon->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/pix/dron.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        icon->setIcon(icon2);
        icon->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(icon);

        url = new QTextEdit(VideoWidget);
        url->setObjectName(QStringLiteral("url"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(url->sizePolicy().hasHeightForWidth());
        url->setSizePolicy(sizePolicy1);
        url->setMaximumSize(QSize(16777215, 38));
        QPalette palette1;
        QBrush brush3(QColor(255, 255, 255, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(231, 231, 231, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        QBrush brush7(QColor(35, 35, 35, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        QBrush brush9(QColor(0, 0, 0, 255));
        brush9.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        url->setPalette(palette1);
        url->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        url->setTabStopWidth(0);

        horizontalLayout->addWidget(url);

        play = new QPushButton(VideoWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/white/x18/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon3);
        play->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(play);

        mute = new QPushButton(VideoWidget);
        mute->setObjectName(QStringLiteral("mute"));
        mute->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/white/mute.png"), QSize(), QIcon::Normal, QIcon::Off);
        mute->setIcon(icon4);
        mute->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(mute);

        volume = new QSlider(VideoWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volume);

        screenshot = new QPushButton(VideoWidget);
        screenshot->setObjectName(QStringLiteral("screenshot"));
        screenshot->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/white/photo@3x.png"), QSize(), QIcon::Normal, QIcon::Off);
        screenshot->setIcon(icon5);
        screenshot->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(screenshot);

        fullscreen = new QPushButton(VideoWidget);
        fullscreen->setObjectName(QStringLiteral("fullscreen"));
        fullscreen->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/white/ic_zoom_out_map_white_36dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        fullscreen->setIcon(icon6);
        fullscreen->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(fullscreen);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QApplication::translate("VideoWidget", "VideoWidget", 0));
        home->setText(QString());
        url->setHtml(QApplication::translate("VideoWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:200; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">Introduce the url and play</span></p></body></html>", 0));
        url->setPlaceholderText(QString());
        play->setText(QString());
        mute->setText(QString());
        screenshot->setText(QString());
        fullscreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
