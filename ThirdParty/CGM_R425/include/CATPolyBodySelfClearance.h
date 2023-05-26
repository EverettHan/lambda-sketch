// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySelfClearance.h
//
//===================================================================
//
// Usage notes:
// Checks clearance inside a PolyBody. If non neighbor triangles get
// too close one to another, they will be reported.
// The clearance value should be much smaller than the average bar
// length for proper results.
//
//===================================================================
//
// Apr 2014 Creation: JXO
//===================================================================
#ifndef CATPolyBodySelfClearance_h
#define CATPolyBodySelfClearance_h

#include "PolyBodyBVHOperators.h"

// Math
#include "CATTolerance.h"

// System
#include "CATSysBoolean.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATIPolyCurveIterator;
class CATIPolyMesh;
class CATPolyBodySelfClearanceObserver;
class CATProgressCallback;

/**
 * Checks a given polybody for self clearance. If non neighbor triangles get
 * too close one to another, they will be reported.
 * The clearance value should be much smaller than the average bar length
 * for proper results.
 */

class ExportedByPolyBodyBVHOperators CATPolyBodySelfClearance
{
public:

  /**
   * Constructor
   * @param iPolybody
   *        input polyhedral body to be checked
   * @param iTol
   *        For the epsilons used in computations
   */
  CATPolyBodySelfClearance (CATPolyBody & iPolyBody, const CATTolerance & iTol = CATGetDefaultTolerance());
  /** Destructor */
  ~CATPolyBodySelfClearance ();

  /**
   * Checks whether the input polybody has self-clearances.
   * If a SurfaceCellLayer is available, intersections with 
   * Neighborhood faces on edges are not reported. 
   * @param iClearance
   *        The clearance value to be checked
   * @param oSelfIntersects
   *        1, 2, 3 if body has self-intersections, self-cleanraces or both
   *        0 otherwise.
   * @return
   *        S_OK if everything went fine, error code otherwise
   */
  HRESULT Check(double iClearance, unsigned char & oSelfIntersects);

  /** Register an observer to be notified as soon as intersections
   *  and clearances are found.
   * @param iObs to be released by caller
   */
  void RegisterObserver(CATPolyBodySelfClearanceObserver * iObs);

  /**
   * Intersecting free bars won't be reported. Can be useful if you don't
   * have a SurfaceCellLayer.
   */
  void DiscardFreeBars();


  /** @nodoc */
  void ComputeCurvesAndTriangles();
  /** @nodoc */
  // To be deleted by caller
  CATIPolyCurveIterator * GetCurves();
  /** @nodoc */
  // To be released by caller
  CATIPolyMesh * GetTriangles();

  /**
   * Set the progress bar.
   * You can Release pBar after this call.
   */
  void SetProgressCallback(CATProgressCallback * pBar);

  /**
   * @nodoc
   * Force number of threads (default is -1 : automatic)
   */
  void ForceNumberOfThreads(int iNbThreads);

private:
  void Reinitialize();
private:
  CATPolyBody & m_PolyBody;
  const CATTolerance & m_Tol;
  double m_clearance;
  int m_computecurves;
  CATIPolyCurveIterator * m_curves;
  CATIPolyMesh * m_mesh;
  int m_deletecurves;
  int m_discardfreebars;
  CATPolyBodySelfClearanceObserver * m_obs;
  CATProgressCallback * m_progress;
  int m_nbthreads;
};

#endif // CATPolyBodySelfClearance_H

