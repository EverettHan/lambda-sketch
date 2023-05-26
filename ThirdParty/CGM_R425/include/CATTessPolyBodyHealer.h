//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// Tessellate a CGM BRep into a polyhedral body
//
//=============================================================================
//  2007-10-23  BPG: New.
//=============================================================================

#ifndef CATTessPolyBodyHealer_H
#define CATTessPolyBodyHealer_H

#include "CATDataType.h"
#include "CATTessDiagnostic.h"
#include "CATErrorDef.h"

class CATBody;
class CATPolyBody;
class CATMapOfPtrToPtr;
class CATFace;
class CATPolyFace;
class CATPolyEdge;
class CATLoop;
class CATEdge;
class CATIPolySurface;
class CATSetOfPtr;

//
class CATTessPolyBodyHealer
{
public:
  CATTessPolyBodyHealer();
  ~CATTessPolyBodyHealer();

public:
  static HRESULT PostProcessHealing(CATBody& iBody,
                                    const CATSetOfPtr& iPolyFaces);
private:  
  static HRESULT ZipLoopWithSurface(CATLoop& iLoop, CATFace& iFace, 
                                    CATIPolySurface& iPolyFace,
                                    const CATMapOfPtrToPtr& iEdge2PolyEdge);
};

#endif // !CATTessPolyBodyHealer_H
