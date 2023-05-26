// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCompareUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2015 Creation: D1A
//===================================================================
#ifndef CATPolyCompareUtil_h
#define CATPolyCompareUtil_h

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h" // HRESULT definition on UNIX systems.
#include "CATBoolean.h"


class CATPolyBody;
class CATIPolyMesh;
class CATPolyCompareParams;


class ExportedByCATPolyMiscellaneous CATPolyCompareUtil
{

public:
    
  /*
  * ComparePolyBodies : Compares 2 input polybodies
  * @param iBody1 : First Input polybody for comparison
  * @param iBody2 : Second Input polybody for comparison
  * @param iCompareVerticesTriangles : if TRUE, it does Vertex-to-vertex comparaison and triangle-to-triangle comparison
  * @param iCompareMassProperties : if TRUE, it does mass properties comparison
  * @param iCompareVertexIds TRUE compare ids FALSE don't and compare vertices coordinate only
  * @return
  *   Returns S_OK if polybodies are same, else returns E_FAIL
  */
  
  static HRESULT ComparePolyBodies(const CATPolyBody & iBody1, const CATPolyBody & iBody2, CATBoolean iCompareVerticesTriangles, CATBoolean iCompareMassProperties, CATBoolean iCompareVertexIds = TRUE );

  /*
  * ComparePolyMeshes : Compares 2 input polymeshes
  * @param iMesh1 : First Input polymesh for comparison
  * @param iMesh2 : Second Input polymesh for comparison
  * @param iCompareVerticesTriangles : if TRUE, it does Vertex-to-vertex comparaison and triangle-to-triangle comparison
  * @param iCompareMassProperties : if TRUE, it does mass properties comparison
  * @param iCompareVertexIds TRUE compare ids FALSE don't and compare vertices coordinate only
  * @return 
  *   Returns S_OK if polymeshes are same, else returns E_FAIL
  */
  
  static HRESULT ComparePolyMeshes(CATIPolyMesh * iMesh1, CATIPolyMesh * iMesh2, CATBoolean iCompareVerticesTriangles, CATBoolean iCompareMassProperties, CATBoolean iCompareVertexIds = TRUE );
  
  /*
  * SetComparisonParams : Set the comparisonParams that will be used during comparison in above two methods
  * @param iCompareParams : input params
  */
  static void SetComparisonParams(const CATPolyCompareParams & iCompareParams);
  
  static CATPolyCompareParams * _ComparisonParams;

};

#endif
