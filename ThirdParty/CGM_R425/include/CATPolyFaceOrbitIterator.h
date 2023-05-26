// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceOrbitIterator
//
//=============================================================================
// 2009-11-19   NDO
//=============================================================================
#pragma once

#include "CATPolyFace.h"
#include "CATPolyFaceOrbit.h"
#include "CATPolyCellOrbitIterator.h"


/**
 * Iterator through all the face-orbits (2-orbits) of a CATPolyFace.
 */
class CATPolyFaceOrbitIterator : public CATPolyCellOrbitIterator
{

public:

  inline CATPolyFaceOrbitIterator (CATPolyFace* iFace = 0) :
    CATPolyCellOrbitIterator (iFace) {}

public:

  /**
   * Returns the current CATPolyFaceOrbit.
   */
  inline CATPolyFaceOrbit* GetOrbit () const
  {
    return (CATPolyFaceOrbit*) CATPolyCellOrbitIterator::GetOrbit ();
  }

};
