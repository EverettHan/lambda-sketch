#ifndef CATPolyCriticalMorseIndexOperator_h__
#define CATPolyCriticalMorseIndexOperator_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyCriticalMorseIndexOperator.h
// Header definition of class NUALittleCriticalMorseIndexOpe
//===================================================================
//
// Usage notes: Determine if a vertex is a local min / max / saddle / regular
//
//===================================================================
// HISTORIQUE :
// 31/08/2018 : NUA : critical point on boundary
// 02/06/2017 : Add callback
// 29/03/2017 : NUA : Creation
//===================================================================

// export
#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"

class CATIPolyMesh;
struct CATPolyWatershedCallback;

// 1/ Call Run method
// 2/ Call GetVertexIndex for each vertex
class ExportedByCATPolyWatershedOperators CATPolyCriticalMorseIndexOperator
{
public:

  enum KindOfVertex
  {
    K_Regular,
    K_Top,
    K_Bottom,
    K_Saddle,
    K_Undef,
    K_BoundaryTop,
    K_BoundaryBottom,
    K_BoundarySaddle
  };

  virtual ~CATPolyCriticalMorseIndexOperator() {}

  virtual HRESULT Run() = 0;

  virtual HRESULT GetVertexIndex(const int iNumVertex, KindOfVertex & oKind) const = 0;

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  static CATPolyCriticalMorseIndexOperator * CreateInstance(const CATIPolyMesh & iMesh);
  static CATPolyCriticalMorseIndexOperator * CreateInstance2(const CATIPolyMesh & iMesh); 

  ////////////// for internal use only
  virtual HRESULT RunImpl() = 0;
};

#endif // CATPolyCriticalMorseIndexOperator_h__
