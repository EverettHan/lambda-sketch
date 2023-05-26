// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarGraphNodeBarIterator.h
//
//===================================================================
// September 2011  Creation NDO
//===================================================================
#ifndef CATPolyBarGraphNodeBarIterator_H
#define CATPolyBarGraphNodeBarIterator_H

#include "PolyBarGraph.h"
#include "CATBoolean.h"
#include "CATPolyBarGraphNodeBTIterator.h"

class CATPolyBarGraph;

/**
 * Iterates through all the bars adjacent to a node.
 */
class ExportedByPolyBarGraph CATPolyBarGraphNodeBarIterator : public CATPolyBarGraphNodeBTIterator
{
public:

  CATPolyBarGraphNodeBarIterator (const CATPolyBarGraph& iBarGraph, const unsigned int iNode);
  CATPolyBarGraphNodeBarIterator& operator++ ();
};

#endif
