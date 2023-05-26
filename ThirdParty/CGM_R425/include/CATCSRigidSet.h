// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSRigidSet.h
// Header definition of CATCSRigidSet
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSRigidSet_H
#define CATCSRigidSet_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometry.h"

//-----------------------------------------------------------------------

class CATCSSketch;
/**
 * A rigid set in three-dimensional space.
 */
class ExportedBySolverInterface CATCSRigidSet : public CATCSGeometry
{
public:
  /**
   * Constructs an instance of the rigid set.
   */
  CATCSRigidSet();

  virtual ~CATCSRigidSet();

  /**
   * Retrieves type of the geometry.
   * @return
   *   Type of the geometry.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

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
   * Applies an affine transformation to the rigid set.
   * @param iMatrix
   *   A matrix representing a rotation in three-dimensional space.
   * @param iTranslation
   *   A vector representing a translation in three-dimensional space.
   */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
   * Applies an affine transformation to the rigid set.
   * All rs geometries must have the same sketch
   * @param iMatrix
   *   A matrix containing a rotation in two-dimensional space as 2x2
   *   submatrix and a translation at the last column. The last row of the
   *   matrix is dummy.
   */
  virtual void ApplyTransformation2D(double iMatrix[3][3]);

  /**
   * Retrieves stiffness of the rigid set.
   * @return
   *   A value of the stiffness.
   */
  double GetStiffness();

  /**
   * Return the common sketch of all geometries inside rigid set if it exists
   * @return Rigid set geometries sketch
   */
  CATCSSketch const * GetSketch() const CATCDSOverride;
  CATCSSketch * GetSketch() CATCDSOverride;

  CATCDSString GetScaleVariableName() const;
  CATCDSBoolean HasScaleVariable() const;
  void SetActualScale(double iScale);
  double GetActualScale();
};

//-----------------------------------------------------------------------

#endif
