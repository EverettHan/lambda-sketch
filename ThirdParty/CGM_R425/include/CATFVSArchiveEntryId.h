#ifndef __CATFVSArchiveEntryId_H
#define __CATFVSArchiveEntryId_H

// OS
#include <string.h>
// SpecialAPI
#include "CATSysDataType.h"
// System
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxKernelUtilities.h"
#include "CATOmxPortability.h"
#include "CATOmxOSet.h"
#include "CATWOmxBinaryStream.h"

// CATFileVaultSystem
#include "CATFileVaultSystem.h"

class CATFVSArchiveFile;

class ExportedByFVS CATFVSArchiveEntryId
{
  DWORD m_SHA[8];
public:
  inline CATFVSArchiveEntryId() {memset(m_SHA,0,sizeof(m_SHA));}

  inline CATFVSArchiveEntryId(const CATFVSArchiveEntryId& iId) {memcpy(m_SHA,iId.m_SHA,sizeof(m_SHA));}
  inline CATFVSArchiveEntryId& operator=(const CATFVSArchiveEntryId& iId) {memcpy(m_SHA,iId.m_SHA,sizeof(m_SHA));return *this;}

  inline CATFVSArchiveEntryId(const CATUnicodeString& iName) {operator=(iName);}
  CATFVSArchiveEntryId& operator=(const CATUnicodeString& iName);

  CATUnicodeString ConvertToString() const; //Prints with format %08x_%08x_%08x_%08x_%08x_%08x_%08x_%08x
  HRESULT BuildFromString(const CATUnicodeString& iStr);          //Parse previous format

  CATWOmxBinaryStream & WriteInStream  (CATWOmxBinaryStream &iSW) const {return iSW.WriteBytes((const void*)m_SHA,sizeof(m_SHA));}
  CATWOmxBinaryStream & ReadFromStream (CATWOmxBinaryStream &iSW)       {return iSW.ReadBytes((void*)m_SHA,sizeof(m_SHA));}
  
  inline int Compare(const CATFVSArchiveEntryId& iId) const {return memcmp(m_SHA,iId.m_SHA,sizeof(m_SHA));}
  inline CATHashKey Hash() const {return CATOmxHash2(CATOmxHash2(m_SHA[0],m_SHA[2]),m_SHA[6]);}

  inline int operator==(const CATFVSArchiveEntryId& iId) const {return 0 == Compare(iId);}
  inline int operator!=(const CATFVSArchiveEntryId& iId) const {return 0 != Compare(iId);}

  friend class CATFVSArchiveFile;
};

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATFVSArchiveEntryId>::manager();
template <> 
ExportedByFVS CATOmxCollecManager & CATOmxDefaultCollecManager <CATOmxOSet<CATFVSArchiveEntryId> >::manager () ;

#endif
