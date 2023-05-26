#ifndef CATICDSLinearPattern_H
#define CATICDSLinearPattern_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSPattern.h"

class CATICDSFactory;
class CATICDSGeometryLeaf;

/**
 * A constraint specifying a repeating linear pattern among geometries.
 */
class ExportedByCDSInterface CATICDSLinearPattern : public CATICDSPattern
{
public:

  /**
   * Creates an instance of the CATICDSLinearPattern constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis
   *   A pointer to the CATICDSGeometryLeaf that specifies the axis of symmetry for the pattern.
   * @param inGeometries
   *   A value that specifies the number of geometries patterned.
   * @param iapGeometries
   *   A pointer to the CATICDSGeometryLeaf that specifies the list of (iNbGeometries) pointers to patterned geometries.
   * @param iapVariables
   *   A list of (iNbGeometries - 1) pointers to variables:  distances between adjacent geometries; when NULL, equal distances are implied.
   * @param iaAlignment
   *   A list of (iNbGeometries - 1) alignments between each argument and the first argument; when NULL, caNOTSPECIFIED is implied.
   *
   * @SIZE iapGeometries inGeometries
   * @SIZE iapVariables inGeometries-1
   * @SIZE iaAlignment inGeometries-1
   */
  static CATICDSLinearPattern* Create(CATICDSFactory *ipFactory,
                                      CATICDSGeometryLeaf *ipAxis,
                                      int inGeometries,
                                      CATICDSGeometryLeaf **iapGeometries,
                                      CATICDSVariable **iapVariables = 0,
                                      CATCAlignment *iaAlignment = 0);

  virtual ~CATICDSLinearPattern() {}
};

#endif
