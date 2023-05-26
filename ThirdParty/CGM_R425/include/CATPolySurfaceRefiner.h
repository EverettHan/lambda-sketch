// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySurfaceRefiner.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2007  Creation: ndo
//===================================================================
#ifndef CATPolySurfaceRefiner_h
#define CATPolySurfaceRefiner_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATBoolean.h"

#include "CATPolyCurveList.h"
#include "CATPolySurfaceRefinerData.h"
#include "CATSetOfIntegerSets.h"
#include "CATMapOfIntToInt.h"
#include "CATPolyRefinerDefaultParams.h"
#include "CATPolyUVRefinerParams.h"
#include "CATPolyUVRefiner.h"


class CATPolyUVRefiner;
class CATPolySurfaceBarTangentCache;
class CATIPolySurface;
class CATIPolyMesh;
class CATPolyBars;


// Refinement engine for CATIPolySurface of any type.
// THIS CLASS IS NOT THREAD SAFE AT ALL
// USE AN INSTANCE OF THIS CLASS PER THREAD
class  ExportedByPolyVizRefiners CATPolySurfaceRefiner 
{
public:

  /*
   * Constructor of a UV refiner engine for surfaces. 
   * RefinementType, RefinementLevelMax and iSag should be set through
   * the Setters.
   */
  CATPolySurfaceRefiner ();

  ~CATPolySurfaceRefiner ();

public:

  INLINE void DoComputeNormals (CATBoolean iDoComputeNormals);
  INLINE void DoComputeUVs (CATBoolean iDoComputeUVs);
  INLINE void SetSag(double sag);
  INLINE void SetRefinementType(CATPolyUVRefiner::RefinementType iRefinementType);
  INLINE void SetRefinementLevel(unsigned int level);

public:

  HRESULT Refine (const CATIPolySurface& iSurface,
                  const CATPolyCurveList& iCurves,
                  const CATPolyBars* iBars = 0);

  INLINE const CATPolySurfaceRefinerData& GetRefinerData () const;

  INLINE const CATSetOfIntegerSets& GetBarToRefinedVertexLayer () const;
  INLINE const CATMapOfIntToInt& GetVertexMapFromBaseMeshToRefinedMesh () const;

protected:

  CATPolySurfaceBarTangentCache* _TangentCache;
  CATPolySurfaceRefinerData _OutputData;  // Buffers for output refiner data.

  CATSetOfIntegerSets _BarToRefinedVertexLayer;
  CATMapOfIntToInt _MapVertexBaseMeshToRefinedMesh;

  CATPolyUVRefiner::RefinementType _RefinementType;
  double _Sag;
  unsigned int _RefinementLevel;
  CATBoolean _DoComputeNormals;
  CATBoolean _DoComputeUVs;

protected:

  HRESULT RefinePNTTriangleMesh (const CATIPolyMesh& iMesh,
                                 const CATPolyCurveList& iCurves,
                                 const CATPolyBars* iBars);

  HRESULT InitializeRefinerData (const CATIPolyMesh& iMesh0, const CATPolyBars& iBars0);

  inline CATBoolean IsRefinementAdaptive () const;

};


INLINE void CATPolySurfaceRefiner::DoComputeNormals (CATBoolean iDoComputeNormals)
{
  _DoComputeNormals = iDoComputeNormals;
}

INLINE void CATPolySurfaceRefiner::DoComputeUVs (CATBoolean iDoComputeUVs)
{
  _DoComputeUVs = iDoComputeUVs;
}

INLINE const CATPolySurfaceRefinerData& CATPolySurfaceRefiner::GetRefinerData () const
{
  return _OutputData;
}

INLINE const CATSetOfIntegerSets& CATPolySurfaceRefiner::GetBarToRefinedVertexLayer () const
{
  return _BarToRefinedVertexLayer;
}

INLINE const CATMapOfIntToInt& CATPolySurfaceRefiner::GetVertexMapFromBaseMeshToRefinedMesh () const
{
  return _MapVertexBaseMeshToRefinedMesh;
}

INLINE CATBoolean CATPolySurfaceRefiner::IsRefinementAdaptive () const
{
#ifdef CATIAR213
  return _RefinementType == CATPolyUVRefiner::eAdaptive || CATPolyUVRefiner::s_uv2;
#else
  return _RefinementType == CATPolyUVRefiner::eAdaptive;
#endif
}
INLINE void CATPolySurfaceRefiner::SetSag(double sag)
{
  _Sag = sag;
}
INLINE void CATPolySurfaceRefiner::SetRefinementType(CATPolyUVRefiner::RefinementType iRefinementType)
{
  _RefinementType = iRefinementType;
}
INLINE void CATPolySurfaceRefiner::SetRefinementLevel(unsigned int level)
{
  _RefinementLevel = level;
}

#endif

