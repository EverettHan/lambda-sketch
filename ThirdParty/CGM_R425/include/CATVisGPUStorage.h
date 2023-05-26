#ifndef CATVisGPUStorage_H
#define CATVisGPUStorage_H

// Copyright Dassault Systemes 2005

#include "SGInfra.h"
#include "DSYSysAtomic.h"


class ExportedBySGInfra CATVisGPUStorage
{
public:

  /**
   *  Creates a new @href CATVisGPUStorage.
   */
  CATVisGPUStorage();
  ~CATVisGPUStorage();
  
  /**
   *  Retrieves the ID associated to this storage.
   */
  inline CATUINTPTR GetID();

  /**
   *  Modifies the ID associated to this storage.
   */
  inline void SetID(CATUINTPTR iID);

  inline unsigned int GetSize();
  inline void SetSize(unsigned int iSize);

  inline unsigned int GetIndexOffset();
  inline void SetIndexOffset(unsigned int iOffset);

  inline unsigned short GetFrame();
  inline void SetFrame(unsigned short iFrame);

  inline unsigned short GetValue();
  inline void SetValue(unsigned short iValue);

protected:

  //static CATMutex _sMutex;
  //unsigned int   _Id;
  unsigned int   _Size; 
  unsigned int   _IndexOffset;
  union
  {
    int _AtomicVal;
    struct
    {
      unsigned short _LastFrameDrawn;
      unsigned short _Value;
    };
  };
  CATUINTPTR _NewId;
};

inline CATUINTPTR CATVisGPUStorage::GetID()
{
  return _NewId;
  //return _Id;
}

inline void CATVisGPUStorage::SetID(CATUINTPTR iID)
{
  //_Id = iID;
  _NewId = iID;
}

inline unsigned int CATVisGPUStorage::GetSize()
{
  return _Size;
}

inline void CATVisGPUStorage::SetSize(unsigned int iSize)
{
  _Size = iSize;
}

inline unsigned int CATVisGPUStorage::GetIndexOffset()
{
  return _IndexOffset;
}

inline void CATVisGPUStorage::SetIndexOffset(unsigned int iOffset)
{
  _IndexOffset = iOffset;
}
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
inline unsigned short CATVisGPUStorage::GetFrame()
{
  return DSYSysInterlockedCompareExchangeInt32(&_AtomicVal, 0, 0) & 0xFFFF;
}

inline void CATVisGPUStorage::SetFrame(unsigned short iFrame)
{
  int oldVal;
  int newVal;
  do
  {
    oldVal = _AtomicVal;
    newVal = iFrame | (oldVal & 0xFFFF0000);
  }
  while(DSYSysInterlockedCompareExchangeInt32(&_AtomicVal, newVal, oldVal) != oldVal);
}

inline unsigned short CATVisGPUStorage::GetValue()
{
  return DSYSysInterlockedCompareExchangeInt32(&_AtomicVal, 0, 0) >> 16;
}

inline void CATVisGPUStorage::SetValue(unsigned short iValue)
{
  int oldVal;
  int newVal;
  do
  {
    oldVal = _AtomicVal;
    newVal = iValue << 16 | (oldVal & 0x0000FFFF);
  }
  while(DSYSysInterlockedCompareExchangeInt32(&_AtomicVal, newVal, oldVal) != oldVal);
}
#ifdef _MSC_VER
  #pragma warning(pop)
#endif
#endif
