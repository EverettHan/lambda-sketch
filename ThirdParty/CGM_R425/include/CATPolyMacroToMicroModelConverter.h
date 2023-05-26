//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// CATPolyMacroToMicroModelConverter.h
// Header definition of CATPolyMacroToMicroModelConverter
//
//=============================================================================
// 2008-08-08   XCZ: New.
//=============================================================================

#ifndef CATPolyMacroToMicroModelConverter_H
#define CATPolyMacroToMicroModelConverter_H

#include "PolyModelConverters.h"
#include "CATErrorDef.h"  // Definition of HRESULT.

class CATPolyBody;
class CATIPolyMesh;
class CATPolyBars;
class CATPolySurfaceFacetSupportLayer;
class CATPolyBarsBarSupportLayer;
class CATPolyMeshVertexNNormalsLayer;
class CATPolyMacroToMicroModelBarsObserver;
class CATMapOfPtrToInt;



/*
 * Class used to convert a Macro Model (CATPolyBody) to a Micro Model (CATIPolyMesh and CATPolyBars).
 */
class ExportedByPolyModelConverters CATPolyMacroToMicroModelConverter
{

public:

	CATPolyMacroToMicroModelConverter() {};
	~CATPolyMacroToMicroModelConverter() {};

public:

  /*
   * Convert a CATPolyBody into a CATIPolyMesh and CATPolyBars model.
   * @param iPolyBody
   *   Input macro model to be converted.
   * @param ioMesh
   *   Output mesh.  The object is allocated by the method.  It must be released by the caller.
   * @param ioBars
   *   Output bars.  The object is allocated by the method.  It must be released by the caller.
   * @return
   *   S_OK upon success.
   */
  HRESULT Convert (const CATPolyBody& iPolyBody, CATIPolyMesh* ioMesh, CATPolyBars* ioBars);

  /*
   * Convert a CATPolyBody into a CATIPolyMesh and CATPolyBars model with supporting layers.
   * @param iPolyBody
   *   Input macro model to be converted.
   * @param iMapCellToSupportId
   *   Input map of a CATPolyCell to an ID.  This is an optional input argument.
   * @param ioMesh
   *   Output mesh.  The object is allocated by the method.  It must be released by the caller.
   * @param ioBars
   *   Output bars.  The object is allocated by the method.  It must be released by the caller.
   * @param oTriangleSupportLayer
   *   Output triangle support layer.  The object is allocated by the method.  It must be released by the caller.
   * @param oBarSupportLayer
   *   Output bar support layer.  The object is allocated by the method.  It must be released by the caller.
   * @param oNormalLayer
   *   Output vertex normal support layer.  The object is allocated by the method.  It must be released by the caller.
   * @return
   *   S_OK upon success.
   */
  HRESULT Convert (const CATPolyBody& iPolyBody,
                   const CATMapOfPtrToInt* iMapCellToSupportId,
                   CATIPolyMesh* ioMesh,
                   CATPolyBars* ioBars, 
                   CATPolySurfaceFacetSupportLayer*& oTriangleSupportLayer,
                   CATPolyBarsBarSupportLayer*& oBarSupportLayer,
                   CATPolyMeshVertexNNormalsLayer*& oNormalLayer);

private:

  HRESULT UpdateBarsWhenMergeVertices(int v0,int v1,CATPolyBars& ioBars,CATPolyMacroToMicroModelBarsObserver* oBarObserver);

  // Forbidden.
  CATPolyMacroToMicroModelConverter (CATPolyMacroToMicroModelConverter &);
  CATPolyMacroToMicroModelConverter& operator=(CATPolyMacroToMicroModelConverter&);

};

#endif // !CATPolyMacroToMicroModelConverter_H
