#ifndef __CATOmbStorageServices_H
#define __CATOmbStorageServices_H

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATOmxArray.h"
#include "CATUnicodeString.h"
#include "CATFile.h"
#include "CATOmxSR.h"
class CATILockBytes2;

/** 
 * wrapper for embedded storages case.
 * DO NOT USE, specific OMC.
 */
class ExportedByAC0XXLNK CATOmbStorageHelper
{
  CATUnicodeString m_path;
  CATOmxSR<CATILockBytes2> m_ILB;
  CATOmxArray<CATStorage*,naive_manager> m_embeddedStorages;
public:
  CATOmbStorageHelper(const CATUnicodeString& iPath,CATILockBytes2* pILB = NULL);

  CATOmxArray<CATUnicodeString> GetStoragesNames();

  CATStorage* GetStorage(DWORD OpenMode,CATBoolean iTryDocumentStorage);

  HRESULT Commit();

  //handles close of opened storages
  ~CATOmbStorageHelper();
};

#endif

