// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DGeomRepEdgeOrLineGPIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CAT3DGeomRepEdgeOrLineGPIterator_H
#define CAT3DGeomRepEdgeOrLineGPIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CAT3DGeomRep;
class CAT3DEdgeGP;
class CAT3DLineGP;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class CATGraphicMaterial;


/**
 * Iterates through all the CAT3DEdgeGP or CAT3DLineGP graphic primitives from a CAT3DGeomRep.
 */
class ExportedByPolyVizUtils CAT3DGeomRepEdgeOrLineGPIterator
{

public:

  CAT3DGeomRepEdgeOrLineGPIterator (const CAT3DGeomRep& iRep);
  ~CAT3DGeomRepEdgeOrLineGPIterator () {}

  /**
   * Returns the number of iterations.
   */
  unsigned int Count () const;

public:

  inline CAT3DGeomRepEdgeOrLineGPIterator& Begin ();
  inline CATBoolean End () const;
  CAT3DGeomRepEdgeOrLineGPIterator& operator++ ();

public:

  CATGraphicPrimitive* GetGP () const;

  CAT3DEdgeGP* GetEdgeGP ();
  CAT3DLineGP* GetLineGP ();

  void GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const;

private:

  const CAT3DGeomRep& _Rep;

  enum Type
  {
    eUnknown        = 0x0000,
    eEdgeGP         = 0x0010,
    eLineGP         = 0x1000
  };

  enum IterationScope
  {
    eThroughEdges          = 1,
    eThroughBoundaries     = 2,
    eThroughSharpEdges     = 3,
    eThroughSmoothEdges    = 4,
    eThroughWireEdges      = 5
  };

  unsigned int _Index;
  unsigned int _Count;

  IterationScope _Scope;
  Type _Type;

  void Initialize ();

};


inline CAT3DGeomRepEdgeOrLineGPIterator& CAT3DGeomRepEdgeOrLineGPIterator::Begin ()
{
  Initialize ();
  return *this;
}

inline CATBoolean CAT3DGeomRepEdgeOrLineGPIterator::End () const
{
  return _Scope == eThroughWireEdges && _Index >= _Count;
}

#endif
