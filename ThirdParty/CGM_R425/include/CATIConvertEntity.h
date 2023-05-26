/**
 * @level Private
 * @usage U1
 */
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1997                                         
//===========================================================================
//
// CATIConvertEntity : 
//
//
//============================================================================
#ifndef CATIConvertEntity_H
#define CATIConvertEntity_H

#include <AD0XXBAS.h>
#include <CATBaseUnknown.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATIContainer.h>
#include <CATFormats.h>

extern ExportedByAD0XXBAS IID IID_CATIConvertEntity;

class  ExportedByAD0XXBAS CATIConvertEntity :  public CATBaseUnknown

{
  CATDeclareInterface;
  
public:
  
  virtual CATLISTV(CATBaseUnknown_var)  ConvertEntity( const CATLISTP(CATFormat)* format, const CATIContainer * cont) = 0;
    
  };

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIConvertEntity, CATBaseUnknown ) ;

#endif
