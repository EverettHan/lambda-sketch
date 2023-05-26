// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHPlanarSectionSurfaceIter.h
//
//===================================================================
// April 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBVHPlanarSectionSurfaceIter_H
#define CATPolyBVHPlanarSectionSurfaceIter_H

#include "PolyBodyBVHOperators.h"
#include "CATIPolySurfaceIterator.h"
#include "CATBVHNodeConst.h"
#include "CATPolyBody.h"
#include "CATMathPlane.h"
#include "CATListPV.h"
#include "CATErrorDef.h"

class CATMathTransformation;


/**
 * Iterates through a series of CATIPolySurface's from a bounding volume hierarchy that intersect a given plane.
 */
class ExportedByPolyBodyBVHOperators CATPolyBVHPlanarSectionSurfaceIter : public CATIPolySurfaceIterator
{

public:

  /*
   * The optional position matrix is defined as the product of the node and polybody position matrices.
   */
  CATPolyBVHPlanarSectionSurfaceIter (CATBVHNodeConst& iNode, 
                                      const CATMathTransformation* iNodePositionMatrix,
                                      const CATMathTransformation* iProductMatrix,
                                      const CATMathPlane& iPlane);
  ~CATPolyBVHPlanarSectionSurfaceIter ();

  // Update the section plane prior to iteration though a new set of surfaces.
  //void UpdatePlane (const CATMathPlane& iPlane) {_Plane = iPlane;}

public:

  // Iterator.
  CATIPolySurfaceIterator& Begin ();
  inline bool End () const;
  CATIPolySurfaceIterator& operator++ ();

  inline CATPolyFace* GetFace () const;
  inline CATIPolySurface* GetSurface () const;

  inline CATIPolySurface* Get () const;
  inline CATIPolySurface* operator* () const;

public:

  // Other query methods for attributes associated to the CATIPolySurface's of the CATPolyBody.

  inline const CATMathTransformation* GetPositionMatrix () const {return _ProductMatrix;}

private:

  CATMathPlane _Plane;           // Keep a copy, not a reference.
  CATBVHNodeConst& _Root;        // Reference.

  const CATMathTransformation* _NodePositionMatrix;
  const CATMathTransformation* _ProductMatrix;
  CATPolyFace* _Face;
  CATIPolySurface* _Surface;

  CATListPV _IteratorStack;

private:

  inline void Push (CATBVHNodeConst& iNode);
  inline CATBVHNodeConst::ConstIterator* Last () const;  // Return the iterator associated to last node pushed.
  inline void Pop ();  // No need to return iterator!

  void ForwardToNextClash ();

};


inline bool CATPolyBVHPlanarSectionSurfaceIter::End () const
{
  return !_Surface;
}


inline CATPolyFace* CATPolyBVHPlanarSectionSurfaceIter::GetFace () const
{
  return _Face;
}


inline CATIPolySurface* CATPolyBVHPlanarSectionSurfaceIter::GetSurface () const
{
  return _Surface;
}


inline CATIPolySurface* CATPolyBVHPlanarSectionSurfaceIter::Get () const
{
  return GetSurface ();
}


inline CATIPolySurface* CATPolyBVHPlanarSectionSurfaceIter::operator* () const
{
  return GetSurface ();
}


inline void CATPolyBVHPlanarSectionSurfaceIter::Push (CATBVHNodeConst& iNode)
{
  _IteratorStack.Append (new CATBVHNodeConst::ConstIterator (iNode));
}


inline CATBVHNodeConst::ConstIterator* CATPolyBVHPlanarSectionSurfaceIter::Last () const
{
  const int nbIterators = _IteratorStack.Size ();
  return nbIterators ? (CATBVHNodeConst::ConstIterator*) _IteratorStack[nbIterators] : 0;
}


inline void CATPolyBVHPlanarSectionSurfaceIter::Pop ()
{
  const int nbIterators = _IteratorStack.Size ();
  if (nbIterators)
  {
    delete (CATBVHNodeConst::ConstIterator*) _IteratorStack[nbIterators];
    _IteratorStack.Size (nbIterators-1);
  }
}

#endif
