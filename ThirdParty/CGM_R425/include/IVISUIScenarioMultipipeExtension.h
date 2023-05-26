#ifndef IVISUIScenarioMultipipeExtension_h
#define IVISUIScenarioMultipipeExtension_h

// COPYRIGHT DASSAULT SYSTEMES 2021

#include "IVInterfaces.h"
#include "IVISUIScenarioMultipipe.h"


extern ExportedByIVInterfaces IID IID_IVISUIScenarioMultipipeExtension;

/**
* Interface representing an Immersive Virtuality Scenario dedicated to CAVE or HMD.
*/
class ExportedByIVInterfaces IVISUIScenarioMultipipeExtension : public IVISUIScenarioMultipipe
{

  CATDeclareInterface;

public:

  /**
   * Stop or restart the rendering in VR.
   *
   */
  virtual void PauseDrawInVR(bool iOnOff) = 0;

};

CATDeclareHandler(IVISUIScenarioMultipipeExtension, IVISUIScenario);

#endif  // IVISUIScenarioMultipipeExtension_h
