// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyCellOrbit
//
//=============================================================================
// 2009-11-20   NDO
//=============================================================================
#pragma once

#include <stdlib.h>  // size_t

template<size_t N> class CATPolyDart;
#ifndef _AIX_SOURCE
using CATPolyDart2 = CATPolyDart<2>;
using CATPolyDart3 = CATPolyDart<3>;
#else
typedef CATPolyDart<2> CATPolyDart2;
typedef CATPolyDart<3> CATPolyDart3;
#endif

class CATPolyCell;
class CATPolyFaceOrbit;
class CATPolyVolumeOrbit;


namespace Poly
{
  /**
   * Qualifier of a cell-orbit within a cell.
   *   * Outer
   *     An outer orbit identifies the outer boundary of a cell.
   *   * Inner
   *     An inner orbit identifies an inner boundary of a cell.
   *   * Full
   *     A full orbit does not identify a boundary of a cell.
   */
  enum OrbitQualifier
  {
    /* None */                 NoQualifier = 0x00,
    /* Outer */                Outer = 0x01,
    /* Inner */                Inner = 0x02,
    /* Full */                 Full = 0x03
  };
}


/**
 * A CATPolyCellOrbit enables the retrieval of a connected set of cells that are incident to a CATPolyCell.
 * Internally, it is used to find all the darts following all the alpha-j involutions with j different of i, 
 * the dimension of the cell.
 * 
 * The cell orbits are:
 *   * CATPolyVertexOrbit from a CATPolyVertex
 *   * CATPolyEdgeOrbit from a CATPolyEdge
 *   * CATPolyFaceOrbit from a CATPolyFace
 *   * CATPolyVolumeOrbit from a CATPolyVolume
 * 
 * A CATPolyCell can have any number of orbits.
 */
class CATPolyCellOrbit
{

public:

  inline CATPolyCell* GetCell () const;

  /**
   * Returns true when the orbit has been declared as an outer orbit.
   */
  inline bool IsOuter () const;

  /**
   * Returns true when the orbit has been declared as an inner orbit.
   */
  inline bool IsInner () const;

  /**
   * Returns true when the orbit has been declared as a full orbit.
   */
  inline bool IsFull () const;

  /**
   * Returns the cell-qualifier for this orbit:
   *   * Outer
   *   * Inner
   *   * Full
   */
  inline Poly::OrbitQualifier GetQualifier () const;

protected:

  union Dart
  { // CATPolyDart<2> or CATPolyDart<3>
    CATPolyDart2* _Dart2;
    CATPolyDart3* _Dart3;
  };

  CATPolyCell* _Cell;  // The cell of the orbit.
  Dart _Dart;  // A dart from the orbit.
  CATPolyCellOrbit* _Next;  // Next orbit.

  bool _Minimal;
  bool _Orientation[2][2];  // Relative orientation w.r.t. the incident cells (up to 2).
  bool _Qualifier[2];

  friend class CATPolyBody;
  friend class CATPolyCell;
  friend class CATPolyCellOrbitRef;
  friend class CATPolyCellOrbitIterator;
  friend class CATPolyBodyHelpers;
  friend class CATPolyDartHelpers;
  template<class DART, size_t K> friend class CATPolyCellOrbitObserver;

  inline CATPolyCellOrbit (CATPolyCell* iCell = 0);
  inline ~CATPolyCellOrbit ();

  static void SetRelativeOrientation (CATPolyFaceOrbit& iFaceOrbit, const CATPolyVolumeOrbit& iVolumeOrbit, int iOrientation);

  static int GetRelativeOrientation (const CATPolyFaceOrbit& iFaceOrbit, const CATPolyVolumeOrbit& iVolumeOrbit);

private:

  template<class DART>
  void SetDart (DART* d, bool iMinimal = false);

  template<class DART>
  inline DART* GetDart () const;

  inline bool HasMinimalDart () const;

  inline void UnsetMinimalDart ();

  inline void SetQualifier (Poly::OrbitQualifier iQualifier);

  inline void SetNext (CATPolyCellOrbit* orbit);

  inline CATPolyCellOrbit* GetNext () const;

  inline CATPolyCellOrbit& operator = (const CATPolyCellOrbit& iRHS);

  /**
   * Resets the relative orientation to an undefined value.
   * The orientation can be set for one or two cells.
   */
  inline void ResetOrientation (bool index);

  inline bool IsOrientationSet (bool index) const;

  /**
   * Sets the relative orientation (positive, negative or null) of this cell w.r.t. an incident cell of dimension K+1.
   * The orientation can be set for one or two cells.
   */
  inline void SetOrientation (bool index, int iOrientation);

  /**
   * Gets the relative orientation (positive, negative or null) of this cell w.r.t. an incident cell of dimension K+1.
   */
  inline int GetOrientation (bool index) const;

private:

  // No copy constructor.
#ifndef _AIX_SOURCE
  CATPolyCellOrbit (const CATPolyCellOrbit& iRHS) = delete;
#else
  CATPolyCellOrbit (const CATPolyCellOrbit& iRHS) {}
#endif

  //void* operator new (size_t s) { return ::operator new (s); }
  //void* operator new (size_t, void* p) { return p; }
};

inline CATPolyCellOrbit::CATPolyCellOrbit (CATPolyCell* iCell)
{
  _Cell = iCell;
  _Dart._Dart2 = 0;
  _Next = 0;
  _Minimal = false;
  _Orientation[0][0] = false;
  _Orientation[0][1] = false;
  _Orientation[1][0] = false;
  _Orientation[1][1] = false;
  _Qualifier[0] = false;
  _Qualifier[1] = false;
}

inline CATPolyCellOrbit::~CATPolyCellOrbit ()
{
  _Cell = 0;
  _Dart._Dart2 = 0;
  _Next = 0;
}

inline CATPolyCellOrbit& CATPolyCellOrbit::operator = (const CATPolyCellOrbit& iRHS)
{
  _Cell = iRHS._Cell;
  _Dart = iRHS._Dart;
  _Next = iRHS._Next;
  _Minimal = iRHS._Minimal;
  _Orientation[0][0] = iRHS._Orientation[0][0];
  _Orientation[0][1] = iRHS._Orientation[0][1];
  _Orientation[1][0] = iRHS._Orientation[1][0];
  _Orientation[1][1] = iRHS._Orientation[1][1];
  _Qualifier[0] = iRHS._Qualifier[0];
  _Qualifier[1] = iRHS._Qualifier[1];
  return *this;
}


inline CATPolyCell* CATPolyCellOrbit::GetCell () const
{
  return _Cell;
}

inline bool CATPolyCellOrbit::IsOuter () const
{
  return _Qualifier[0] && !_Qualifier[1];
}

inline bool CATPolyCellOrbit::IsInner () const
{
  return !_Qualifier[0] && _Qualifier[1];
}

inline bool CATPolyCellOrbit::IsFull () const
{
  return _Qualifier[0] && _Qualifier[1];
}

inline Poly::OrbitQualifier CATPolyCellOrbit::GetQualifier () const
{
  if (_Qualifier[0])
    return _Qualifier[1] ? Poly::Full : Poly::Outer;
  else
    return _Qualifier[1] ? Poly::Inner : Poly::NoQualifier;
}

template<>
inline CATPolyDart2* CATPolyCellOrbit::GetDart<CATPolyDart2> () const
{
  return _Dart._Dart2;
}

template<>
inline CATPolyDart3* CATPolyCellOrbit::GetDart<CATPolyDart3> () const
{
  return _Dart._Dart3;
}

inline bool CATPolyCellOrbit::HasMinimalDart () const
{
  return _Minimal;
}

inline void CATPolyCellOrbit::UnsetMinimalDart ()
{
  _Minimal = false;
}

inline void CATPolyCellOrbit::ResetOrientation (bool index)
{
  _Orientation[index][0] = false;
  _Orientation[index][1] = false;
}

inline bool CATPolyCellOrbit::IsOrientationSet (bool index) const
{
  return _Orientation[index][0] || _Orientation[index][1];
}

inline void CATPolyCellOrbit::SetOrientation (bool index, int iOrientation)
{
  if (iOrientation > 0)
  {
    _Orientation[index][0] = true;
    _Orientation[index][1] = false;
  }
  else if (iOrientation < 0)
  {
    _Orientation[index][0] = false;
    _Orientation[index][1] = true;
  }
  else // (iOrientation == 0)
  {
    _Orientation[index][0] = true;
    _Orientation[index][1] = true;
  }
}

inline int CATPolyCellOrbit::GetOrientation (bool index) const
{
  if (_Orientation[index][0] && !_Orientation[index][1])
    return 1;
  else if (!_Orientation[index][0] && _Orientation[index][1])
    return -1;
  else
    return 0;
}

inline void CATPolyCellOrbit::SetQualifier (Poly::OrbitQualifier iQualifier)
{
  switch (iQualifier)
  {
  case Poly::Outer:
    _Qualifier[0] = true;
    _Qualifier[1] = false;
    return;
  case Poly::Inner:
    _Qualifier[0] = false;
    _Qualifier[1] = true;
    return;
  case Poly::Full:
    _Qualifier[0] = true;
    _Qualifier[1] = true;
    return;
  default:
    _Qualifier[0] = false;
    _Qualifier[1] = false;
  }
}

inline void CATPolyCellOrbit::SetNext (CATPolyCellOrbit* orbit)
{
  _Next = orbit;
}

inline CATPolyCellOrbit* CATPolyCellOrbit::GetNext () const
{
  return _Next;
}


// Temporary class.
// Encapsulates and behaves like a CATPolyCellOrbit.
class CATPolyCellOrbitRef
{

public:

  inline CATPolyCellOrbitRef (CATPolyCellOrbit* orbit = 0) { _Orbit = orbit; }
  inline CATPolyCellOrbitRef (const CATPolyCellOrbitRef& iRHS) { _Orbit = iRHS._Orbit; }  // Copy constructor.

  inline ~CATPolyCellOrbitRef () { _Orbit = 0; }

  // Assignment operator.
  inline CATPolyCellOrbitRef& operator = (const CATPolyCellOrbitRef& iRHS) { _Orbit = iRHS._Orbit; return *this; }

  inline bool operator == (const CATPolyCellOrbitRef& iRHS) const { return _Orbit == iRHS._Orbit; }

  inline CATPolyCellOrbit* GetOrbit () const { return _Orbit; }

  inline CATPolyCell* GetCell () const { return _Orbit ? _Orbit->GetCell () : 0; }

protected:

  CATPolyCellOrbit* _Orbit;

};
