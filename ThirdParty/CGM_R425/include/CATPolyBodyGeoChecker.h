//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//=============================================================================
//
// CATPolyBodyGeoChecker
//
// Check geometrical consistency of a polyhedral body
//
//=============================================================================
// 2014-06-13 JXO: New.
//=============================================================================
#ifndef CATPolyBodyGeoChecker_H
#define CATPolyBodyGeoChecker_H

#include "PolyBodyBVHOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATTolerance.h"

class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATPolyVertex;
class CATPolyBodyGeoCheckerObserver;
class CATProgressCallback;


/**
 * This class performs several consistency checks of the geometry of a CATPolyBody.
 * @see CATPolyBodyGeoDiagnosis
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyGeoChecker
{

public:

  CATPolyBodyGeoChecker ();
  ~CATPolyBodyGeoChecker ();

public:

/** @name Main Method
    @{ */

  /**
   * Performs all the various geometric checks on a CATPolyBody object.
   * Errors found during the checks are logged onto the geo diagnosis.
   * @param iTol
   *        Check tolerance. Default is not to perform the checks that need a tolerance.
   * @return
   *   <ul>
   *     <li> <tt>S_OK</tt> The CATPolyBody passes this test.
   *          The CATPolyBody is valid.
   *     <li> <tt>S_FALSE</tt> The CATPolyBody fails this test. 
   *          Errors are logged onto the diagnosis.
   *     <li> <tt>E_FAIL</tt> A serious error occured during the check of the CATPolyBody 
   *          or the check could not be completed.
   *   </ul>
   */
  HRESULT FullCheck(CATPolyBody& iBody, double iTol = -1., const CATTolerance & iTolObj = CATGetDefaultTolerance()) const;

  /**
   * Checks for degenerate triangles (no tolerance)
   */
  HRESULT CheckDegenerateTriangles(CATPolyBody& iBody) const;
  /**
   * Checks for self intersections (no tolerance)
   */
  HRESULT CheckSelfIntersecting(CATPolyBody& iBody, const CATTolerance & iTolObj = CATGetDefaultTolerance()) const;

  // Next checks need a tolerance
  /**
   * Checks for needles and caps
   * @param iTol
   *        Tolerance for the bar length tests, and for the vertex-bar distance tests
   */
  HRESULT CheckNeedlesAndCaps(CATPolyBody& iBody, double iTol, const CATTolerance & iTolObj = CATGetDefaultTolerance()) const;
  /**
   * Checks for self contacts (and as a consequence, for self intersections too)
   * @param iTol
   *        Tolerance for the distance tests
   *        (triangles are in contact if their distance is less than the tolerance)
   */
  HRESULT CheckSelfIntersectingAndContact(CATPolyBody& iBody, double iTol, const CATTolerance & iTolObj = CATGetDefaultTolerance()) const;

  /**
   * Checks for too close CATPolyVertex
   * @param iTol
   *        Tolerance for the distance tests
   */
  HRESULT CheckPolyVertices(CATPolyBody& iBody, double iTol, const CATTolerance & iTolObj) const;

  /**
   * Registers an observer for fine error outputs.
   * And AddRef is done on obs, a Release will be done in destructor
   */
  void RegisterObserver(CATPolyBodyGeoCheckerObserver * obs) const;
  /** 
   * Unregisters obs. Release will be called.
   */
  void UnregisterObserver(CATPolyBodyGeoCheckerObserver * obs) const;
  /**
   * Set a progress bar.
   * @param iBar you can release it after this call.
   */
  void SetProgressCallback(CATProgressCallback * iBar);
  /**
   * Force number of threads for the self-intersections checking (default is -1 : automatic)
   */
  void ForceNumberOfThreads(int iNbThreads);

private:
  mutable CATPolyBodyGeoCheckerObserver * m_obs;
  int m_off;
  CATProgressCallback * m_bar;
  int m_NbThreads;
};


#endif // !CATPolyBodyGeoChecker_H
