// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBValue.h
// Header definition of CATWBValue
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
// 27/11/19 Q48  Versioning using cached CATWBEnvironment
// 29/11/19 Q48  UMR: every object needs unique versioning
// 01/06/22 Q48  Migrate some debug utilities
//===================================================================

#ifndef CATWBValue_h
#define CATWBValue_h

#include "CATCDSBoolean.h"
#include "WhiteBoxMath.h"
#include "CATWBTypes.h"
#include "CATWBIntervalTypes.h"
#include "CATWBFraction.h"
#include "CATCDSListP.h"

class CATWBEnvironment;
class CATWBFactory;

// Debug
#include "CATWBDebug.h"

#ifdef WBX_DEBUG_TRACE 
#include "CATCDSString.h"
#endif

//-----------------------------------------------------------------------
/**
* @brief The CATWBValue class represents the structure which stores all possible “values” for variables (integer, real, interval, enumerations, boolean ) 
*/
class ExportedByWhiteBoxMath CATWBValue
{
public:
  CATWBValue(CATWBValueType iType = vtUndefined);
  CATWBValue(int iValue);
  CATWBValue(double iValue);
  CATWBValue(const CATWBIntegerInterval & iValue);
  CATWBValue(const CATWBRealInterval & iValue);
  CATWBValue(CATWBBoolean iValue);
  CATWBValue(const CATWBIntegerEnum & iValue);
  CATWBValue(const CATWBRealEnum & iValue);
  CATWBValue(const CATWBFraction & iValue);
  ~CATWBValue();

  CATWBValue(const CATWBValue & iValue);
  CATWBValue & operator = (const CATWBValue & iValue);

  CATWBValue * Clone() const;

  void UpdateEnv(const CATWBFactory     & iFactory);
  void UpdateEnv(const CATWBEnvironment & iEnv) const;

  CATWBValueType GetType() const;

  /**
   * return TRUE if it can be casted
   */
  CATCDSBoolean IsAKindOf(CATWBValueType iType) const;

  /**
   * return TRUE if it can be converted (integer->real but not real->integer)
   * This method is synchronized with GetAs... methods
   */
  CATCDSBoolean IsConvertible(CATWBValueType iType) const;

  CATCDSBoolean IsEmpty(const CATWBEnvironment & iEnv) const;
  CATCDSBoolean IsConsistent(const CATWBEnvironment & iEnv) const { return !IsEmpty(iEnv); }
  CATCDSBoolean IsExact(const CATWBEnvironment & iEnv) const;
  CATCDSBoolean IsEqualTo(const CATWBEnvironment & iEnv, const CATWBValue & iValue) const;
  CATCDSBoolean IsIndefinite(const CATWBEnvironment & iEnv) const;

  void Set(int iValue);
  void Set(double iValue);
  void Set(const CATWBIntegerInterval& iValue);
  void Set(const CATWBRealInterval& iValue);
  void Set(CATWBBoolean iValue);
  void Set(const CATWBIntegerEnum & iValue);
  void Set(const CATWBRealEnum & iValue);

  void Set(int iSize, const int * iaValues);
  void Set(int iSize, const double * iaValues);
  void SetIndefinite();

  void Set(const CATWBFraction& iValue);

  void Assign(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
  void AssignWithType(const CATWBEnvironment & iEnv, const CATWBValue & iValue);

  //Intersect returns TRUE if this changes and FALSE otherwise
  CATCDSBoolean Intersect(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
  void Exclude(const CATWBEnvironment & iEnv, const CATWBValue & iValue);
  void Unite(const CATWBEnvironment & iEnv, const CATWBValue & iValue);

  /**
   * Converts from any type and returns double value for real evaluator.
   */
  double GetAsDouble() const;

  int GetAsInteger() const;
  double GetAsReal() const;
  CATWBIntegerInterval GetAsIntegerInterval() const;
  CATWBRealInterval GetAsRealInterval() const;
  CATWBBoolean GetAsBoolean() const;

  void SimplifyFraction(CATCDSBoolean iToBaseType = FALSE);
  CATCDSBoolean IsAFraction() const;
  CATWBFraction GetAsFraction() const;

  void GetAsIntegerEnum(CATWBIntegerEnum & oRes) const;
  void GetAsRealEnum(CATWBRealEnum & oRes) const;

  CATWBIntegerEnum & GetIntegerEnum();
  const CATWBIntegerEnum & GetIntegerEnum() const;
  CATWBRealEnum & GetRealEnum();
  const CATWBRealEnum & GetRealEnum() const;

  double GetMiddle() const;
  double GetWidth() const;
  double GetMAG() const;
  
  // Streaming
  // ---------

private:

  friend class CATWBxValueUnStr;
  void Load(const CATWBFraction & iFrac);

private:

  CATWBValueType _type;

  union 
  {
    CATWBIntegerInterval _iValue;
    CATWBRealInterval _rValue;
    CATWBBoolean _bValue;
  };

  CATWBFraction _fValue;
  CATWBIntegerEnum _ieValue;
  CATWBRealEnum _reValue;

  mutable CATWBEnvironment const * _Env; // for versioning changes

//#ifdef WBX_DEBUG_TRACE
public:
  CATCDSString Str() const;
//#endif // WBX_DEBUG_TRACE
};

CATCDSLISTP_DECLARE_EXPORTED(CATWBValue, ExportedByWhiteBoxMath);
//-----------------------------------------------------------------------

#endif
