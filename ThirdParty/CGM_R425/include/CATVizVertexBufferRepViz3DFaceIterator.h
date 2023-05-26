// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATVizVertexBufferRepViz3DFaceIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CATVizVertexBufferRepViz3DFaceIterator_H
#define CATVizVertexBufferRepViz3DFaceIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATVizVertexBufferRep;
class CATVizPrimitiveSet;
class CATViz3DFace;


/**
 * Iterates through all the CATViz3DFace graphic primitives from a CATVizVertexBufferRep.
 */
class ExportedByPolyVizUtils CATVizVertexBufferRepViz3DFaceIterator
{

public:

  CATVizVertexBufferRepViz3DFaceIterator (CATVizVertexBufferRep& iRep);
  ~CATVizVertexBufferRepViz3DFaceIterator () {_VizFaces = 0;}

  /**
   * Returns the number of iterations.
   */
  inline unsigned int Count () const;

public:

  inline CATVizVertexBufferRepViz3DFaceIterator& Begin ();
  inline CATBoolean End () const;
  inline CATVizVertexBufferRepViz3DFaceIterator& operator++ ();

public:

  CATViz3DFace* GetVizFace () const;

private:

  CATVizPrimitiveSet* _VizFaces;

  unsigned int _Index;
  unsigned int _Count;

};


inline unsigned int CATVizVertexBufferRepViz3DFaceIterator::Count () const
{
  return _Count;
}

inline CATVizVertexBufferRepViz3DFaceIterator& CATVizVertexBufferRepViz3DFaceIterator::Begin ()
{
  _Index = 0;
  return *this;
}

inline CATBoolean CATVizVertexBufferRepViz3DFaceIterator::End () const
{
  return _Index >= _Count;
}

inline CATVizVertexBufferRepViz3DFaceIterator& CATVizVertexBufferRepViz3DFaceIterator::operator++ ()
{
  ++_Index;
  return *this;
}

#endif
