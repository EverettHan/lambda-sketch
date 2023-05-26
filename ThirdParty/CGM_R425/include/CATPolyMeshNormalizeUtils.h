// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshNormalizeUtils.h
// Header definition of CATPolyMeshNormalizeUtils
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2006 Creation: NDO
//===================================================================
#ifndef CATPolyMeshNormalizeUtils_H
#define CATPolyMeshNormalizeUtils_H

#include "CATPolyGriddingTools.h"
#include "CATErrorDef.h"

class CATPolyExactArithmetic;
class CATMathBox;
class CATIPolyMesh;


/*
Utilities to construct an instance of exact arithmetic and normalize meshes prior to using exact arithmetic.
*/
class ExportedByCATPolyGriddingTools CATPolyMeshNormalizeUtils
{

public :

  CATPolyMeshNormalizeUtils (void) {};
  ~CATPolyMeshNormalizeUtils (void) {};

  // Normalize the mesh and return its bounding box after normalization and definition of a new instance of 
  // exact arithmetic.
  static HRESULT NormalizeOperand (CATIPolyMesh* ioMesh, 
                                   CATMathBox& oBoundingBox, CATPolyExactArithmetic*& oExactArithmetic);

  // Normalize the meshes and return the bounding box after normalization and definition of a new instance of 
  // exact arithmetic.
  static HRESULT NormalizeOperands (CATIPolyMesh* iMesh0, CATIPolyMesh* iMesh1, 
                                    CATMathBox& oBoundingBox, CATPolyExactArithmetic*& oExactArithmetic);

};

#endif

