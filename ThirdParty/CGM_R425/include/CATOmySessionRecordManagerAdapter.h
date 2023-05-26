// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATOmySessionRecordManagerAdapter.h
// Provide adapter to interface CATIOmySessionRecordManager
#ifndef CATOmySessionRecordManagerAdapter_H
#define CATOmySessionRecordManagerAdapter_H

#include "CATIOmySessionRecordManager.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown_WR.h"
#include "CATOMYCommunication.h"
#include "CATOmyLogInfos.h"
#include "PLMMaintenanceMessageStorage.h"
#include "CATIOmyRecordAuthorizationErrorReporter.h"

class CATOmyStorageHandler;
class CATOmyStreamHandler;
class CATIComSidlStreamTube;
class CATStorage;
class CATHashDico;
class ExportedByCATOMYCommunication CATOmySessionRecordManagerAdapter: public CATIOmySessionRecordManager

{
  CATDeclareClass;
public:
  // Implements CATIOmySessionRecordManager::SetAuthorizationErrorReporter
  HRESULT SetAuthorizationErrorReporter(CATIOmyRecordAuthorizationErrorReporter *);

  // Implements CATIOmySessionRecordManager::CheckModeAuthorization
  HRESULT CheckModeAuthorization();

  // Implements CATIOmySessionRecordManager::SetPathToRecordData
  HRESULT SetPathToRecordData (const char *  iPathToRecordData ) ;
  
  // Implements CATIOmySessionRecordManager::GetPathToCache
  HRESULT GetPathToCache(CATUnicodeString & oPathToCache);

  // Implements CATIOmySessionRecordManager::GetPathToRecordData
  CATUnicodeString GetPathToRecordData() { return _PathToRecordData; };

  // Implements CATIOmySessionRecordManager::OpenLocalVaultStorage
  CATOmyStorageHandler * OpenLocalVaultStorage(DWORD iOpenMode);

  // Implements CATIOmySessionRecordManager::OpenLocalSaveStorage
  CATOmyStorageHandler *  OpenLocalSaveStorage(DWORD  iOpenMode);

  // Implements CATIOmySessionRecordManager::OpenMessageStorage
  CATOmyStorageHandler * OpenMessageStorage ();

protected:
  CATOmySessionRecordManagerAdapter();
  ~CATOmySessionRecordManagerAdapter();

  virtual HRESULT CheckAndUpdatePathToRecordData(CATUnicodeString & ioPathToRecordData)=0;
  virtual HRESULT CheckLicenceAuthorization()=0;

  CATOmyStorageHandler * _OpenRecordStorage();
  CATBoolean _IsADirectory(const char *  iPath);

private:
  CATOmyStorageHandler * _OpenSubStorage(const CATUnicodeString &iStorageName, DWORD iOpenMode, CATBoolean iCloseOnDelete=TRUE);

  CATStorage * _RootStg, * _VaultStg;
  CATUnicodeString _PathToRecordData;

  CATIOmyRecordAuthorizationErrorReporter_var _AuthorizationErrorReporter;
};

//-----------------------------------------------------------------------

#endif
