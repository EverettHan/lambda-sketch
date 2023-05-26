//===================================================================
// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATIPLMSessionPopulate.h
// Define the CATIPLMSessionPopulate interface
//
//===================================================================
//
// Usage notes:
// interface implemented as part of Project:
// Ability to import a 3DXML for review in V6 session using a specific provider called Psp.
// (Psp like Provider Session)
//
// Interface specification:
// Import in an authoring TOS a CATIPLMRecordReadSet object.
// Object stored in CATIPLMRecordReadSet object must respect some rules:
// - References must be stored before Instances.
// - Instance cannot be stored in the CATIPLMRecordReadSet object without their reference.
// - Mandatory attributes must be set on each object.
//
// TOS: table of objects in session.
//
//===================================================================
// June 2010  Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMSessionPopulate_H
#define CATIPLMSessionPopulate_H

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

class CATIPLMRecordReadSet;
class CATPLMBag;

#include "CATCollec.h"
class CATLISTV(CATComponentId);

class CATIAdpErrorMonitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionPopulate;
#else
extern "C" const IID IID_CATIPLMSessionPopulate;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionPopulate : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
  * Populate the authoring TOS with objects stored in CATIPLMRecordReadSet object.
  * <br><b>Role</b>: Populate the authoring TOS with objects stored in CATIPLMRecordReadSet object.
  *
  * @param ipRecordReadSet
  *        List of objects that must be loaded into the authoring TOS.
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT Populate(CATIPLMRecordReadSet* ipRecordReadSet) = 0;

  /**
  * Retrieve the bag and list of roots stored in authoring TOS.
  * <br><b>Role</b>: Retrieve the bag and list of roots stored in authoring TOS.
  *
  * @param oBag
  *        Bag that hold all objects stored in authoring TOS.
  *
  * @param oListOfRoots
  *        Different graph of objects are stored in the TOS. One root per graph.
  *        oListOfRoots contains the list of roots.
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetLoadedData(  CATPLMBag& oBag,
                                  CATLISTV(CATComponentId)& oListOfRoots) = 0;

};

CATDeclareHandler( CATIPLMSessionPopulate, CATBaseUnknown );

#endif
