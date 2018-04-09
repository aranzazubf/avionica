#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T08:40:14
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Avionicav2
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    viewer.cpp \
    interactor_style_actor.cpp \
    videowidget.cpp \
    reconstruction.cpp \
    qdatabase.cpp \
    helpviewer.cpp \
    helperviewer2.cpp

HEADERS  += mainwindow.h \
    viewer.h \
    interactor_style_actor.h \
    videowidget.h \
    reconstruction.h \
    qdatabase.h \
    helpviewer.h \
    helperviewer2.h \
    pcl_includes.h \
    vtk_includes.h \
    common_includes.h

FORMS    += mainwindow.ui \
    viewer.ui \
    videowidget.ui \
    reconstruction.ui \
    qdatabase.ui \
    helpviewer.ui \
    helperviewer2.ui

DISTFILES += \
    CMakeLists.txt

RESOURCES += \
    qrc.qrc
