// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyEdgeOrbit
//
//=============================================================================
// 2009-11-03   NDO: Revisited implementation, optimizations
// 2007-01-03   BPG: New
//=============================================================================
#pragma once

#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyCellOrbit.h"
#include "CATPolyEdge.h"


// Orbit of darts around a CATPolyEdge.
// An edge can have one or several orbits (manifold edges).
// All the methods are inline.
class CATPolyEdgeOrbit : public CATPolyCellOrbit
{

public:

  static inline CATPolyEdgeOrbit* Cast (CATPolyCellOrbit* orbit);
  static inline const CATPolyEdgeOrbit* Cast (const CATPolyCellOrbit* orbit);

  inline CATPolyEdge* GetEdge () const;

public:   // private ?

/** @name Orientation
    @{ */

  /**
   * Sets the flag for a start-vertex reference.
   */
  inline void SetReferToStartVertex (bool b);

  /**
   * Sets the flag for an end-vertex reference.
   */
  inline void SetReferToEndVertex (bool b);

  /**
   * Returns true if the edge-orbit refers to a start vertex.
   */
  inline bool ReferToStartVertex () const;

  /**
   * Returns true if the edge-orbit refers to an end vertex.
   */
  inline bool ReferToEndVertex () const;

/** @} */

protected:

  friend class CATPolyCell;
  friend class CATPolyDartHelpers;
  friend class CATPolyEdgeOrbitIterator;
  template<class DART> friend class CATPolyEdgeDartIterator;

  inline CATPolyEdgeOrbit (CATPolyEdge* iEdge);
  inline ~CATPolyEdgeOrbit () {}

private:

  // No copy constructor and assignment operator.
#ifndef _AIX_SOURCE
  CATPolyEdgeOrbit () = delete;
  CATPolyEdgeOrbit (const CATPolyEdgeOrbit& iRHS) = delete;
  CATPolyEdgeOrbit& operator = (const CATPolyEdgeOrbit& iRHS) = delete;
#else
  CATPolyEdgeOrbit () {}
  CATPolyEdgeOrbit (const CATPolyEdgeOrbit& iRHS) {}
  CATPolyEdgeOrbit& operator = (const CATPolyEdgeOrbit& iRHS) { return *this; }
#endif

  void* operator new (size_t s) { return ::operator new (s); }
  void* operator new (size_t, void* p) { return p; }
};


inline CATPolyEdgeOrbit::CATPolyEdgeOrbit (CATPolyEdge* iEdge) :
  CATPolyCellOrbit (iEdge)
{
}

inline CATPolyEdgeOrbit* CATPolyEdgeOrbit::Cast (CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyEdge::Cast (orbit->GetCell ()) ? (CATPolyEdgeOrbit*)orbit : 0;
}

inline const CATPolyEdgeOrbit* CATPolyEdgeOrbit::Cast (const CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyEdge::Cast (orbit->GetCell ()) ? (const CATPolyEdgeOrbit*)orbit : 0;
}

inline CATPolyEdge* CATPolyEdgeOrbit::GetEdge () const
{
  return (CATPolyEdge*) GetCell ();
}

inline void CATPolyEdgeOrbit::SetReferToStartVertex (bool b)
{
  _Orientation[0][0] = b;
}

inline void CATPolyEdgeOrbit::SetReferToEndVertex (bool b)
{
  _Orientation[1][0] = b;
}

inline bool CATPolyEdgeOrbit::ReferToStartVertex () const
{
  return _Orientation[0][0];
}

inline bool CATPolyEdgeOrbit::ReferToEndVertex () const
{
  return _Orientation[1][0];
}


// Temporary class.
// Encapsulates and behaves like a CATPolyFaceOrbit.
class CATPolyEdgeOrbitRef : public CATPolyCellOrbitRef
{
public:
  inline CATPolyEdgeOrbitRef (CATPolyEdgeOrbit* orbit = 0) : CATPolyCellOrbitRef (orbit) {}
};
