// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATIPLMSessionSave.h
// Define the CATIPLMSessionSave interface
//
//===================================================================
//
// Usage notes:
// 
//
//===================================================================
// June 2010  Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMSessionSave_H
#define CATIPLMSessionSave_H

//*************************************************************************
//*************************************************************************
//*************************************************************************
// Limited access
//*************************************************************************
//*************************************************************************
//*************************************************************************

#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 

#endif

#define AuthorizedModule 999
// List of authorized infrastructure modules 
#define CATPLMImportMgt             AuthorizedModule
#define CATPLMIntegrationInterfaces AuthorizedModule
#define CATPLMPspProviderImpl       AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

      #error Access To CATPLMIntegrationInterfaces services from a non-authorized module is prohibited
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMImportMgt
#undef CATPLMIntegrationInterfaces
#undef CATPLMPspProviderImpl

#undef AuthorizedModule

// ExportedByCATPLMIntegrationInterfaces def
#if defined __CATPLMIntegrationInterfaces
#define ExportedByCATPLMIntegrationInterfaces DSYExport
#else
#define ExportedByCATPLMIntegrationInterfaces DSYImport
#endif
#include "DSYExport.h"

//*************************************************************************
//*************************************************************************
//*************************************************************************

#include "CATBaseUnknown.h"               // System PublicInterfaces

class CATPLMBag;

#include "CATCollec.h"
class CATLISTV(CATComponentId);

class CATIAdpErrorMonitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionSave;
#else
extern "C" const IID IID_CATIPLMSessionSave;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionSave : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  virtual HRESULT SetLoadedData(  CATPLMBag& oBag,
                                  CATLISTV(CATComponentId)& iListOfRoots) = 0;

  virtual HRESULT Save(CATIAdpErrorMonitor * iopErrorMonitor = NULL) = 0;

};

CATDeclareHandler( CATIPLMSessionSave, CATBaseUnknown );

#endif
