/* -*-C++-*-*/
#ifndef CATGMPolyGeoOperator_H
#define CATGMPolyGeoOperator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2019
//
// CATGMPolyGeoOperator
//
// DESCRIPTION :
// virtual mother class for all polyhedral CATCGMOperator derivations
//
// History
//
// 20190529 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATCGMOperator.h"     // derivation
#include "GMPolyBasicOper.h"    // ExportedBy

#include "CATMathInline.h"      // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"     // HRESULT

class CATGeoFactory;
class CATBody;
class CATGMPolyOperGeoExt;
class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;
class CATString;
class CATCGMODTScaleManager;

/** @nodoc */
class ExportedByGMPolyBasicOper CATGMPolyGeoOperator : public CATCGMOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyGeoOperator);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyGeoOperator();

  
  /**
  * Returns the software configuration used by the operator
  */
  virtual CATSoftwareConfiguration * GetSoftwareConfiguration() const;


protected:

  /**
  * Constructor
  * @nodoc @nocgmitf 
  */
  CATGMPolyGeoOperator(CATGeoFactory & iFactory, CATGMPolyOperGeoExt & iPolyExtension);

  /**
  * Runs the operator
  * @nodoc @nocgmitf 
  */
  virtual int RunOperator();

  // ------------------
  // CGMReplay Methods
  // ------------------

protected:
  /** @nodoc * @nocgmitf */
  virtual /* CATCGMOperator method */ const CATString * GetOperatorId();
	
public:
  /** @nodoc * @nocgmitf
   * For CGMReplay only
   */
  void SetCGMODTScaleManager(CATCGMODTScaleManager * iScaleManager); // Not to be overloaded


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyGeoOperator();
  CATGMPolyGeoOperator(const CATGMPolyGeoOperator& iOneOf); 
  CATGMPolyGeoOperator& operator =(const CATGMPolyGeoOperator& iOneOf);


protected:
   
  CATGMPolyOperGeoExt &             _PolyOperExtension;

};

#endif
