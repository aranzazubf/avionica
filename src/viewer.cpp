#include "viewer.h"
#include "../build/ui_viewer.h"
#include <iostream>

Viewer::Viewer(QWidget *parent) :  QWidget(parent),ui(new Ui::Viewer),
  filtering_axis_ (1), //y
  color_mode_ (1), //rainbow
  text_id (1),
  line_id (1),
  mPartner(0)
{
    ui->setupUi(this);


    /**********************
     *
     *  Create a plane VTK
     *  Tampoco soy capaz de moverlo con VTK: Hay que crear un interactorstyle
     *  customizado juntando haciendo que el interactor style de pcl
     *  extienda de vtkInteractorStyleTrackballActor pero que añada la función de
     * vtkInteractorStyleRubberBandPick.
     * */


   /*Creamos una nueva de puntos la rellenamos de puntos y la pintamos*/
    cloud_.reset(new PointCloudT);

    cloud_2D.reset(new PointCloudT);
    plane_.reset(new Planar);
     plane_1.reset(new pcl::ModelCoefficients);
    fillCloud();
    colorCloudDistances ();

    /*Creamos un visualizador pcl le añadimos los ojes de coordenadas y la nube de puntos*/
    viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    show2ViewPort();


    /*Registramos los eventos en el visualizador para raton teclado seleccion y punteo*/
    viewer_->registerMouseCallback (&Viewer::mouseEventOccurred, *this, (void*)&viewer_);
    viewer_->registerPointPickingCallback(&Viewer::pickEventLine, *this, (void*)&viewer_);
    viewer_->registerKeyboardCallback (&Viewer::keyBoardEventOccurred,*this, (void*)&viewer_);
    viewer_->registerAreaPickingCallback(&Viewer::area_picking_callback, *this, (void*)&viewer_);

    /*Añadimos el visualizador al QVTKWidget de nuestra interfaz para poder verlo y manejarlo*/
    ui->qvtkWidget->SetRenderWindow (viewer_->getRenderWindow ());

    connect(ui->back_2, SIGNAL(clicked()), this, SLOT(showHome()));

    /*Conectamos al interfaz con sus métodos: SIGNALS Y SLOTS DEL FORMULARIO*/

    connect (ui->line, SIGNAL(clicked ()), this, SLOT(addLine()));
   // connect (ui->circle, SIGNAL(clicked ()), this, SLOT(addPlane()));
     //  connect (ui->circle, SIGNAL(clicked ()), this, SLOT(addPolygonPlane()));

    connect(ui->x, SIGNAL(clicked()),this,SLOT(crossSectionX()));
    connect(ui->y, SIGNAL(clicked()),this,SLOT(crossSectionY()));
    connect(ui->z, SIGNAL(clicked()),this,SLOT(crossSectionZ()));
    connect (ui->load, SIGNAL(clicked ()), this, SLOT(loadFileButtonPressed ()));
    connect (ui->save, SIGNAL(clicked ()), this, SLOT(saveFileButtonPressed ()));
    connect (ui->back, SIGNAL(clicked ()), this, SLOT(shootScreen()));
    connect (ui->rubber, SIGNAL(clicked()), this, SLOT(deleteDistances()));
    connect(ui->fullScreen, SIGNAL(clicked()), this, SLOT(showFullScreen()));


    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT (load2D()));

    connect (ui->horizontalSlider, SIGNAL(valueChanged(int)),this, SLOT(translatePlane(int)));

    interactorInit();

}

void Viewer::showHome(){


    mPartner->show();


    this->hide();
}
void Viewer::setPartner(QWidget *partner){

    mPartner=partner;



}

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

void Viewer::load2D(){

pcl::ModelCoefficients slice_coeff;
PointT point;

slice_coeff.values.resize (4);
slice_coeff=getTranslationCoefficients("polplane");

    for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
    {
        point.x=cloud_it->x;
        point.y=cloud_it->y;
        point.z=cloud_it->z;


       double d=distanceToPlane(slice_coeff,cloud_it);

      //if(d<0)d=d*(-1);




       //double dsd=pointToPlaneDistance(point,v);

      // std::cout<<cloud_it->x<<std::endl;
       if(d<0.5){
    //   std::cout<<" found distance 0 "<<d<<std::endl;
           /*Point inside the plane*/

        cloud_2D->push_back(point);

       }
       else{


       }

     }
    for (PointCloudT::iterator cloud_it = cloud_2D->begin (); cloud_it != cloud_2D->end (); ++cloud_it)
    {
        cloud_it->r = 128;
        cloud_it->g = 128;
        cloud_it->b = 128;

    }




   viewer_->updatePointCloud (cloud_2D, "cloud2");

    viewer_->resetCamera ();
    ui->qvtkWidget->update ();
  }


double Viewer::distanceToPlane(pcl::ModelCoefficients coefficients, PointCloudT::iterator point){

    double distance;
    double norm_sqr = (coefficients.values[0] * coefficients.values[0] +
                               coefficients.values[1] * coefficients.values[1] +
    coefficients.values[2] * coefficients.values[2] );
    double A= coefficients.values[0]*point->x;
    double B= coefficients.values[1]*point->y;
    double C=coefficients.values[2]*point->z;
    double D=coefficients.values[3];

   double absoluto=fabs(A+B+C+D);

   distance=absoluto/sqrt(norm_sqr);

   return distance;
}

pcl::ModelCoefficients Viewer::getTranslationCoefficients(std::string id){
    ShapeActorMap::iterator am_it = viewer_->getShapeActorMap()->find(id);
    if(am_it==viewer_->getShapeActorMap()->end()){
        std::cout<<"The shape doesn't exist"<<std::endl;

        }
pcl::ModelCoefficients slice_coeff;
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


void Viewer::interactorInit(){
    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());

    //if(!ui->radioButton->isChecked())ui->radioButton->toggle();
    //if(ui->radioButton_2->isChecked())ui->radioButton->toggle();
}


/**Funciones para cambiar de estilo de interaccion con el visor, por defecto se mueve la camara con los actores en conjunto*
 * *Si lo cambiamos al modo Actor podemos mover cada actor por separado pero no tenemos las funcionalidades que aporta
 * el interactor de cámara como mostrar la escala, hacer click...etc*
void Viewer::loadInteractorCamera(bool checked) {

    if((checked)&&(ui->radioButton_2->isChecked()))ui->radioButton_2->toggle();

    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());

}

void Viewer::loadInteractorActor(bool checked) {

    if((checked)&&(ui->radioButton->isChecked()))ui->radioButton->toggle();
    vtkSmartPointer<interactor_style_actor> style =
        vtkSmartPointer<interactor_style_actor>::New();
   viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow (), style);
}
*/
/*Eventos de teclado*/
void Viewer::keyBoardEventOccurred (const pcl::visualization::KeyboardEvent &event,void* viewer_void){

/*NO FUNCIONA EL FULLSCREEN SE CUELGA*/

//    std::cout<<"Ha pulsado la letra: "<<event.getKeySym()<<endl;

//  if(event.getKeySym()=="Escape" && event.keyDown ()){
//      std::cout<<"presione esc";

//          viewer_->setFullScreen(false);
//          //this->setWindowState(Qt::WindowMaximized);
//      }
//  if(event.getKeySym()=="m" && event.keyDown ()){
//      std::cout<<"presione esc";

//          viewer_->setFullScreen(true);
//        //  this->setWindowState(Qt::WindowMaximized);
//      }

/**************************PRESS R************************/
  if (event.getKeySym () == "r" && event.keyDown ())
  {
    std::cout << "r was pressed => removing all text" << std::endl;

    char str[512];
    for (unsigned int i = 0; i < text_id; ++i)
    {
      sprintf (str, "text#%03d", i);
      viewer_->removeShape (str);
    }
    text_id = 0;
  }
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
/*Eventos de ratón*/
void Viewer::mouseEventOccurred (const pcl::visualization::MouseEvent &event, void* viewer_void){
     if(number_points!=0){
       if (event.getButton () == pcl::visualization::MouseEvent::LeftButton &&
           event.getType () == pcl::visualization::MouseEvent::MouseButtonRelease)
       {
//         char str[512];
//         char buffer[512];
//         sprintf (str, "text#%03d", text_id++);
//         sprintf (buffer, "(%d,%d)", event.getX(), event.getY());
//         viewer_->addText (buffer, event.getX(), event.getY(),str);
       }
        }
 }
/*Eventos pick*/
void Viewer::pickEventLine (const pcl::visualization::PointPickingEvent& event, void* viewer_void){

 int idx = event.getPointIndex ();
 if (idx == -1)return;

 number_points++;

 if(number_points<=2){
    char str[512];
    char buffer[512];
    char line[512];
    char marker[512];
    char mesh[512];
    int i=1;
    float distance;
    PointT picked_point;
    PointT p1, p2;

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


/**** NO FUNCIONA BIEN**/

void Viewer::area_picking_callback (const pcl::visualization::AreaPickingEvent& event, void* viewer_void){
std::vector<int> indices;
    PointCloudT::Ptr cloud_pick;
       PointT current_point;
       cloud_pick.reset(new PointCloudT);
        pcl::visualization::PointCloudColorHandlerCustom<PointT> red (cloud_pick, 255, 0, 0);
      if (event.getPointsIndices(indices))
      {
          for(int i=0; i<indices.size();i++){
            current_point=cloud_->points[indices[i]];
            cloud_pick->points.push_back(current_point);
          }
          viewer_->removePointCloud("cloud_pick");
          viewer_->addPointCloud(cloud_pick, red, "cloud_pick");
          viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "cloud_pick");
        std::cout << "picked " << indices.size () <<std::endl;
         ui->qvtkWidget->update ();
      }
      else
        std::cout << "No valid points selected!" << std::endl;
 }


void Viewer::boundariesCloud(){
minx=maxx= cloud_->points[0].x;
miny=maxy= cloud_->points[0].y;
minz=maxz=cloud_->points[0].z;
    for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
    {
          if (minx > cloud_it->x)
            minx = cloud_it->x;

          if (maxx < cloud_it->x)
            maxx = cloud_it->x;

          if (miny > cloud_it->y)
            miny = cloud_it->y;

          if (maxy < cloud_it->y)
            maxy = cloud_it->y;

          if (minz > cloud_it->z)
            minz = cloud_it->z;

          if (maxz < cloud_it->z)
            maxz = cloud_it->z;
     }
}





/*Rellena una nube de puntos y la muestra mientras no se sube ningun archivo*/
void Viewer::fillCloud(){

    cloud_->resize (500);

      // Fill the cloud with random points
      for (size_t i = 0; i < cloud_->points.size (); ++i)
      {
        cloud_->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud_->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
        cloud_->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
      }

}

void Viewer::colorCloudDistances ()
{
  // Find the minimum and maximum values along the selected axis
  double min, max;
  // Set an initial value
  switch (filtering_axis_)
  {
    case 0:  // x
      min = cloud_->points[0].x;
      max = cloud_->points[0].x;
      break;
    case 1:  // y
      min = cloud_->points[0].y;
      max = cloud_->points[0].y;
      break;
    default:  // z
      min = cloud_->points[0].z;
      max = cloud_->points[0].z;
      break;
  }

  // Search for the minimum/maximum
  for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
    switch (filtering_axis_)
    {
      case 0:  // x
        if (min > cloud_it->x)
          min = cloud_it->x;

        if (max < cloud_it->x)
          max = cloud_it->x;
        break;
      case 1:  // y
        if (min > cloud_it->y)
          min = cloud_it->y;

        if (max < cloud_it->y)
          max = cloud_it->y;
        break;
      default:  // z
        if (min > cloud_it->z)
          min = cloud_it->z;

        if (max < cloud_it->z)
          max = cloud_it->z;
        break;
    }
  }

  // Compute LUT scaling to fit the full histogram spectrum
  double lut_scale = 255.0 / (max - min);  // max is 255, min is 0

  if (min == max)  // In case the cloud is flat on the chosen direction (x,y or z)
    lut_scale = 1.0;  // Avoid rounding error in boost

  for (PointCloudT::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
    int value;
    switch (filtering_axis_)
    {
      case 0:  // x
        value = boost::math::iround ( (cloud_it->x - min) * lut_scale);  // Round the number to the closest integer
        break;
      case 1:  // y
        value = boost::math::iround ( (cloud_it->y - min) * lut_scale);
        break;
      default:  // z
        value = boost::math::iround ( (cloud_it->z - min) * lut_scale);
        break;
    }

    // Apply color to the cloud
    switch (color_mode_)
    {
      case 0:
        // Blue (= min) -> Red (= max)
        cloud_it->r = value;
        cloud_it->g = 0;
        cloud_it->b = 255 - value;
        break;
      case 1:
        // Green (= min) -> Magenta (= max)
        cloud_it->r = value;
        cloud_it->g = 255 - value;
        cloud_it->b = value;
        break;
      case 2:
        // White (= min) -> Red (= max)
        cloud_it->r = 255;
        cloud_it->g = 255 - value;
        cloud_it->b = 255 - value;
        break;
      case 3:
        // Grey (< 128) / Red (> 128)
        if (value > 128)
        {
          cloud_it->r = 255;
          cloud_it->g = 0;
          cloud_it->b = 0;
        }
        else
        {
          cloud_it->r = 128;
          cloud_it->g = 128;
          cloud_it->b = 128;
        }
        break;
      default:
        // Blue -> Green -> Red (~ rainbow)
        cloud_it->r = value > 128 ? (value - 128) * 2 : 0;  // r[128] = 0, r[255] = 255
        cloud_it->g = value < 128 ? 2 * value : 255 - ( (value - 128) * 2);  // g[0] = 0, g[128] = 255, g[255] = 0
        cloud_it->b = value < 128 ? 255 - (2 * value) : 0;  // b[0] = 255, b[128] = 0
    }
  }
}

void Viewer::crossSectionX(){
boundariesCloud();
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
 addPolygonPlane(p1,p2,p3,p4,plane_1,v1);
 ui->horizontalSlider->setValue(plane_initvalue);
ui->qvtkWidget->update ();


}
void Viewer::crossSectionY(){
boundariesCloud();
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
 addPolygonPlane(p1,p2,p3,p4,plane_1,v1);
ui->horizontalSlider->setValue(plane_initvalue);
ui->qvtkWidget->update ();
}
void Viewer::crossSectionZ(){

boundariesCloud();
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
 addPolygonPlane(p1,p2,p3,p4,plane_1,v1);
ui->horizontalSlider->setValue(plane_initvalue);
 ui->qvtkWidget->update ();


}
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

void Viewer::updateShapePosePlanarPolygon(Eigen::Affine3f translation, std::string id){

    ShapeActorMap::iterator am_it = viewer_->getShapeActorMap()->find(id);
    if (am_it != viewer_->getShapeActorMap()->end())std::cout<<"si encontro el plano"<<endl;

    vtkOpenGLActor* actor=vtkOpenGLActor::SafeDownCast(am_it->second);
    vtkSmartPointer<vtkMatrix4x4> matrix=  vtkSmartPointer<vtkMatrix4x4> ::New();
viewer_->convertToVtkMatrix(translation.matrix(), matrix);
actor->SetUserMatrix(matrix);
actor->Modified();
ui->qvtkWidget->update ();

}
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

/*************************SLOTS***********************/

/*MENU INFERIOR*/
void Viewer::shootScreen(){
      originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
      saveScreenshot();
}
void Viewer::showFullScreen(){
    if(this->isFullScreen()) {
        //viewer_->setFullScreen(false);
        this->setWindowState(Qt::WindowMaximized);
    }
    else{
        this->setWindowState(Qt::WindowFullScreen);
        //viewer_->setFullScreen 	( 	true	);
    }

}
void Viewer::loadFileButtonPressed (){
  // You might want to change "/home/" if you're not on an *nix platform
  QString filename = QFileDialog::getOpenFileName (this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));
          PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());
  PointCloudT::Ptr cloud_tmp (new PointCloudT);
  PointCloudT::Ptr cloud_filtered (new PointCloudT);
  PointCloudT::Ptr cloud_aux (new PointCloudT);
  PointCloudI::Ptr cloud_bi (new PointCloudI);
 PointCloudI::Ptr cloud_bi_filt (new PointCloudI);
  if (filename.isEmpty ()) return;

  int return_status;
  if (filename.endsWith (".pcd", Qt::CaseInsensitive))
    return_status = pcl::io::loadPCDFile (filename.toStdString (), *cloud_tmp);
  else
    return_status = pcl::io::loadPLYFile (filename.toStdString (), *cloud_tmp);

  if (return_status != 0)
  {
    PCL_ERROR("Error reading point cloud %s\n", filename.toStdString ().c_str ());
    return;
  }

/*
 *FILTER: REMOVENANFROMPOINTCLOUD
*/
  if (cloud_tmp->is_dense)
    pcl::copyPointCloud (*cloud_tmp, *cloud_);
  else
  {
    PCL_WARN("Cloud is not dense! Non finite points will be removed\n");
    std::vector<int> vec;
    pcl::removeNaNFromPointCloud (*cloud_tmp, *cloud_, vec);
  }

  /*
   * FILTER VOXELGRID
   * */
fVoxelGrid(50);
 pcl::copyPointCloud (*cloud_,*cloud_aux);
  pcl::VoxelGrid<PointT> sor;
   sor.setInputCloud (cloud_);
   sor.setLeafSize (0.5f, 0.5f, 0.5f);
   sor.filter (*cloud_filtered);
   pcl::copyPointCloud (*cloud_filtered, *cloud_);

  colorCloudDistances ();
  viewer_->removeAllShapes();
  viewer_->updatePointCloud (cloud_, "cloud1");
   pcl::copyPointCloud (*cloud_aux, *cloud_);
  viewer_->resetCamera ();
  ui->qvtkWidget->update ();
}
void Viewer::saveFileButtonPressed (){
  // You might want to change "/home/" if you're not on an *nix platform
  QString filename = QFileDialog::getSaveFileName(this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));

  PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());

  if (filename.isEmpty ())
    return;

  int return_status;
  if (filename.endsWith (".pcd", Qt::CaseInsensitive))
    return_status = pcl::io::savePCDFileBinary (filename.toStdString (), *cloud_);
  else if (filename.endsWith (".ply", Qt::CaseInsensitive))
    return_status = pcl::io::savePLYFileBinary (filename.toStdString (), *cloud_);
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
void Viewer::saveScreenshot(){
    //Viewer* v;
    QString format = "png";

       QString initialPath = QDir::currentPath() + tr("/untitled.") + format;

//QString fileName = QFileDialog::getSaveFileName(this, tr ("Save As"),
             //                                   "/home/",
               //                                 tr ("(*.png)"));

QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                           initialPath,
                           tr("%1 Files (*.%2);;All Files (*)")
                           .arg(QString(format.toUpper()))
                           .arg(QString(format)));

       if (!fileName.isEmpty())
           originalPixmap.save(fileName, format.toLatin1());


}

/*TOOLBAR*/
void Viewer::deleteDistances(){
    /*delete lines*/
    char line[512];
    for (unsigned int i = 0; i < line_id; ++i)
    {
      sprintf (line, "line#%03d", i);
      viewer_->removeShape (line);
    }
    line_id = 0;
    /*delete markers*/
    char marker[512];
    for (unsigned int i = 0; i < marker_id; ++i)
    {
      sprintf (marker, "sphere#%03d", i);
      viewer_->removeShape (marker);
    }
    marker_id = 0;
    /*delete distances*/
   ui->listWidget->clear();
    marker_id = 0;
    /*delete free forms*/

    /*delete areas*/

    /*delete angles*/


    /*clean*/
 ui->qvtkWidget->update ();



}

void Viewer::addLine(){
 std::cout<<"addLine"<<std::endl;
number_points=0;
 }


/*FILTRADO PCL*/
void Viewer::fVoxelGrid(int value){
PointCloudT::Ptr cloud_filtered (new PointCloudT);
PointCloudT::Ptr cloud_aux (new PointCloudT);

 pcl::copyPointCloud (*cloud_,*cloud_aux);
    pcl::VoxelGrid<PointT> sor;
     sor.setInputCloud (cloud_);
     float realvalue=0.01*value;
     sor.setLeafSize (realvalue,realvalue,realvalue);
     sor.filter (*cloud_filtered);
   pcl::copyPointCloud (*cloud_filtered, *cloud_);

   colorCloudDistances ();
    viewer_->updatePointCloud (cloud_, "cloud");
     pcl::copyPointCloud (*cloud_aux, *cloud_);


    ui->qvtkWidget->update ();



}





Viewer::~Viewer()
{
    delete ui;
}
