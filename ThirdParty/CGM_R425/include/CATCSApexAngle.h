// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATCSApexAngle.h
// Header definition of CATCSApexAngle
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2007  Creation:                     Ilia IVANOV
//===================================================================
#ifndef CATCSApexAngle_H
#define CATCSApexAngle_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying angle at an apex of cone.
 */
class ExportedBySolverInterface CATCSApexAngle : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSApexAngle();

  virtual ~CATCSApexAngle();

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

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Angle;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetAngle(iValue);}

private:
  double _Angle;
};

//-----------------------------------------------------------------------

#endif
