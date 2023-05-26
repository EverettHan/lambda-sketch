/**
 * @level Private
 * @usage U1
 */
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1999                                         
//===========================================================================
//
// CATIConversionTransactionFactory : 
//
//
//============================================================================
#ifndef CATIConversionTransactionFactory_H
#define CATIConversionTransactionFactory_H

#include <AD0XXBAS.h>
#include <CATIConvertEntity.h>
#include "CATLISTV_CATIConvertEntity.h"
#include <CATBaseUnknown.h>
#include <CATIContainer.h>
#include <CATFormats.h>

class CATIConversionTransaction;

extern ExportedByAD0XXBAS IID IID_CATIConversionTransactionFactory;

class  ExportedByAD0XXBAS CATIConversionTransactionFactory :  public CATBaseUnknown

{
  CATDeclareInterface;
  
public:
  
  virtual CATIConversionTransaction * Create(const CATIContainer_var &iContainer ) = 0;
    
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIConversionTransactionFactory, CATBaseUnknown ) ;

#endif
