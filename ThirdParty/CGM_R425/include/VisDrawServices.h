//===================================================================
// COPYRIGHT Dassault Systemes 2021-06-11
//===================================================================

#ifndef VisDrawServices_H
#define VisDrawServices_H

#include "SGInfra.h"

#include <functional>
#include <list>

class CATViewer;

using VisContinuousDrawEndCallback = std::function<bool(const CATViewer*)>;
using VisContinuousDrawEndCallbackHandler = std::list<VisContinuousDrawEndCallback>::const_iterator;

class CATSupport;
class CATVizViewer;
class ExportedBySGInfra VisDrawServices
{
public:
  //-----------------------------------------
  // Continous Draw
  
  static VisContinuousDrawEndCallbackHandler ActivateContinuousDraw(CATVizViewer* iViewer,      VisContinuousDrawEndCallback iCB = nullptr);
  static VisContinuousDrawEndCallbackHandler ActivateContinuousDraw(const CATSupport& iSupport, VisContinuousDrawEndCallback iCB = nullptr);
  
  static void DeactivateContinuousDraw(CATVizViewer* iViewer,      VisContinuousDrawEndCallbackHandler iCBHandler);
  static void DeactivateContinuousDraw(const CATSupport& iSupport, VisContinuousDrawEndCallbackHandler iCBHandler);

private:
  VisDrawServices () {};
  ~VisDrawServices() {};
};

//-----------------------------------------------------------------------

#endif
