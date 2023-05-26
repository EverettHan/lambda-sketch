#ifndef CAT3DNoOccObsPLMBagRep_H
#define CAT3DNoOccObsPLMBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2023

#include "SGInfra.h"
#include "CAT3DPLMBagRep.h"


/**
* @class CAT3DNoOccObsPLMBagRep is for limited use.
* Don't expose it to applications!
*
* @class CAT3DNoOccObsPLMBagRep is dedicated to part of the scene graph
* we don't want to see in the occurrence graph of the observer.
* This is useful only for huge modifications on the SG not to spend
* too many time in the update of the occurrence graph.
* In this case the rep and all its children are drawnin volatile.
**/
class ExportedBySGInfra CAT3DNoOccObsPLMBagRep : public CAT3DPLMBagRep
{
  CATDeclareClass;
  friend class DELPPRLiveProxyROOT3DBagRep; // give unique application access
  friend class DELPPRLiveProxy3DGeoVisuROOT; // give unique application access
  friend class DELPPRLiveResProxy3DGeoVisuROOT; // give unique application access (new version)
  friend class DELPPRLiveResProxyROOT3DBagRep; // give unique application access (new version)
private:

  static CAT3DNoOccObsPLMBagRep* CreateRep();


private:
  CAT3DNoOccObsPLMBagRep();
  virtual ~CAT3DNoOccObsPLMBagRep();
};

#endif
