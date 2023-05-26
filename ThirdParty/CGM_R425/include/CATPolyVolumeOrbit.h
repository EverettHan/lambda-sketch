// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVolumeOrbit
//
//=============================================================================
// 2022-06-10   NDO
//=============================================================================
#pragma once

#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyCellOrbit.h"
#include "CATPolyVolume.h"


/**
 * A CATPolyVolumeOrbit enables the retrieval of a connected set of cells that are incident to a CATPolyVolume.
 * A CATPolyVolume can have any number of orbits.
 * All methods are inline.
 */
class CATPolyVolumeOrbit : public CATPolyCellOrbit
{

public:

  static inline CATPolyVolumeOrbit* Cast (CATPolyCellOrbit* orbit);
  static inline const CATPolyVolumeOrbit* Cast (const CATPolyCellOrbit* orbit);

  inline CATPolyVolume* GetVolume () const;

public:

/** @name Orientation
    @{ */

  /**
   * Sets the relative orientation of a face w.r.t. the volume.
   */
  inline void SetRelativeOrientation (CATPolyFaceOrbit& iFaceOrbit, int iOrientation);

  /**
   * Gets the relative orientation of a face w.r.t. the volume.
   */
  inline int GetRelativeOrientation (CATPolyFaceOrbit& iFaceOrbit) const;

/** @} */

protected:

  friend class CATPolyCell;
  friend class CATPolyDartHelpers;
  friend class CATPolyVolumeOrbitIterator;
  template<class DART> friend class CATPolyVolumeDartIterator;

  // Reserved for friend classes.
  inline CATPolyVolumeOrbit (CATPolyVolume* iVolume);
  inline ~CATPolyVolumeOrbit () {}

private:

  // No copy constructor and assignment operator.
#ifndef _AIX_SOURCE
  CATPolyVolumeOrbit () = delete;
  CATPolyVolumeOrbit (const CATPolyVolumeOrbit& iRHS) = delete;
  CATPolyVolumeOrbit& operator = (const CATPolyVolumeOrbit& iRHS) = delete;
#else
  CATPolyVolumeOrbit () {}
  CATPolyVolumeOrbit (const CATPolyVolumeOrbit& iRHS) {}
  CATPolyVolumeOrbit& operator = (const CATPolyVolumeOrbit& iRHS) { return *this; }
#endif

  void* operator new (size_t s) { return ::operator new (s); }
  void* operator new (size_t, void* p) { return p; }
};


inline CATPolyVolumeOrbit::CATPolyVolumeOrbit (CATPolyVolume* iVolume) :
  CATPolyCellOrbit (iVolume)
{
}

inline CATPolyVolumeOrbit* CATPolyVolumeOrbit::Cast (CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyVolume::Cast (orbit->GetCell ()) ? (CATPolyVolumeOrbit*)orbit : 0;
}

inline const CATPolyVolumeOrbit* CATPolyVolumeOrbit::Cast (const CATPolyCellOrbit* orbit)
{
  return orbit && CATPolyVolume::Cast (orbit->GetCell ()) ? (const CATPolyVolumeOrbit*)orbit : 0;
}

inline CATPolyVolume* CATPolyVolumeOrbit::GetVolume () const
{
  return (CATPolyVolume*) GetCell ();
}

inline void CATPolyVolumeOrbit::SetRelativeOrientation (CATPolyFaceOrbit& iFaceOrbit, int iOrientation)
{
  CATPolyCellOrbit::SetRelativeOrientation (iFaceOrbit, *this, iOrientation);
}

inline int CATPolyVolumeOrbit::GetRelativeOrientation (CATPolyFaceOrbit& iFaceOrbit) const
{
  return CATPolyCellOrbit::GetRelativeOrientation (iFaceOrbit, *this);
}


// Temporary class.
// Encapsulates and behaves like a CATPolyVolumeOrbit.
class CATPolyVolumeOrbitRef : public CATPolyCellOrbitRef
{
public:
  inline CATPolyVolumeOrbitRef (CATPolyVolumeOrbit* orbit = 0) : CATPolyCellOrbitRef (orbit) {}
};
