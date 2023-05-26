// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATWBEnvironment.h
// Header definition of CATWBEnvironment
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /01/07     Creation (Sergey Lipski)
// 06/09/19 Q48 Add WBx level (moved from CATWBFactory)
// 26/11/19 Q48 Remove default constructor (enforce WB level)
//===================================================================

#ifndef CATWBEnvironment_h
#define CATWBEnvironment_h

#include "WhiteBoxMath.h"
#include "CATCDSBoolean.h"
#include "CATWBTypes.h"

/**
 * Error states
 */
const unsigned int CATWBError_InconsistentValue = 1;
const unsigned int CATWBError_WrongArgType = 2;
/**
* @brief The CATWBEnvironment class represents the structure defining the context  of the factory (tolerance, BBxPrecision, ...)
*/
class ExportedByWhiteBoxMath CATWBEnvironment
{
//private:
//  CATWBEnvironment();
  
public:
  CATWBEnvironment(const unsigned int iWBLevel);

  void SetError(unsigned int iError) const;
  void ClearError() const;
  void InitForEval(); // at the beginning of every evaluation, the previous possible CATWBError_InconsistentValue is removed 
  unsigned int GetError() const;

  void SetTolerance(double iTolerance);
  double GetTolerance() const;

  unsigned int GetWBLevel() const;

  // Trigonometric limits
  void SetTrigonometricLimits(double iLowValue, double iHighValue);
  void GetTrigonometricLimits(double & oLowValue, double & oHighValue) const;

  // Enumeration size
  void SetMaxEnumSize(int iSize);
  int GetMaxEnumSize() const;

  //
  // Options for black boxes
  //
  void SetBBAlgorithm(CATWBBlackBoxAlgorithm iMethod);
  CATWBBlackBoxAlgorithm GetBBAlgorithm() const;

  void SetBBPrecision(double iPrecision);
  double GetBBPrecision() const;

  void SetMaxNumberOfBBCalls(int iMaxNumber);
  int GetMaxNumberOfBBCalls() const;

  void SetNumberOfBBAttempts(int inAttempts);
  int GetNumberOfBBAttempts() const;

  void SetUseUnimodalInterval(CATCDSBoolean iUseUnimodal);
  CATCDSBoolean GetUseUnimodalInterval() const;

  void SetMinimizeNumberOfBBCalls(CATCDSBoolean iMinimize);
  CATCDSBoolean GetMinimizeNumberOfBBCalls() const;

  void SetUseOldSymbolicTransformations(CATCDSBoolean iUseOldSymbolicTransformations);
  CATCDSBoolean IsUseOldSymbolicTransformations() const;

  void SetBBWidth(double iWidth);
  double GetBBWidth() const;

  void SetBBCacheSize(int iCacheSize);
  int GetBBCacheSize() const;

private:
  unsigned int _error;
  double _tolerance;
  double _BBPrecision;
  double _BBWidth;
  double _TrigLimitLow, _TrigLimitHigh; // trigonometric limits

  CATWBBlackBoxAlgorithm _BBAlgorithm;
  int _MaxNumberOfBBCalls;
  int _NumberOfBBAttempts;
  int _BBCacheSize;
  int _MaxEnumSize;
  CATCDSBoolean _UseUnimodalInterval;
  CATCDSBoolean _MinimizeNumberOfBBCalls;
  CATCDSBoolean _IntegerDivision;
  CATCDSBoolean _UseOldSymbolicTransformations;

  const unsigned int _WBLevel;
};

//-----------------------------------------------------------------------

#endif
