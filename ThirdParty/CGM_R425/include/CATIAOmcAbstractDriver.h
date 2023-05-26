/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998  
//=============================================================================
/**
 *   class CATIAOmcAbstractDriver.h
 */


#ifndef CATIAOmcAbstractDriver_h
#define CATIAOmcAbstractDriver_h
  
class CATIANamingContext;
class CATIBindParameters;
#include "CATBaseUnknown.h"
#include "CATOmcBase.h"
#include "sequence_octet.h"


class CATUnicodeString;


class ExportedByCATOmcBase CATIAOmcAbstractDriver
{
  public :
 virtual HRESULT GetObject_B(CATIANamingContext &iNaming, const SEQUENCE(octet)& name,
                                     CATIBindParameters*    params,
                                     const CATIdent         interfaceID, CATBaseUnknown *&oObject );
 virtual boolean CreateIndex(CATIANamingContext &iNaming);  
 virtual void UnsetIndex(CATIANamingContext &iNaming);
 

};

 
#endif
