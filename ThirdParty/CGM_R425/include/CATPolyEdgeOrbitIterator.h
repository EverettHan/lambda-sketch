// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyEdgeOrbitIterator
//
//=============================================================================
// 2022-12-19   NDO
//=============================================================================
#pragma once

#include "CATPolyEdge.h"
#include "CATPolyEdgeOrbit.h"
#include "CATPolyCellOrbitIterator.h"


/**
 * Iterator through all the edge-orbits (1-orbits) of a CATPolyEdge.
 */
class CATPolyEdgeOrbitIterator : public CATPolyCellOrbitIterator
{

public:

  inline CATPolyEdgeOrbitIterator (CATPolyEdge* iEdge = 0) :
    CATPolyCellOrbitIterator ((CATPolyCell*) iEdge) {}

public:

  /**
   * Returns the current CATPolyEdgeOrbit.
   */
  inline CATPolyEdgeOrbit* GetOrbit () const
  {
    return CATPolyEdgeOrbit::Cast (_Orbit);
  }

};
