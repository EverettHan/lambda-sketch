// COPYRIGHT DASSAULT SYSTEMES 2007-2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRefinerTSurfaceTessPoint.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2007  Creation: ndo
//===================================================================
#ifndef CATPolyRefinerTSurfaceTessPoint_H
#define CATPolyRefinerTSurfaceTessPoint_H

#include "PolyVizRefiners.h"
#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"

class CATPolyMathTriangleSurface;


class ExportedByPolyVizRefiners CATPolyRefinerTSurfaceTessPoint
{

public:

  // Watch: Tessellation points are not initialized with this constructor!
  CATPolyRefinerTSurfaceTessPoint () {}
  ~CATPolyRefinerTSurfaceTessPoint () {}

  void Init ();

public:

  inline void SetU (const unsigned int iu);
  inline void SetV (const unsigned int iv);
  inline void SetW (const unsigned int iw);

  inline unsigned int GetU () const;
  inline unsigned int GetV () const;
  inline unsigned int GetW () const;

  // Return the u, v, w associated to the point.
  // The three values returned are between 0 and 1.
  void GetUVW (double uvw[]) const;

  inline CATMathPoint& Point ();
  inline const CATMathPoint& Point () const;

  inline CATMathVector& Normal ();
  inline const CATMathVector& Normal () const;

public:

  void Evaluate (const CATPolyMathTriangleSurface& iPatch);

public:

  inline int IsTessellationPoint () const;
  inline int IsPointEvaluated () const;

  inline void SetTessellationPoint () ;
  inline void SetPointEvaluated () ;

protected:

  unsigned int _U : 8;
  unsigned int _V : 8;
  unsigned int _W : 8;
  unsigned int _Flags : 8;

  CATMathPoint _P;
  CATMathVector _N;

};


inline void CATPolyRefinerTSurfaceTessPoint::SetU (const unsigned int iu)
{
  _U = iu;
}

inline void CATPolyRefinerTSurfaceTessPoint::SetV (const unsigned int iv)
{
  _V = iv;
}

inline void CATPolyRefinerTSurfaceTessPoint::SetW (const unsigned int iw)
{
  _W = iw;
}

inline unsigned int CATPolyRefinerTSurfaceTessPoint::GetU () const
{
  return _U;
}

inline unsigned int CATPolyRefinerTSurfaceTessPoint::GetV () const
{
  return _V;
}

inline unsigned int CATPolyRefinerTSurfaceTessPoint::GetW () const
{
  return _W;
}

inline CATMathPoint& CATPolyRefinerTSurfaceTessPoint::Point ()
{
  return _P;
}

inline const CATMathPoint& CATPolyRefinerTSurfaceTessPoint::Point () const
{
  return _P;
}

inline CATMathVector& CATPolyRefinerTSurfaceTessPoint::Normal ()
{
  return _N;
}

inline const CATMathVector& CATPolyRefinerTSurfaceTessPoint::Normal () const
{
  return _N;
}

inline int CATPolyRefinerTSurfaceTessPoint::IsTessellationPoint () const
{
  return _Flags & 0x01; 
}

inline int CATPolyRefinerTSurfaceTessPoint::IsPointEvaluated () const
{
  return _Flags & 0x02; 
}

inline void CATPolyRefinerTSurfaceTessPoint::SetTessellationPoint () 
{
  _Flags |= 0x01;
}

inline void CATPolyRefinerTSurfaceTessPoint::SetPointEvaluated () 
{
  _Flags |= 0x02;
}

#endif
