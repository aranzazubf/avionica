#include "reconstruction.h"
#include "../build/ui_reconstruction.h"

Reconstruction::Reconstruction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reconstruction),
    filtering_axis_ (1), //y
    color_mode_ (1),
     mPartner(0)//rainbow
{
    ui->setupUi(this);
    cloud_.reset(new PointCloudT);
    fillCloud();
    colorCloudDistances ();
    viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    showCloud();
     ui->qvtkWidget->SetRenderWindow (viewer_->getRenderWindow ());
     connections();
     interactorInit();
}

Reconstruction::~Reconstruction()
{
    delete ui;
}
void Reconstruction::setPartner(QWidget *partner){

    mPartner=partner;



}
void Reconstruction::showCloud(){

  //  viewer_->createViewPort(0.0,1.0,1.0,1.0, v1);
    viewer_->addText("3D", 10, 10, "v1 text", v1);
    viewer_->addPointCloud<PointT> (cloud_,  "cloud1", v1);
    viewer_->addCoordinateSystem (1.0,"axis1", v1);

    nclouds++;
}
void Reconstruction::connections(){

    connect( ui->camara, SIGNAL(clicked()), this, SLOT(loadInteractorCamera()));
    connect(ui->actor, SIGNAL(clicked()), this, SLOT(loadInteractorActor()));
    connect (ui->load, SIGNAL(clicked ()), this, SLOT(loadFileButtonPressed ()));
    connect (ui->save, SIGNAL(clicked ()), this, SLOT(saveFileButtonPressed ()));
    connect (ui->back, SIGNAL(clicked ()), this, SLOT(shootScreen()));
    connect(ui->fullScreen, SIGNAL(clicked()), this, SLOT(showFullScreen()));
    connect(ui->back_2, SIGNAL(clicked()), this, SLOT(showHome()));


}
void Reconstruction::showHome(){

   // player->setMuted(true);

    mPartner->show();


    this->hide();
}
void Reconstruction::interactorInit(){
    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
}
void Reconstruction::loadInteractorActor() {


    vtkSmartPointer<interactor_style_actor> style =
        vtkSmartPointer<interactor_style_actor>::New();
   viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow (), style);
}
void Reconstruction::loadInteractorCamera() {



    viewer_->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());

}
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

void Reconstruction::colorCloudDistances ()
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
  }}
  void Reconstruction::shootScreen(){
        originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
        saveScreenshot();
  }
  void Reconstruction::showFullScreen(){
      if(this->isFullScreen()) {
          //viewer_->setFullScreen(false);
          this->setWindowState(Qt::WindowMaximized);
      }
      else{
          this->setWindowState(Qt::WindowFullScreen);
          //viewer_->setFullScreen 	( 	true	);
      }

  }
  void Reconstruction::loadFileButtonPressed (){
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

  void Reconstruction::saveScreenshot(){
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
  void Reconstruction::saveFileButtonPressed (){
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
  /*FILTRADO PCL*/
  void Reconstruction::fVoxelGrid(int value){
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

