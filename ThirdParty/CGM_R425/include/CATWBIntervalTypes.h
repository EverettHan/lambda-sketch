// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATWBIntervalTypes.h
// Header definition of interval types for CATWBValue
//
//===================================================================
//
// Usage notes: A types for White Boxes equations support in CDS.
//
//===================================================================
//
//   /04/07      Creation (Sergey Lipski)
// 11/06/19 Q48  Migration to class for integer / real enum type
// 11/06/19 Q48  Fix initial values for enums for streaming
//===================================================================

#ifndef CATWBIntervalTypes_h
#define CATWBIntervalTypes_h


//#define WDE1Proto_LongInteger

#include "WhiteBoxMath.h"
#include "CATWBEnvironment.h"

struct CATWBIntegerInterval
{
  int _lo;
  int _hi;
};

struct CATWBRealInterval
{
  double _lo;
  double _hi;
};

enum CATWBBoolean
{
  wbFalse = 0,
  wbTrue,
  wbIndef,
  wbContr
};

enum CATWBEnumRepresentation
{
  erList = 0,
  erInterval,
  erAny,
  erNil
};

#include "CATWBConstants.h"

//
// CATWBIntegerEnum class
//

class ExportedByWhiteBoxMath CATWBIntegerEnum
{
public:
  
  CATWBIntegerEnum(CATWBEnumRepresentation iView = erAny);
  ~CATWBIntegerEnum();

  CATWBIntegerEnum(const CATWBIntegerEnum & iVal);

  CATWBIntegerEnum & operator = (const CATWBIntegerEnum & iEnum);

  void Remove(int iValue);
  void Insert(int iValue);
  void Append(int iValue);

  /**
   * Correct the internal representation of the value.
   * This method should be call after the Set* methods
   * SetAsIntegerInterval, Set, and SetRep
   * to fix the created value.
   */
  void Correct(const CATWBEnvironment & iEnv);

  void SetNil();
  void SetAny();
  CATCDSBoolean IsNil() const { return _representation == erNil; }
  CATCDSBoolean IsAny() const { return _representation == erAny; }

  // for enumerations (_representation == erList) only
  void SetSize(int iSize);
  int GetSize() const;
  void Set(int iIdx, int iValue);
  int Get(int iIdx) const;
  void RemovePosition(int iPos, int iSize);
  int FindLT(int iValue) const;
  int FindGT(int iValue) const;
  CATCDSBoolean Find(int iValue, int &oIdx) const;

  // for intervals (_representation == erInterval) only
  CATWBIntegerInterval GetAsIntegerInterval() const;
  void SetAsIntegerInterval(const CATWBIntegerInterval &iValue);

  void SetRep(CATWBEnumRepresentation iView) { _representation = iView; }
  CATWBEnumRepresentation GetRep() const { return _representation; }

private:
  // for intervals (_representation == erInterval) only
  void ExpandInterval(int iValue);
  void ReduceInterval(int iValue);

  void EnsureSize(int iSize);

  int* _aValues;
  int _size, _max_size;
  CATWBEnumRepresentation _representation;
};

//
// CATWBRealEnum class
//

class ExportedByWhiteBoxMath CATWBRealEnum
{
public:

  CATWBRealEnum(CATWBEnumRepresentation iView = erAny);
  ~CATWBRealEnum();

  CATWBRealEnum(const CATWBRealEnum & iEnum);
  CATWBRealEnum & operator = (const CATWBRealEnum & iEnum);
  CATWBRealEnum & operator = (const CATWBIntegerEnum & iEnum);

  void Append(double iValue);
  void Insert(double iValue, double iTolerance);
  void Remove(double iValue, double iTolerance = CATWBAbsPrecision);

  /**
   * Correct the internal representation of the value.
   * This method should be call after the Set* methods
   * SetAsIntegerInterval, Set, and SetRep
   * to fix the created value.
   */
  void Correct(const CATWBEnvironment & iEnv);

  void SetNil();
  void SetAny();
  CATCDSBoolean IsNil() const { return _representation == erNil; }
  CATCDSBoolean IsAny() const { return _representation == erAny; }

  // for enumerations (_representation == erList) only
  void SetSize(int iSize);
  int GetSize() const;
  void Set(int iIdx, double iValue);
  double Get(int iIdx) const;
  void RemovePosition(int iPos, int iSize);
  int FindLT(double iValue) const;
  int FindGT(double iValue) const;
  CATCDSBoolean Find(double iValue, int &oIdx, double iTolerance = 0.0) const;

  // for intervals (_representation == erInterval) only
  CATWBRealInterval GetAsRealInterval() const;
  void SetAsRealInterval(const CATWBRealInterval &iValue);

  void SetRep(CATWBEnumRepresentation iView) { _representation = iView; }
  CATWBEnumRepresentation GetRep() const { return _representation; }
  
private:
  // for intervals (_representation == erInterval) only
  void ExpandInterval(double iValue);
  void ReduceInterval(double iValue, double iTolerance = CATWBAbsPrecision);

  void EnsureSize(int iSize);

  double* _aValues;
  int _size, _max_size;
  CATWBEnumRepresentation _representation;
};

#endif
