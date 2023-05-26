// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSCurvature.h
// Header definition of CATCSCurvature
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2010  Creation                   Vadim Yelagin
//===================================================================
#ifndef CATCSCurvature_H
#define CATCSCurvature_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying curvature of a curve.
 */
class ExportedBySolverInterface CATCSCurvature : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSCurvature();

  virtual ~CATCSCurvature();

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
   * Retrieves value of the curvature.
   * @param oCurvature
   *   A value of the curvature.
   * @see #SetCurvature
   */
  virtual void GetCurvature(double &oCurvature);

  /**
   * Sets value of the curvature.
   * @param iCurvature
   *   A value of the curvature.
   * @see #GetCurvature
   */
  virtual void SetCurvature(const double iCurvature);

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Curvature;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetCurvature(iValue);}

  CATCDSInline void SetUseAbsoluteValue(CATCDSBoolean iValue) {_useAbsoluteValue = iValue;}

  CATCDSInline CATCDSBoolean GetUseAbsoluteValue() const {return _useAbsoluteValue;}
  
private:
  double _Curvature;
  CATCDSBoolean _useAbsoluteValue;
};

//-----------------------------------------------------------------------

#endif
