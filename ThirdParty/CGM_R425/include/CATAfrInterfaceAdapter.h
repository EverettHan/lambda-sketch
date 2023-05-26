//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/11/17
//===================================================================
// CATAfrInterfaceAdapter.cpp
// Header definition of class CATAfrInterfaceAdapter
//===================================================================
//
// Usage notes: Use this class as a base class for interface adapters
//
//===================================================================
//  2010/11/17 Creation: ERS
//===================================================================

#ifndef CATAfrInterfaceAdapter_H
#define CATAfrInterfaceAdapter_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

//-----------------------------------------------------------------------
HRESULT ExportedByCATAfrItf QueryAdapter (CATBaseUnknown * iObj, const char *ipAdapterClassName, const IID & iIdent, void ** oPpv);

#define CATDeclareAdapter(InterfaceName)                                      \
static const char * InterfaceName##_CATGetAdapterClassName();

#define CATImplementAdapter(InterfaceName, adapterClassName)                  \
const char * InterfaceName::InterfaceName##_CATGetAdapterClassName()          \
{                                                                             \
  return #adapterClassName;                                                   \
}

#define CATQueryAdapter(iObj, InterfaceName, oPpv)                            \
QueryAdapter (iObj, InterfaceName::InterfaceName##_CATGetAdapterClassName(), IID_##InterfaceName,oPpv)
//-----------------------------------------------------------------------

#endif
