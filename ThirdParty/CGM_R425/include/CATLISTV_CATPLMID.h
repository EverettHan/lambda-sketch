/* -*-c++-*- */
#ifndef CATLISTV_CATPLMID_H
#define CATLISTV_CATPLMID_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
* @level Private
* @usage U3
*/

#include "CATPLMIdentificationAccess.h"
#include "CATOmxArray.h"
#include "CATPLMID.h"

template <> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager<CATPLMID>::manager();

class ExportedByCATPLMIdentificationAccess CATListValCATPLMID : public CATOmxArray<CATPLMID>
{
public:
  inline CATListValCATPLMID() {}
  inline CATListValCATPLMID(const CATOmxArray<CATPLMID> &iCopy) :CATOmxArray<CATPLMID>(iCopy) {}
  inline CATListValCATPLMID(int iSize) {}
  inline CATPLMID & operator[](int idx) { return GetW(idx); }
  inline const CATPLMID& operator[](int idx)const { return CATOmxArray<CATPLMID>::operator[](idx); }
  inline void Append(const CATPLMID & iPLMID) { CATOmxArray<CATPLMID>::Append(iPLMID); }
  inline void Append(const CATListValCATPLMID & iPLMIDs) { CATOmxArray<CATPLMID>::Append(iPLMIDs); }
  inline void InsertAt(int idx, const CATPLMID  & iPLMID) { Insert(idx, iPLMID); }
  inline int Size(void) const { return CATOmxArray<CATPLMID>::Size(); }
  inline void RemovePosition(int idx) { Remove(idx); }
  inline int operator==(const CATListValCATPLMID & iPLMIDs) const { return CATOmxArray<CATPLMID>::operator==(iPLMIDs); }
  inline int operator!=(const CATListValCATPLMID & iPLMIDs) const { return !this->operator==(iPLMIDs); }
  int Locate(const CATPLMID  & iPLMID, int idx = 1) const;
  inline void RemoveAll(CATCollec::MemoryHandling iKeepAlloc = CATCollec::ReleaseAllocation) { CATOmxArray<CATPLMID>::RemoveAll(iKeepAlloc == CATCollec::KeepAllocation); }
  int RemoveDuplicates();
  int RemoveValue(const CATPLMID & iRemove);
};


typedef CATListValCATPLMID CATPLMIDs;

//required for legacy reason
#include "CATLISTV_Clean.h"
#define CATLISTV_Append
#define CATLISTV_RemoveAll
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_Locate
#define CATLISTV_AppendList
#define CATLISTV_RemoveDuplicatesCount
#define CATLISTV_InsertAt
#include "CATLISTV_Declare.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIdentificationAccess

#endif
