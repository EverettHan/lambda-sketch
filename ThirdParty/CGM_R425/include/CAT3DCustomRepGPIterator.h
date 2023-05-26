// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DCustomRepGPIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CAT3DCustomRepGPIterator_H
#define CAT3DCustomRepGPIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CAT3DCustomRep;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;


/**
 * Iterates through all the CAT3DFaceGP graphic primitives from a CAT3DCustomRep.
 */
class ExportedByPolyVizUtils CAT3DCustomRepGPIterator
{

public:

  CAT3DCustomRepGPIterator (const CAT3DCustomRep& iRep);
  ~CAT3DCustomRepGPIterator () {}

public:

  inline CAT3DCustomRepGPIterator& Begin ();
  inline CATBoolean End () const;
  inline CAT3DCustomRepGPIterator& operator++ ();

public:

  CATGraphicPrimitive* GetGP () const;

  void GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const;

private:

  const CAT3DCustomRep& _Rep;

  unsigned int _Index;
  unsigned int _Count;

};


inline CAT3DCustomRepGPIterator& CAT3DCustomRepGPIterator::Begin ()
{
  _Index = 0;
  return *this;
}

inline CATBoolean CAT3DCustomRepGPIterator::End () const
{
  return _Index >= _Count;
}

inline CAT3DCustomRepGPIterator& CAT3DCustomRepGPIterator::operator++ ()
{
  ++_Index;
  return *this;
}

#endif
