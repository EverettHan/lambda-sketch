#ifndef CATICDSPattern_H
#define CATICDSPattern_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSConstraint.h"

class CATICDSVariable;
class CATICDSGeometryLeaf;

/**
 * A constraint specifying a repeating pattern among geometries.
 */
class ExportedByCDSInterface CATICDSPattern : public CATICDSConstraint
{
public:

  /**
   * Retreive pattern axis.
   */
  virtual CATICDSGeometryLeaf* GetAxis() const = 0;

  /**
   * Retreive pattern geometry definition
   * @param onGeometries
   *   A value that specifies the number of geometries patterned.
   * @param oapGeometries
   *   A pointer to the CATICDSGeometryLeaf that specifies the list of (oNbGeometries) pointers to patterned geometries.
   * @param oapVariables
   *   A list of (oNbGeometries - 1) pointers to variables:  distances between adjacent geometries for linear pattern or angles of rotation around an axis among adjacent geometries for circular patterns; when NULL, equal distances are implied for linear patterns whereas angles are implied by (2*PI/oNbGeometries) for circular patterns.
   * @param oaAlignment
   *   A list of (oNbGeometries - 1) alignments between each argument and the first argument; when NULL, caNOTSPECIFIED is implied.
   * 
   * @SIZE oapGeometries onGeometries
   * @SIZE oapVariables onGeometries-1
   * @SIZE oaAlignment onGeometries-1
   */
  virtual void GetGeometries(int &onGeometries,
                             CATICDSGeometryLeaf **&oapGeometries,
                             CATICDSVariable **&oapVariables,
                             CATCAlignment *&oaAlignment) const = 0;

  virtual ~CATICDSPattern() {}
};

#endif
