//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Gridded Mesh and Bars.
//
//=============================================================================
// 2008-07-30   NDO: New
//=============================================================================
#ifndef CATPolyGriddedMeshAndBars_H
#define CATPolyGriddedMeshAndBars_H

#include "CATPolyGriddingTools.h"
#include "CATPolyGriddedMeshAndBarsConst.h"

class CATIPolyMesh;
class CATPolyBars;
class CATPolyGriddedPositions;


class ExportedByCATPolyGriddingTools CATPolyGriddedMeshAndBars : public CATPolyGriddedMeshAndBarsConst
{

public:

  inline CATPolyGriddedMeshAndBars (CATIPolyMesh& iMesh,
                                    CATPolyBars& iBars,
                                    CATPolyGriddedPositions& iGriddedVertexPositions);

  ~CATPolyGriddedMeshAndBars () {}

public:

  inline CATIPolyMesh& GetMesh ();
  inline CATPolyBars& GetBars ();

  inline CATPolyGriddedPositions& GetVertexPositions ();

};


inline CATPolyGriddedMeshAndBars::CATPolyGriddedMeshAndBars (CATIPolyMesh& iMesh,
                                                             CATPolyBars& iBars,
                                                             CATPolyGriddedPositions& iGriddedVertexPositions) :
  CATPolyGriddedMeshAndBarsConst (iMesh, iBars, iGriddedVertexPositions)
{
}

inline CATIPolyMesh& CATPolyGriddedMeshAndBars::GetMesh ()
{
  return (CATIPolyMesh&) _Mesh;
}

inline CATPolyBars& CATPolyGriddedMeshAndBars::GetBars ()
{
  return (CATPolyBars&) _Bars;
}

inline CATPolyGriddedPositions& CATPolyGriddedMeshAndBars::GetVertexPositions ()
{
  return (CATPolyGriddedPositions&) _GriddedVertexPositions;
}

#endif // !CATPolyGriddedMeshAndBars_H
