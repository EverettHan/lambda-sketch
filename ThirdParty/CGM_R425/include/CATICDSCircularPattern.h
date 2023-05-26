#ifndef CATICDSCircularPattern_H
#define CATICDSCircularPattern_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSPattern.h"

class CATICDSFactory;

class ExportedByCDSInterface CATICDSCircularPattern : public CATICDSPattern
{
public:

  /** 
   * @DEPRECATED
   */
  virtual void SetFullAlignment(CATCAlignment iAlignment) = 0;

  /** 
   * @DEPRECATED
   */
  virtual CATCAlignment GetFullAlignment() const = 0;

  /**
   * Creates an instance of a CATICDSCircularPattern
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param ipAxis
   *   Pointer to the CATICDSGeometryLeaf that defines the Axis of symmetry around which the CATICDSGeometryLeaf objects are patterned.
   * @param inGeometries
   *   Number of geometries that are to be patterned
   * @param iapGeometries
   *   The actual list of N geometries that are to be patterned
   * @param iapVariables
   *   A list of (N-1) variables describing the angle between each adjacent geometry
   * @param iaAlignment
   *   Specifies the Alignment for a full circular pattern. The ith value specifies alignment of the (i+1)th object with respect to the first object.
   *   The default values are caNOTSPECIFIED which leads to not specified orientations
   *
   * @SIZE iapGeometries inGeometries
   * @SIZE iapVariables inGeometries-1
   * @SIZE iaAlignment inGeometries-1
   */
  static CATICDSCircularPattern* Create(CATICDSFactory *ipFactory,
                                        CATICDSGeometryLeaf *ipAxis,
                                        int inGeometries,
                                        CATICDSGeometryLeaf **iapGeometries,
                                        CATICDSVariable **iapVariables,
                                        CATCAlignment *iaAlignment = 0);

  /**
   * @DEPRECATED
   */
  static CATICDSCircularPattern* Create(CATICDSFactory *ipFactory,
                                        CATICDSGeometryLeaf *ipAxis,
                                        int inGeometries,
                                        CATICDSGeometryLeaf **iapGeometries);

  virtual ~CATICDSCircularPattern() {}
};

#endif
