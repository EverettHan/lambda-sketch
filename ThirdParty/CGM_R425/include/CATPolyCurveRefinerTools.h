// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCurveRefinerTools.h
//
//===================================================================
// June 2007  Creation: ndo
//===================================================================
#ifndef CATPolyCurveRefinerTools_h
#define CATPolyCurveRefinerTools_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.

class CATIPolyCurve;
class CATIPolyCurveVertexTangentConstLayer;

class CATIPolyMesh;
class CATIPolySurfaceVertexNormalConstLayer;
class CATIPolySurfaceVertexCellConstLayer;

class CATPolyMathCubicBezierCurve;


//-----------------------------------------------------------------------------
// CATPolyCurveRefinerTools
// Tools to construct a CATPolyMathCubicBezierCurve object from a CATIPolyCurve object.
//-----------------------------------------------------------------------------
class ExportedByPolyVizRefiners CATPolyCurveRefinerTools 
{

public:

  /*
   * Construct a CATPolyMathCubicBezierCurve object.
   * Caller is responsible for deleting the output object oCurve (delete operator).
   */
  static HRESULT ConstructMathCurve (const CATIPolyCurve& iCurve, const int iBarVertices[],
                                     const CATIPolyCurveVertexTangentConstLayer& iTangentLayer,
                                     CATPolyMathCubicBezierCurve*& oCurve) ;

  static HRESULT ConstructMathCurve (const CATIPolyMesh& iMesh, const int iBarVertices[],
                                     const CATIPolySurfaceVertexNormalConstLayer& iNormalLayer,
                                     const CATIPolySurfaceVertexCellConstLayer& iCellLayer,
                                     CATPolyMathCubicBezierCurve*& oCurve) ;

};

#endif
