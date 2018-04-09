#include "mainwindow.h"
#include "../build/ui_mainwindow.h"
/*Esta clase se corresponde con la pantalla principal de la aplicación
 *en ella podemos ver una imagen con el titulo de la aplicacion y cuatro
 *botones que dan acceso a las 4 diferentes pantallas de la aplicacion
 * */

/*Constructor:
 *Inicialización de los objetos Viewer VideoWidget Reconstruccion y QDataBase
 *Conexion de los 4 botones del formulario con los métodos a los que se llama al ser pulsados
 *Al pulsar cada boton, los 4 hacen lo mismo, se abre el formulario de la clase correspondiente,se indica que esa clase fue llamada desde esta "MainWindow" para poder
 *volver después,  y se oculta la pantalla principal.
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewer = new Viewer();
    video = new VideoWidget();
    rec= new Reconstruction();
    data= new QDataBase();

    QPixmap pix("://images/pix/pix3.jpg");
    ui->label_pic->setPixmap(pix);

    connect(ui->video, SIGNAL(clicked()), this, SLOT(openVideo()));
    connect(ui->photo, SIGNAL(clicked()), this, SLOT(openRec()));
    connect(ui->lab, SIGNAL(clicked()), this, SLOT(openLab()));
    connect(ui->data, SIGNAL(clicked()), this, SLOT(openData()));
}

void MainWindow::openVideo()
{
   video->show();
   video->setPartner(this);
   this->hide();
}
void MainWindow::openRec()
{
   rec->show();
   rec->setPartner(this);

   this->hide();
}
void MainWindow::openLab()
{


   viewer->show();
   viewer->setPartner(this);
   this->hide();

}
void MainWindow::openData()
{
   data->show();
   data->setPartner(this);
   this->hide();
}
MainWindow::~MainWindow()
{
    delete ui;
}
