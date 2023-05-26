// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSVariable.h
// Header definition of CATCSVariable
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation:                       Ilia IVANOV
//===================================================================
#ifndef CATCSVariable_H
#define CATCSVariable_H

class CATCDSIntArray;

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCDSBoolean.h"
#include "CATCSEntity.h"
#include "CATCDSArray.h"
#include "CATCDSListP.h"

//-----------------------------------------------------------------------

/**
 * An entity representing a variable.
 */
class ExportedBySolverInterface CATCSVariable : public CATCSEntity
{
public:
  /**
   * Constructs an instance of the variable.
   * @param iVarType
   *   A type of the variable.
   */
  CATCSVariable(CATCSVariableType iVarType = vtFREE);

  virtual ~CATCSVariable();

  /**
   * Retrieves type of the entity.
   * @return
   *   Type of the entity.
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
   * Sets type of the variable.
   * @param iVarType
   *   A type of the variable.
   * @see #GetVariableType
   */
  void SetVariableType(CATCSVariableType iVarType);

  /**
   * Retrieves type of the variable.
   * @return
   *   A type of the variable.
   * @see #SetVariableType
   */
  CATCSVariableType GetVariableType() const;

  /**
   * Retrieves tolerance of the variable.
   * @return
   *   A tolerance of the variable.
   * @see #SetTolerance
   */
  double GetTolerance() const;

  /**
   * Sets tolerance of the variable.
   * @param iTolerance
   *   A tolerance of the variable.
   * @see #GetTolerance
   */
  void SetTolerance(double iTolerance);

  /**
   * Sets value of the variable.
   * @param iValue
   *   A value of the variable.
   * @see #GetValue
   */
  virtual void SetValue(double iValue);

  /**
   * Retrieves value of the variable.
   * @return
   *   A value of the variable.
   * @see #SetValue
   */
  virtual double GetValue() const;

  /**
   * Fixes value of the variable.
   * @see #Unfix, #IsFixed
   */
  virtual void Fix();

  /**
   * Unfixes value of the variable.
   * @see #Fix, #IsFixed
   */
  virtual void Unfix();

  /**
   * Checks whether a value of the variable is fixed.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if value of the variable is fixed,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   * @see #Fix, #Unfix
   */
  virtual CATCDSBoolean IsFixed() const;

  /**
   * Sets limits for a value of the variable.
   * @param iLow
   *   A lower limit.
   * @param iHigh
   *   An upper limit.
   * @see #GetLimits, #SetLimitsActivity
   */
  virtual void SetLimits(double iLow, double iHigh);

  /**
   * Retrieves limits for a value of the variable.
   * @param oLow
   *   A lower limit.
   * @param oHigh
   *   An upper limit.
   * @see #SetLimits
   */
  virtual void GetLimits(double &oLow, double &oHigh);

  /**
   * Sets activity status of limits.
   * @param iLowActive
   *   An activity status of the lower limit.
   * @param iHighActive
   *   An activity status of the upper limit.
   * @see #GetLimitsActivity, #SetLimits
   */
  virtual void SetLimitsActivity(CATCDSBoolean iLowActive, CATCDSBoolean iHighActive);

  /**
   * Retrieves activity status of limits.
   * @param oLowActive
   *   An activity status of the lower limit.
   * @param oHighActive
   *   An activity status of the upper limit.
   * @see #SetLimitsActivity
   */
  virtual void GetLimitsActivity(CATCDSBoolean &oLowActive, CATCDSBoolean &oHighActive);

  /**
   * Retrieves the list of callbacks linked to this variable.
   * @param oCallbacks
   *   List of callback pointers
   * @param oIndexes
   *   List of indexes (index of the variable in the corresponding callback)
   *
   * @SKIP
   */
  virtual void GetLinkedNodes(CATCDSLISTP(CATCSEntity) &oCallbacks, CATCDSIntArray &oIndexes);

  /**
   * Checks if the current value (or a value pointed by ipTargetValue) is in domain, as defined by the user limits.
   * @param ipTargetValue
   *   An optional pointer to the value to check (if NULL the value returned by GetValue is used).
   * @return
   *    TRUE if the value is in domain, FALSE otherwise
   * @see #SetLimits, #SetLimitsActivity
   */
  virtual CATCDSBoolean IsInDomain(double * ipTargetValue = 0);

protected:
  CATCSVariableType _varType;
  double _tolerance;
  double _dValue, _dLow, _dHigh;
  CATCDSBoolean _bFixed, _bLowActive, _bHighActive;
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSVariable, ExportedBySolverInterface);
CATCDSARRAY_DECLARE(CATCDSListPCATCSVariable);

//-----------------------------------------------------------------------

#endif
