// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATWBSymbolicTransformations.h
// Header definition of CATWBSymbolicTransformations
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /12/08      Creation (Sergey Lipski)
// 07/03/19 Q48  Make stream version part of the class
// 07/03/19 Q48  Migration to CATCDSStream
//===================================================================

#ifndef CATWBSymbolicTransformations_h
#define CATWBSymbolicTransformations_h

// Base class header
#include "CATCDSOperator.h"

// CDS
#include "CATCDSVirtual.h"
#include "CATCDSBoolArray.h"
#include "CATCDSString.h"
#include "CATCDSIntArray.h"

#include "SymbolicTransformations.h"

class CATWBFactory;
class CATWBExpression;

//-----------------------------------------------------------------------

const unsigned int CATWBCalcLinearProperty = 0x01;
const unsigned int CATWBCalcGauss = 0x02;
const unsigned int CATWBSimplify = 0x04;
const unsigned int CATWBUnrollNAry = 0x08;
const unsigned int CATWBCheckInequalities = 0x10;

extern ExportedBySymbolicTransformations char const * const CATWBConstantProperty;
extern ExportedBySymbolicTransformations char const * const CATWBLinearProperty;
/**
* @brief The CATWBSymbolicTransformations class represents the operator of simplification of the formal expressions.
*/
class ExportedBySymbolicTransformations CATWBSymbolicTransformations : public CATCDSOperator
{
public:
  CATWBSymbolicTransformations(const unsigned int iCDSLevel, CATWBFactory & iFactory);
  virtual ~CATWBSymbolicTransformations();

  virtual void InitWithEnv() CATCDSOverride;

  int GetVersionOfStream() const CATCDSFinal;

  virtual CATCDSBoolean CheckInput(CATCDSStream & ioStream) const CATCDSFinal;
  virtual CATCDSBoolean CheckOutput(CATCDSStream & ioStream) const CATCDSFinal;

  virtual CATCDSBoolean SetEquationToSimplify(int iEquationId);

  void SetMode(unsigned int iMode);
  unsigned int GetMode();

  virtual CATCDSBoolean AreInequalitiesInconsistent();

protected:

  // Internal data
  // -------------

  enum CATWBProperty
  {
    prConstant,
    prLinear,
    prMaxNum
  };

  enum SubstituteMode
  {
    smUnknown,
    smForce,
    smDisable
  };

  void SetProperty(CATWBExpression* ipExpression, CATWBProperty iProperty, CATCDSBoolean iValue = TRUE);
  CATCDSBoolean GetProperty(CATWBExpression* ipExpression, CATWBProperty iProperty);
  void SetProperties(CATWBExpression* ipExpression);

  CATWBFactory& _Factory;
  unsigned int _mode;
  int _aProperties[prMaxNum];

public:

  static const int _CurrentStreamVersion;

private:
  CATCDSDeclareOperator;
};

//-----------------------------------------------------------------------

/**
 * Create a symbolic transformation object.
 * @return a pointer to the created object
 */
ExportedBySymbolicTransformations
  CATWBSymbolicTransformations * CATCreateWBSymbolicTransformations(unsigned int iCDSLevel, CATWBFactory & iFactory);

/**
 * Remove a symbolic transformation object.
 * @param ipToRemove a pointer to the object to be removed
 */
ExportedBySymbolicTransformations
  void CATRemove(CATWBSymbolicTransformations * ipToRemove);


#endif
