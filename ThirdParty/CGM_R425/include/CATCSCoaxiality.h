// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATCSCoaxiality.h
// Header definition of CATCSCoaxiality
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2007  Creation:                     Ilia Ivanov
//===================================================================
#ifndef CATCSCoaxiality_H
#define CATCSCoaxiality_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying coaxiality between geometries.
 */
class ExportedBySolverInterface CATCSCoaxiality : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSCoaxiality();

  virtual ~CATCSCoaxiality();

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
