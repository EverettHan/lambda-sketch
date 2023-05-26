// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessPointOnEdgeCache.h
//
//===================================================================
//
// Nov 2012  Creation: TPG
//===================================================================

#ifndef CATTessPointOnEdgeCache_H
#define CATTessPointOnEdgeCache_H

#include "TessDiscretize.h"
#include "CATMathPoint.h"
#include "CATMathSetOfPointsND.h"

class ExportedByTessDiscretize CATTessPointOnEdgeCache
{
public:
  CATTessPointOnEdgeCache(double iGlobalParameter);
  ~CATTessPointOnEdgeCache();

public:

inline double GetGlobalParameter() const
{
  return _GlobalParameter;
}
inline void SetSpacePoint(CATMathPoint & iPt)
{
  _Pt = iPt;
}
inline void GetSpacePoint(CATMathPoint & oPt) const
{
  oPt = _Pt;
}
inline void SetPointsOnSurface(int iIdx, double iU, double iV, double iWidthU, double iWidthV, double iNormal[3])
{
  double PointsOnSurface[7] = {iU, iV, iWidthU, iWidthV, iNormal[0], iNormal[1], iNormal[2]};
  _ArrayPointsOnSurface->InsertPoint (PointsOnSurface, iIdx);
}
inline void GetPointsOnSurface(int iIdx, double & oU, double & oV, double & oWidthU, double & oWidthV, double oNormal[3]) const
{
  double PointsOnSurface[7] = {};
  _ArrayPointsOnSurface->GetPoint (iIdx, PointsOnSurface);
  oU = PointsOnSurface[0];
  oV = PointsOnSurface[1];
  oWidthU = PointsOnSurface[2];
  oWidthV = PointsOnSurface[3];
  oNormal[0] = PointsOnSurface[4];
  oNormal[1] = PointsOnSurface[5];
  oNormal[2] = PointsOnSurface[6];
}
inline void SetPrevious(CATTessPointOnEdgeCache * iPrev)
{
  _Prev = iPrev;
}
inline CATTessPointOnEdgeCache * GetPrevious() const
{
  return _Prev;
}
inline void SetNext(CATTessPointOnEdgeCache * iNext)
{
  _Next = iNext;
}
inline CATTessPointOnEdgeCache * GetNext() const
{
  return _Next;
}

protected:
  double _GlobalParameter;
  CATMathPoint _Pt;
  CATMathSetOfPointsND * _ArrayPointsOnSurface; // U,V,WidthU,WidthV,Normal
  CATTessPointOnEdgeCache * _Prev;
  CATTessPointOnEdgeCache * _Next;
};

#endif
