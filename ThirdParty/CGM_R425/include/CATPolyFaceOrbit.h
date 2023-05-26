// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceOrbit
//
//=============================================================================
// 2018-12-03   NDO
//=============================================================================
#pragma once

#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyCellOrbit.h"
#include "CATPolyFace.h"


/**
 * A CATPolyFaceOrbit enables the retrieval of a connected set of cells that are incident to a CATPolyFace.
 * A CATPolyFace can have any number of orbits.
 * All methods are inline.
 */
class CATPolyFaceOrbit : public CATPolyCellOrbit
{

public:

  static inline CATPolyFaceOrbit* Cast (CATPolyCellOrbit* orbit);
  static inline const CATPolyFaceOrbit* Cast (const CATPolyCellOrbit* orbit);

  inline CATPolyFace* GetFace () const;

public:

  // Returns true if the face-orbit is open.
  // Its first dart is 0-free or 1-free.
  inline bool IsOpen () const;

protected:

  friend class CATPolyCell;
  friend class CATPolyDartHelpers;
  friend class CATPolyFaceOrbitIterator;
  template<class DART> friend class CATPolyFaceDartIterator;

  inline CATPolyFaceOrbit (CATPolyFace* iFace);
  inline ~CATPolyFaceOrbit () {}

private:

  // No copy constructor and assignment operator.
#ifndef _AIX_SOURCE
  CATPolyFaceOrbit () = delete;
  CATPolyFaceOrbit (const CATPolyFaceOrbit& iRHS) = delete;
  CATPolyFaceOrbit& operator = (const CATPolyFaceOrbit& iRHS) = delete;
#else
  CATPolyFaceOrbit () {}
  CATPolyFaceOrbit (const CATPolyFaceOrbit& iRHS) {}
  CATPolyFaceOrbit& operator = (const CATPolyFaceOrbit& iRHS) { return *this; }
#endif

  void* operator new (size_t s) { return ::operator new (s); }
  void* operator new (size_t, void* p) { return p; }
};


inline CATPolyFaceOrbit::CATPolyFaceOrbit (CATPolyFace* iFace) :
  CATPolyCellOrbit (iFace)
{
}

inline CATPolyFaceOrbit* CATPolyFaceOrbit::Cast (CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyFace::Cast (orbit->GetCell ()) ? (CATPolyFaceOrbit*)orbit : 0;
}

inline const CATPolyFaceOrbit* CATPolyFaceOrbit::Cast (const CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyFace::Cast (orbit->GetCell ()) ? (const CATPolyFaceOrbit*)orbit : 0;
}

inline CATPolyFace* CATPolyFaceOrbit::GetFace () const
{
  return (CATPolyFace*) GetCell ();
}

inline bool CATPolyFaceOrbit::IsOpen () const
{
  return Poly::IsOpen (*this);
}


// Temporary class.
// Encapsulates and behaves like a CATPolyFaceOrbit.
class CATPolyFaceOrbitRef : public CATPolyCellOrbitRef
{
public:
  inline CATPolyFaceOrbitRef (CATPolyFaceOrbit* orbit = 0) : CATPolyCellOrbitRef (orbit) {}

  inline CATPolyFaceOrbit* GetFaceOrbit () const
  {
    return (CATPolyFaceOrbit*) GetOrbit ();
  }

  inline bool IsOpen () const
  {
    return _Orbit ? Poly::IsOpen ((CATPolyFaceOrbit&)*_Orbit) : false;
  }
};
