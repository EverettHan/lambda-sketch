// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATVizVertexBufferRepViz3DEdgeOrLineIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CATVizVertexBufferRepViz3DEdgeOrLineIterator_H
#define CATVizVertexBufferRepViz3DEdgeOrLineIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATVizVertexBufferRep;
class CATVizPrimitiveSet;
class CATVizPrimitive;
class CATViz3DEdge;
class CATViz3DLine;


/**
 * Iterates through all the CATViz3DEdge or CATViz3DLine viz primitives from a CATVizVertexBufferRep.
 */
class ExportedByPolyVizUtils CATVizVertexBufferRepViz3DEdgeOrLineIterator
{

public:

  CATVizVertexBufferRepViz3DEdgeOrLineIterator (CATVizVertexBufferRep& iRep);
  ~CATVizVertexBufferRepViz3DEdgeOrLineIterator () {_VizSet = 0;}

  /**
   * Returns the number of iterations.
   */
  unsigned int Count () const;

public:

  inline CATVizVertexBufferRepViz3DEdgeOrLineIterator& Begin ();
  inline CATBoolean End () const;
  CATVizVertexBufferRepViz3DEdgeOrLineIterator& operator++ ();

public:

  CATVizPrimitive* GetVizPrimitive () const;

  CATViz3DEdge* GetVizEdge ();
  CATViz3DLine* GetVizLine ();

private:

  CATVizVertexBufferRep& _Rep;

  enum Type
  {
    eUnknown         = 0x0000,
    eVizEdge         = 0x0010,
    eVizLine         = 0x1000
  };

  enum IterationScope
  {
    eThroughEdges          = 1,
    eThroughBoundaries     = 2,
    eThroughSharpEdges     = 3,
    eThroughSmoothEdges    = 4,
    eThroughWireEdges      = 5
  };

  CATVizPrimitiveSet* _VizSet;

  unsigned int _Index;
  unsigned int _Count;

  IterationScope _Scope;
  Type _Type;

  void Initialize ();

};


inline CATVizVertexBufferRepViz3DEdgeOrLineIterator& CATVizVertexBufferRepViz3DEdgeOrLineIterator::Begin ()
{
  Initialize ();
  return *this;
}

inline CATBoolean CATVizVertexBufferRepViz3DEdgeOrLineIterator::End () const
{
  return _Scope == eThroughWireEdges && _Index >= _Count;
}

#endif
