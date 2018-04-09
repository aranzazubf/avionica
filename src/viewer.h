#ifndef VIEWER_H
#define VIEWER_H
#include "pcl_includes.h"
#include "common_includes.h"
#include "vtk_includes.h"
#include "interactor_style_actor.h"
#include "helperviewer2.h"
#include "reconstruction.h"
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


private:
    Ui::Viewer *ui;
    QWidget * mPartner;
    HelperViewer2 * h;
    Planar::Ptr plane_;
     PointCloudT::Ptr cloud_2D;
    PointT p1,p2;
    PointT m_registration_points[2];
    pcl::ModelCoefficients::Ptr plane_1;
    int line_id=0;
    int marker_id=0;
    int mesh_id=0;
    int number_points=-1;
    int plane_initvalue=0;
    int v2=1;
    int coordinate;
    double origin=0.0;
    double minx,maxx,miny,maxy,minz,maxz;
protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
    vtkSmartPointer<pcl::visualization::PCLVisualizerInteractorStyle> interactor_;
    PointCloudT::Ptr cloud_;
    PointCloudT::Ptr cloud_tmp;
    PointCloudT::Ptr cloud_aux;
    QPixmap originalPixmap;
    int v1=0;

public:
    explicit Viewer(QWidget *parent = 0);
    ~Viewer();
     void setPartner(QWidget* partner);
private:
    void addPolygonPlane(PointT p1,PointT p2,PointT p3, PointT p4,pcl::ModelCoefficients::Ptr plane_1, int v );
    void updateShapePosePlanarPolygon(Eigen::Affine3f translation, std::string id);
    double distanceToPlane(pcl::ModelCoefficients coefficients, PointCloudT::iterator point);
    pcl::ModelCoefficients getTranslationCoefficients( std::string id);
    void show2ViewPort();
    void registerEvents();
    void connections();
    void boundariesCloud();
    void keyBoardEventOccurred (const pcl::visualization::KeyboardEvent &event, void* viewer_void);
    void pickEventLine (const pcl::visualization::PointPickingEvent &event, void* viewer_void);
    void updateCloud();
protected:

    void fillCloud();
    void colorCloudDistances ();
    void saveScreenshot();
    void removeNan();
    void filterVoxel();
    void interactorInit();

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
    void showHelp();
    void slice();
    void translatePlane(int value);

};

#endif // VIEWER_H
