// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSFocus.h
// Header definition of CATCSFocus
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2011  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSFocus_H
#define CATCSFocus_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying focus of geometries.
 */
class ExportedBySolverInterface CATCSFocus : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSFocus();

  virtual ~CATCSFocus();

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
