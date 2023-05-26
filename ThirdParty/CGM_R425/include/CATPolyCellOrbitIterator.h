// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyCellOrbitIterator
//
//=============================================================================
// 2022-03-02   NDO: New
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyCellOrbit.h"
#include "CATPolyCell.h"


/**
 * Iterator through all the distinct orbits associated to a CATPolyCell.
 * See also CATPolyCellOrbit.
 * For example:
 *   * 0-orbits around a vertex;
 *   * 1-orbits around an edge;
 *   * 2-orbits around a face;
 *   * 3-orbits around a volume.
 * All methods are inline.
 */
class ExportedByPolyMODEL CATPolyCellOrbitIterator
{

public:

  inline CATPolyCellOrbitIterator (CATPolyCell* iCell = 0);
  inline CATPolyCellOrbitIterator (const CATPolyCellOrbitIterator& iRHS);
  inline ~CATPolyCellOrbitIterator ();

public:

  CATPolyCellOrbitIterator& Begin (CATPolyCell* iCell);
  inline bool End () const;
  inline CATPolyCellOrbitIterator& operator++ ();

public:

  /**
   * Returns the current cell-orbit.
   */
  inline CATPolyCellOrbit* GetOrbit () const;

  inline CATPolyCellOrbitRef GetRef () const;

  // To get rid in this class.
  inline CATPolyCell* GetCell () const;

protected:

  CATPolyCellOrbit* _Orbit;

};

inline CATPolyCellOrbitIterator::CATPolyCellOrbitIterator (CATPolyCell* iCell) :
  _Orbit (0)
{
  Begin (iCell);
}

inline CATPolyCellOrbitIterator::CATPolyCellOrbitIterator (const CATPolyCellOrbitIterator& iRHS)
{
  _Orbit = iRHS._Orbit;
}

inline CATPolyCellOrbitIterator::~CATPolyCellOrbitIterator ()
{
  _Orbit = 0;
}

inline bool CATPolyCellOrbitIterator::End () const
{
  return _Orbit == 0;
}

inline CATPolyCellOrbitIterator& CATPolyCellOrbitIterator::operator++ ()
{
  if (_Orbit)
    _Orbit = _Orbit->GetNext ();
  return *this;
}

inline CATPolyCellOrbit* CATPolyCellOrbitIterator::GetOrbit () const
{
  return _Orbit;
}

inline CATPolyCellOrbitRef CATPolyCellOrbitIterator::GetRef () const
{
  return CATPolyCellOrbitRef (_Orbit);
}

inline CATPolyCell* CATPolyCellOrbitIterator::GetCell () const
{
  return _Orbit ? _Orbit->GetCell () : 0;
}
