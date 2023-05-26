// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBOperator.h
// Header definition of CATWBOperator
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
// 23/03/17 Q48  Refactor of differentiate methods
// 10/12/18 Q48  Make IntegrateTable methods protected
// 29/07/19 Q48  Add protected constructor for JSON streaming
// 03/09/19 Q48  Add define to remove inactive old code for differentiate
// 19/09/19 Q48  Remove define (old code for differentiate is needed)
//===================================================================

#ifndef CATWBOperator_h
#define CATWBOperator_h

// Class header
#include "CATWBExpression.h"

// ExportedBy
#include "WhiteBoxData.h"

// C++11
#include "CATCDSVirtual.h"

//-----------------------------------------------------------------------
 /**
  * @brief The CATWBOperator class represents the generic structure which manages the operators.
  */
class ExportedByWhiteBoxData CATWBOperator : public CATWBExpression
{
public:
  CATWBOperator(      CATWBFactory         & iFactory,
                const CATWBExpressionType    iType,
                const int                    inChildren,
                      CATWBExpression     ** iapChildren);

  virtual ~CATWBOperator();

  virtual CATCDSBoolean IsFree(CATWBVariable const * ipVariable) const CATCDSOverride;

  virtual CATCDSBoolean IsEqualTo(const CATWBExpression * ipExpression) const CATCDSOverride;

  virtual int GetNbOfChildren() const CATCDSOverride;

  virtual       CATWBExpression * GetChild(int iIdx) CATCDSOverride;
  virtual const CATWBExpression * GetChild(int iIdx) const CATCDSOverride;

  virtual CATCDSBoolean ReplaceChild(int iIdx, CATWBExpression * ipChild) CATCDSOverride;

  virtual void FillPresentVariables(CATCDSBoolean * iaVariables) const CATCDSOverride;

  virtual void ResetBuffer(const CATCDSBoolean iRecursive = TRUE) CATCDSOverride;

  virtual double GetParameter(int iIdx) const CATCDSOverride;
  virtual int GetNbOfParameters() const CATCDSOverride;

  virtual CATWBExpression * Evaluate(int iNVariables, CATWBVariable **iapVar, CATWBExpression **iapVal) CATCDSOverride;

public:

   // Memory usage optimisation
   // -------------------------

   virtual void RemoveUniqueChildren();

protected:

  CATCDSBoolean IsEqualChildren(const CATWBExpression * ipExpression) const;

private:
  
  CATCDSBoolean IsEqualChildren_Order(const CATWBExpression * ipExpression) const;
  CATCDSBoolean IsEqualChildren_NoOrder(const CATWBExpression * ipExpression) const;

protected:

          CATWBExpression * DoDifferentiate(CATWBVariable * ipVariable);

          CATCDSBoolean CheckChildIndex(const int iChildIndex) const;
  virtual CATWBExpression* DifferentiateChild(const int iChildIndex, /*const*/ CATWBExpression* iChildDeriv);
  
  virtual CATWBExpression* IntegrateTableProtected(CATWBVariable * ipVariable, CATCDSBoolean & oSuccess) CATCDSOverride;

  CATCDSBoolean RemoveChild(CATWBExpression* iChild) CATCDSOverride;

  virtual CATCDSBoolean ValidateAllowBufferEval() const CATCDSOverride;

  // Streaming
  // ---------

protected:

  CATWBOperator(      CATWBFactory         & iFactory,
                const int                    iTag,
                const CATWBExpressionType    iType,
                const int                    inChildren,
                      CATWBExpression     ** iapChildren);

private:
  void CommonInitChildren(const int                    inChildren,
                                CATWBExpression     ** iapChildren);

  // Data
  // ----

protected:

  CATCDSLISTP(CATWBExpression) _apChildren;

#ifdef WBX_DEBUG_TRACE
public:

  void Debug_PrintStructure() const CATCDSOverride CATCDSFinal;
  void Debug_PrintChildrenStructure() const;
 
#endif
};

//-----------------------------------------------------------------------

#endif
