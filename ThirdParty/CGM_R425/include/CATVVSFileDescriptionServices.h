/**
 * @level Private
 * @usage U1
 */
 /* -*-c++-*- */
 //=============================================================================
 // COPYRIGHT DASSAULT SYSTEMES 2014
 //=============================================================================
#ifndef CATVVSFileDescriptionServices_H
#define CATVVSFileDescriptionServices_H

// BSFBuildtimeData
#include "CATIAV5Level.h"
// CATVirtualVaultSystem
#include "CATVVSUrl.h"
#include "VVSUtils.h"
// SystemTS
#include "CATErrorDef.h"
#include "CATILockBytes2.h"
// System
#include "CATUnicodeString.h"
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"

#define VVS_ERR_BASE 0x0A00
#define S_VVS_LS_FileFound            MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, VVS_ERR_BASE + 0x0041)
#define E_VVS_LS_NoPointedPath        MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0042)
#define E_VVS_LS_PathUnset            MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0043)
#define E_VVS_LS_NotAFilePath         MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0044)
#define E_VVS_LS_FileNotFound         MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0045)
#define E_VVS_LS_NotAValidDir         MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0046)
#define E_VVS_LS_CurrentDirNotEmpty   MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0047)
#define E_VVS_LS_ProposedDirNotEmpty  MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_ITF, VVS_ERR_BASE + 0x0048)

class ExportedByVVSUtils FileDescriptionData : public CATOmxSharable
{
public:

  FileDescriptionData() {}
  FileDescriptionData(const CATUuid& iOwnerId, const CATVVSUrl& iLocalUrl) :
    _OwnerId(iOwnerId), _LocalUrl(iLocalUrl) {}

  inline CATVVSUrl GetLocalUrl() const { return _LocalUrl; };
  inline CATUuid GetLocalOwner() const { return _OwnerId; };

private:

  CATUuid _OwnerId;
  CATVVSUrl _LocalUrl;
};

namespace FD
{
  enum FileDescriptionBehavior { Managed = 1, Integrity, Unmanaged };
}

/**
 * Class supplying enhanced services to support the management of File Descriptions
 * <b>Role</b>: Purpose of this class is to supply
 * services that support File Description operations.
 * This class is private to the VirtualVaultSystem
 */
class ExportedByVVSUtils CATVVSFileDescriptionServices
{
public:
  /**
  * Create a new File Description V1
  * @param iPointedFile [in]
  * Url pointed by the File Description.
  * @param iExpectedBehavior [in]
  * Expected behavior that manages how to treat the pointed file.
  * @param ioILB [inout]
  * Lockbyte used to write the newly created File Description.
  * @return
  * S_OK if the File Description has been created properly, E_FAIL if not.
  */
  static HRESULT CreateFileDescription(CATVVSUrl& iPointedFile, FD::FileDescriptionBehavior iExpectedBehavior, CATILockBytes2& ioILB);

  /**
  * Create a new File Description V2 (from V6R2020 on)
  * @param iPhysicalId [in]
  * the physical id of the component that owns the StreamDescriptor being set in LocalStorage mode
  * @param iPointedFile [in]
  * Url pointed by the File Description.
  * @param iExpectedBehavior [in]
  * Expected behavior that manages how to treat the pointed file.
  * @param ioILB [inout]
  * Lockbyte used to write the newly created File Description.
  * @return
  * S_OK if the File Description has been created properly, E_FAIL if not.
  */
  static HRESULT CreateFileDescription(const CATUuid& iPhysicalId, CATVVSUrl& iPointedFile, FD::FileDescriptionBehavior iExpectedBehavior, CATILockBytes2& ioILB);

  /**
  * Delete a File Description.
  * @param iUrlToFDFile [in]
  * File Description url.
  * @return
  * S_OK if the File Description has been deleted properly, E_FAIL if not.
  */
  static HRESULT DeleteFileDescription(CATVVSUrl& iUrlToFDFile);

  /**
  * Get the pointed url by the File Description.
  * @param iUrlToFDFile [in]
  * Local File Description url.
  *  or
  * @param iIlbToFDFile [in]
  * ILockByte handling the local File Description
  * @param oUrlToPointedFile [out]
  * Url pointed by the File Description.
  * pioAccessMask [inout]
  * R/W access information about pointed local Url
  * @return
  * S_OK if the pointed url can be retrieved properly, E_FAIL if not.
  */
  static HRESULT GetPointedUrl(CATVVSUrl& iUrlToFDFile, CATVVSUrl& oUrlToPointedFile, int* pioAccessMask = NULL);
  static HRESULT GetPointedUrl(CATILockBytes2* iIlbToFDFile, CATVVSUrl& oUrlToPointedFile, int* pioAccessMask = NULL);

  /**
  * Get the directory used to store the pointed url in managed mode.
  * @param oManagedDirectory [out]
  * Path to the managed urls directory.
  * @return
  * S_OK if the managed directory path can be retrieved properly, E_FAIL if not.
  */
  static HRESULT RetrieveManagedDirectory(CATUnicodeString& oManagedDirectory);

  /**
  * Get the path of default folder for appData content.
  * For instance c:\users\xxx\AppData\Local\DassaultSystemes
  * @param ioPath  [inout]
  *   the path that will be returned. pointer must point a valid CATUnicodeString
  * @param iKeepResult
  *   if equals to true, the ioPath pointer will be stored to avoid recalculation, make sure ioPath will be persistent if you use it.
  * @return
  *   S_OK : all is fine
  *   S_FALSE : problem during initialization of environment, and this one might be set to temporary directory
  *   E_FAIL : failure
  */
  static HRESULT GetDSAppdataDefaultPath(CATUnicodeString& ioPath);

  /**
  * Gets the data stored by a File Description stream,
  * @param iIlbToFDFile [in]
  * ILockByte handling the local File Description
  * @param oPointedData [out]
  * Data stored into the file description stream:
  * - PhysicalId of the owning component: the one owning the SD when SD set in LocalStorage state and Saved, and not created by duplication.
  *    ->  CATUuid PhysicalId = oPointedData->GetLocalOwner()
  * - pointed local url
  *    ->  CATVVSUrl PointedUrl = oPointedData->GetLocalUrl()
  * @return
  * S_OK if the pointed local data can be retrieved properly, E_FAIL if not.
  */
  static HRESULT GetPointedData(CATILockBytes2* iIlbToFDFile, CATOmxSR<FileDescriptionData>& oPointedData);

  /**
  * Ask for changing the current Local Storage Managed repository with a new user one (through UI Preference setting)
  * @param iUserDir [in]
  * The new absolute directory path asked by user
  * This directory must exist on a local disk and be empty (excepted eventual lsinfo.log file)
  * @param oLSManagedDir [out]
  * the effective current Local Storage Managed Dir
  *   = iUserDir if change succeeded
  *   = the currently used dir if File Descriptions still present in this directory or iUserDir invalid
  * @return
  *   S_OK   : Successfully ended. This new path is registered in setting and LocalStorage locking structure
  *   FAILED : Current Local Storage repository path does not change
  *   E_FAIL : A software error occured
  *   specific failures (for UI information)
  *   E_VVS_LS_NotAValidDir        : new Local Storage repository does not exist/not a valid absolute folder path
  *   E_VVS_LS_CurrentDirNotEmpty  : current Local Storage repository not empty (most currently, .fd files remaining)
  *   E_VVS_LS_ProposedDirNotEmpty : new Local Storage repository not empty
  */
  static HRESULT ChangeManagedDirectory(const CATUnicodeString& iUserDir, CATUnicodeString& oLSManagedDir);

  /**
  * Gets the default Local Storage Managed Directory
  * @param oLSDefaultDir [out]
  * the default Local Storage Managed Directory
  * @return
    * S_OK as this default directory is always re-built from environment pathes
  */
  static HRESULT GetDefaultManagedDirectory(CATUnicodeString& oLSDefaultDir);

private:

  static CATBoolean _GetDataInternal;

  static HRESULT CreateFileDescriptionInternal(const char iVersion, const CATUuid& iPhysicalId, CATVVSUrl& iPointedFile, FD::FileDescriptionBehavior iExpectedBehavior, CATILockBytes2& ioILB);
  static HRESULT SelectManagedDirectory(const CATUnicodeString& iSettingDir, const CATUnicodeString& iUserDir, CATBoolean iUserInput, CATUnicodeString& oSelectedDir);
};

#endif

