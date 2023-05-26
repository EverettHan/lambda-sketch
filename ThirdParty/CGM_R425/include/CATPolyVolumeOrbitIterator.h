// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVolumeOrbitIterator
//
//=============================================================================
// 2022-06-13  NDO
//=============================================================================
#pragma once

#include "CATPolyVolume.h"
#include "CATPolyVolumeOrbit.h"
#include "CATPolyCellOrbitIterator.h"


/**
 * Iterator through all the volume-orbits (3-orbits) of a CATPolyVolume.
 */
class CATPolyVolumeOrbitIterator : public CATPolyCellOrbitIterator
{

public:

  inline CATPolyVolumeOrbitIterator (CATPolyVolume* iVolume = 0) :
    CATPolyCellOrbitIterator (iVolume) {}

public:

  /**
   * Returns the current CATPolyVolumeOrbit.
   */
  inline CATPolyVolumeOrbit* GetOrbit ()
  {
    return (CATPolyVolumeOrbit*) CATPolyCellOrbitIterator::GetOrbit ();
  }
};
