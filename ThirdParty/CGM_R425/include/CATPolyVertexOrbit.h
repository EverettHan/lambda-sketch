// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVertexOrbit
//
//=============================================================================
// 2009-11-03   NDO: Revisited implementation, optimizations
// 2007-01-03   BPG: New
//=============================================================================
#pragma once

#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyCellOrbit.h"
#include "CATPolyVertex.h"


// Orbit of darts around a CATPolyVertex.
// A vertex can have one or several orbits (pseudo-manifold vertices).
// All the methods are inline.
class CATPolyVertexOrbit : public CATPolyCellOrbit
{

public:

  static inline CATPolyVertexOrbit* Cast (CATPolyCellOrbit* orbit);
  static inline const CATPolyVertexOrbit* Cast (const CATPolyCellOrbit* orbit);

  inline CATPolyVertex* GetVertex () const;

protected:

  friend class CATPolyCell;
  friend class CATPolyDartHelpers;
  friend class CATPolyVertexOrbitIterator;
  template<class DART> friend class CATPolyVertexDartIterator;

  inline CATPolyVertexOrbit (CATPolyVertex* iVertex);
  inline ~CATPolyVertexOrbit () {}

private:

  // No copy constructor and assignment operator.
#ifndef _AIX_SOURCE
  CATPolyVertexOrbit () = delete;
  CATPolyVertexOrbit (const CATPolyVertexOrbit& iRHS) = delete;
  CATPolyVertexOrbit& operator = (const CATPolyVertexOrbit& iRHS) = delete;
#else
  CATPolyVertexOrbit () {}
  CATPolyVertexOrbit (const CATPolyVertexOrbit& iRHS) {}
  CATPolyVertexOrbit& operator = (const CATPolyVertexOrbit& iRHS) { return *this; }
#endif

  //void* operator new (size_t s) { return ::operator new (s); }
  //void* operator new (size_t, void* p) { return p; }
};


inline CATPolyVertexOrbit::CATPolyVertexOrbit (CATPolyVertex* iVertex) :
  CATPolyCellOrbit (iVertex)
{
}

inline CATPolyVertexOrbit* CATPolyVertexOrbit::Cast (CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyVertex::Cast (orbit->GetCell ()) ? (CATPolyVertexOrbit*)orbit : 0;
}

inline const CATPolyVertexOrbit* CATPolyVertexOrbit::Cast (const CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyVertex::Cast (orbit->GetCell ()) ? (const CATPolyVertexOrbit*)orbit : 0;
}

inline CATPolyVertex* CATPolyVertexOrbit::GetVertex () const
{
  return (CATPolyVertex*) GetCell ();
}


// Temporary class.
// Encapsulates and behaves like a CATPolyVertexOrbit.
class CATPolyVertexOrbitRef : public CATPolyCellOrbitRef
{
public:
  inline CATPolyVertexOrbitRef (CATPolyVertexOrbit* orbit = 0) : CATPolyCellOrbitRef (orbit) {}
};
