// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSAntiTangency.h
// Header definition of CATCSAntiTangency
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2010  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSAntiTangency_H
#define CATCSAntiTangency_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying anti-tangency between geometries.
 */
class ExportedBySolverInterface CATCSAntiTangency : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSAntiTangency();

  virtual ~CATCSAntiTangency();

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
};

//-----------------------------------------------------------------------

#endif // CATCSAntiTangency_H
