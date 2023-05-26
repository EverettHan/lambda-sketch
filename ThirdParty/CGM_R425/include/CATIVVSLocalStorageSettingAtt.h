/**
* @level Protected
* @usage U3
*/
// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// CATIVVSLocalStorageSettingAtt.h
// Define the CATIVVSLocalStorageSettingAtt interface
//
//===================================================================
//
// Usage notes:
//  Interface to be used to read/write persistent Preferences settings
//  related to Local Storage functionality management
//  (Non CATIA result documents management on Local disk)
//
//===================================================================
//  March 2022 Creation                                           VCS
//===================================================================
#ifndef CATIVVSLocalStorageSettingAtt_H
#define CATIVVSLocalStorageSettingAtt_H

//#include "CATOMYUtils.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "VVSUtils.h"
#include "CATSettingInfo.h"

// Attribute names for PLM Local Storage repository Setting file
#define LS_MANAGED_PATH  "LSManagedPath"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVVSUtils IID IID_CATIVVSLocalStorageSettingAtt;
#else
extern "C" const IID IID_CATIVVSLocalStorageSettingAtt;
#endif

//------------------------------------------------------------------

/**
* Interface to modify Local Storage settings as shown or defined in 3DExperience UI Preferences.
* <b>Role</b>: This interface defines the communication protocols between the LocalStorage options
* set or shown in Preferences/xxx/Local Storage settings and the Local Storage Engine.
*/

class ExportedByVVSUtils CATIVVSLocalStorageSettingAtt : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Gets the current absolute path of the Local Storage repository
  * Reads the absolute value of the current Local Storage repository path from setting currently set in memory.
  * If the local path is defined from environment variables, it returns the expanded format.
  * The eventual literal (unexpanded) format can be retrieved with @href #GetLocalStoragePathSymb.
  * @param oLocalPath [out]
  *       the local storage expanded path
  * @return
  *        S_OK   : Successfully ended
  *        E_FAIL : A software error occured
  */
  virtual HRESULT GetLocalStoragePath(CATUnicodeString& oLocalPath) = 0;

  /**
  * Gets the current literal path of the Local Storage repository.
   * Reads the literal value of the current Local Storage repository path from setting currently set in memory.
  * If the local path is defined with environment variables, it returns the literal format.
  * if no literal used, it returns the absolute path, as @href #GetLocalStoragePath does.
  *  specific case:  default value CSIDL_LOCAL_APPDATA is a symbolic display representation of the absolute Local Storage default path.
  *                  it is not considered as an environment variable representing the entire absolute path and so not directly expanded
  *                  but the absolute path is computed from it by the setting controler, when using  @href #GetLocalStoragePath.
  *
  * @param oLocalPath [out]
  *       the local storage symbolic path
  * @return
  *        S_OK   : Successfully ended
  *        E_FAIL : A software error occured
  */
  virtual HRESULT GetLocalStoragePathSymb(CATUnicodeString& oLocalPath) = 0;

  /**
  * Sets a user Local Storage repository path
  * Registers a user Local Storage repository path, in absolute or literal format, as the new current setting in memory:
  * This path becomes the new reference path for all File Description files storing/locking.
  * This path is stored into LocalStorage.CATSettings file at next Preferences UI save.
  * This path must exist and be an absolute folder path.
  * This folder must be empty (no file or sub-folder) excepted eventual lsinfo.log lock file from a previous affectation.
  * The current Local Storage repository it replaces must also be empty (no file or sub-folder) excepted eventual lsinfo.log lock file,
  * as the cross usage of several Local Storage repositories is not supported.
  *
  * @param iLocalPath [in]
  *       the new Local Storage repository path.
  * @return
  *        S_OK   : Successfully ended. This new path is registered in setting and LocalStorage locking structure
  *        FAILED : Current Local Storage repository path does not change
  *        E_FAIL : A software error occured
  *        specific failures (for UI information)
  *        E_VVS_LS_NotAValidDir        : new Local Storage repository does not exist/not a valid absolute folder path
  *        E_VVS_LS_CurrentDirNotEmpty  : current Local Storage repository not empty (most currently, .fd files remaining)
  *        E_VVS_LS_ProposedDirNotEmpty : new Local Storage repository not empty
  */
  virtual HRESULT SetLocalStoragePath(CATUnicodeString& iLocalPath) = 0;

  /**
  * Sets back the default Local Storage repository path.
  * This default path is CSIDL_LOCAL_APPDATA\\PLM_LocalResult.
  * It becomes the new reference path for all File Description files storing/locking.
  * It is stored into LocalStorage.CATSettings file at next Preferences UI save.
  * It must be empty (no file or sub-folder) excepted eventual lsinfo.log lock file from a previous affectation.
  * The current Local Storage repository it replaces must also be empty (no file or sub-folder) excepted eventual lsinfo.log lock file,
  * as the cross usage of several Local Storage repositories is not supported.
  *
  ** @return
  *        S_OK   : Successfully ended. This new path is registered in setting and LocalStorage locking structure
  *        FAILED : Current path Local Storage does not change
  *        E_FAIL : A software error occured
  *        specific failures (for UI information)
  *        E_VVS_LS_CurrentDirNotEmpty  : current Local Storage repository not empty (most currently, .fd files remaining)
  *        E_VVS_LS_ProposedDirNotEmpty : new Local Storage repository not empty
  */
  virtual HRESULT SetDefaultLocalStoragePath() = 0;

  /**
  * Retrieves the state of the Local Storage Path parameter (for lock/unlock info..)
  * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetLSManagedPathInfo(CATSettingInfo* oInfo) = 0;

};

//------------------------------------------------------------------

#endif
