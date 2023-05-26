// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef V5OmbCacheDataSession_H_
#define V5OmbCacheDataSession_H_

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "IUnknown.h" 
#include "CATOmxOHMap.h"
#include "CATOmxOSet.h"

class V5OmbSession ;
class CATDocument ;
class CATIDocId ;
class CATIDocDescriptor ;

enum OMBCacheDataStatus 
{
 OMBCacheData_Present    = 0,
 OMBCacheData_Missing	 = 1,
 OMBCacheData_Unknown	 = 2,
 OMBCacheData_Unknown_becauseof_E_FAIL	= 3
};

class V5OmbCacheDataSession
{
 public :
 
   V5OmbCacheDataSession(V5OmbSession* session) ;
  ~V5OmbCacheDataSession() ;

  OMBCacheDataStatus Contains(CATIDocId* iDocId) ;
  OMBCacheDataStatus Contains(CATUnicodeString* iDocUrl) ;

  OMBCacheDataStatus Get(CATIDocId* iDocId,CATIDocDescriptor** oDocDescriptor) ;
  OMBCacheDataStatus Get(CATUnicodeString* iDocUrl,CATIDocDescriptor** oDocDescriptor) ;

  HRESULT Put(CATIDocId* iDocId,OMBCacheDataStatus status,CATIDocDescriptor* iDocDescriptor) ;
  HRESULT Put(CATUnicodeString* iDocUrl,OMBCacheDataStatus status,CATIDocDescriptor* iDocDescriptor) ;

  ExportedByAC0XXLNK HRESULT ClearData() ;
  HRESULT ClearDocumentEntry(CATDocument* doc) ;
  HRESULT ClearDocumentEntry(CATIDocId* doc) ;
  HRESULT ClearDocumentEntry(CATUnicodeString* doc_url) ;


 private :

   CATOmxOHMap<CATUnicodeString,CATBaseUnknown*> _PathResolutionHashtable ;
   CATOmxOSet<CATUnicodeString> _MissingLinkHashtable ;
   V5OmbSession* _session ;
} ;
#endif
