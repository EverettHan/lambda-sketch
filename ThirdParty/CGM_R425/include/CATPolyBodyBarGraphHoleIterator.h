// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarGraphHoleIterator.h
//
//===================================================================
// May 2016  Creation: JXO
//===================================================================
#ifndef CATPolyBodyBarGraphHoleIterator_H
#define CATPolyBodyBarGraphHoleIterator_H

#include "PolyBodyDecimate.h"

// System
#include "CATBoolean.h"

class CATPolyBodyBarGraph;
class CATPolyBodyBarGraphHoleBarIterator;

/**
 * Iterates through button holes in a bar graph.
 * That means close boundary bars (given a tolerance) that would be stitched by CATPolyBodyStitcher.
 */
class ExportedByPolyBodyDecimate CATPolyBodyBarGraphHoleIterator
{
public:
  /** Destructor */
  virtual ~CATPolyBodyBarGraphHoleIterator();
  /* Returns number of button holes */
  virtual int Size() const = 0;
  /** Begin iteration */
  virtual CATPolyBodyBarGraphHoleIterator & Begin() = 0;
  /** Return TRUE if no more button holes in iterator, FALSE otherwise */
  virtual CATBoolean End() const = 0;
  /** Iterates */
  virtual CATPolyBodyBarGraphHoleIterator & operator ++() = 0;
  /**
   * Returns bars iterator on current button hole.
   * Lives as long as the CATPolyBodyBarGraphHoleIterator. Do not delete.
   */
  virtual CATPolyBodyBarGraphHoleBarIterator * GetBarIterator() = 0;
  /** Returns the computed hole width, that should be smaller than the tolerance given to the stitch operator */
  virtual double GetHoleWidth() = 0;

protected:
  CATPolyBodyBarGraphHoleIterator();
};

#endif
