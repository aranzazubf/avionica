#ifndef INTERACTOR_STYLE_ACTOR_H
#define INTERACTOR_STYLE_ACTOR_H

#include <vtkVersion.h>
#include <vtkSelectEnclosedPoints.h>
#include <vtkRendererCollection.h>
#include <vtkPointData.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransform.h>
#include <vtkLinearTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkObjectFactory.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <vtkInteractorStyleSwitch.h>
#include <iostream>
class interactor_style_actor : public vtkInteractorStyleTrackballActor
{
public:
    static interactor_style_actor *New();
    vtkTypeMacro(interactor_style_actor, vtkInteractorStyleTrackballActor);
interactor_style_actor();
      virtual void OnLeftButtonDown();

};

#endif // INTERACTOR_STYLE_ACTOR_H

