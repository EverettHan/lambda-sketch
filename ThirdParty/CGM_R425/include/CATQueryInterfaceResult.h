/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//								   
// CATQueryInterfaceResult						   
//
//=============================================================================
// October 07   Creation
//=============================================================================
#ifndef CATQueryInterfaceResult_H
#define CATQueryInterfaceResult_H

#include "JS0CORBA.h"
#include "IUnknown.h"

// Returns E_ACCESSDENIED if the last CATBaseUnknown::QueryInterface(const IID &iIID, void **oPPV) call has failed due to licensing
// else returns the same HRESULT as the last QueryInterface call.
ExportedByJS0CORBA HRESULT GetResultFromLastQueryInterface() ;

#endif



