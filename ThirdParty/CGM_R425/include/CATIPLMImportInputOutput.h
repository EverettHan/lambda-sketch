// COPYRIGHT Dassault Systemes 2010
//===================================================================
// CATIPLMImportInputOutput.h
//===================================================================
//
// Usage notes:
// interface implemented as part of Project:
// Ability to import a 3DXML for review in V6 session using a specific provider called Psp.
// (Psp like Provider Session)
//
// interface specification:
// describe the kind of import that you want to realise
// 3DXML import in session, in database, in database using session.
// If you have chosen 3DXML with option "import in session" or "import in database using session",
// you can display in an editor datas loaded in session using the method display.
//
//===================================================================
// June 2010  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMImportInputOutput_H
#define CATIPLMImportInputOutput_H

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
#define CATPLMIdentification_PLM    AuthorizedModule
#define PLMImportEV5DXPAUT          AuthorizedModule // Replaced by PLMImport3DXMLReviewExperience  
#define PLMImport3DXMLReviewExperience AuthorizedModule
#define TstCATPLMPspImportCoverage  AuthorizedModule
#define TstCATPLMPsp                AuthorizedModule
#define Import3DXMLBatchUI          AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else

#error Access To CATPLMIntegrationInterfaces services from a non-authorized module is prohibited
  // Fatal error on solaris
  @error

#endif

#undef CATPLMImportMgt
#undef CATPLMIntegrationInterfaces
#undef CATPLMIdentification_PLM
#undef PLMImportEV5DXPAUT
#undef PLMImport3DXMLReviewExperience
#undef TstCATPLMPspImportCoverage
#undef TstCATPLMPsp

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

#include "CATBaseUnknown.h"

#include "CATPLMImportOption.h"

class CATPLMRepositoryName;

#include "CATCollec.h"
class CATLISTP(CATIPLMComponent);

class CATPLMBag;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMImportInputOutput;
#else
extern "C" const IID IID_CATIPLMImportInputOutput;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMImportInputOutput : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * specify location of the datas during an import operation.
  *
  * <br><b>Role</b>:
  * specify location of the datas during an import operation.
  *
  * eg: import a 3DXML in database
  * source provider: 3DXML
  * target provider: M1
  * In such a case, iRepositoryName == "3DXML"
  *
  * @param iRepositoryName
  *        location of datas to import.
  *
  */
  virtual void SetRepositoryNameSource(CATPLMRepositoryName & iRepositoryName) = 0;


  /**
  * Kind of import that you want to realize.
  *
  * <br><b>Role</b>: Kind of import that you want to realize.
  *
  * @param iOption
  *        kind of import that you want to realize
  *
  */
  virtual void SetImportOption(CATPLMImportOption::ImportOption iOption) = 0;


  /**
  * Display imported datas in an editor.
  *
  * <br><b>Role</b>: Display imported datas in an editor.
  *                  If you have chosen 3DXML with option "import in session" or "import in database using session",
  *                  you can display in an editor datas loaded in session using the method display.
  *
  * Call to this method has a sense only if:
  * CATPLMImportOption::ImportOption == CATPLMImportOption::ImportInSession
  * or
  * CATPLMImportOption::ImportOption == CATPLMImportOption::ImportInSessionAndSave
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>if no root has been found.
  * </dl>
  */
  //virtual HRESULT Display() = 0;




  /**
  * Retrieve the bag that holds all datas loaded in session and the list of roots.
  *
  * <br><b>Role</b>: Retrieve the bag that holds all datas loaded in session and the list of roots.
  *
  * Call to this method has a sense only if:
  * CATPLMImportOption::ImportOption == CATPLMImportOption::ImportInSession
  * or
  * CATPLMImportOption::ImportOption == CATPLMImportOption::ImportInSessionAndSave
  *
  * @param oBag
  *        bag that hold all datas.
  *        bag must be kept until the creation of the window or while you need to use datas.
  * @param oListOfRoots
  *        list of roots loaded in session. CATLISTP_APPLY_RELEASE on this list.
  * @return
  * <dt><code>S_OK</code> <dd> one (or more) roots loaded in session
  * <dt><code>E_FAIL</code> <dd>no roots loaded in session
  */
  virtual HRESULT GetLoadedData(CATPLMBag& oBag,
                                CATListPtrCATIPLMComponent& oListOfRoots) = 0;

};
CATDeclareHandler(CATIPLMImportInputOutput, CATBaseUnknown);
#endif
