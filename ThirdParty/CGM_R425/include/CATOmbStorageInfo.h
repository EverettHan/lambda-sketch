#ifndef CATOmbStorageInfo_H
#define CATOmbStorageInfo_H

#include "CATUnicodeString.h"
#include "CATOmxSharable.h"
class CATStorage;

/**
* @level protected
* @usage U1
*/


/**
* This class allows the storage of several information concerning a CATStorage. 
* Il also keep the current number of time a storage is opened. 
*/
class CATOmbStorageInfo: public CATOmxSharable
{
public:
  /**
  * Constuctor.
  * Only used to retrieve a CATOmbStorageInfo in a Hash Table of CATOmbStorageInfo
  */
  CATOmbStorageInfo(const CATUnicodeString& StorageUuid,DWORD iReadWriteMode);

  /**
  * Main constructor. This constructor should used whenever it is possible. 
  */ 
  CATOmbStorageInfo(const CATUnicodeString& iStorageUuid, CATStorage& iStorage,DWORD iReadWriteMode);

  /**
  * Second constructor. This constructor should be called when the StorageUUid is unknown. 
  * In that case, this constructor will retrieve it. 
  */
  CATOmbStorageInfo(CATStorage& iStorage,DWORD iReadWriteMode);

  void Reset(CATStorage* iStorage,DWORD iReadWriteMode);

  /**
  * Destructor
  */ 
  virtual ~CATOmbStorageInfo();

  const CATUnicodeString& GetStorageUuid() const {return _StorageUuid;}

  CATStorage* GetStorage() const {return _pStorage;}

  /** 
  * Returns the number of time the storage is currently opened. 
  */ 
  int GetCounterOpen()  const {return _CounterOpen;}

  /**
  * Increases the open counter of one unit. 
  * Returns its new value. 
  */ 
  int IncreaseCounter() {return ++_CounterOpen;}

  /**
  * Decreases the open counter of one unit. 
  * Returns its new value. 
  */
  int DecreaseCounter() {return --_CounterOpen;}

  DWORD GetReadWriteMode() {return _ReadWriteMode;}
  void SetReadWriteMode(DWORD iMode) {_ReadWriteMode = iMode;}

  virtual CATHashKey Hash() const;
  virtual int Cmp(const CATOmxSharable &St) const;

private:
  CATOmbStorageInfo(CATOmbStorageInfo&);

  CATUnicodeString _StorageUuid;
  CATStorage* _pStorage;
  int _CounterOpen;
  DWORD _ReadWriteMode;

};

#endif
