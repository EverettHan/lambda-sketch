/* -*-c++-*- */

/**
 * @level Private
 * @usage U1
 */

/**
 * Integration of LocalSave features
 * This class is a singleton, you can get it with GetSIManager.
 */

#ifndef CATPLMSessionImageManager_h
#define CATPLMSessionImageManager_h

#include "CATPLMIntegrationBase.h"
#include "CATUnicodeString.h"
#include "CATBooleanDef.h"
#include "CATPLMRepositoryName.h"
#include "CATIPLMSessionImageManager.h"
#include "CATOmxSR.h"
#include "CATOmyBSCTypeDefs.h"

class CATIPLMCompConnectionInstance;
class CATIPLMEngineListener;
class CATIOmyEditorStreamManagement;
class CATIPLMSessionImageDecorator;
class CATOMYUnicodeStringHTab;
class CATProxySpaceImageAssistant;
class CATIPLMCompSaveTransaction;
class CATProxySpace;
class CATIAdpErrorMonitor;
class CATPLMBag;

class ExportedByCATPLMIntegrationBase CATPLMSessionImageManager
{
public:
  CATPLMSessionImageManager();
  ~CATPLMSessionImageManager();

  /**
  * Check that the current authentified user matches the current image's one
  * @return S_OK if the login infos are mathing
  *         E_FAIL if there are differences. Those are registered in the optionnal errorMonitor
  */
  HRESULT CheckLoginInfo();

  HRESULT ReconnectWithImageParams(const CATUnicodeString & iPassword = "");

  /**
   * Open the current image (Restore) operation
   * @return S_OK if the image has been successfully restored
   *         S_FALSE if no image has been restored
   *         E_FAIL if the restoration failed
   */
  HRESULT OpenImage();

  /**
   * @param [out] oSynchroOK TRUE if a LocalSave transaction can be performed
   * @param [out] oSynchroOK FALSE if no localsave transaction can be performed (localsave not activated or in OpenImage context)
   */
  HRESULT PrepareLocalSaveTransaction(CATBoolean & oSynchroOK);

  /**
   * @param [in] iLSTransOK
   */
  HRESULT EndLocalSaveTransaction(CATProxySpace & iWS,
                                  const LocalSaveTransaction::Status iLocalSaveTransactionStatus, CATProxySpaceImageAssistant & iImageAssistant);
  HRESULT EndLocalSaveTransaction(CATProxySpace & iWS,
                                  const LocalSaveTransaction::Status iLocalSaveTransactionStatus, CATProxySpaceImageAssistant & iImageAssistant,
                                  int iNbCompsInSession, int iNbCompsDirty);

                                /**
                                 * Creates a LocalSaveTransaction on the right provider
                                 */
  HRESULT GetLocalSaveTransaction(CATProxySpaceImageAssistant & iWSImage,
                                  CATIPLMCompSaveTransaction *& oLSTransaction);

                                /**
                                 * Renvoit FALSE s'il n'est pas necessaire de creer une transaction vide (validante) au cas ou rien n'est dirty
                                 * en LOG localSave.
                                 */
  CATBoolean NeedsToCreateNewTransaction(CATProxySpaceImageAssistant & iWSImage, int iNbComponentsInSession) const;

  /**
  * Initialize the various managers related to user interface,
  * such as editors manager and snapshot manager.
  * @returns
  *      S_OK if the managers have been initialized,
  *      S_FALSE if they haven't benn initialized because they shouldn't (for example, if Local Save is not active)
  *      E_FAIL if an error occured during initialization.
  */
  HRESULT InitUIManagers();

  /*
  * Attache/detache un bag externe. Necessaire s'il n'y a pas d'editeur
  */
  HRESULT AttachBag(CATPLMBag &ioBag);
  HRESULT DetachBag();

  /*
  * Rend le lifecycle. Ne pas utiliser si AttachBag a ete utilser, mais appeler DetachBag.
  */
  HRESULT RemoveComponents();

  /*
  * Disable the editors stream manager.
  * Need to call InitUIManagers to re-initialize it.
  */
  HRESULT DisableUIManagers();

  CATOmxSR<CATIAdpErrorMonitor> GetErrorMonitor();

private:
  CATPLMSessionImageManager(const CATPLMSessionImageManager &);
  CATPLMSessionImageManager & operator=(const CATPLMSessionImageManager &);

  CATIPLMSessionImageManager * _Impl;
};
#endif
