#ifndef CATICDSDistance_H
#define CATICDSDistance_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSGeometry;
class CATICDSFactory;

/**
 * A constraint specifying distance between geometries.
 */
class ExportedByCDSInterface CATICDSDistance : public CATICDSGeomDimConstraint
{
public:
  
  /**
   * Retrieves half-space orientation of a geometry.
   * @param ipGeometry
   *   A pointer to the geometry.
   * @return
   *   A half-space orientation.
   * @see #SetHalfSpace
   */
  virtual CATCDSHalfSpace GetHalfSpace(CATICDSGeometry *ipGeometry) const = 0;

  /**
   * Sets half-space orientation of a geometry.
   * @param ipGeometry
   *   A pointer to the geometry.
   * @param iHalfSpace
   *   A half-space orientation.
   * @see #GetHalfSpace
   */
  virtual void SetHalfSpace(CATICDSGeometry *ipGeometry, CATCDSHalfSpace iHalfSpace) = 0;

  /**
   * Creates an instance of the CATICDSDistance Constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   * @param ipGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   * @param ipDirection
   *   Optional pointer to the CATICDSGeometryLeaf that specifies the direction for directional distance constraints. 
   *   Directional distance constraints are valid only between two points.
   *   The CATICDSDistance becomes a directional distance if the GetDirection method returns a pointer to an existing 
   *   CATICDSLine (this geometry must have been declared to CDS). The CATICDSLine is the line on which the distance is projected.
   *   The directional distance can also be used to represent a distance between 2 points coincident to the same line, 
   *   in this case a special chirality is defined in order to keep the points on the line in the same order (with 
   *   respect to the orientation of the line). See the Chirality section for more details.
   */
  static CATICDSDistance* Create(CATICDSFactory *ipFactory,
                                 CATICDSGeometryLeaf* ipGeometry1,
                                 CATICDSGeometryLeaf* ipGeometry2,
                                 CATICDSGeometryLeaf* ipDirection = 0);

  virtual ~CATICDSDistance() {}
};

#endif
