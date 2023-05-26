//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Gridded Mesh and Bars.
//
//=============================================================================
// 2008-07-30   NDO: New
//=============================================================================
#ifndef CATPolyGriddedMeshAndBarsConst_H
#define CATPolyGriddedMeshAndBarsConst_H

#include "CATPolyGriddingTools.h"
#include "CATPolyGriddedPositions.h"
#include "CATErrorDef.h"  // HRESULT.

class CATPolyExactArithmetic;
class CATIPolyMesh;
class CATPolyBars;
class CATMathBox;


class ExportedByCATPolyGriddingTools CATPolyGriddedMeshAndBarsConst
{

public:

  inline CATPolyGriddedMeshAndBarsConst (const CATIPolyMesh& iMesh,
                                         const CATPolyBars& iBars,
                                         CATPolyGriddedPositionsConst& iGriddedVertexPositions);

  ~CATPolyGriddedMeshAndBarsConst () {}

public:

  inline const CATPolyExactArithmetic& GetExactArithmetic () const;

  inline const CATIPolyMesh& GetMesh () const;
  inline const CATPolyBars& GetBars () const;

  inline CATPolyGriddedPositionsConst& GetVertexPositions () const;

  HRESULT GetBoundingBox (CATMathBox& oBBox) const;

protected:

  const CATIPolyMesh& _Mesh;
  const CATPolyBars& _Bars;

  CATPolyGriddedPositionsConst& _GriddedVertexPositions;

};


inline CATPolyGriddedMeshAndBarsConst::CATPolyGriddedMeshAndBarsConst (const CATIPolyMesh& iMesh,
                                                                       const CATPolyBars& iBars,
                                                                       CATPolyGriddedPositionsConst& iGriddedVertexPositions) :
  _Mesh (iMesh),
  _Bars (iBars),
  _GriddedVertexPositions (iGriddedVertexPositions)
{
}

inline const CATPolyExactArithmetic& CATPolyGriddedMeshAndBarsConst::GetExactArithmetic () const
{
  return _GriddedVertexPositions.GetExactArithmetic ();
}

inline const CATIPolyMesh& CATPolyGriddedMeshAndBarsConst::GetMesh () const
{
  return _Mesh;
}

inline const CATPolyBars& CATPolyGriddedMeshAndBarsConst::GetBars () const
{
  return _Bars;
}

inline CATPolyGriddedPositionsConst& CATPolyGriddedMeshAndBarsConst::GetVertexPositions () const
{
  return _GriddedVertexPositions;
}

#endif // !CATPolyGriddedMeshAndBarsConst_H
