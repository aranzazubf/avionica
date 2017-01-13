#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "viewer.h"
#include "videowidget.h"
#include "reconstruction.h"
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
    Viewer *viewer;
    Ui::MainWindow *ui;
    VideoWidget * video;
    Reconstruction* rec;
public slots:
   void openLab();
void openVideo();
void openRec();
};

#endif // MAINWINDOW_H
