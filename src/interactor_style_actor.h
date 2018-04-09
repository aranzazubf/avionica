#ifndef INTERACTOR_STYLE_ACTOR_H
#define INTERACTOR_STYLE_ACTOR_H

#include "common_includes.h"
#include "vtk_includes.h"
class interactor_style_actor : public vtkInteractorStyleTrackballActor
{
public:
    static interactor_style_actor *New();
    vtkTypeMacro(interactor_style_actor, vtkInteractorStyleTrackballActor);
interactor_style_actor();
      virtual void OnLeftButtonDown();

};

#endif // INTERACTOR_STYLE_ACTOR_H

