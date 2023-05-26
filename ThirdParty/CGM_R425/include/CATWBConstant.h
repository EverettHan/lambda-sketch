// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBConstant.h
// Header definition of CATWBConstant
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
// 24/07/18 Q48  Make DoEval const (for printer)
// 10/12/18 Q48  Make IntegrateTable methods protected
// 29/07/19 Q48  Add protected constructor for JSON streaming
// 09/09/19 TE9  Add PartialEval
//===================================================================

#ifndef CATWBConstant_h
#define CATWBConstant_h

#include "CATCDSVirtual.h"
#include "CATWBExpression.h"
#include "CATWBValue.h"

//-----------------------------------------------------------------------
/**
* @brief The CATWBConstant class represents the structure of the  constants in the formal expressions.
*/
class ExportedByWhiteBoxData CATWBConstant : public CATWBExpression
{
public:
  CATWBConstant(CATWBFactory & iFactory, const CATWBValue & iValue);
  virtual ~CATWBConstant();

  virtual CATCDSBoolean IsEqualTo(const CATWBExpression * ipExpression) const CATCDSOverride;
  virtual void IsZeroOrOne(CATCDSBoolean & oIsNull, CATCDSBoolean & oIsEqualToOne) const;

  virtual int GetNbOfChildren() const CATCDSOverride;
  virtual CATWBExpression * GetChild(int iIdx) CATCDSOverride;
  virtual const CATWBExpression * GetChild(int iIdx) const CATCDSOverride;
  virtual CATCDSBoolean ReplaceChild(int iIdx, CATWBExpression * ipChild) CATCDSOverride;

  virtual CATWBExpression * Evaluate(int iNVariables, CATWBVariable **iapVar, CATWBExpression **iapVal) CATCDSOverride;

  virtual CATCDSBoolean IsFree(CATWBVariable const * ipVariable) const CATCDSOverride;

  virtual void FillPresentVariables(CATCDSBoolean * iaVariables) const CATCDSOverride;

  virtual const CATWBValue & GetExprValue() const CATCDSOverride;

  virtual void SetValue(const CATWBValue & iValue, CATWBExpression * ipRootToReset = 0);
  
  virtual CATWBExpression* PartialEval(CATWBVariable ** iapVar, CATWBExpression ** iapVal, const int iNumVar) CATCDSOverride;

public:

   // Memory usage optimisation
   // -------------------------

   virtual void RemoveUniqueChildren();

protected:
  CATWBConstant(CATWBFactory & iFactory, const CATWBValue & iValue, const CATWBExpressionType iType);

  virtual void DoEval(CATWBValue & oValue) const CATCDSOverride;

  virtual CATWBExpression* DifferentiateProtected(CATWBVariable * ipVariable) CATCDSOverride;
  
  virtual CATWBExpression* IntegrateTableProtected(CATWBVariable * ipVariable, CATCDSBoolean & oSuccess) CATCDSOverride;

  // Streaming
  // ---------

protected:
  
  friend class CATWBFactory;
  CATWBConstant(CATWBFactory & iFactory, const int iTag, const CATWBValue & iValue);
  CATWBConstant(CATWBFactory & iFactory, const int iTag, const CATWBValue & iValue, const CATWBExpressionType iType);

  // Data
  // ----

  CATWBValue _value;
  
#ifdef WBX_DEBUG_TRACE
public:

  virtual void Debug_PrintStructure() const CATCDSOverride;
  virtual CATCDSString Debug_SymbolString(const short iLongMode) const CATCDSOverride;
#endif
};

//-----------------------------------------------------------------------

#endif
