/* -*-c++-*- */
#ifndef CATIBuildPath_H
#define CATIBuildPath_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
  * @CAA2Level L1
  * @CAA2Usage U3
  */ 

#include "CATBaseUnknown.h"
#include "CATVisItf.h"
class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIBuildPath;
#else
extern "C" const IID IID_CATIBuildPath;
#endif

/**
  * Interface to build a CATPathElement from an object.
  */

class ExportedByCATVisItf CATIBuildPath : public CATBaseUnknown
{
  CATDeclareInterface;
 
public:
  /**
    * Builds a CATPathElement from an object.
    *   @param iContext 
    *      The context. The CATPathElement which is added a the top of the created CATPathElement.
    *      Usually it is the CATPathElement retrieved from CATFrmEditor::GetUIActiveObject method.
    *   @param oPath 
    *      The created CATPathElement. 
    *      oPath must be released byt he caller.
    */	
  virtual HRESULT ExtractPathElement(const CATPathElement* iContext, CATPathElement** oPath) = 0;
};

CATDeclareHandler( CATIBuildPath, CATBaseUnknown);

#endif

