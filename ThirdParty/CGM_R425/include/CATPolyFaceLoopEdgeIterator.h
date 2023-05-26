// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyFaceLoopEdgeIterator
//
//=============================================================================
// May 2019 - NDO
//=============================================================================
#pragma once

#include "CATPolyFaceOrbitEdgeIterator.h"
#include "CATPolyFaceLoop.h"


/**
 * Iterator through all the edges around a face loop.
 * This iterator cycles through the edges around the loop once and only once.
 */
class CATPolyFaceLoopEdgeIterator : public CATPolyFaceOrbitEdgeIterator
{

public:

  inline CATPolyFaceLoopEdgeIterator (const CATPolyFaceOrbit* orbit = 0) : CATPolyFaceOrbitEdgeIterator (orbit) {}

  inline CATPolyFaceLoopEdgeIterator (const CATPolyFaceLoop* L) : CATPolyFaceOrbitEdgeIterator (L ? L->GetFaceOrbit () : 0) {}

};
