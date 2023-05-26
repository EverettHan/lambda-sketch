#ifndef _CATComponentIdStreamDescriptorsManager_H
#define _CATComponentIdStreamDescriptorsManager_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMIntegrationInfra            AuthorizedModule
#define CATPLMIntegrationBase             AuthorizedModule
#define CATPLMLocalSaveBase               AuthorizedModule
#define CATPLMSessionImages               AuthorizedModule
#define CATOxiStreamDescriptors           AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATPLMStreamDescriptor            AuthorizedModule

//ODT
#define SelectiveLoadingTST_BasicSwitch   AuthorizedModule
#define SelectiveLoadingTST_RepRefTSTImpl AuthorizedModule
#define CATOmbTST_FTARelationAccess       AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATComponentIdStreamDescriptorsManager from a non-infrastructure module
@error 
#endif

#undef CATPLMTos   
#undef CATPLMIntegration
#undef CATPLMIntegrationInfra
#undef CATPLMIntegrationBase
#undef CATPLMLocalSaveBase
#undef CATPLMSessionImages
#undef CATOxiStreamDescriptors
#undef CATPLMIdentification_PLM
#undef CATPLMStreamDescriptor            

//ODT
#undef SelectiveLoadingTST_BasicSwitch
#undef SelectiveLoadingTST_RepRefTSTImpl
#undef CATOmbTST_FTARelationAccess
// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "CATTosMacros.h"
#include "CATComponentId.h"

class CATITosIterator_var;

/**
* Object managing stream descriptors at tos level
*/
class ExportedByCATPLMTos CATComponentIdStreamDescriptorsManager
{
public:

  /**
  * @nodoc
  */
  CATComponentIdStreamDescriptorsManager(const CATComponentId & iCID);

  /**
  * @nodoc
  */
  ~CATComponentIdStreamDescriptorsManager();

  /**
  * Get iterator providing access to stream descriptors
  *
  * Interfaces implemented by stream descriptors :
  *   CATITosStreamDescriptor (basic view)
  *   CATITosStreamDescriptorStreamAccess (specific access for persistency management)
  *
  * @return 
  *     The iterator
  */
  CATITosIterator_var GetIterator();

  /**
  * Returns the modification status according to LOG level.
  *
  * @param iTodoLevel
  *     The LOG level Global/Differential.
  * @param oIsModified
  *     The modification status.
  * @return
  *     An HRESULT value.
  *     <br><b>Legal values</b>:
  *     <ul>
  *         <li><tt>S_OK</tt> if succeeded.</li>
  *         <li><tt>E_FAIL</tt> if failed.</li>
  *     </ul>
  */
  HRESULT IsModified(CATTosTodoLevel iTodoLevel, CATBoolean & oIsModified);

private:

  // Forbidden operators 
  CATComponentIdStreamDescriptorsManager (CATComponentIdStreamDescriptorsManager&);
  CATComponentIdStreamDescriptorsManager& operator=(CATComponentIdStreamDescriptorsManager&);
  void * operator new(size_t, CATComponentIdStreamDescriptorsManager&);

  CATComponentId _Handle;
};

#endif
