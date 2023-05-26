/**
 * @level Protected
 * @usage U5
 */
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  1997                                         
//===========================================================================
//
// CATINavigateModel : 
//
//
//============================================================================
#ifndef CATINavigateProcedural_H
#define CATINavigateProcedural_H

#include "AC0CATPL.h"
#include "CATINavigateObject.h"
#include "CATUnicodeString.h"

extern ExportedByAC0CATPL IID IID_CATINavigateProcedural;

class  ExportedByAC0CATPL CATINavigateProcedural :  public CATINavigateObject

{
  CATDeclareInterface;
  
public:

  virtual void GetTextStatus(CATUnicodeString &string)=0; 
  virtual void GetStatus(int &color ,int &spec) = 0;
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(  CATINavigateProcedural, CATINavigateObject ) ;

#endif
