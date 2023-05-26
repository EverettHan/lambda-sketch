// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyVertexOrbitIterator
//
//=============================================================================
// 2022-12-19   NDO
//=============================================================================
#pragma once

#include "CATPolyVertex.h"
#include "CATPolyVertexOrbit.h"
#include "CATPolyCellOrbitIterator.h"


/**
 * Iterator through all the vertex-orbits (0-orbits) of a CATPolyVertex.
 */
class CATPolyVertexOrbitIterator : public CATPolyCellOrbitIterator
{

public:

  inline CATPolyVertexOrbitIterator (CATPolyVertex* iVertex = 0) :
    CATPolyCellOrbitIterator ((CATPolyCell*) iVertex) {}

public:

  /**
   * Returns the current CATPolyVertexOrbit.
   */
  inline CATPolyVertexOrbit* GetOrbit () const
  {
    return CATPolyVertexOrbit::Cast (_Orbit);
  }

};
