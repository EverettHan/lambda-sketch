/* -*-C++-*-*/
#ifndef CATImplicitTopOperator_H
#define CATImplicitTopOperator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATImplicitTopOperator
//
// DESCRIPTION :
// virtual mother class for all CATImplicit CATTopOperators
//
//
// History
//
// Nov. 2021 WZC Creation
//
//=============================================================================

#include "GMScalarFieldsOperators.h"

#include "CATTopOperator.h"     // derivation

#include "CATMathInline.h"      // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"     // HRESULT


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATImplicitOperTopExt;
class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;
class CATString;



class ExportedByGMScalarFieldsOperators CATImplicitTopOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATImplicitTopOperator);

public:


  /**
  * Destructor
  */
  virtual ~CATImplicitTopOperator();

  /**
  * @nodoc @nocgmitf 
  */
  INLINE CATImplicitOperTopExt & GetCATImplicitOperExtension();

protected:

  /**
  * Constructor
  * @nodoc @nocgmitf 
  */
  CATImplicitTopOperator(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt & iPolyExtension);


  /**
  * Runs the operator
  * @nodoc @nocgmitf 
  */
  virtual int RunOperator();


protected:
  
  // ------------------
  // CGMReplay Methods
  // ------------------
  /* @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  virtual void RequireDefinitionOfInputAndOutputObjects();

  /**
  * @nodoc @nocgmitf 
  * Computation method returning the result Body (may be null), including CATTry/CATCatch mechanism
  * This method guarantees that the potential error is caught
  */
  HRESULT RunAndGetResult(CATBody * &oResultBody, CATError * &oResultError, CATBodyFreezeMode iFreezeMode=CATBodyFreezeOff, CATBoolean iPersistencyTransactionMode=FALSE);
  
private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATImplicitTopOperator();
  CATImplicitTopOperator(const CATImplicitTopOperator& iOneOf); 
  CATImplicitTopOperator& operator =(const CATImplicitTopOperator& iOneOf);


protected:
   
  CATImplicitOperTopExt &             _implicitOperExtension;

};

// INLINE methods
// ==============

INLINE CATImplicitOperTopExt & CATImplicitTopOperator::GetCATImplicitOperExtension() {
  return _implicitOperExtension; 
}

#endif
