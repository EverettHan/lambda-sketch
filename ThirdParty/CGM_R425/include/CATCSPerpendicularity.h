// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSPerpendicularity.h
// Header definition of CATCSPerpendicularity
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2009  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSPerpendicularity_H
#define CATCSPerpendicularity_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying perpendicularity between geometries.
 */
class ExportedBySolverInterface CATCSPerpendicularity: public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSPerpendicularity();

  virtual ~CATCSPerpendicularity();

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

#endif
