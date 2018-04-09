#include "interactor_style_actor.h"
/**
 * Interactor basado en vtkInteractorStyleTracballActor
 */
vtkStandardNewMacro(interactor_style_actor);
interactor_style_actor::interactor_style_actor()
{

}

void interactor_style_actor::OnLeftButtonDown(){

  std::cout << "Pressed left mouse button." << std::endl;
  // Forward events
  vtkInteractorStyleTrackballActor::OnLeftButtonDown();
}
