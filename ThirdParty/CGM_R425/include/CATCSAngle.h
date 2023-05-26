// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSAngle.h
// Header definition of CATCSAngle
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//  Nov 2002  'GetAxis' added:            Dmitry Ushakov
//===================================================================
#ifndef CATCSAngle_H
#define CATCSAngle_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying angle between geometries.
 */
class ExportedBySolverInterface CATCSAngle : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSAngle();

  virtual ~CATCSAngle();

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
   * Retrieves value of the angle.
   * @param oAngle
   *   A value of the angle.
   * @see #SetAngle
   */
  virtual void GetAngle(double &oAngle);

  /**
   * Sets value of the angle.
   * @param iAngle
   *   A value of the angle.
   * @see #GetAngle
   */
  virtual void SetAngle(const double iAngle);

  /**
   * Retrieves axis of planar angle. The axis can be represented by a line or
   * a plane.
   * @return
   *   A pointer to the axis.
   * @see #SetAxis
   */
  virtual CATCSGeometryLeaf *GetAxis();

  /**
   * Sets axis of planar angle. The axis can be represented by a line or a
   * plane.
   * @param ipAxis
   *   A pointer to the axis.
   * @see #GetAxis
   */
  virtual void SetAxis(CATCSGeometryLeaf *ipAxis);

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Angle;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetAngle(iValue);}

private:
  double _Angle;
  CATCSGeometryLeaf *_pAxis;
};

//-----------------------------------------------------------------------

#endif
