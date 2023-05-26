#ifndef CATVvsCacheUtil_H
#define CATVvsCacheUtil_H

#include "CATFileVaultSystem.h"

#include "CATOmxSR.h"
#include "CATVVSUrl.h"
#include "CATUnicodeString.h"
#include "CATOmxOSet.h"
#include "CATFVSArchiveEntryId.h"

class CATFVSArchivesSession;
class CATFVSArchiveFile;

class  ExportedByFVS CATVvsCacheUtil
{
public:
  
  CATVvsCacheUtil();
  
  // Specific to AW  
  HRESULT    FromUrlToAWInfos(const CATVVSUrl & iFullCacheUrl, CATUnicodeString & oArchiveDir, CATUnicodeString & oArchiveName, CATFVSArchiveEntryId & oEntryVal);
  HRESULT    UnloadAndDeleteArchive(CATUnicodeString & iArchiveDir, CATUnicodeString & iArchiveName) ;
  HRESULT    GetArchivePath(const CATUnicodeString & iArchiveDir, const CATUnicodeString & iArchiveName, CATUnicodeString & oPath) ;
  HRESULT    FreezeCurrentArchive() ;
  // Dump of archive TOC is always done
  // If iDirForExtract is null, no extract is done. If iDirForExtract is not null and iEntryIdsForExtract is empty, all entries are extracted.
  HRESULT    DumpArchiveAndExtract(CATUnicodeString & iArchivePath, CATOmxOSet<CATUnicodeString>& iEntryIdsForExtract, CATUnicodeString iDirForExtract="");  
  
private:
  CATOmxSR<CATFVSArchivesSession>  _spAWMngr; 
};

#endif


