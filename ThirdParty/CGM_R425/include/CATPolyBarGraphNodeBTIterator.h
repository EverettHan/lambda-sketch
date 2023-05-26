// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarGraphNodeBTIterator.h
//
//===================================================================
// September 2011  Creation NDO
//===================================================================
#ifndef CATPolyBarGraphNodeBTIterator_H
#define CATPolyBarGraphNodeBTIterator_H

#include "CATBoolean.h"
#include "CATPolyBarGraphNode.h"


/**
 * Iterates through all the bars or tags (TOF, TOC) associated to a node.
 */
class CATPolyBarGraphNodeBTIterator
{

public:

  inline CATPolyBarGraphNodeBTIterator (const CATPolyBarGraphNode& N) : _Node (N), _Index (0) {}

  ~CATPolyBarGraphNodeBTIterator () {}

public:

  inline CATPolyBarGraphNodeBTIterator& Begin () {_Index = 0; return *this;}
  inline CATBoolean End () const {return _Index >= _Node._Count;}
  inline CATPolyBarGraphNodeBTIterator& operator++ () {++_Index; return *this;}

  inline unsigned int operator* () const {return _Node.GetBarOrTag (_Index);}
  inline unsigned int Size() const { return _Node.GetNbBars(); }; // /!\ : O(N) at worse

private:

  const CATPolyBarGraphNode& _Node;
  unsigned int _Index;

};

#endif
