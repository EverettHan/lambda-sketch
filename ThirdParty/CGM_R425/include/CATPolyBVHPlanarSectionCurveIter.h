// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHPlanarSectionCurveIter.h
//
//===================================================================
//
// October 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBVHPlanarSectionCurveIter_H
#define CATPolyBVHPlanarSectionCurveIter_H

#include "PolyBodyBVHOperators.h"
#include "CATIPolyCurveIterator.h"
#include "CATBVHNodeConst.h"
#include "CATPolyBody.h"
#include "CATMathPlane.h"
#include "CATListPV.h"
#include "CATErrorDef.h"

class CATMathTransformation;


/**
 * Iterates through a series of CATIPolyCurve's from a bounding volume hierarchy that intersect a given plane.
 */
class  ExportedByPolyBodyBVHOperators CATPolyBVHPlanarSectionCurveIter : public CATIPolyCurveIterator
{

public:

  CATPolyBVHPlanarSectionCurveIter (CATBVHNodeConst& iNode, 
                                    const CATMathTransformation* iNodePositionMatrix,
                                    const CATMathTransformation* iProductMatrix,    
                                    const CATMathPlane& iPlane);
  ~CATPolyBVHPlanarSectionCurveIter ();

public:

  // Iterator methods.

  CATIPolyCurveIterator& Begin ();

  inline CATBoolean End () const;

  CATIPolyCurveIterator& operator++ ();

public:

 /**
  * Returns a curve from the iterator. 
  * @return [out, IUnknown#Release]
  *   A CATIPolyCurve to be released by caller.
  */
  virtual CATIPolyCurve* GetAndRelease ();

  /**
   * Returns a curve from the iterator.
   * @return [out, IUnknown#Release]
   *   A CATIPolyCurve to be released by caller.
   */
  CATIPolyCurve* DummyGet ();

public:

  // Other query methods for attributes associated to the CATIPolyCurve's of the CATPolyBody.

  inline const CATMathTransformation* GetPositionMatrix () const {return _ProductMatrix;}

private:

  CATMathPlane _Plane;           // Keep a copy, not a reference.
  CATBVHNodeConst& _Root;        // Reference.

  const CATMathTransformation* _NodePositionMatrix;
  const CATMathTransformation* _ProductMatrix;

  CATListPV _IteratorStack;

private:

  inline void Push (CATBVHNodeConst& iNode);
  inline CATBVHNodeConst::ConstIterator* Last () const;  // Return the iterator associated to last node pushed.
  inline void Pop ();  // No need to return iterator!

  void ForwardToNextClash ();

};


inline CATBoolean CATPolyBVHPlanarSectionCurveIter::End () const
{
  return _IteratorStack.Size () ? FALSE : TRUE;
}


inline void CATPolyBVHPlanarSectionCurveIter::Push (CATBVHNodeConst& iNode)
{
  _IteratorStack.Append (new CATBVHNodeConst::ConstIterator (iNode));
}


inline CATBVHNodeConst::ConstIterator* CATPolyBVHPlanarSectionCurveIter::Last () const
{
  const int nbIterators = _IteratorStack.Size ();
  return nbIterators ? (CATBVHNodeConst::ConstIterator*) _IteratorStack[nbIterators] : 0;
}


inline void CATPolyBVHPlanarSectionCurveIter::Pop ()
{
  const int nbIterators = _IteratorStack.Size ();
  if (nbIterators)
  {
    delete (CATBVHNodeConst::ConstIterator*) _IteratorStack[nbIterators];
    _IteratorStack.Size (nbIterators-1);
  }
}

#endif
