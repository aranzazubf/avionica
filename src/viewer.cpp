#include "viewer.h"
#include "../build/ui_viewer.h"
#include <iostream>

Viewer::Viewer(QWidget *parent) : QWidget(parent),ui(new Ui::Viewer),
  line_id (1),
  mPartner(0)
{
    ui->setupUi(this);

    h=new HelperViewer2();
    viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    cloud_.reset(new PointCloudT);
    cloud_2D.reset(new PointCloudT);
    plane_.reset(new Planar);
    plane_1.reset(new pcl::ModelCoefficients);

    fillCloud();
    colorCloudDistances ();
    show2ViewPort();
    registerEvents();
    connections();

    ui->qvtkWidget->SetRenderWindow (viewer_->getRenderWindow ());
    interactorInit();

}

void Viewer::setPartner(QWidget *partner){

    mPartner=partner;
}
/* En este caso solo tenemos un modo de interaccion, le modo camara
 * se podria modificar para tener tambien el modo actor como en la pantalla
 * de reconstruccion (photo) pero habria que tener en cuenta el funcionamiento
 * (mas detalles en el manual tecnico)
 * */
void Viewer::interactorInit(){
    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
}
/*Rellena una nube de puntos y la muestra mientras no se sube ningun archivo*/
void Viewer::fillCloud(){
    cloud_->resize (500);
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
void Viewer::colorCloudDistances ()
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
void Viewer::show2ViewPort(){

    viewer_->createViewPort(0.0,0.5,1.0,1.0, v1);
    viewer_->addText("3D", 10, 10, "v1 text", v1);
    viewer_->addPointCloud<PointT> (cloud_,  "cloud1", v1);
    viewer_->addCoordinateSystem (1.0,"axis1", v1);
    viewer_->createViewPort(0.0, 0.0, 1.0, 0.5, v2);
    viewer_->addText("2D", 10, 10, "v2 text", v2);
    viewer_->addPointCloud<PointT> (cloud_,  "cloud2", v2);
    viewer_->addCoordinateSystem (1.0,"axis2",v2);
}

  /*Registramos los eventos en el visualizador para raton teclado seleccion y punteo*/
void Viewer::registerEvents(){

    viewer_->registerPointPickingCallback(&Viewer::pickEventLine, *this, (void*)&viewer_);
    viewer_->registerKeyboardCallback (&Viewer::keyBoardEventOccurred,*this, (void*)&viewer_);
}

 /*Conectamos al interfaz con sus métodos: SIGNALS Y SLOTS DEL FORMULARIO*/
void Viewer::connections(){
    connect(ui->back_2, SIGNAL(clicked()), this, SLOT(showHome()));
    connect (ui->load, SIGNAL(clicked ()), this, SLOT(loadFileButtonPressed ()));
    connect (ui->back, SIGNAL(clicked ()), this, SLOT(shootScreen()));
    connect (ui->save, SIGNAL(clicked ()), this, SLOT(saveFileButtonPressed ()));
    connect (ui->fullScreen, SIGNAL(clicked()), this, SLOT(showFullScreen()));
    connect (ui->help, SIGNAL(clicked()), this, SLOT(showHelp()));
    connect (ui->x, SIGNAL(clicked()),this,SLOT(crossSectionX()));
    connect (ui->y, SIGNAL(clicked()),this,SLOT(crossSectionY()));
    connect (ui->z, SIGNAL(clicked()),this,SLOT(crossSectionZ()));
    connect (ui->horizontalSlider, SIGNAL(valueChanged(int)),this, SLOT(translatePlane(int)));
    connect (ui->pushButton, SIGNAL(clicked()),this, SLOT (slice()));
    connect (ui->line, SIGNAL(clicked ()), this, SLOT(addLine()));
    connect (ui->rubber, SIGNAL(clicked()), this, SLOT(deleteDistances()));
}

/*Eventos de teclado:
 *s: elimina las lineas dibujadas
*/
void Viewer::keyBoardEventOccurred (const pcl::visualization::KeyboardEvent &event,void* viewer_void){

  /*************************PRESS S*************************/
  if (event.getKeySym () == "s" && event.keyDown ())
  {
    std::cout << "s was pressed => removing all lines" << std::endl;
    char line[512];
    for (unsigned int i = 0; i < line_id; ++i)
    {
      sprintf (line, "line#%03d", i);
      viewer_->removeShape (line);
    }
    line_id = 0;
  }
}

/*Eventos pick:
 * Este tipo de evento se detecta a pulsar shift+click izquierdo del raton
* Consiste en marcar dos puntos como extremos de una linea y medir la distancia entre ellos
*
*/
void Viewer::pickEventLine (const pcl::visualization::PointPickingEvent& event, void* viewer_void){

 int idx = event.getPointIndex ();
 if ((idx == -1)||(number_points==-1))return;
 number_points++;
 if(number_points<=2){

    char buffer[512];
    char line[512];
    char marker[512];
    char mesh[512];

    float distance;
    PointT picked_point;

    /*Detect point and save*/
    event.getPoint(picked_point.x,picked_point.y,picked_point.z);
    m_registration_points[number_points-1]=picked_point;

        /*Point Marker*/
        sprintf(marker, "sphere#%03d", marker_id++);
        viewer_->addSphere (picked_point, 0.01, 1.0, 0.0, 0.0, marker);
        if(number_points==2){
            /*Line*/
            sprintf(line,"line#%03d",line_id++ );
            viewer_->addLine(m_registration_points[0],m_registration_points[1],line);
            /*Distance*/
            distance=euclideanDistance(m_registration_points[0],m_registration_points[1]);
            sprintf (mesh, "mesh#%03d", mesh_id++);
            sprintf (buffer, "(d%i= %f m.)",mesh_id, distance);
            /*Combo*/

            ui->listWidget->addItem(buffer);
            ui->qvtkWidget->update ();
           }
      }

 }

/***********************************MENU INFERIOR*******************************/

/*
 *Vuelta a la pantalla principal
 * */
void Viewer::showHome(){
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
void Viewer::loadFileButtonPressed (){

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
  void Viewer::removeNan(){
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
  void Viewer::filterVoxel(){

      pcl::VoxelGrid<PointT> sor;

      pcl::copyPointCloud (*cloud_tmp,*cloud_aux);
      sor.setInputCloud (cloud_tmp);
      sor.setLeafSize (0.5f, 0.5f, 0.5f);
      sor.filter (*cloud_tmp);
  }

  /*Una vez realizado los cambios en la nube de puntos generada a partir del archivo ply o pcd
   * se colorea esta nueva nube y se añade o se actualiza
   * */
  void Viewer::updateCloud(){
      pcl::copyPointCloud (*cloud_tmp, *cloud_);
      colorCloudDistances ();
      viewer_->removeAllShapes();
      viewer_->updatePointCloud (cloud_, "cloud1");
      pcl::copyPointCloud (*cloud_aux, *cloud_);
      viewer_->resetCamera ();
      ui->qvtkWidget->update ();
  }
  /*
   * Graba la pantalla actual
   * */
   void Viewer::shootScreen(){
       originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
       saveScreenshot();
   }

  /* Guarda una captura de pantalla de la aplicacion
   *
   * */
   void Viewer::saveScreenshot(){
     QString format = "png";
     QString initialPath = QDir::currentPath() + tr("/untitled.") + format;
     QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                initialPath,
                                tr("%1 Files (*.%2);;All Files (*)")
                                .arg(QString(format.toUpper()))
                                .arg(QString(format)));
     if (!fileName.isEmpty())originalPixmap.save(fileName, format.toLatin1());
    }

  /* Guarda la nube de puntos que este disponible en el visor en ese momento
   *
   */
  void Viewer::saveFileButtonPressed (){
   // You might want to change "/home/" if you're not on an *nix platform
   QString filename = QFileDialog::getSaveFileName(this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));
   PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());
   if (filename.isEmpty ())return;
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

 /* Pantalla completa
  *
  */
 void Viewer::showFullScreen(){
     if(this->isFullScreen())this->setWindowState(Qt::WindowMaximized);
     else(this->setWindowState(Qt::WindowFullScreen));
 }

/* Invoca al dialogo que muestra los controles disponibles para cada tipo
 * de modo de interaccion: actor o camara
 */
void Viewer::showHelp(){
    h->show();
}


/****************************TOOLBAR******************************************/
/*Añade el plano x*/
void Viewer::crossSectionX(){

    PointT p1, p2, p3, p4;
    p1.x=origin;p1.y=miny;p1.z=minz;
    p2.x=origin;p2.y=maxy;p2.z=minz;
    p3.x=origin;p3.y=maxy;p3.z=maxz;
    p4.x=origin;p4.y=miny;p4.z=maxz;
    plane_1->values.resize (4);
    plane_1->values[0] = 1;
    plane_1->values[1] = 0;
    plane_1->values[2] = 0;
    plane_1->values[3] = 0;
    coordinate=1;
    boundariesCloud();
    addPolygonPlane(p1,p2,p3,p4,plane_1,v1);
    ui->horizontalSlider->setValue(plane_initvalue);
    ui->qvtkWidget->update ();
}

/*Añade el plano y*/
void Viewer::crossSectionY(){

    PointT p1, p2, p3, p4;
    p1.x=minx;p1.y=origin;p1.z=minz;
    p2.x=minx;p2.y=origin;p2.z=maxz;
    p3.x=maxx;p3.y=origin;p3.z=maxz;
    p4.x=maxx;p4.y=origin;p4.z=minz;
    plane_1->values.resize (4);
    plane_1->values[0] = 0;
    plane_1->values[1] = 1;
    plane_1->values[2] = 0;
    plane_1->values[3] = 0;
    coordinate=2;
    boundariesCloud();
    addPolygonPlane(p1,p2,p3,p4,plane_1,v1);
    ui->horizontalSlider->setValue(plane_initvalue);
    ui->qvtkWidget->update ();
}

/*Añade el plano z*/
void Viewer::crossSectionZ(){

    PointT p1, p2, p3, p4;
    p1.x=minx;p1.y=miny;p1.z=origin;
    p2.x=minx;p2.y=maxy;p2.z=origin;
    p3.x=maxx;p3.y=maxy;p3.z=origin;
    p4.x=maxx;p4.y=miny;p4.z=origin;
    plane_1->values.resize (4);
    plane_1->values[0] = 0;
    plane_1->values[1] = 0;
    plane_1->values[2] = 1;
    plane_1->values[3] = 0;
    coordinate=3;
    boundariesCloud();
    addPolygonPlane(p1,p2,p3,p4,plane_1,v1);
    ui->horizontalSlider->setValue(plane_initvalue);
    ui->qvtkWidget->update ();
}

/*
 * Se añade el plano con los coeficientes y vertices indicados y con las siguientes caracteristicas
 * color rojo semitransparente y coloreado entero no solo el borde
 * */
void Viewer::addPolygonPlane(PointT p1,PointT p2,PointT p3, PointT p4,  pcl::ModelCoefficients::Ptr plane_1,int v ){
        PointCloudT::Ptr contour_;
        contour_.reset(new PointCloudT);
        contour_->push_back (p1);
        contour_->push_back (p2);
        contour_->push_back (p3);
        contour_->push_back (p4);

        plane_->setCoefficients(*plane_1);
        plane_->setContour(*contour_);

        ShapeActorMap::iterator am_it = viewer_->getShapeActorMap()->find("polplane");
       if (am_it != viewer_->getShapeActorMap()->end())
            viewer_->removeShape("polplane",0);
        viewer_->addPolygon(*plane_,255,0,0,"polplane",v);
        viewer_->setShapeRenderingProperties (pcl::visualization::PCL_VISUALIZER_COLOR, 0.9, 0.1, 0.1 /*R,G,B*/, "polplane", v);
        viewer_->setShapeRenderingProperties (pcl::visualization::PCL_VISUALIZER_OPACITY, 0.6, "polplane", v);
        viewer_->setShapeRenderingProperties (pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_SURFACE, "polplane", v);
}
/* Calculo de los maximos y minimos de cada coordenada de la nube de puntos
 * subida
 * */
void Viewer::boundariesCloud(){

    minx=maxx= cloud_->points[0].x;
    miny=maxy= cloud_->points[0].y;
    minz=maxz=cloud_->points[0].z;
    for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
    {
          if (minx > cloud_it->x)minx = cloud_it->x;
          if (maxx < cloud_it->x)maxx = cloud_it->x;
          if (miny > cloud_it->y)miny = cloud_it->y;
          if (maxy < cloud_it->y)maxy = cloud_it->y;
          if (minz > cloud_it->z)minz = cloud_it->z;
          if (maxz < cloud_it->z)maxz = cloud_it->z;
     }
}


/*SLOT para la barra horizontal que traslada positiva o negativamente el plano activo
 *
 * */
void Viewer::translatePlane(int value){

 std::cout<<"value changed"<<value<<std::endl;
 Eigen::Affine3f translation=Eigen::Affine3f::Identity();
 double pose=value*0.001;
    switch(coordinate){
    case 1:
        std::cout<<"pose: "<<pose<<" coordinate: "<<coordinate<<endl;
        translation.translation()<<pose,0,0;
        break;
    case 2:
         std::cout<<"pose: "<<pose<<" coordinate: "<<coordinate<<endl;
         translation.translation()<<0,pose,0;
           break;
    case 3:
         std::cout<<"pose: "<<pose<<" coordinate: "<<coordinate<<endl;
       translation.translation()<<0,0,pose;
         break;
    default: break;
    }
     std::cout<<"translation: "<<translation.matrix()<<endl;
     updateShapePosePlanarPolygon(translation, "polplane");
}

/* Desplazamiento positivo o negativo del plano mostrado
 *
 * */
void Viewer::updateShapePosePlanarPolygon(Eigen::Affine3f translation, std::string id){

    ShapeActorMap::iterator am_it;
    vtkOpenGLActor* actor;
    vtkSmartPointer<vtkMatrix4x4> matrix;
    am_it= viewer_->getShapeActorMap()->find(id);
    if (am_it != viewer_->getShapeActorMap()->end())std::cout<<"si encontro el plano"<<endl;
    actor=vtkOpenGLActor::SafeDownCast(am_it->second);
    matrix=  vtkSmartPointer<vtkMatrix4x4> ::New();
    viewer_->convertToVtkMatrix(translation.matrix(), matrix);
    actor->SetUserMatrix(matrix);
    actor->Modified();
    ui->qvtkWidget->update ();
}
/*Busca los puntos cuya distancia al plano sea mínima (si se pone cero no se considera
 * un margen minimo de error y no coge ningun punto por tanto elegimos 0.5) y los
 * añade a otra nube que se mostrara en el visor superior obteniendo una nube casi 2D
 * sobre la cual se pueden realizar medidas de una manera mas exacta
 * */
 void Viewer::slice(){

 pcl::ModelCoefficients slice_coeff;
 PointT point;
 double d;
 slice_coeff.values.resize (4);
 slice_coeff=getTranslationCoefficients("polplane");
 for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it){
    point.x=cloud_it->x;
    point.y=cloud_it->y;
    point.z=cloud_it->z;
    d=distanceToPlane(slice_coeff,cloud_it);
    if(d<0.5)cloud_2D->push_back(point);
 }
 for (PointCloudT::iterator cloud_it = cloud_2D->begin (); cloud_it != cloud_2D->end (); ++cloud_it){
    cloud_it->r = 128;
    cloud_it->g = 128;
    cloud_it->b = 128;
 }
 viewer_->updatePointCloud (cloud_2D, "cloud2");
 viewer_->resetCamera ();
 ui->qvtkWidget->update ();
}

/*
 *Obtiene los coeficientes del plano dependiendo del plano sobre
 * el que se hace el corte. Realmente solo se necesita el coeficiente D ya
 * que el A B y C se saben por el plano sobre el que estan
 */
pcl::ModelCoefficients Viewer::getTranslationCoefficients(std::string id){
    pcl::ModelCoefficients slice_coeff;
    ShapeActorMap::iterator am_it;

    am_it= viewer_->getShapeActorMap()->find(id);
    if(am_it==viewer_->getShapeActorMap()->end()) std::cout<<"The shape doesn't exist"<<std::endl;
    slice_coeff.values.resize (4);

        switch(coordinate){
        case 1:
            slice_coeff.values[0] = 1.0;
            slice_coeff.values[1] = 0.0;
            slice_coeff.values[2] = 0.0;
            slice_coeff.values[3]= -(am_it->second->GetMatrix()->GetElement(0,3));
            std::cout<<slice_coeff.values[3]<<std::endl;
            break;
        case 2:
             slice_coeff.values[0] = 0.0;
             slice_coeff.values[1] = 1.0;
             slice_coeff.values[2] = 0.0;
             slice_coeff.values[3]= -(am_it->second->GetMatrix()->GetElement(1,3));
             std::cout<<slice_coeff.values[3]<<std::endl;
            break;
        case 3:
             slice_coeff.values[0] = 0.0;
             slice_coeff.values[1] = 0.0;
             slice_coeff.values[2] = 1.0;
             slice_coeff.values[3]=-(am_it->second->GetMatrix()->GetElement(2,3));
             std::cout<<slice_coeff.values[3]<<std::endl;
             break;
        default: break;


    }
     std::cout<<*(am_it->second->GetMatrix())<<std::endl;
     return slice_coeff;
}

/* Calcula con la ecuacion de distancia de un punto a un plano, la distancia
 * para posteriormente quedarnos con los puntos que estan sobre el plano
 * con un margen de error de 0.5
 * */
double Viewer::distanceToPlane(pcl::ModelCoefficients coefficients, PointCloudT::iterator point){

    double distance;
    double norm_sqr;
    double A,B,C,D;
    double absoluto;

    norm_sqr= (coefficients.values[0] * coefficients.values[0] +
               coefficients.values[1] * coefficients.values[1] +
               coefficients.values[2] * coefficients.values[2] );
    A= coefficients.values[0]*point->x;
    B= coefficients.values[1]*point->y;
    C=coefficients.values[2]*point->z;
    D=coefficients.values[3];
    absoluto=fabs(A+B+C+D);
    distance=absoluto/sqrt(norm_sqr);
    return distance;
}





/* Cada vez que se quiere añadir una linea hay que inicializar el numero de puntos a
 * cero para que con el evento "picking" se marquen los extremos de cada linea
 * */
void Viewer::addLine(){
 std::cout<<"addLine"<<std::endl;
 number_points=0;
}

/* Elimina las lineas y marcas dibujadas al tomar medidas
 *
 * */
void Viewer::deleteDistances(){

    char line[512];
    char marker[512];
    for (unsigned int i = 0; i < line_id; ++i)
    {
      sprintf (line, "line#%03d", i);
      viewer_->removeShape (line);
    }
    line_id = 0;
    for (unsigned int i = 0; i < marker_id; ++i)
    {
      sprintf (marker, "sphere#%03d", i);
      viewer_->removeShape (marker);
    }
    marker_id = 0;
    ui->listWidget->clear();
    ui->qvtkWidget->update ();
}


Viewer::~Viewer()
{
   delete ui;
}
