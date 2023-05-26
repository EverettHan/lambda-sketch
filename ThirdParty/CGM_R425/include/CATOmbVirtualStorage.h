#ifndef __CATOmbVirtualStorage_H
#define __CATOmbVirtualStorage_H

#include "CATOmxSharable.h"
#include "CATUnicodeString.h"
#include "CATOmxSR.h"
#include "AC0XXLNK.h"
#include "CATWTypes.h"
#include "CATOmxIter.h"
#include "CATOmxDefaultCollecManager.h"
class CATIOmxBinaryStream;
class CATStorage;
class CATILockBytes2;

/**
 * STATSTG like struct
 */
struct CATOmbVirtualStorageElement
{
  CATUnicodeString Name;
  STGTY Type; //STGTY_STORAGE or STGTY_STREAM
  CATLONG64 Size; //meaningful if Type==STGTY_STREAM
};

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbVirtualStorageElement>::manager();

/**
 * Abstraction of CATStorage API.
 */
class CATOmbVirtualStorage : public CATOmxSharable
{
public:

  /**Create wrapper on CATStorage*/
  static ExportedByAC0XXLNK CATOmxSR<CATOmbVirtualStorage> CreateOnCATStorage(CATStorage& iStorage);

  /**Create a "simple" storage. Simple storage is meant for TINY archives*/
  static ExportedByAC0XXLNK HRESULT CreateSimpleStorage(CATILockBytes2& iILB2, DWORD iMode, CATOmxSR<CATOmbVirtualStorage>& oStorage);

  /** Create a CATOmbVirtualStorage wrapper on iILB2. Can be a CATStorage or a "simple" storage*/
  static ExportedByAC0XXLNK HRESULT OpenForRead(CATILockBytes2& iILB2, CATOmxSR<CATOmbVirtualStorage>& oStorage);

  /** Emulation of CATStorage API*/
  virtual HRESULT OpenStorage(const CATUnicodeString& iName, DWORD iMode, CATOmxSR<CATOmbVirtualStorage>& oStream) = 0;
  virtual HRESULT OpenStream(const CATUnicodeString& iName, DWORD iMode, CATOmxSR<CATIOmxBinaryStream>& oStream) = 0;
  virtual HRESULT CloseStream(CATIOmxBinaryStream& iStream) = 0;
  virtual HRESULT DestroyElement(const CATUnicodeString& iName) = 0;
  virtual HRESULT Close() = 0;
  virtual HRESULT Commit() = 0;
  virtual HRESULT EnumElements(CATOmxIter<const CATOmbVirtualStorageElement>& oElements) = 0;

  //PLEASE DO NOT USE, NOT FOUND OTHER WAY TO MAKE BAD STUPID DEBUG CODE WORK
  virtual CATStorage* AsCATStorage() = 0;
};

#endif
