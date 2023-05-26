// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSTangency.h
// Header definition of CATCSTangency
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSTangency_H
#define CATCSTangency_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying tangency between geometries.
 */
class ExportedBySolverInterface CATCSTangency : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSTangency();

  virtual ~CATCSTangency();

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
   * Sets the tangency mode between ruled geometries (cones and cylinders). Two modes are available :
   * Tangency on a point (default mode for all geometries) or along a generatrix of the ruled geometries
   * @param iRuledGeometriesMode
   *   A ruled geometries mode
   * @see #GetRuledGeometriesMode
   */
  virtual void SetRuledGeometriesMode(CATCSRuledGeometriesMode iRuledGeometriesMode);

  /**
   * Gets the tangency mode between ruled geometries (cones and cylinders).
   * @return
   *   A ruled geometries mode
   * @see #SetRuledGeometriesMode
   */
  virtual CATCSRuledGeometriesMode GetRuledGeometriesMode();

private:
  CATCSRuledGeometriesMode _RuledGeometriesMode;
};

//-----------------------------------------------------------------------

#endif
