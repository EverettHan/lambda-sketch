// COPYRIGHT DASSAULT SYSTEMES 2017

#ifndef IVIVizViewer_H
#define IVIVizViewer_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATSysErrorDef.h"

extern ExportedByCATVisItf IID IID_IVIVizViewer;

/**
* Interface to extend the CATVizViewer without Dialog / Visualization Controller prereq
*/

class ExportedByCATVisItf IVIVizViewer: public CATBaseUnknown
{

  CATDeclareInterface;

public:
  
 /**
  * Create slave windows from VisMultipipeConfiguration set on the CATVizViewer.
  */
  virtual HRESULT ActivateMultipipe() = 0;

 /**
  * Destroy slave windows from VisMultipipeConfiguration set on the CATVizViewer.
  */
  virtual HRESULT DesactivateMultipipe() = 0;

  /** 
   * Sets the viewer's FullScreen state.
   *  @param iOnOff the FullScreen mode
   */
  virtual HRESULT SetFullScreen( const int iOnOff = 1 ) = 0;

};

CATDeclareHandler(IVIVizViewer, CATBaseUnknown);

#endif

