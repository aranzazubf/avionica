#include "mainwindow.h"
#include "../build/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("://images/pix/pix3.jpg");
ui->label_pic->setPixmap(pix);
viewer = new Viewer();
video = new VideoWidget();
rec= new Reconstruction();


connect(ui->lab, SIGNAL(clicked()), this, SLOT(openLab()));


connect(ui->video, SIGNAL(clicked()), this, SLOT(openVideo()));

connect(ui->photo, SIGNAL(clicked()), this, SLOT(openRec()));
}
void MainWindow::openLab()
{

   // Be sure to destroy you window somewhere
   viewer->show();
   viewer->setPartner(this);
   this->hide();
   // ...
}
void MainWindow::openVideo()
{

   // Be sure to destroy you window somewhere
   video->show();
   video->setPartner(this);
   this->hide();
   // ...
}
void MainWindow::openRec()
{

   // Be sure to destroy you window somewhere
   rec->show();
   rec->setPartner(this);
   this->hide();
   // ...
}
MainWindow::~MainWindow()
{
    delete ui;
}
