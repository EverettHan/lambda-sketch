// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSConcentricity.h
// Header definition of CATCSConcentricity
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2004  Creation:             Konstantin Kucheryavy
//===================================================================
#ifndef CATCSConcentricity_H
#define CATCSConcentricity_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying concentricity between geometries.
 */
class ExportedBySolverInterface CATCSConcentricity : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSConcentricity();

  virtual ~CATCSConcentricity();

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
