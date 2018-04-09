#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "common_includes.h"
#include "viewer.h"
#include "videowidget.h"
#include "reconstruction.h"
#include "qdatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoWidget * video;
    Reconstruction* rec;
    Viewer *viewer;
    QDataBase* data;
public slots:
   void openLab();
   void openVideo();
   void openRec();
   void openData();

};

#endif // MAINWINDOW_H
