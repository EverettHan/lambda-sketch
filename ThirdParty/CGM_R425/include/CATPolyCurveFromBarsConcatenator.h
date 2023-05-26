// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCurveFromBarsConcatenator.h
//
//===================================================================
// 2010-01-21 NDO
// 2013-12-03 JXO Doubles
//===================================================================
#ifndef CATPolyCurveFromBarsConcatenator_H
#define CATPolyCurveFromBarsConcatenator_H

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCompareDoublePoints.h"
#include "CATBucketsOfPoints.h"
#include "CATSetOf3Doubles.h"
#include "CATMapOfPtrToInt.h"
#include "CATPolyBars.h"

#include "CATIPolyCurveIterator.h"
#include "CATIPolyCurveVertexPositionConstLayer.h"

class CATIPolyCurveVertexPositionConstLayer;
class CATPolyBarsToPolyCurveFactory;


/*
 * Concatenate a set of bars into curves.
 */
class ExportedByCATPolyMiscellaneous CATPolyCurveFromBarsConcatenator
{

public:

  /*
   * The compare function is used to compare two triplet of doubles or two double points.
   * By default the comparison function is a lexicographic sort with strict equality between the float
   * representation of the doubles. Points are stored as doubles but compared as floats.
   * However, the comparaison function is customizable by derivation from CATCompareDoublePoints.
   */
  CATPolyCurveFromBarsConcatenator (const CATCompareDoublePoints* iCompareFunction = 0, CATBoolean iTwoSided = FALSE);
  ~CATPolyCurveFromBarsConcatenator ();

public:

  HRESULT AddBar (const CATMathPoint& P1, const CATMathPoint& P2);

  int AddVertex (const CATMathPoint& P);
  HRESULT AddBar (const int iVertex0, const int iVertex1);

public:

  /*
   * Returns an iterator that cycle through a set of constructed curves.
   */
  HRESULT GetCurveFactory (CATPolyBarsToPolyCurveFactory*& oCurveFactory) const;

private:

  CATBucketsOfPoints _UniquePoints;
  CATPolyBars _Bars;

  CATSetOf3Doubles _PointToHandle;
  CATMapOfPtrToInt _HandleToVertex;

  CATIPolyCurveVertexPositionConstLayer* _VertexPositionLayer;
  CATBoolean _TwoSided;
};

#endif // !CATPolyCurveFromBarsConcatenator_H
