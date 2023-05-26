//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// CATPolyMicroToMacroModelConverter.h
//
//=============================================================================
// 2008-08-22 NDO
//=============================================================================
#ifndef CATPolyMicroToMacroModelConverter_H
#define CATPolyMicroToMacroModelConverter_H

#include "PolyModelConverters.h"
#include "CATErrorDef.h"  // Definition of HRESULT.

class CATPolyBody;
class CATIPolyMesh;
class CATPolyBars;
class CATPolySurfaceFacetSupportLayer;
class CATPolyBarsBarSupportLayer;
class CATPolyMeshVertexNNormalsLayer;
class CATMapOfPtrToInt;
class CATPolyMeshVertexNTexCoordsLayer;

/*
 * Class used to convert a Micro Model (CATIPolyMesh and CATPolyBars) to a Micro Model (CATPolyBody).
 */
class ExportedByPolyModelConverters CATPolyMicroToMacroModelConverter
{

public:

	CATPolyMicroToMacroModelConverter () {};
	~CATPolyMicroToMacroModelConverter () {};

public:

  /*
   * Convert a CATIPolyMesh and CATPolyBars model into a CATPolyBody model.
   * @param iMesh
   *   Input mesh to be converted.
   * @param iBars
   *   Input bars to be converted.
   * @param oPolyBody
   *   Output CATPolyBody.  The object is allocated by the method.  It must be deleted by the caller.
   * @return
   *   S_OK upon success.
   */
  HRESULT Convert (const CATIPolyMesh& iMesh, const CATPolyBars& iBars, CATPolyBody*& oPolyBody);

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
   *   Output map of a CATPolyCell to an ID. The object is allocated by the method.  It must be deleted by the caller.
   * @return
   *   S_OK upon success.
   */
  HRESULT Convert (const CATIPolyMesh& iMesh,
                   const CATPolyMeshVertexNNormalsLayer* iNormalLayer,
                   const CATPolyMeshVertexNTexCoordsLayer* iTexCoordsLayer,
                   const CATPolySurfaceFacetSupportLayer* iTriangleSupportLayer,
                   const CATPolyBars* iBars,
                   const CATPolyBarsBarSupportLayer* iBarSupportLayer, 
                   CATPolyBody*& oPolyBody,
                   CATMapOfPtrToInt*& oMapCellToSupportId);

};

#endif // !CATPolyMicroToMacroModelConverter_H
