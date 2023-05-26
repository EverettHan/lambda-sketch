// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DGeomRepFaceGPIterator.h
//
//===================================================================
// April 2013 - Creation NDO
//===================================================================
#ifndef CAT3DGeomRepFaceGPIterator_H
#define CAT3DGeomRepFaceGPIterator_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CAT3DGeomRep;
class CAT3DFaceGP;
class CATGraphicAttributeSet;
class CATGraphicMaterial;


/**
 * Iterates through all the CAT3DFaceGP graphic primitives from a CAT3DGeomRep.
 */
class ExportedByPolyVizUtils CAT3DGeomRepFaceGPIterator
{

public:

  CAT3DGeomRepFaceGPIterator (const CAT3DGeomRep& iRep);
  ~CAT3DGeomRepFaceGPIterator () {}

  /**
   * Returns the number of iterations.
   */
  inline unsigned int Count () const;

public:

  inline CAT3DGeomRepFaceGPIterator& Begin ();
  inline CATBoolean End () const;
  inline CAT3DGeomRepFaceGPIterator& operator++ ();

public:

  CAT3DFaceGP* GetGP () const;

  void GetGraphicAttributeSet (CATGraphicAttributeSet& ioGA) const;

  CATGraphicMaterial* GetGraphicMaterial () const;

private:

  const CAT3DGeomRep& _Rep;

  unsigned int _Index;
  unsigned int _Count;

};


inline unsigned int CAT3DGeomRepFaceGPIterator::Count () const
{
  return _Count;
}

inline CAT3DGeomRepFaceGPIterator& CAT3DGeomRepFaceGPIterator::Begin ()
{
  _Index = 0;
  return *this;
}

inline CATBoolean CAT3DGeomRepFaceGPIterator::End () const
{
  return _Index >= _Count;
}

inline CAT3DGeomRepFaceGPIterator& CAT3DGeomRepFaceGPIterator::operator++ ()
{
  ++_Index;
  return *this;
}

#endif
