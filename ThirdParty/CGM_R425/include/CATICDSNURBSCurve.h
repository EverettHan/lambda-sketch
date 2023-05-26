#ifndef CATICDSNURBSCurve_H
#define CATICDSNURBSCurve_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSCurve.h"

class CATICDSFactory;
class CATICDSPoint;

/**
 * A 3D NURBS curve constructed on an array of control points.
 */
class ExportedByCDSInterface CATICDSNURBSCurve : public CATICDSCurve
{
public:

  /**
   * Returns the degree of NURBS curve
   */
  virtual int GetDegree() const = 0;

  /**
   * Returns the number of control points in (degree + 1, or greater)
   */
  virtual int GetNbOfControlPoints() const = 0;

  /**
   * Returns the control point at the given index.
   * @param iIdx
   * Index of point to return. Must be 0 or greater and less or equal than 
   * n control points - 1
   */
  virtual CATICDSPoint* GetControlPoint(int iIdx) const = 0;

  /**
   * Returns the (n points  + degree + 1 ) array of knots.
   *
   * @SIZE result (GetNbOfControlPoints()+GetDegree()+1)
   */
  virtual const double* GetKnots() const = 0;

  /**
   * Returns the (n points) array of weights.
   *
   * @SIZE result GetNbOfControlPoints()
   */
  virtual const double* GetWeights() const = 0;
  
  /**
   * Constructs an instance of 3D NURBS curve.
   * @param ipFactory.
   *   Pointer to the instance of CATICDSFactory to use
   * @param iNbPoints
   *   Number of control points. Should be (iDegree+1) or greater.
   * @param iDegree
   *   Degree of NURBS. Should be 1 or greater.
   * @param iaKnots
   *   Array of (iNbPoints+iDegree+1) knots, defining the NURBS shape
   *   and parameterization.
   *   iaKnots[i+1] should be equal to or greater than iaKnots[i].
   *   Lower and upper bound of curve parameter will be equal to
   *   iaKnots[iDegree] and iaKnots[iNbPoints] respectively.
   * @param iapPoints
   *   Array of iNbPoints pointers to the NURBS control points.
   *   The order of points corresponds to NURBS definition, each point
   *   can be present in the array any number of times.
   * @param iaWeights
   *   Array of iNbPoints weights, defining the NURBS form.
   *   If iaWeights is NULL, equal weights are taken, and the curve is
   *   non-rational B-spline.
   *
   * @SIZE iaKnots (iNbPoints+iDegree+1)
   * @SIZE iapPoints iNbPoints
   * @SIZE iaWeights iNbPoints
   */
  static CATICDSNURBSCurve* Create(CATICDSFactory *ipFactory,
                                   int iNbPoints, int iDegree,
                                   const double *iaKnots,
                                   CATICDSPoint** iapPoints,
                                   const double *iaWeights = 0);

  virtual ~CATICDSNURBSCurve() {}
};

#endif
