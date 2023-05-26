// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarGraphHoleBarIterator.h
//
//===================================================================
// May 2016  Creation: JXO
//===================================================================
#ifndef CATPolyBodyBarGraphHoleBarIterator_H
#define CATPolyBodyBarGraphHoleBarIterator_H

#include "PolyBodyDecimate.h"

// Poly
#include "CATPolyBodyBarGraph.h"

// Math
#include "CATMathPoint.h"

// System
#include "CATBoolean.h"


class CATPolyBodyBarGraphHoleBarIteratorImpl;

/**
 * Iterates through the bars of a button hole in a bar graph.
 * That means close boundary bars (given a tolerance) that would be stitched by CATPolyBodyJoinDecimateBuilder.
 */
class ExportedByPolyBodyDecimate CATPolyBodyBarGraphHoleBarIterator
{
public:
  ~CATPolyBodyBarGraphHoleBarIterator();

public:
  /* Returns number of bars */
  int Size();
  /** Begin iteration */
  CATPolyBodyBarGraphHoleBarIterator & Begin();
  /** Return TRUE if no more bars in iterator, FALSE otherwise */
  CATBoolean End();
  /** Iterates */
  CATPolyBodyBarGraphHoleBarIterator & operator ++();

  unsigned int GetBarIndex();
  CATPolyBodyBarGraph::BarType GetBarType();
  unsigned int GetEdgeIndex();
  unsigned int GetFaceIndex();
  unsigned int GetNode0();
  unsigned int GetNode1();
  CATMathPoint GetNode0Position();
  CATMathPoint GetNode1Position();

private:
  friend class CATPolyBodyBarGraphHoleIteratorImpl;
  friend class CATPolyBodyStitcher;
  /** Becomes owner of the impl (will be deleted in destructor) */
  CATPolyBodyBarGraphHoleBarIterator(CATPolyBodyBarGraphHoleBarIteratorImpl & iIt);
  CATPolyBodyBarGraphHoleBarIteratorImpl & m_impl;
};

#endif
