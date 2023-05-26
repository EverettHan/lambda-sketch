#ifndef CATICDSFullPattern2D_H
#define CATICDSFullPattern2D_H

// COPYRIGHT DASSAULT SYSTEMES  2015

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSPattern.h"

class CATICDSFactory;
class CATICDSAxis2D;

/**
 * A constraint specifying a repeating full pattern among geometries.
 * Each instance is the image of the previous one by the transformation defined by 3 variables (one angle and two lengths).
 */
class ExportedByCDSInterface CATICDSFullPattern2D : public CATICDSPattern
{
public:

  /**
   * Creates an instance of the CATICDSFullPattern2D constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis
   *   A pointer to the CATICDSAxis2D that specifies the axis system of symmetry for the pattern.
   * @param inGeometries
   *   A value that specifies the number of geometries patterned.
   * @param iapGeometries
   *   A pointer to the CATICDSGeometryLeaf that specifies the list of (iNbGeometries) pointers to patterned geometries.
   * @param iapVariables
   *   A list of (iNbGeometries - 1) tuples of (an, length1, length2) pointers to variables:  relative positions with respect to previous adjacent geometries
   *   The pattern will enforce the following constraint Geometry(i+1) = translation(i)(rotation(i)(Geometry(i))) where
   *   rotation(i) is the rotation around sketch axis of angle iapVariables[3 * i]
   *   translation(i) is the sum of translation iapVariables[3 * i + 1] * ipAxis.FirstVector and iapVariables[3 * i + 2] * ipAxis.SecondVector
   *
   * @SIZE iapGeometries inGeometries
   * @SIZE iapVariables 3*(inGeometries-1)
   */
  static CATICDSFullPattern2D* Create(CATICDSFactory *ipFactory,
                                      CATICDSAxis2D *ipAxis,
                                      int inGeometries,
                                      CATICDSGeometryLeaf **iapGeometries,
                                      CATICDSVariable **iapVariables);

  virtual ~CATICDSFullPattern2D() {}
};

#endif
