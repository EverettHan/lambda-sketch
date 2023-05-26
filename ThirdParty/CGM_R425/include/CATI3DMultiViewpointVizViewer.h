// COPYRIGHT DASSAULT SYSTEMES 2021

#ifndef CATI3DMultiViewpointVizViewer_H
#define CATI3DMultiViewpointVizViewer_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATListPV.h"


extern ExportedByCATVisItf IID IID_CATI3DMultiViewpointVizViewer;

/**
* Interface to get CATI3DMultiViewpointViewer on the CATVizViewer without Dialog / Visualization Controller prereq
*/

class ExportedByCATVisItf CATI3DMultiViewpointVizViewer : public CATBaseUnknown
{
   CATDeclareInterface;

public :
  
  /**
   * Get the multi view viewpoint list.
   */
  virtual void GetDefinedVPList(CATListPV& ioVpList) = 0;

  /**
   * Get the multi view viewpoint synchronization mode.
   */
  virtual int GetViewpointSynchroMode(void) = 0;
};

CATDeclareHandler(CATI3DMultiViewpointVizViewer, CATBaseUnknown);

#endif
