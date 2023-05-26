#ifndef CATICDSSegmentLength_H
#define CATICDSSegmentLength_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;
class CATICDSGeometryLeaf;

/**
 * A constraint specifying the length of a geometry segment.
 */
class ExportedByCDSInterface CATICDSSegmentLength : public CATICDSGeomDimConstraint
{
public:
  
  /**
   * Creates an instance of the CATICDSSegmentLength constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipStart
   *   Pointer to the CATICDSGeometryLeaf that specifies the start of the segment length.
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that specifies the end of the segment length.
   * @param ipSupport
   *   Pointer to the CATICDSGeometryLeaf that specifies the geometry on which the segment length is measured.
   */
  static CATICDSSegmentLength* Create(CATICDSFactory *ipFactory,
                                      CATICDSGeometryLeaf* ipStart,
                                      CATICDSGeometryLeaf* ipEnd,
                                      CATICDSGeometryLeaf* ipSupport);

  virtual ~CATICDSSegmentLength() {}
};

#endif
