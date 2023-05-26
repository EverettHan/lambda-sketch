#ifndef CATICDSVariable_H
#define CATICDSVariable_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEntity.h"
#include "CATCDSBoolean.h"

class CATICDSFactory;

/**
 * An entity representing a variable.
 */
class ExportedByCDSInterface CATICDSVariable : public CATICDSEntity
{
public:

  /**
   * Sets the variable type.
   * @param iVarType
   *   A variable type.
   * @see #GetVariableType
   */
  virtual void SetVariableType(CATCDSVariableType iVarType) = 0;

  /**
   * Retrieves the variable type.
   * @return
   *   A variable type.
   * @see #SetVariableType
   */
  virtual CATCDSVariableType GetVariableType() const = 0;

  /**
   * Retrieves the variable tolerance.
   * @return
   *   A variable tolerance.
   * @see #SetTolerance
   */
  virtual double GetTolerance() const = 0;

  /**
   * Sets the variable tolerance.
   * @param iTolerance
   *   A variable tolerance.
   * @see #GetTolerance
   */
  virtual void SetTolerance(double iTolerance) = 0;

  /**
   * Sets the variable value.
   * @param iValue
   *   A variable value.
   * @see #GetValue
   */
  virtual void SetValue(double iValue) = 0;

  /**
   * Retrieves the variable value.
   * @return
   *   A variable value.
   * @see #SetValue
   */
  virtual double GetValue() const = 0;

  /**
   * Fixes the variable value.
   * @see #Unfix, #IsFixed
   */
  virtual void Fix() = 0;

  /**
   * Unfixes the variable value.
   * @see #Fix, #IsFixed
   */
  virtual void Unfix() = 0;

  /**
   * Checks whether the variable value is fixed.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if variable value is fixed
   *     <li><tt>FALSE</tt> - otherwise
   *   </ul>
   * @see #Fix, #Unfix
   */
  virtual CATCDSBoolean IsFixed() const = 0;

  /**
   * Sets limits for the variable value.
   * @param iLow
   *   A lower limit.
   * @param iHigh
   *   An upper limit.
   * @see #GetLimits, #SetLimitsActivity
   */
  virtual void SetLimits(double iLow, double iHigh) = 0;

  /**
   * Retrieves limits for the variable value.
   * @param oLow
   *   A lower limit.
   * @param oHigh
   *   An upper limit.
   * @see #SetLimits
   */
  virtual void GetLimits(double &oLow, double &oHigh) const = 0;

  /**
   * Sets activity status of limits.
   * @param iLowActive
   *   An activity status of the lower limit.
   * @param iHighActive
   *   An activity status of the upper limit.
   * @see #GetLimitsActivity, #SetLimits
   */
  virtual void SetLimitsActivity(CATCDSBoolean iLowActive, CATCDSBoolean iHighActive) = 0;

  /**
   * Retrieves activity status of limits.
   * @param oLowActive
   *   An activity status of the lower limit.
   * @param oHighActive
   *   An activity status of the upper limit.
   * @see #SetLimitsActivity
   */
  virtual void GetLimitsActivity(CATCDSBoolean &oLowActive, CATCDSBoolean &oHighActive) const = 0;

  /**
   * Creates an instance of the CATICDSVariable constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iVarType
   *   Creates one of the three variable types:  linear, angular, or free (used to declare equations).
   */
  static CATICDSVariable* Create(CATICDSFactory* ipFactory,
                                 CATCDSVariableType iVarType);

  virtual ~CATICDSVariable() {}
};

#endif
