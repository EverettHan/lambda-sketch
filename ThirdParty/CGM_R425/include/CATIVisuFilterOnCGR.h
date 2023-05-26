// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATIVisuFilterOnCGR_h
#define CATIVisuFilterOnCGR_h

#include <SceneGraphManager.h>

#include "CATBaseUnknown.h"
#include "CATListOfInt.h"

ExportedBySceneGraphManager extern IID IID_CATIVisuFilterOnCGR;

/**
* Interface for layer visibility.
* <br>Interface implemented by the @href CATVisManager that you retrieve by the
* static function @href CATVisManager#GetVisManager . 
*/
class ExportedBySceneGraphManager CATIVisuFilterOnCGR: public CATBaseUnknown
{
  CATDeclareInterface;
  
 public :
	 
	 virtual HRESULT GetVisibleLayerList (CATListOfInt * iopLayerNumberList) = 0;
};

#endif
