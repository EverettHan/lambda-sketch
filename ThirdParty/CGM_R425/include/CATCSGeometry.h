// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSGeometry.h
// Header definition of CATCSGeometry
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSGeometry_H
#define CATCSGeometry_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSEntity.h"

class CATCSSketch;

//-----------------------------------------------------------------------

/**
 * A basic class representing geometry as a rigid body in three-dimensional
 * space.
 */
class ExportedBySolverInterface CATCSGeometry : public CATCSEntity
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSGeometry();

  virtual ~CATCSGeometry();

  /**
   * Checks whether the geometry is matched to a specific type. The geometry
   * can be casted to a corresponding class if the matching is successful.
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
   * Applies an affine transformation to the geometry.
   * @param iMatrix
   *   A matrix representing a rotation in three-dimensional space.
   * @param iTranslation
   *   A vector representing a translation in three-dimensional space.
   */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) = 0;

  /**
   * Return geometry sketch
   * @return Geometry sketch
   */
  virtual CATCSSketch const * GetSketch() const = 0;
  virtual CATCSSketch * GetSketch() = 0;
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSGeometry, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
