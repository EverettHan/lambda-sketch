// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSDistance.h
// Header definition of CATCSDistance
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSDistance_H
#define CATCSDistance_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

class CATCSGeometry;

//-----------------------------------------------------------------------

/**
 * A constraint specifying distance between geometries.
 */
class ExportedBySolverInterface CATCSDistance : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSDistance();

  virtual ~CATCSDistance();

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
   * Retrieves value of the distance.
   * @param oDistance
   *   A value of the distance.
   * @see #SetDistance
   */
  virtual void GetDistance(double &oDistance);

  /**
   * Sets value of the distance.
   * @param iDistance
   *   A value of the distance.
   * @see #GetDistance
   */
  virtual void SetDistance(const double iDistance);

  /**
   * Retrieves direction of the distance. The direction has to be represented
   * by a line.
   * @return
   *   A pointer to the direction.
   * @see #SetDirection
   */
  virtual CATCSGeometry *GetDirection();

  /**
   * Sets direction of the distance. The direction has to be represented by a
   * line.
   * @param ipDirection
   *   A pointer to the direction.
   * @see #GetDirection
   */
  virtual void SetDirection(CATCSGeometry *ipDirection);

  /**
   * Retrieves half-space orientation of a geometry.
   * @param ipGeometry
   *   A pointer to the geometry.
   * @return
   *   A half-space orientation.
   * @see #SetHalfSpace
   */
  virtual CATPHalfSpace GetHalfSpace(CATCSGeometry *ipGeometry);

  /**
   * Sets half-space orientation of a geometry.
   * @param ipGeometry
   *   A pointer to the geometry.
   * @param iHalfSpace
   *   A half-space orientation.
   * @see #GetHalfSpace
   */
  virtual void SetHalfSpace(CATCSGeometry *ipGeometry, CATPHalfSpace iHalfSpace);

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Distance;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetDistance(iValue);}

  // DO NOT USE (internal use only)
  CATCDSBoolean IsModifiedHalfSpace() const;
  void SetModifiedHalfSpace(CATCDSBoolean iModified = TRUE);

private:
  double _Distance;
  CATCSGeometry *_pDirection;
  CATCSGeometry *_apGeometry[2];
  CATPHalfSpace _aHalfSpace[2];
  CATCDSBoolean _ModifiedHalfSpace;
};

//-----------------------------------------------------------------------

#endif
