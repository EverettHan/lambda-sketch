// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATWBEquations:
//   Class maintains system of equations with variables and
//   can read and write itself in CATCDSStream.
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
//   /04/07      Creation (Vladislav Kornienko)
// 07/03/19 Q48  Migration of some global methods to static on class
// 07/03/19 Q48  Data storage classes to create list from CATWBTypes.h
//=============================================================================

#ifndef CATWBEquations_h
#define CATWBEquations_h

#include "CATCDSDebug.h"

#ifdef CDS_DEBUG

#include "CATCDSCPlusPlusVersions.h"

#include "CATCDSBoolean.h"
#include "CATCDSIntArray.h"

#include "CATCDSExpressionTerm.h"
#include "CATCDSStorage.h"
#include "CATCDSString.h"


#include "CATWBTypes.h"
#include "CATWBValue.h"
#include "WhiteBoxUtilities.h"

class CATCDSStream;
class CATWBFactory;
class CATWBVariable;
class CATWBEquation;
class CATWBExpression;

// Auxiliary functions
//!todo move them to proper place
ExportedByWhiteBoxUtilities CATCDSString ValueTypeToString(CATWBValueType iType);
ExportedByWhiteBoxUtilities CATWBValueType StringToValueType(const CATCDSString & iType);
ExportedByWhiteBoxUtilities CATCDSString BooleanToString(CATWBBoolean iValue);
ExportedByWhiteBoxUtilities CATCDSBoolean StringToBoolean(const CATCDSString & iString, CATWBBoolean & oValue);
//ExportedByWhiteBoxUtilities CATCDSString ValueToString(const CATWBValue & iValue);
ExportedByWhiteBoxUtilities CATCDSString EquationTypeToString(CATWBEquationType iType);
ExportedByWhiteBoxUtilities CATCDSExpressionType ExprTypeToOper(CATWBExpressionType iType);
ExportedByWhiteBoxUtilities CATWBExpressionType OperToExprType(CATCDSExpressionType iType);
//ExportedByWhiteBoxUtilities CATCDSString ExprTypeToString(CATWBExpressionType iType);
//ExportedByWhiteBoxUtilities CATWBExpressionType StringToExprType(const CATCDSString & iType);

// ----------------------------------------------------------------------------------------
// CATWBEquations class
// ----------------------------------------------------------------------------------------

#ifndef CPP11_AVALAIBLE
#define WBx_StaticArraysForList // Switch for static arrays or not (avoid if possible)
#endif

// ----------------------------------------------------------------------------------------
// Force (old) static initialisation as a backup mode in case of build error
//#define WBx_StaticArraysForList
// ----------------------------------------------------------------------------------------

class ExportedByWhiteBoxUtilities CATWBEquations
{
public:
  CATWBEquations(CATWBFactory & iFactory, CATCDSStorage::ReplayPart iPart, const int iVersionOfStream);

  virtual ~CATWBEquations();

  void Write(CATCDSStream & ioStream, CATCDSBoolean iStrict = FALSE) const;

  void GetListEqToSimplify(CATCDSIntArray& oaEqToSimplify) const;
  void SetListEqToSimplify(const CATCDSIntArray& iaEqToSimplify);

protected:
  CATCDSExpressionTerm* CreateTerm(const CATWBExpression* ipExpr, CATCDSBoolean iNAryFunctions) const;

  CATCDSString ExprTypeToStringParse(CATWBExpressionType iType) const;
  CATCDSString ExprTypeToStringPrint(CATWBExpressionType iType) const;

  CATWBExpressionType StringParseToExprType(const CATCDSString & iStr) const;

public:  

  static CATCDSString        ExprTypeToStringPrint(const CATWBExpressionType   iType, const int iVersionOfStream);
  static CATWBExpressionType StringParseToExprType(const CATCDSString        & iStr , const int iVersionOfStream);

protected:

  CATCDSString ValueToString(const CATWBValue & iValue) const;
  CATCDSString FractionToName(const CATWBFraction & iValue) const;

  void WriteVariables(CATCDSStorage& ioStorage) const;
  void WriteValues(CATCDSStorage& ioStorage) const;
  void WriteEquations(CATCDSStorage& ioStorage, CATCDSBoolean iStrict) const;
  void WriteEnvironment(CATCDSStorage& ioStorage) const;
  void WriteEquationsToSimplify(CATCDSStorage& ioStorage) const;

  CATWBExpression * CreateExpression(const CATCDSExpressionTerm * ipRoot);

  CATWBEquations(const CATWBEquations & iEquations);
  CATWBEquations & operator = (const CATWBEquations & iEquations);

  CATCDSIntArray _aEqToSimplify;
  CATWBFactory& _factory;
  CATCDSStorage::ReplayPart _part;

  const int _VersionOfStream;

  // Data storage
public:

  class CATWBExpressionTypeUtility
  {
  protected:
    CATWBExpressionTypeUtility();

  public:
    CATWBExpressionTypeUtility(const CATWBExpressionType   iType, 
                               const CATCDSString        & iStr);

    CATWBExpressionTypeUtility(const CATWBExpressionType   iType, 
                               const CATCDSString        & iStrToParse,
                               const CATCDSString        & iStrToPrint);
    ~CATWBExpressionTypeUtility();

    //CATCDSBoolean MatchesStr(const CATCDSString & iStr) const;

    CATWBExpressionType GetType() const;
    CATCDSString GetStringToParse(const int iStreamVersion) const;
    CATCDSString GetStringToPrint(const int iStreamVersion) const;


  private:
    CATWBExpressionType _Type;
    CATCDSString        _StrParse;

    CATCDSBoolean       _IsDifferentStr;
    CATCDSString        _StrPrint;
  };

  class CATWBExpressionTypeUtilityList
  {
  protected: // cannot be constructed outside the class --> only access via static GetList
    
    CATWBExpressionTypeUtilityList();
    ~CATWBExpressionTypeUtilityList();

  public:
    static const CATWBExpressionTypeUtilityList& GetList(); // only public access

    int Size() const;
    const CATWBExpressionTypeUtility& Get(const int iIndex) const;

  private:

#ifdef WBx_StaticArraysForList
    static const CATWBExpressionTypeUtility _ExpressionTypes[];
#else
    const CATWBExpressionTypeUtility _ExpressionTypes[CATWBExpressionType::etTypeEND];
#endif
  };

protected:
 
  const CATWBExpressionTypeUtilityList& _ExpressionTypes; // cache a reference to the static instance of the list
};

#endif CDS_DEBUG
#endif
