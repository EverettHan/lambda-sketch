// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySelfIntersector.h
//
//===================================================================
//
// Usage notes:
// Checks whether a PolyBody self-intersects
//
//===================================================================
//
// Aug 2009 Creation: JXO
// May 2014      JXO: Observer
// Sep 2018      JXO: Multithread
//===================================================================
#ifndef CATPolyBodySelfIntersector_h
#define CATPolyBodySelfIntersector_h

#include "PolyBodyBVHOperators.h"

// Poly math
#include "CATSetOfPtr.h"

// Math
#include "CATTolerance.h"

// System
#include "CATSysBoolean.h"
#include "CATErrorDef.h"
#include "CATListOfInt.h"

class CATPolyBody;
class CATIPolyCurveIterator;
class CATPolyBodySelfClearanceObserver;
class CATProgressCallback;

/**
 * Checks a given polybody for self intersections
 */

class ExportedByPolyBodyBVHOperators CATPolyBodySelfIntersector
{
public:

  /**
   * Constructor and destructor.
   */
  CATPolyBodySelfIntersector (CATPolyBody & iPolyBody, const CATTolerance & iTol = CATGetDefaultTolerance());
  ~CATPolyBodySelfIntersector ();

  /**
   * Checks whether the input polybody has self-intersections.
   * If a SurfaceCellLayer is available, intersections with 
   * Neighborhood faces on edges are not reported. 
   * @param oSelfIntersects
   *        TRUE if body self-intersects, FALSE otherwise.
   * @return
   *        S_OK if everything went fine
   */
  HRESULT Check(CATBoolean & oSelfIntersects);

  /**
   * Checks whether the input polybody has self-intersections.
   * If a SurfaceCellLayer is available, intersections with 
   * Neighborhood faces on edges are not reported.
   * @param oSelfIntersects
   *        TRUE if body self-intersects, FALSE otherwise.
   * @param iFacesToCheck
   *        List containing indices of faces that will be taken into account for self-intersection computation.
   *        They may be also clashing with other faces (this will be reported). Faces that do not appear in this list
   *        won't be checked against themselves (or against one another).
   *        These are indices in the input CATPolyBody.
   * @return
   *        S_OK if everything went fine
   */
  HRESULT Check(CATBoolean & oSelfIntersects, CATListOfInt & iFacesToCheck);

  /**
   * Intersecting free bars won't be reported. Can be useful if you don't
   * have a SurfaceCellLayer.
   */
  void DiscardFreeBars();


  /** Register an observer to be notified as soon as intersections
   *  and clearances are found.
   * @param iObs to be released by caller
   */
  void RegisterObserver(CATPolyBodySelfClearanceObserver * iObs);

  /** Set the callback for the progress */
  void SetProgressCallback(CATProgressCallback * pBar);


  /** @nodoc */
  void ComputeCurves();
  /** @nodoc */
  // To be deleted by caller
  CATIPolyCurveIterator * GetCurves();
  /**
   * @nodoc
   * Force number of threads (default is -1 : automatic)
   */
  void ForceNumberOfThreads(int iNbThreads);

  /** @nodoc */
  void OptimizeCheckWithTags(CATBoolean iO = TRUE);

private:
  void FillUpSetOfValidFaces();
private:
  CATPolyBody & _PolyBody;
  const CATTolerance & m_Tol;
  int _computecurves;
  CATIPolyCurveIterator * _curves;
  int _deletecurves;
  int _discardfreebars;
  CATPolyBodySelfClearanceObserver * m_obs;
  CATProgressCallback * m_bar;
  int m_nbthreads;
  CATBoolean m_OptimizeCheckWithTags;
  CATSetOfPtr m_SetOfValidFaces;
};

#endif // CATPolyBodySelfIntersector_H

