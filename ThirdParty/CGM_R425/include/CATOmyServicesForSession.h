/* -*-c++-*- */

#ifndef CATOmyServicesForSession_h
#define CATOmyServicesForSession_h

#include "CATOMYBaseSession.h"

#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATIPLMMaintenanceTubeErrorReporter.h"
class CATListPtrCATOmySessionImageDescriptor;
class CATOmySessionImageDescriptor;
class CATUnicodeString;

/**
 * @level Private
 * @usage U1
 */

/**
 * Service class exposed for the Session management
 */

// #define DELTA_SESSION_ENABLE

class ExportedByCATOMYBaseSession CATOmyServicesForSession
{
  friend class CATPLMActivateSIMCmd;
  friend class CATPLMHibernateCmd;
  friend class CATPLMInitSessionCmd;
  friend class CATPLMCacheSettingWatcher;
  friend class CATAdpLocalSaveUtils;
  // odts
  friend class CATOmyBSCTest;
  friend class CATPLMPXnTestUtils;
  friend class CATPLMSessionImageManagerTest;
  friend class CATPLMLocalSave_PowerIo;
  friend class CATOxiSessionImageAssistant;
  friend class CATOxiSessionImageAssistantEnvHook;
  friend class TestBSCBackup;
  friend class OmyBSCTestUtils;
  friend class OmyBSCTestSession;
  friend class OmyBSCTestImage;
  friend class CATAdpAllInOneOffline;
  friend class CATLSComputeServerServices;
  friend class CATOmyDeltaSession;

public:
  /**
   * This method should be used by the Init command of CATIA or by other programs like odts.
   * This method must be called at the beginning of a program which uses local save features.
   *
   * It will check that local save is active and parse the available images. If iAutoSelectFirstImage
   * is set to TRUE, the first image will be selected. This image is the last used one or a new one if
   * no preexisting image is found If iAutoSelectFirstImage is set to FALSE, the image list can then
   * be retrieve through GetImageList and then you can select one with SelectImage.
   *
   * @param iAutoSelectFirstImage set to TRUE to auto select the first available image (last used or new)
   * @param iDeleteOthers         if iAutoSelectFirstImage is set to TRUE, tells if the other images should be deleted
   * @return S_OK    if localsave is active
   *         S_FALSE if localsave is not active
   *         E_*     if a important error has been encountered
   */

  static HRESULT Init(const CATIPLMMaintenanceTubeErrorReporter_var & iMaintenanceErrorReporter = NULL_var);

private:

  /**
  * Warning, dangerous ! destroy the existing BSC and reinit a new one. Shouldn't be called if image selection already occured !
  */
  static HRESULT Reinit();

  /**
   * Gives the list of SessionImageDescriptor found in the image directory
   * This method should be called in a context where UI is available and Init returned oSelectionToDo==TRUE
   * @param oList [out]
   *        The list of SessionImageDescriptor
   */
  static HRESULT GetImageList(CATListPtrCATOmySessionImageDescriptor & oList, CATBoolean iKeepEmptyImages = FALSE);

  /**
   * Method called when the user choosed the image he wants to work with.
   * @param iSID [in]
   *        The pointer on the image selected
   * @param deleteOthers [in]
   *        If TRUE, all the used valid images will be deleted
   * @return
   *        S_OK    image selection is OK.
   *        S_FALSE image selection KO LocalSave will be inactivated
   *               (most of the time, due to a cache inconsistance)
   *        E_FAIL  unexpected error.
   */
  static HRESULT SelectImage(CATOmySessionImageDescriptor * iSID, CATBoolean deleteOthers = TRUE, CATBoolean autoActivate = TRUE);
  static HRESULT ActivateImage();

  /**
   * Removes the given images from disk. The associated data will be lost.
   */
  static HRESULT RemoveImagesFromDisk(const CATListPtrCATOmySessionImageDescriptor & iImagesToRemove);

  /**
   * Hibernation of the session
   * this call put the status hibernate on the current image
   */
  static HRESULT Hibernate();

  /**
   * The same as Hibernate
   */
  static int Hibernate(int);

  /**
   * Set the name of the SessionImage and write it in the image
   */
  static HRESULT SetImageName(const CATUnicodeString &iName);

  /**
   * Check that the external setting parameters of the SessionImage/PowerIO Cache have not been modified
   * by a setting change from DataBase
   */

  /**
  * Check that the external setting parameters of the SessionImage/PowerIO Cache have not been modified
  * in session since their last valid use (reference) by the Cache
  * <br><b>Role</b>: Return TRUE when PowerIO Cache setting parameter(s) modified in session
  * @param obChanged [out]
  *   <code>TRUE</code> if yes
  *   <code>FALSE</code> if no
  * @return
  *   <code>S_OK</code> if everything ran ok, S_FALSE if no reference to compare with, otherwise E_FAIL;
  */
  static HRESULT CheckImageCacheSettingChange(CATBoolean & obChanged);

};

#endif
