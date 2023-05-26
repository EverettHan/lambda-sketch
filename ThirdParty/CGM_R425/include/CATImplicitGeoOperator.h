/* -*-C++-*-*/
#ifndef CATImplicitGeoOperator_H
#define CATImplicitGeoOperator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2023
//
// CATImplicitGeoOperator
//
// DESCRIPTION :
// virtual mother class for all CATImplicit CATCGMOperators
//
//
// History
//
// 2023-02 XXC Creation
//
//=============================================================================

#include "GMScalarFieldsOperators.h"

#include "CATCGMOperator.h"     // derivation

#include "CATMathInline.h"      // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"     // HRESULT


class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATImplicitOperGeoExt;
class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;
class CATString;
class CATCGMODTScaleManager;



class ExportedByGMScalarFieldsOperators CATImplicitGeoOperator : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATImplicitGeoOperator);

public:


  /**
  * Destructor
  */
  virtual ~CATImplicitGeoOperator();

  /**
  * Returns the software configuration used by the operator
  */
  virtual CATSoftwareConfiguration * GetSoftwareConfiguration() const;

  // /**
  // * @nodoc @nocgmitf 
  // */
  // INLINE CATImplicitOperGeoExt & GetCATImplicitOperExtension();

protected:

  /**
  * Constructor
  * @nodoc @nocgmitf 
  */
  CATImplicitGeoOperator(CATGeoFactory & iFactory, CATImplicitOperGeoExt & iExtension);


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
  
public:
  /** @nodoc * @nocgmitf
   * For CGMReplay only
   */
  void SetCGMODTScaleManager(CATCGMODTScaleManager * iScaleManager); // Not to be overloaded

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATImplicitGeoOperator();
  CATImplicitGeoOperator(const CATImplicitGeoOperator& iOneOf); 
  CATImplicitGeoOperator& operator =(const CATImplicitGeoOperator& iOneOf);


protected:
  
  CATImplicitOperGeoExt &             _implicitOperExtension;

};

// // INLINE methods
// // ==============

// INLINE CATImplicitOperGeoExt & CATImplicitGeoOperator::GetCATImplicitOperExtension() {
//   return _implicitOperExtension;
// }

#endif
