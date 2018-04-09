#include "reconstruction.h"
#include "../build/ui_reconstruction.h"

/* Esta clase es la encargada de permitir la visualizacion de varios
 * archivos ply como nubes de puntos a la vez y de el manejo de estos
 * tanto de manera independiente en modo objeto como de forma conjunta
 * manejando la escena entera. Así se pueden simular situaciones entre
 * los diferentes objetos*/


/*
 * Inicializamos el constructor indicando el color del que se va a pintar
 * la nube de puntos y la direccion que va a seguir el color, además de
 * inicializar el objeto partner para poder volver a la pantalla principal
 *
 * Inicializa la nube de puntos, el visualizador pcl y el objeto HelpViewer
 * para poder emitir luego el dialogo cuando se necesite consultar la confi-
 * guracion
 *
 * Rellenamos la nube inicialmente con puntos aleatorios que se coloreraran
 * como el arcoiris en la direccion y, lo ponemos asi por defecto se puede
 * cambiar y la mostramos.
 *
 * Hacemos la llamada para conectar los elementos del formulario con sus slots
 *
 * inicializamos el modo de interaccion con el visualizador.
 * */
Reconstruction::Reconstruction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reconstruction),
    mPartner(0)
{
    ui->setupUi(this);

    cloud_.reset(new PointCloudT);
    viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    v=new HelpViewer();

    fillCloud();
    colorCloudDistances ();
    showCloud();
    //Necesitamos indicar que el qvtkwidget del formulario sera relleno con
    //la venta del visualizador pcl
    ui->qvtkWidget->SetRenderWindow (viewer_->getRenderWindow ());
    connections();
    interactorInit();

}

/*
 *Funcion que indica desde que clase se invoco esta
*/
void Reconstruction::setPartner(QWidget *partner){

    mPartner=partner;
}

/*
 *Inicialmente se sube una nube de puntos generados aleatoriamente
 * con la funcion rand()
*/
void Reconstruction::fillCloud(){

    cloud_->resize (500);

      // Fill the cloud with random points
      for (size_t i = 0; i < cloud_->points.size (); ++i)
      {
        cloud_->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud_->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud_->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
      }

}

/*
 * Se rellena la nube de puntos del color del arcoiris a lo largo del eje y
 *  */
void Reconstruction::colorCloudDistances ()
{
  double min, max;
   min = cloud_->points[0].y;
   max = cloud_->points[0].y;

  for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
      if (min > cloud_it->y)min = cloud_it->y;
      if (max < cloud_it->y)max = cloud_it->y;
  }
  double lut_scale = 255.0 / (max - min);
  if (min == max)  lut_scale = 1.0;
  for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
    int value;
        value = boost::math::iround ( (cloud_it->y - min) * lut_scale);
        cloud_it->r = value;
        cloud_it->g = 255 - value;
        cloud_it->b = value;
  }
}

/* Añade la nube de puntos inicial al visor y le
 * añade un sistema de coordenadas
 */
void Reconstruction::showCloud(){
    viewer_->addText("3D", 10, 10, "v1 text", v1);
    viewer_->addPointCloud<PointT> (cloud_,  "cloud1", v1);
    viewer_->addCoordinateSystem (1.0,"axis1", v1);
    nclouds++;
}

/*Conecta los elementos del formulario con sus respectivos slots.*/
void Reconstruction::connections(){
    connect(ui->camara, SIGNAL(clicked()), this, SLOT(loadInteractorCamera()));
    connect(ui->actor, SIGNAL(clicked()), this, SLOT(loadInteractorActor()));
    connect(ui->back_2, SIGNAL(clicked()), this, SLOT(showHome()));
    connect(ui->load, SIGNAL(clicked ()), this, SLOT(loadFileButtonPressed ()));
    connect(ui->save, SIGNAL(clicked ()), this, SLOT(saveFileButtonPressed ()));
    connect(ui->back, SIGNAL(clicked ()), this, SLOT(shootScreen()));
    connect(ui->fullScreen, SIGNAL(clicked()), this, SLOT(showFullScreen()));
    connect(ui->help, SIGNAL(clicked()),this, SLOT(showHelp()));
}

/* Inicializa el modo de interaccion como modo camara (es el modo por defecto
 * por eso no le pasa el parametro interactor_style)
 * */
void Reconstruction::interactorInit(){
    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
}

/* Invoca al dialogo que muestra los controles disponibles para cada tipo
 * de modo de interaccion: actor o camara
*/
void Reconstruction::showHelp(){
 v->show();
}

/* Para activar el modo actor, se usa un puntero a la clase interactor_style_actor
 * que extiende de la clase vtkInteractorStyleTrackballActor en la cual estan
 * definidos los controles.
 * */
void Reconstruction::loadInteractorActor() {

   vtkSmartPointer<interactor_style_actor> style = vtkSmartPointer<interactor_style_actor>::New();
   viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow (), style);
}

/*
 * Activar el modo camara al hacer click en el boton
 * */
void Reconstruction::loadInteractorCamera() {
    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());

}
/*
 *Vuelta a la pantalla principal
 * */
void Reconstruction::showHome(){

    mPartner->show();
    this->hide();
}

/*
 * Carga archivos PCD o PLY pero ojo porque lo hace desde el directorio /home/
 * si no se esta en un sistema UNIX hay que adaptarlo
 *
 * Una vez que carga el archivo lo pasa por varios filtros para mejorar
 * la visualización y la interacción con la nube de puntos que se genera.
 *
 * */
void Reconstruction::loadFileButtonPressed (){

    int return_status;
    QString filename;

    cloud_tmp.reset(new PointCloudT);
    cloud_aux.reset(new PointCloudT);

    filename= QFileDialog::getOpenFileName (this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));
    PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());
    if (filename.isEmpty ()) return;
    if (filename.endsWith (".pcd", Qt::CaseInsensitive))
      return_status = pcl::io::loadPCDFile (filename.toStdString (), *cloud_tmp);
    else
      return_status = pcl::io::loadPLYFile (filename.toStdString (), *cloud_tmp);

    if (return_status != 0)
    {
      PCL_ERROR("Error reading point cloud %s\n", filename.toStdString ().c_str ());
      return;
    }
    removeNan();
    filterVoxel();
    updateCloud();


  }

/*Filtro para eliminar puntos nulos
 *
 * */
void Reconstruction::removeNan(){
    if (!cloud_tmp->is_dense)

    {
      PCL_WARN("Cloud is not dense! Non finite points will be removed\n");
      std::vector<int> vec;
      pcl::removeNaNFromPointCloud (*cloud_tmp, *cloud_tmp, vec);
    }


}

/* Este filtro diezma la nube de puntos para
 * un mejor manejo de la misma
 * */
void Reconstruction::filterVoxel(){
    pcl::copyPointCloud (*cloud_tmp,*cloud_aux);
     pcl::VoxelGrid<PointT> sor;
      sor.setInputCloud (cloud_tmp);
      sor.setLeafSize (0.5f, 0.5f, 0.5f);
      sor.filter (*cloud_tmp);
}

/*Una vez realizado los cambios en la nube de puntos generada a partir del archivo ply o pcd
 * se colorea esta nueva nube y se añade o se actualiza
 * */
void Reconstruction::updateCloud(){

    pcl::copyPointCloud (*cloud_tmp, *cloud_);

   colorCloudDistances ();
   viewer_->removeAllShapes();
   if(nclouds==1){
   viewer_->updatePointCloud (cloud_, "cloud1");
   nclouds++;
   }
   if(nclouds>1){
   nclouds++;
   char idcloud[512];
   sprintf (idcloud, "cloud#%03d", nclouds);

   viewer_->addPointCloud(cloud_,idcloud,v1);
   }
    pcl::copyPointCloud (*cloud_aux, *cloud_);
   viewer_->resetCamera ();
   ui->qvtkWidget->update ();

}



  /*
   * Guarda la nube de puntos que este disponible en el visor en ese momento
   * */


  void Reconstruction::saveFileButtonPressed (){
    // You might want to change "/home/" if you're not on an *nix platform
    QString filename = QFileDialog::getSaveFileName(this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));

    PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());

    if (filename.isEmpty ())
      return;

    int return_status;
    if (filename.endsWith (".pcd", Qt::CaseInsensitive)) return_status = pcl::io::savePCDFileBinary (filename.toStdString (), *cloud_);
    else if (filename.endsWith (".ply", Qt::CaseInsensitive))return_status = pcl::io::savePLYFileBinary (filename.toStdString (), *cloud_);
    else
    {
      filename.append(".ply");
      return_status = pcl::io::savePLYFileBinary (filename.toStdString (), *cloud_);
    }
    if (return_status != 0)
    {
      PCL_ERROR("Error writing point cloud %s\n", filename.toStdString ().c_str ());
      return;
    }
  }

 /*
  * Graba la pantalla actual
  * */
  void Reconstruction::shootScreen(){
        originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
        saveScreenshot();
  }
  /* Guarda una captura de pantalla de la aplicacion
   *
   * */
    void Reconstruction::saveScreenshot(){

    QString format = "png";
    QString initialPath = QDir::currentPath() + tr("/untitled.") + format;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                               initialPath,
                               tr("%1 Files (*.%2);;All Files (*)")
                               .arg(QString(format.toUpper()))
                               .arg(QString(format)));
    if (!fileName.isEmpty())originalPixmap.save(fileName, format.toLatin1());
   }

  /* Pantalla completa
   * */
  void Reconstruction::showFullScreen(){
      if(this->isFullScreen())this->setWindowState(Qt::WindowMaximized);
      else(this->setWindowState(Qt::WindowFullScreen));
  }

  Reconstruction::~Reconstruction() {
      delete ui;
  }
