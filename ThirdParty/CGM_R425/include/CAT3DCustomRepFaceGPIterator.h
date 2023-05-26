// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DCustomRepFaceGPIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CAT3DCustomRepFaceGPIterator_H
#define CAT3DCustomRepFaceGPIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CAT3DCustomRepGPIterator.h"

class CAT3DCustomRep;
class CAT3DFaceGP;
class CATGraphicAttributeSet;


/**
 * Iterates through all the CAT3DFaceGP graphic primitives from a CAT3DCustomRep.
 */
class ExportedByPolyVizUtils CAT3DCustomRepFaceGPIterator
{

public:

  CAT3DCustomRepFaceGPIterator (const CAT3DCustomRep& iRep);
  ~CAT3DCustomRepFaceGPIterator () {}

public:

  CAT3DCustomRepFaceGPIterator& Begin ();
  inline CATBoolean End () const;
  CAT3DCustomRepFaceGPIterator& operator++ ();

public:

  CAT3DFaceGP* GetGP () const;

  inline void GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const;

private:

  CAT3DCustomRepGPIterator _Iterator;

};


inline CATBoolean CAT3DCustomRepFaceGPIterator::End () const
{
  return _Iterator.End ();
}

inline CAT3DFaceGP* CAT3DCustomRepFaceGPIterator::GetGP () const
{
  return (CAT3DFaceGP*) _Iterator.GetGP ();
}

inline void CAT3DCustomRepFaceGPIterator::GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const
{
  _Iterator.GetGraphicAttributeSet (ioGA);
}

#endif
