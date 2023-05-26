// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyGeoServices.h
//
//===================================================================
// July  2014  Creation: JXO
// Nov   2018  JXO: You can now pass a CATSoftwareConfiguration
//===================================================================
#ifndef CATPolyBodyGeoServices_h
#define CATPolyBodyGeoServices_h

#include "PolyBodyBVHOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATPolyEdge;
class CATProgressCallback;

// Math
#include "CATTolerance.h"
class CATSoftwareConfiguration;


/** @file
 * Geometrical services for CATPolyBody.
 */


namespace Poly
{
  /** @name Length, Area, Volume Services
  *
  * CATPolyBodyGeoServices.h
  * @{ */

  /**
   * Computes the length of an edge.
   * @return
   *   <ul>
   *     <li> <tt>S_OK</tt> if a valid edge is computed from the geometry of the edge.
   *     <li> <tt>E_FAIL</tt> if an error occurs.
   *   </ul>
   */
  ExportedByPolyBodyBVHOperators HRESULT GetLength (const CATPolyEdge& edge, double& oLength);

  /** @} */

};


/** @name GeoDiagnosis
    @{ */

/**
 * Returns the status about the geometric validity of the CATPolyBody.
 * @param iTol
 *        Tolerance used for the geometric checks
 * @return
 *   <ul>
 *     <li> <tt>S_OK</tt> if the CATPolyBody is geometrically valid;
 *     <li> <tt>S_FALSE</tt> if the CATPolyBody is geometrically invalid;
 *     <li> <tt>E_FAIL</tt> if a serious error is detected (corrupted CATPolyBody) and the tests
 *          could not be completed.
 *   </ul>
 * See CATPolyBodyGeoDiagnosis if the CATPolyBody is invalid for further information about
 * the errors.
 */
ExportedByPolyBodyBVHOperators HRESULT CATPolyIsGeoValid (const CATPolyBody& iPolyBody, double iTol = -1.);

/**
 * Chains all the needed checks to be sure a CATPolyBody can be imported into a CATBody.
 * Updates the CATPolyBodyDiagnosis and CATPolyBodyGeoDiagnosis if needed.
 * To pass the test, input CATPolyBody must be valid (CATPolyBodyChecker), geometrically valid (CATPolyBodyGeoChecker), and
 * - if solid, must be watertight (CATPolyBodyIsGeometricallyClosed and CATPolyBodyIsClosed), and have a coherent orientation (CATPolyBodySolidOrientationChecker)
 * - if not, must have its bounding edges (CATPolyBodyBoundingEdgesChecker)
 * @param iBody
 *   Input CATPolyBody to check. If the diagnosis already have the check return codes, then the check is not launched (lazy.)
 * @param iTol
 *   Should be the tolerance of the factory where the CATBody will be instanciated
 * @param iConfig
 *   Software configuration to be used in the checker. If null (default), then last version is used.
 * @param ioProgress
 *   Progression callback to be able to follow the progression and have the ability to interrupt the check (returns E_ABORT).
 * @return
 *   <ul>
 *     <li> <tt>S_OK</tt> iBody is valid for import;
 *     <li> <tt>S_FALSE</tt> iBody is not valid for import;
 *     <li> <tt>E_FAIL</tt> The check itself failed. iBody may be unusable.
 *   </ul>
 */
ExportedByPolyBodyBVHOperators HRESULT CATPolyIsCATBodyReady (CATPolyBody& iPolyBody, const CATTolerance & iTol, CATBoolean iForceCheck = FALSE, CATSoftwareConfiguration * iConfig = 0,
                                                              CATProgressCallback * ioProgress = 0);


/** @} */


#endif
