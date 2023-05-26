// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBVariable.h
// Header definition of CATWBVariable
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
// 10/12/18 Q48  Make IntegrateTable methods protected
// 29/07/19 Q48  Add protected constructor for JSON streaming
// 09/09/19 TE9  Add PartialEval
//===================================================================

#ifndef CATWBVariable_h
#define CATWBVariable_h

#include "CATCDSVirtual.h"
#include "CATCDSString.h"
#include "CATWBConstant.h"
#include "CATWBValue.h"

class CATWBFactory;

//-----------------------------------------------------------------------
/**
* @brief The CATWBVariable class represents the structure of the  variables in the formal expressions.
*/
class ExportedByWhiteBoxData CATWBVariable : public CATWBConstant
{
public:
  CATWBVariable(CATWBFactory & iFactory, const int iIdx);
  virtual ~CATWBVariable();

  virtual CATCDSBoolean IsEqualTo(const CATWBExpression * ipExpression) const CATCDSOverride;

  //virtual CATWBExpression * Differentiate(CATWBVariable * ipVariable) CATCDSOverride;

  virtual CATWBExpression * Evaluate(int iNVariables, CATWBVariable **iapVar, CATWBExpression **iapVal) CATCDSOverride;

  virtual CATCDSBoolean IsFree(CATWBVariable const * ipVariable) const CATCDSOverride;

  virtual void FillPresentVariables(CATCDSBoolean * iaVariables) const CATCDSOverride;

  virtual void SetExprValue(const CATWBValue & iValue) /*const*/ CATCDSOverride;

  virtual CATWBExpression* PartialEval(CATWBVariable ** iapVar, CATWBExpression ** iapVal, const int iNumVar) CATCDSOverride;

  int GetIdx() const;

  void SetPreferedValue(double iValue);
  CATCDSBoolean GetPreferedValue(double & oValue) const;

  void Fix(CATCDSBoolean iFix);
  CATCDSBoolean IsFixed() const;

  void SetDividedFlag(int iFlag);
  int GetDividedFlag() const;

  void SetName(const CATCDSString& iaName);
  const CATCDSString& GetName() const;
  const char* GetStrName() const { return GetName().str(); }

protected:

  virtual CATWBExpression* DifferentiateProtected(CATWBVariable * ipVariable) CATCDSOverride;
  
  virtual CATWBExpression* IntegrateTableProtected(CATWBVariable * ipVariable, CATCDSBoolean & oSuccess) CATCDSOverride;

  // Streaming
  // ---------

protected:

  friend class CATWBFactory;
  CATWBVariable(CATWBFactory & iFactory, const int iTag, const int iIdx);

  // Data

  const int _idx;
  double _preferedValue;
  CATCDSBoolean _hasPref, _fixed;
  int _dividedFlag;

  CATCDSString _name;

#ifdef WBX_DEBUG_TRACE
public:

  void Debug_PrintStructure() const CATCDSOverride CATCDSFinal;
  CATCDSString Debug_SymbolString(const short iLongMode) const CATCDSOverride CATCDSFinal;
#endif
};

//-----------------------------------------------------------------------

CATCDSLISTP_DECLARE_EXPORTED(CATWBVariable, ExportedByWhiteBoxData);

#endif
