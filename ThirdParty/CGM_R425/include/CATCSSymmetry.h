// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSSymmetry.h
// Header definition of CATCSSymmetry
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSSymmetry_H
#define CATCSSymmetry_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying symmetry between geometries.
 */
class ExportedBySolverInterface CATCSSymmetry : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSSymmetry();

  virtual ~CATCSSymmetry();

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
