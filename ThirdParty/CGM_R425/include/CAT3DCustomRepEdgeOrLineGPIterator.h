// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DCustomRepEdgeOrLineGPIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CAT3DCustomRepEdgeOrLineGPIterator_H
#define CAT3DCustomRepEdgeOrLineGPIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CAT3DCustomRepGPIterator.h"

class CAT3DCustomRep;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;


/**
 * Iterates through all the CAT3DEdgeGP or CAT3DLineGP graphic primitives from a CAT3DCustomRep.
 */
class ExportedByPolyVizUtils CAT3DCustomRepEdgeOrLineGPIterator
{

public:

  CAT3DCustomRepEdgeOrLineGPIterator (const CAT3DCustomRep& iRep);
  ~CAT3DCustomRepEdgeOrLineGPIterator () {}

public:

  CAT3DCustomRepEdgeOrLineGPIterator& Begin ();
  inline CATBoolean End () const;
  CAT3DCustomRepEdgeOrLineGPIterator& operator++ ();

public:

  inline CATGraphicPrimitive* GetGP () const;

  inline void GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const;

private:

  CAT3DCustomRepGPIterator _Iterator;

};


inline CATBoolean CAT3DCustomRepEdgeOrLineGPIterator::End () const
{
  return _Iterator.End ();
}

inline CATGraphicPrimitive* CAT3DCustomRepEdgeOrLineGPIterator::GetGP () const
{
  return _Iterator.GetGP ();
}

inline void CAT3DCustomRepEdgeOrLineGPIterator::GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const
{
  _Iterator.GetGraphicAttributeSet (ioGA);
}

#endif
