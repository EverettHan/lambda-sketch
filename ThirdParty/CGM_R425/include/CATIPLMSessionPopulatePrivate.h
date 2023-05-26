// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATIPLMSessionPopulatePrivate.h
// Define the CATIPLMSessionPopulatePrivate interface
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

#ifndef CATIPLMSessionPopulatePrivate_H
#define CATIPLMSessionPopulatePrivate_H

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
#define CATPLMPsp                   AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

      #error Access To CATPLMIntegrationInterfaces services from a non-authorized module is prohibited
        // Fatal error on solaris
        @error 

#endif

#undef CATPLMImportMgt
#undef CATPLMIntegrationInterfaces
#undef CATPLMPsp

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

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionPopulatePrivate;
#else
extern "C" const IID IID_CATIPLMSessionPopulatePrivate;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionPopulatePrivate : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  
  /**
  * Hardcoded method provided to import 3DXML in session.
  * Loading in an authoring TOS objects stored in ipRecordReadSet object.
  *
  * <br><b>Role</b>: Loading in an authoring TOS objects stored in ipRecordReadSet object.
  *
  *                  This method supposes that an instance of CATIPLMImportInputOutput has already been created before.
  *                  The instance of CATIPLMImportInputOutput is filled with the bag and the list of roots loaded in the authoring TOS
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
  virtual HRESULT PopulateWith3DXMLFRData(CATIPLMRecordReadSet* ipRecordReadSet) = 0;

};

CATDeclareHandler( CATIPLMSessionPopulatePrivate, CATBaseUnknown );

#endif
