// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSMinorRadius.h
// Header definition of CATCSMinorRadius
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSMinorRadius_H
#define CATCSMinorRadius_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying minor radius of a geometry.
 */
class ExportedBySolverInterface CATCSMinorRadius : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSMinorRadius();

  virtual ~CATCSMinorRadius();

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
   * Retrieves value of the radius.
   * @param oRadius
   *   A value of the radius.
   * @see #SetRadius
   */
  virtual void GetRadius(double &oRadius);

  /**
   * Sets value of the radius.
   * @param iRadius
   *   A value of the radius.
   * @see #GetRadius
   */
  virtual void SetRadius(const double iRadius);

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Radius;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetRadius(iValue);}
  
private:
  double _Radius;
};

//-----------------------------------------------------------------------

#endif
