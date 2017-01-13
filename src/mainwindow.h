#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "viewer.h"
#include "videowidget.h"
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
public slots:
   void openLab();
void openVideo();
};

#endif // MAINWINDOW_H
