//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// CATPolyBodyFromDecoMeshBarsBuilder.h
//
//=============================================================================
// 2013-04-10 ANR : Ajout de iLevelTreatmentForClosedPolyCurve
// 2008-08-22 NDO
// 2009-03-18 ZFI
//=============================================================================

#ifndef CATPolyBodyFromDecoMeshBarsBuilder_H
#define CATPolyBodyFromDecoMeshBarsBuilder_H

#include "PolyBodyBuilders.h"
#include "CATErrorDef.h" 
#include "CATBoolean.h"

class CATPolyDecoMeshBars;
class CATPolyBody;
class CATMapOfPtrToInt;

class ExportedByPolyBodyBuilders CATPolyBodyFromDecoMeshBarsBuilder
{
public:
	CATPolyBodyFromDecoMeshBarsBuilder () {};
	~CATPolyBodyFromDecoMeshBarsBuilder () {};

public:

   /*
   * Convert a CATIPolyMesh and CATPolyBars model into a CATPolyBody model with supporting layers.
   * @param iMesh
   *   Input mesh to be converted.
   * @param iNormalLayer
   *   Input vertex normal support layer. This is an optional input argument. 
   *   The triangle support layer must be defined in order to use this option.
   * @param iTriangleSupportLayer
   *   Input triangle support layer.  This is an optional input argument.
   * @param iBars
   *   Input bars to be converted.
   * @param iBarSupportLayer
   *   Input bar support layer.  This is an optional input argument.
   * @param oPolyBody
   *   Output CATPolyBody.  The object is allocated by the method.  It must be deleted by the caller.
   * @param oMapCellToSupportId
   *   Output map of a CATPolyCell to an ID. The object is optional
   * @param iLevelTreatmentForClosedPolyCurve
   *   option of adding a vertex on a closed polycurve
   *   iLevelTreatmentForClosedPolyCurve = 1 -----> treatment as before
   *   iLevelTreatmentForClosedPolyCurve = 2 -----> Adding the vertex in the middle of the PolyCurve.
   * @return
   *   S_OK upon success.
   */

  HRESULT Convert (const CATPolyDecoMeshBars& iDecoMesh, 
                   CATPolyBody*& oPolyBody,
                   CATBoolean iCreateEdges=1,
                   CATBoolean iCreateWires=0,
                   CATMapOfPtrToInt* ioMapCellToSupportId=0,
                   int iLevelTreatmentForClosedPolyCurve=1
                   );

};

#endif 
