#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H
#include "pcl_includes.h"
#include "common_includes.h"
#include "vtk_includes.h"
#include "interactor_style_actor.h"
#include "helpviewer.h"

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

private:
    Ui::Reconstruction *ui;
    QWidget* mPartner;
    HelpViewer * v;
protected:

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
    vtkSmartPointer<pcl::visualization::PCLVisualizerInteractorStyle> interactor_;
    PointCloudT::Ptr cloud_;
    PointCloudT::Ptr cloud_tmp;
    PointCloudT::Ptr cloud_aux;
    QPixmap originalPixmap;

    int v1=0;
    int nclouds=0;
    void fillCloud();
    void colorCloudDistances ();
    void removeNan();
    void filterVoxel();
    void saveScreenshot();
    void interactorInit();

private:
    void showCloud();
    void connections();
    void updateCloud();
public:
    void setPartner(QWidget * partner);

    explicit Reconstruction(QWidget *parent = 0);
    ~Reconstruction();

public slots:
    void loadInteractorCamera();
    void loadInteractorActor();
    void showHome();
    void loadFileButtonPressed ();
    void saveFileButtonPressed ();
    void shootScreen();
    void showFullScreen();
    void showHelp();

};

#endif // RECONSTRUCTION_H
