#ifndef VIEWER_H
#define VIEWER_H

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
typedef boost::unordered::unordered_map<std::string, vtkSmartPointer<vtkProp>> ShapeActorMap;
typedef boost::shared_ptr<ShapeActorMap> ShapeActorMapPtr;
typedef pcl::PlanarPolygon<PointT> Planar;
namespace Ui {
class Viewer;
}

class Viewer : public QWidget
{
    Q_OBJECT

public:
    explicit Viewer(QWidget *parent = 0);
    ~Viewer();
void saveScreenshot();
void addPolygonPlane(PointT p1,PointT p2,PointT p3, PointT p4,pcl::ModelCoefficients::Ptr plane_1, int v );
void updateShapePosePlanarPolygon(Eigen::Affine3f translation, std::string id);
double distanceToPlane(pcl::ModelCoefficients coefficients, PointCloudT::iterator point);
    void fVoxelGrid(int value);
pcl::ModelCoefficients getTranslationCoefficients( std::string id);
void setPartner(QWidget* partner);
private:
    Ui::Viewer *ui;
 QWidget * mPartner;
protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
    vtkSmartPointer<pcl::visualization::PCLVisualizerInteractorStyle> interactor_;
    Planar::Ptr plane_;
    PointCloudT::Ptr cloud_;
    PointCloudT::Ptr cloud_2D;
    PointT p1,p2;
    PointT m_registration_points[2];
    QPixmap originalPixmap;
    pcl::ModelCoefficients::Ptr plane_1;
    int text_id=0;
    int line_id=0;
    int marker_id=0;
    int mesh_id=0;
    int filtering_axis_;
    int color_mode_;
    int number_points;
    int plane_initvalue=0;

    double origin=0.0;
    double minx,maxx,miny,maxy,minz,maxz;
int v1=0;
int v2=1;
int coordinate;
void boundariesCloud();
    void  colorCloudDistances ();
    void fillCloud();
    void mouseEventOccurred (const pcl::visualization::MouseEvent& event, void* viewer_void);
    void keyBoardEventOccurred (const pcl::visualization::KeyboardEvent &event, void* viewer_void);
    void pickEventLine (const pcl::visualization::PointPickingEvent &event, void* viewer_void);
    void area_picking_callback (const pcl::visualization::AreaPickingEvent &event, void*);
    void interactorInit();
    void show2ViewPort();
public slots:
    void showHome();
    void shootScreen();
    void saveFileButtonPressed ();
    void loadFileButtonPressed ();
    void addLine();

    void crossSectionX();
    void crossSectionY();
    void crossSectionZ();
    void deleteDistances();
    void showFullScreen();

//    void loadInteractorCamera(bool checked);
//    void loadInteractorActor(bool checked);
    void load2D();

void translatePlane(int value);

};

#endif // VIEWER_H
