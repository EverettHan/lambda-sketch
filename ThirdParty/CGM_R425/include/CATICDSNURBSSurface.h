#ifndef CATICDSNURBSSurface_H
#define CATICDSNURBSSurface_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSSurface.h"

class CATICDSFactory;
class CATICDSPoint;

/**
 * @SKIP
 *
 * A 3D NURBS surfce constructed on an array of control points.
 */
class ExportedByCDSInterface CATICDSNURBSSurface : public CATICDSSurface
{
public:

  /**
   * Returns the number of control points in U direction (degree in U + 1, or greater)
   */
  virtual int GetUNbOfControlPoints() const = 0;

  /**
   * Returns the number of control points in V direction (degree in V + 1, or greater)
   */
  virtual int GetVNbOfControlPoints() const = 0;

  /**
   * Returns the degree of NURBS surface in the U direction
   */
  virtual int GetUDegree() const = 0;

  /**
   * Returns the degree of NURBS surface in the V direction
   */
  virtual int GetVDegree() const = 0;

  /**
   * Returns the (n points in U + degreee in U + 1 ) array of knots in the U direction.
   */
  virtual const double* GetUKnots() const = 0;

  /**
   * Returns the (n points in V + degreee in V + 1 ) array of knots in the V direction.
   */
  virtual const double* GetVKnots() const = 0;

  /**
   * Returns the control point at the given index.
   * @param iIdx
   * Index of point to return. Must be 0 or greater and less or equal than 
   * (n control points in U * n control points in V) + 1
   */
  virtual CATICDSPoint* GetControlPoint(int iIdx) const = 0;

  /**
   * Returns the (n points in U* n points in V) array of weights.
   */
  virtual const double* GetWeights() const = 0;

  /**
   * Constructs an instance of 3D NURBS surface.
   * @param ipFactory.
   *   Pointer to the instance of CATICDSFactory to use
   * @param iUNbPoints
   * @param iVNbPoints
   *   Number of control points. Should be (iDegree+1) or greater.
   * @param iUDegree
   * @param iVDegree
   *   Degree of NURBS. Should be 0 or greater.
   * @param iaUKnots
   * @param iaVKnots
   *   Array of (iNbPoints+iDegree+1) knots, defining the NURBS shape
   *   and parameterization.
   *   iaKnots[i+1] should be equal to or greater than iaKnots[i].
   *   Lower and upper bound of surface parameter will be equal to
   *   iaKnots[iDegree] and iaKnots[iNbPoints] respectively.
   * @param iapPoints
   *   Array of iUNbPoints*iVNbPoints pointers to the NURBS control points.
   *   The order of points corresponds to NURBS definition, each point
   *   can be present in the array any number of times.
   * @param iaWeights
   *   Array of iUNbPoints*iVNbPoints weights, defining the NURBS shape.
   *   If iaWeights is NULL, equal weights are taken, and the surface is
   *   non-rational B-spline surface.
   * @param iUPeriodic
   * @param iVPeriodic
   *   Specifies, whether the NURBS parameterization is periodic.
   *   Does not affect the NURBS shape. In order to continuously connect
   *   the NURBS boundary points, iaKnots, iapPoints and iaWeights
   *   arrays should be properly "wrapped".
   */
  static CATICDSNURBSSurface* Create(CATICDSFactory *ipFactory,
                                     int iUNbPoints, int iVNbPoints,
                                     int iUDegree, int iVDegree,
                                     const double *iaUKnots, const double *iaVKnots,
                                     CATICDSPoint** iapPoints,
                                     const double *iaWeights = 0,
                                     CATCDSBoolean iUPeriodic = FALSE, CATCDSBoolean iVPeriodic = FALSE);

  virtual ~CATICDSNURBSSurface() {}
};

#endif
