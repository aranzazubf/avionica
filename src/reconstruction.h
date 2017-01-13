#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H


/*******Boost*****/
#include <boost/math/special_functions/round.hpp>
#include <boost/thread/thread.hpp>
#include <boost/unordered/unordered_map.hpp>
/*******Eigen*****/
#include <eigen3/Eigen/Geometry>
/*******STD*******/
#include <iostream>
/*******Qt********/
#include <QtWidgets>
#include <QFileDialog>
#include <QIcon>
#include <QPixmap>
#include <QDesktopWidget>
/*Point Cloud Library*/

#include <pcl-1.8/pcl/common/distances.h>
#include <pcl-1.8/pcl/common/common_headers.h>
#include <pcl-1.8/pcl/console/parse.h>
#include <pcl-1.8/pcl/features/normal_3d.h>
#include <pcl-1.8/pcl/filters/bilateral.h>
#include <pcl-1.8/pcl/filters/filter.h>
#include <pcl-1.8/pcl/filters/grid_minimum.h>
#include <pcl-1.8/pcl/filters/voxel_grid.h>
#include <pcl-1.8/pcl/filters/passthrough.h>
#include <pcl-1.8/pcl/io/ply_io.h>
#include <pcl-1.8/pcl/io/pcd_io.h>
#include <pcl-1.8/pcl/point_cloud.h>
#include <pcl-1.8/pcl/point_types.h>
#include <pcl-1.8/pcl/sample_consensus/sac_model_plane.h>
#include <pcl-1.8/pcl/search/kdtree.h>
#include <pcl-1.8/pcl/visualization/common/actor_map.h>
#include <pcl-1.8/pcl/visualization/pcl_visualizer.h>
#include <pcl-1.8/pcl/visualization/interactor_style.h>
#include <pcl-1.8/pcl/geometry/planar_polygon.h>
// Visualization Toolkit (VTK)
#include <vtk-6.2/vtkLODActor.h>
#include <vtk-6.2/vtkActor.h>
#include <vtk-6.2/vtkInteractorStyleTrackballActor.h>
#include <vtk-6.2/vtkPlaneSource.h>
#include <vtk-6.2/vtkPolyData.h>
#include <vtk-6.2/vtkPolyDataMapper.h>
#include <vtk-6.2/vtkProp.h>
#include <vtk-6.2/vtkRenderWindow.h>
#include <vtk-6.2/vtkSmartPointer.h>
#include <vtk-6.2/vtkVersion.h>
#include <vtk-6.2/vtkInteractorStyleSwitch.h>
#include <vtk-6.2/vtkOpenGLActor.h>
#include <vtk-6.2/vtkMatrix4x4.h>
/**Clases propias*/
#include "interactor_style_actor.h"

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::PointXYZI PointI;
typedef pcl::PointXYZ PointB;
typedef pcl::PointCloud<PointB> PointCloudB;
typedef pcl::PointCloud<PointI> PointCloudI;
namespace Ui {
class Reconstruction;
}

class Reconstruction : public QWidget
{
    Q_OBJECT

public:
    void interactorInit();
    void saveScreenshot();
       void fVoxelGrid(int value);
       void setPartner(QWidget * partner);
    explicit Reconstruction(QWidget *parent = 0);
    ~Reconstruction();

private:
    Ui::Reconstruction *ui;
    QWidget* mPartner;
protected:
    int filtering_axis_;
    int color_mode_;
    int v1=0;
       int nclouds=0;
     PointCloudT::Ptr cloud_;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
    vtkSmartPointer<pcl::visualization::PCLVisualizerInteractorStyle> interactor_;
    QPixmap originalPixmap;
    void  colorCloudDistances ();
    void fillCloud();
    void showCloud();
    void connections();
public slots:
        void showHome();
    void shootScreen();
       void saveFileButtonPressed ();
    void loadFileButtonPressed ();
    void showFullScreen();
    void loadInteractorCamera();
    void loadInteractorActor();

};

#endif // RECONSTRUCTION_H
