cmake_minimum_required (VERSION 2.6 FATAL_ERROR)

project      (Avionicav2)
find_package (Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)
find_package (VTK REQUIRED)
find_package (PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")
#include(${VTK_USE_FILE})

set (CMAKE_CXX_STANDARD 11)

set  (project_SOURCES main.cpp videowidget.cpp mainwindow.cpp viewer.cpp interactor_style_actor.cpp)
set  (project_HEADERS videowidget.h mainwindow.h viewer.h interactor_style_actor.h)
set  (project_FORMS  videowidget.ui mainwindow.ui viewer.ui)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


SET(QT_USE_QTMULTIMEDIA TRUE)
SET(QT_USE_QTMULTIMEDIAWIDGETS TRUE)

ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (Avionicav2 ${project_SOURCES}
                                ${project_FORMS_HEADERS}
                                ${project_HEADERS_MOC} qrc.qrc)

                            TARGET_LINK_LIBRARIES (Avionicav2 ${QT_LIBRARIES} ${PCL_LIBRARIES})
QT5_USE_MODULES (Avionicav2 Multimedia MultimediaWidgets)
