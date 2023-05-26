// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuInterferenceTools.h
//
//===================================================================
//
// Usage notes: Tools to convert results of interference to
//              visualization representations
//
//===================================================================
//
// Oct 2013 Creation: JXO
//===================================================================

#ifndef CATPolyVisuInterferenceTools_h
#define CATPolyVisuInterferenceTools_h

#include "PolyVisuClash.h"

// Poly
class CATIPolyCurveIterator;
class CATIPolyCurve;
class CATIPolyMesh;

// Visu
class CATRep;
class CAT3DRep;
class CAT3DBagRep;
class CAT3DBoundingSphere;
#include "CATGraphicAttributeSet.h"

// Math
class CATMathPoint;

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"

/**
 * Tools to convert results of interference to visualization representations.
 */
class ExportedByPolyVisuClash CATPolyVisuInterferenceTools
{
public:
  /**
   * Computes the visualization representation from a CATIPolyCurveIterator.
   * @param iCurves input curve iterator.
   * @param ipVisuAttribute input graphic attribute. Default is a red line with a thickness of 2.
   * @param opBagCurve returned representation. Pass a null pointer.
   * @param islargescale Pass TRUE to compute a local matrix based on the barycenter of the points.
   */
  static HRESULT GetRepFromCurves(CATIPolyCurveIterator * iCurves, CATGraphicAttributeSet * ipVisuAttribute, CAT3DBagRep *& opBagCurve, CATBoolean islargescale = FALSE, int * onbofcurves = 0, int * onbofbars = 0);
  /**
   * Computes the visualization representation from a CATIPolyCurve.
   * @param iCurve input curve.
   * @param ipVisuAttribute input graphic attribute. Default is a red line with a thickness of 2.
   * @param onbofbars returns the number of added bars.
   * @param islargescale Pass TRUE to compute a local matrix based on the barycenter of the points.
   */
  static CAT3DRep * GetRepFromCurve(CATIPolyCurve * iCurve, CATGraphicAttributeSet * ipVisuAttribute, int & onbofbars, CATBoolean islargescale = FALSE);
  /**
   * Computes the visualization representation from a set of ordered points.
   * @param points input points.
   * @param nbPoints input number of points.
   * @param ipVisuAttribute input graphic attribute. Default is a green line with a thickness of 1.
   * @param isclosed to set a closed curve.
   * @param islargescale Pass TRUE to compute a local matrix based on the barycenter of the points.
   */
  static CAT3DRep * GetRepFromListOfPoints(CATMathPoint points[], int nbPoints, CATGraphicAttributeSet * ipVisuAttribute, CATBoolean isclosed = FALSE, CATBoolean islargescale = FALSE);
  /**
   * Computes the visualization representation from a mesh, resulting from a contact or clearance interference
   * @param mesh input mesh.
   * @param iVisuAttribute input graphic attribute
   * @param iswire to display a wire
   * @param islargescale Pass TRUE to compute a local matrix based on the barycenter of the points.
   */
  static CAT3DRep * GetRepFromMesh(const CATIPolyMesh & iMesh, const CATGraphicAttributeSet & iVisuAttribute, CATBoolean islargescale = FALSE, CATBoolean iswire = FALSE, int TypeVisuMode = 1 /* For interferences (see with YLE) */);

private:
  CATPolyVisuInterferenceTools(){}
  virtual ~CATPolyVisuInterferenceTools(){}
};

#endif

