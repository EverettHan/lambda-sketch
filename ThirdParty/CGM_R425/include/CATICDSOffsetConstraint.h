#ifndef CATICDSOffsetConstraint_H
#define CATICDSOffsetConstraint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSConstraint.h"

class CATICDSVariable;
class CATICDSProfile2D;
class CATICDSFactory;

/**
 *
 */
class ExportedBySolverInterface CATICDSOffsetConstraint : public CATICDSConstraint
{
public:

  /**
   * Retrieves geometries connected with the constraint.
   * @param oapGeometries
   *   2-size array with the base profile at the index  0 and the offset profile at the index 1.
   *
   * @SIZE oapGeometries 2
   */
  virtual void GetGeometries(CATICDSProfile2D **&oapGeometries) = 0;

  /**
   * TODO
   * @return
   *   A pointer to the variable.
   *
   * @SKIP
   */
  virtual CATICDSVariable *GetNextVariable(int &ioIter) const = 0;

  /**
   * Activate (TRUE) or desactivate (FALSE) the alignment of the border vertices with their offset
   * @param isAligned
   *   value of the alignment
   */
  virtual void SetBorderVerticesAlignment(CATCDSBoolean isAligned) = 0;
  /**
   * @return
   *   TRUE if the alignment is activated
   */
  virtual CATCDSBoolean GetBorderVerticesAlignment() = 0;  /**
   *
   */
  static CATICDSOffsetConstraint* Create(CATICDSFactory *ipFactory, CATICDSProfile2D* ipGeometry1, CATICDSProfile2D* ipGeometry2, CATICDSVariable *ipVariables);

  /**
   * @SKIP
   */
  static CATICDSOffsetConstraint* Create(CATICDSFactory *ipFactory, CATICDSProfile2D* ipGeometry1, CATICDSProfile2D* ipGeometry2, CATICDSVariable **iapVariables);

  virtual ~CATICDSOffsetConstraint() {}
};

#endif
