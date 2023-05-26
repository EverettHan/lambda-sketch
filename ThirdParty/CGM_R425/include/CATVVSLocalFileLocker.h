/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2018
//------------------------------------------------------------------------------
//
//  wrapper on LocalStorage lock management access
// 
//------------------------------------------------------------------------------
// Sept 2018 Creation                                                       VCS
//------------------------------------------------------------------------------

#ifndef CATVVSLocalFileLocker_h
#define CATVVSLocalFileLocker_h

// CATVirtualVaultSystem
#include "CATVVSUrl.h"
#include "VVSUtils.h"
// SystemTS
#include "IUnknown.h"
// System
#include "CATError.h"
#include "CATUnicodeString.h"
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxSR.h"
#include "CATOmxList.h"

namespace LocalFile
{
  // Locally stored file lock status, asked to local PLM_LocalResult locking table:
  // LockUndef: status not yet asked
  // NotLocked: file not locked 
  // LockedByComp: locked by the component status is asked for
  // LockedBySource: locked by the source component referenced in FileDescription and NOT by the component itself (check web component cloning case, by DB LocalStorage collector)
  // LockedByOther: locked by any other component than the component/source status is asked for 
  enum LockState { LockUndef, NotLocked, LockedByComp, LockedBySource, LockedByOther };
}

class ExportedByVVSUtils CATVVSLocalFileLocker
{
public:

  CATVVSLocalFileLocker();
  virtual ~CATVVSLocalFileLocker();

  // Records a locking context in lock manager
  // (As of now, to be used by LocalSave/Offline)
  void RecordLockingContext(const CATUuid& iContextId);

  // Locks a locally stored file for a given context 
  // (As of now, used by Session context with iContextID = 0)
  HRESULT LockLocalFile(const CATVVSUrl& iLocalUrl, const CATUuid& iPhysicalId, const CATUuid& iContextId);

  // Locks a locally stored file for given context(s) already recorded by (a series of) RecordLockingContext
  // (As of now, used by LocalSave/Offline, having already recorded their own ContextID)
  HRESULT LockLocalFileToContexts(const CATVVSUrl& iLocalUrl, const CATUuid& iPhysicalId);

  // Unlocks a locally stored file for a given context 
  // (As of now, used by Session context with iContextID = 0, and for Local Save/Offline with image ID)
  HRESULT UnlockLocalFile(const CATVVSUrl& iLocalUrl, const CATUuid& iPhysicalId, const CATUuid& iContextId, CATOmxSR<CATError>& opError);

  // Unlocks ALL locally stored file for a given context 
  // (As of now, used by LocalSave/Offline, when their current image is being deleted)
  HRESULT UnlockLocalFilesFromContext(const CATUuid& iContextId, CATOmxList<CATError>& oUnlockErrors);

  // Read a local file lock status TRUE: is currently locked by at least one couple (PhysicalId, ContextId)
  CATBoolean IsLocalFileLocked(const CATVVSUrl& iLocalUrl);

  LocalFile::LockState IsLocalFileLockedByComponent(const CATVVSUrl& iLocalUrl, const CATUuid& iPhysicalId, const CATUuid& iSourceId);
  HRESULT IsLocalFileRemovable(const CATVVSUrl& iLocalUrl, const CATUuid& iPhysicalId, const CATUuid& iContextId, CATBoolean& oRemovable);

  // Streams locking table in memory to lock file
  HRESULT StreamToLockFile(CATBoolean iSaveEnded);

  // Unlocks a locally stored file for ALL LocalSave/Offline contexts involved by current session
  // (As of now, used by session for LocalSave/Offline Urls, when Local storage is being unset)
  HRESULT UnlockLocalFileFromContexts(const CATVVSUrl& iLocalUrl, const CATUuid& iPhysicalId, CATOmxList<CATError>& oUnlockErrors);

  // Gets the local Storage current repository (can be modified by setting from R424 FD03 on)
  const CATUnicodeString GetLockDirectory() const;

  // Read and dump locking table from log file 
  int DumpLockFile(const CATUnicodeString& iLockDirPath) const;

  // Remove obsolete entry from locking table
  HRESULT RemoveObsoleteFileLock(const CATVVSUrl& iLocalUrl);

  // Get UTC and local times
  CATUnicodeString GetCurrentTimes(CATUnicodeString& oUTC);

private:

  CATVVSLocalFileLocker(const CATVVSLocalFileLocker&); // not implemented
  CATVVSLocalFileLocker& operator= (const CATVVSLocalFileLocker&); // not implemented
};
#endif
