/**
 * @level Private
 * @usage U1
 */
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1999
//===========================================================================
//
// CATIConversionTransaction :
//
//
//============================================================================
#ifndef CATIConversionTransaction_H
#define CATIConversionTransaction_H

#include <AD0XXBAS.h>
//#include <CATIConvertEntity.h>
#include <CATBaseUnknown.h>
#include "CATLISTV_CATBaseUnknown.h"
#include "CATIConvertEntity.h"
#include "CATLISTV_CATIConvertEntity.h"


extern ExportedByAD0XXBAS IID IID_CATIConversionTransaction;

class  ExportedByAD0XXBAS CATIConversionTransaction :  public CATBaseUnknown

{
  CATDeclareInterface;

public:

  // Add one element in the conversion transaction
  virtual void  AddConvertEntity( const CATFormat* iFormat,
		    const CATIConvertEntity_var & iConvertEntity ) = 0;

  // Add a list of elements in the conversion transaction
  virtual void  AddConvertEntity( const CATFormat* iFormat,
		    const CATLISTV(CATIConvertEntity_var) & iConvertEntityList ) = 0;

  // Run the conversion
  virtual void  Run() = 0;

  // Get the conversion result
  virtual void  GetResult( CATLISTV(CATBaseUnknown_var) & result ) = 0;

  // Gestion du path element cible
  virtual void  AddTargetPathElement ( const CATLISTV(CATBaseUnknown_var) & to_objects ) = 0;

  // Run fait un lock de la Part. On doit faire un V4V5TransactionUnlockPart apres.
  virtual void V4V5TransactionUnlockPart() = 0;

  // To get the V5 result(s) of the conversion of iV4PointedElement, which is a V4 element.
  virtual HRESULT GetMapping( const CATBaseUnknown*      iV4PointedElement,
                              CATLISTP(CATBaseUnknown)*& oResultingElements ) const =0 ;

  // To set specific modes for conversion.
  virtual HRESULT SetConversionMode( const char* iConversionMode ) const =0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIConversionTransaction, CATBaseUnknown ) ;

#endif
