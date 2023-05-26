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
#ifndef CATINavigateModel_H
#define CATINavigateModel_H

#include "AC0CATPL.h"
#include "CATINavigateObject.h"

extern ExportedByAC0CATPL IID IID_CATINavigateModel;

class  ExportedByAC0CATPL CATINavigateModel :  public CATINavigateObject

{
  CATDeclareInterface;
  
public:

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(  CATINavigateModel, CATINavigateObject ) ;

#endif
