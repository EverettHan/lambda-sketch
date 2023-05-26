/* -*-c++-*- */
#ifndef CATOmyServicesForSIM_h
#define CATOmyServicesForSIM_h

#include "CATOMYBaseSession.h"
#include "CATBoolean.h"
#include "CATOmySessionImageDescriptor.h"
#include "CATVVSUrl.h"
#include "CATOmxSR.h"

class CATUnicodeString;
class CATString;
class CATOMYUnicodeStringHTab;
class CATOmyEditorRegistry;
class CATIOmyTransactionsManager;

/**
* @level Private
* @usage U1
*/


/**
* service class exposed to the SessionImageManager
*/
class ExportedByCATOMYBaseSession CATOmyServicesForSIM
{

  friend class CATPLMSessionImageManagerImpl;
  friend class CATPLMPhotoEngine;
  friend class CATOmyBSCTest;        // odt
  friend class TestBSCInactivationByCache;
  friend class LocalSaveInactivationChecker;
  friend class __TA__TestBSCInactivationByCache; // odt
  friend class __TA__LocalSaveInactivationChecker; // odt
  friend class CATPLMSessionImageManagerTest; // odt
  friend class CATOmyTSTLocalSave;   // odt
  friend class SwitchEngine_PUA;     // odt OMB_Unit.tst
  friend class CATPLMInitSessionCmd; //Localsave inactivation
  friend class CATPLMInitSessionCmd2; //pour recuperer le chemin de l'image
  friend class CATPLMPXnTestUtils;
  friend class CATOmyFaradayManager;
  friend class CATOmyOnlineOfflineSwitch;
  friend class TestBSCBackup;
  friend class OmyBSCTestImage;
  friend class OmyBSCTestUtils;
  friend class CATAdpAllInOneOffline;
  friend class CATPLMOfflineRepositoryManager; //pour recuperer le chemin de l'image
  friend class CATOmyCuteIOTransaction;
  friend class ComputeDeltaAndUpload;
  friend class CATAsyncDeltaServices;
  friend class CATOmyBaseSessionCoordinator;
  friend class CATPLMLocalSave_SwitchCollabSpaceRestoreAndVerifyCollabSpace; //odt
  friend class CATPLMLocalSave_SwitchCollabSpaceRestoreAndVerifyCollabSpaceChanged; //odt
  friend class TestFaradayBase; // odt
  friend class CATOxiProviderConnection; //odt
  friend class CATPLMLocalTestBase;
  friend class CATPLMSessionImageManager; //SetBroken
  friend class CATOmySessionRecordServices;

public:

  /**
  * Tells if the LocalSave fonctions are active or not
  * @return TRUE if automatic Local save is running
  *         FALSE if not
  */
  static CATBoolean IsSessionRecordingActive();

  /**
  * Indicates whether hardlink is activated for current session
  * Hardlink is enabled if LocalSave is disabled and the PLMxLF Vault Site supports hard link
  * @return TRUE if hardlink is activated
  *         FALSE otherwise
  */
  static CATBoolean HardLinkSupportIsActivatedForURL(CATVVSUrl& iUrl);

  /**
  * Retrieves the current editor registry.
  * @returns a addrefed pointer to the registry.
  */
  static CATOmyEditorRegistry* GetEditorRegistry();

  /**
  * Retrieves the current editor registry for infra purpose.
  * The editors contained in this registry will be unstreamed before the session components are restored.
  * Therefore, they should not be dependent on the availability of any components in session.
  *
  * @returns a addrefed pointer to the registry.
  */
  static CATOmyEditorRegistry* GetInfraEditorRegistry();


  /*
  * Tests the Localsave state for out of order (ie. local save is no more available)
  */
  static CATBoolean IsLocalSaveOutOfOrder();


  static HRESULT ConnectionDone(char* iProviderName = NULL);

  /*
  * Unfortunately, local save will now be out of order and unaccessible.
  * Localsave will be set as out of order.
  * This should be called for every operation which will break localsave functionality
  * We don't want to restore corrupted image, and one a local save has failed, it should be
  * considered the whole local save is in a bad state.
  * Hopefully, every case where we call this method should be corrected.
  * You can't get back Local Save after this unless starting a new session
  */
  static HRESULT PutLocalSaveAside();

private:
  /**
  * Tells the Session image Manager what is the path of the current image
  * @param oPath [out] the pat to the image
  */
  static HRESULT GetImagePath(CATUnicodeString& oPath);
  /**
  * Tells if the session has been initialized from an hibernated or a crashed session
  *   @param oHib [out]
  *          TRUE if the session has been initialized from an hibernated or a crashed session
  *          FALSE if not. (New session or local save not active)
  */
  static HRESULT IsSessionInitializedFromHibernatedSession(CATBoolean& oHib);

  /**
  * Provides the Path to store the TOS stream
  */
  static HRESULT GetTOSFilePath(CATUnicodeString& oPath);

  /**
  * Provides the Path to store the UFO stream
  */
  static HRESULT GetUFOFilePath(CATUnicodeString& oPath);

  /**
  * Provides the Path to store snapshot of the session
  */
  static HRESULT GetSessionPreviewFilePath(CATUnicodeString& oPath);

  /**
  * @see CATOmySessionImageDescriptor#GetImageStatus
  */
  static HRESULT GetImageStatus(ImageType& oimgtype);

  /**
  * Get the transactions manager for current image
  */
  static HRESULT GetTransactionsManager(CATOmxSR<CATIOmyTransactionsManager>& oManager);

  /**
  * Validates that the image has been correctly restored
  */
  static HRESULT SetStatusInUse();

  /**
  * Sets the validity of the current image
  * @param iIsValid [in] FALSE if the image cannot be considered as valid
  *                      TRUE if it can
  * @param iNbCompInTOS [in] the number of components in the image TOS dump
  *                          It is taken in account only if iIsValid equals TRUE
  * @param iNbCompDirty [in] the number of TODO (dirty) components in the TOS dump
  *                          It is taken in account only if iIsValid equals TRUE
  */
  static HRESULT SetImageValidity(const CATBoolean& iIsValid, const int iNbCompInTOS, const int iNbCompDirty);

  /**
  * Sets the validity of the current image
  * @param iIsValid [in] FALSE if the image cannot be considered as valid
  *                      TRUE if it can
  */
  static HRESULT SetImageValidity(const CATBoolean& iIsValid);

  /*
  * Unfortunately, really unfortunately, image is broken.
  * This image won't be restored... However we keep it until it is destroyed.
  */
  static HRESULT SetImageBroken();

  /**
  * Values the Login infos necessary to log in the VPLM Server
  */
  static HRESULT SetLoginInfos(const CATOMYUnicodeStringHTab& iData);

  /**
  * @deprecated
  * Doit degager des que le login automatique sera actif
  */
  static HRESULT GetLoginInfos(CATOMYUnicodeStringHTab& oData);

  // Marks the current transaction. It could be restored.
  static HRESULT SetCurrentTransactionRestorable();

  static HRESULT PackDataForRecord();

  static CATBoolean LocalSaveInactivationByCache();

  static CATUnicodeString GetTransactionName();

};


#endif
