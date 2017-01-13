#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T08:40:14
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Avionicav2
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    viewer.cpp \
    interactor_style_actor.cpp \
    videowidget.cpp

HEADERS  += mainwindow.h \
    viewer.h \
    interactor_style_actor.h \
    ui_viewer.h \
    videowidget.h

FORMS    += mainwindow.ui \
    viewer.ui \
    videowidget.ui

DISTFILES += \
    CMakeLists.txt

RESOURCES += \
    qrc.qrc
