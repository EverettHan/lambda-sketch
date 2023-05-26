// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSParallelism.h
// Header definition of CATCSParallelism
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2009  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSParallelism_H
#define CATCSParallelism_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying parallelism between geometries.
 */
class ExportedBySolverInterface CATCSParallelism : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSParallelism();

  virtual ~CATCSParallelism();

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
