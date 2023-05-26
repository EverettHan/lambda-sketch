// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSCoincidence.h
// Header definition of CATCSCoincidence
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSCoincidence_H
#define CATCSCoincidence_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying coincidence between geometries.
 */
class ExportedBySolverInterface CATCSCoincidence : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSCoincidence();

  virtual ~CATCSCoincidence();

  /**
   * Retrieves type of the constraint.
   * @return
   *   Type of the geometry.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Retrieves orientation between a circle and a torus. This property is
   * actual in case the constraint connects a circle and a torus.
   * @return
   *   An orientation between a circle and a torus.
   * @see #SetCircleTorusOrientation
   */
  virtual CATCSTorusOrientation GetCircleTorusOrientation();

  /**
   * Sets orientation between a circle and a torus. This property is actual in
   * case the constraint connects a circle and a torus.
   * @param iOrientation
   *   An orientation between a circle and a torus.
   * @see #GetCircleTorusOrientation
   */
  virtual void SetCircleTorusOrientation(CATCSTorusOrientation iOrientation);

private:
  CATCSTorusOrientation _TorusOrientation;
};

//-----------------------------------------------------------------------

#endif
