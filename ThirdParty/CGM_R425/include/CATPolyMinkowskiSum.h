// COPYRIGHT Dassault Systemes 2007, all rights reserved
//===================================================================
// CATPolyMinkowskiSum
//===================================================================
// Jun 2020 : VKH1: Creation in PolyhedralOperatorsAdv
//===================================================================


#ifndef CATPolyMinkowskiSum_H
#define CATPolyMinkowskiSum_H

class CATIPolyMesh;
class CATPolyMinkowskiSumObserver;
class CATPolyExactArithmetic;
class CATMathPoint;
class CATUnicodeString;
#include "CATSysErrorDef.h" // HRESULT
#include "ExportedByCATPolyMinkowskiSum.h"
enum CATPolyMinkowskiSum_TypeToCompute
{
    TypeToCompute_VT = 1,
    TypeToCompute_TV, 
    TypeToCompute_EEConvex, 
    TypeToCompute_EECS
};
#include "CATBoolean.h"

class ExportedByCATPolyMinkowskiSum CATPolyMinkowskiSum
{
  
public:

  static CATPolyMinkowskiSum *CreateInstanceOfMinkowskiSum(CATIPolyMesh * iTool, CATIPolyMesh * iWorkpiece ,
                                                           CATIPolyMesh * iResultMesh,CATBoolean NewMinkowski=FALSE);

  virtual ~CATPolyMinkowskiSum() {} ;
  //
  // return 0 if OK
  // iResult must be an empty, instanciated CATIPolyMesh (if not empy, the resukt wil be added (as chains can be aded) to the previous content...
  virtual int Run () = 0;

  // Rajout d'un observer pour suivre la creation des triangles dans le resultat
  virtual void AddObserver(CATPolyMinkowskiSumObserver * iObserver) = 0;

  virtual void DeactivateParallelCode() = 0;

  // Restrict the computations to the triangles of the Minkowski sum which intersect the space 
  // above plane z = iLowZ and below plane z = iHighZ.
  // Bounds are inclusive.
  virtual void SetZBounds(double iLowZ, double iHighZ) {};

  // Add for Tool Path Computation
  static bool IsEdgeConvex(CATIPolyMesh& iMesh, const unsigned int iTriangle1, const unsigned int iTriangle2, CATPolyExactArithmetic& iExactArithmetic, bool & oResult);
  static HRESULT ComputeTriangleOrientation(CATMathPoint& iV1, CATMathPoint& iV2, CATMathPoint& iV3, CATMathPoint& iV4, CATMathPoint& iV5, CATMathPoint& iV6, CATPolyMinkowskiSum_TypeToCompute iConfigToCompute, int& oOrientation);
};
#endif
