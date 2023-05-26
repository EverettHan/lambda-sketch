/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
/**
*  CATxPDMInternalDescriptor :
*      Descriptor of file
*/
//================================================================
//  Usage notes :
//
//  
//	Dec.98	slg
//================================================================
#ifndef CATxPDMInternalDescriptor_H
#define CATxPDMInternalDescriptor_H

/**
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
//
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATLib.h"
#include "CATLib64.h"
#include "CATIPointedSymbols.h"
#include "CATIDocDescriptor.h"
#include "CATIFileDescriptor.h"
#include "CATUuid.h"
#include "CATOmxSR.h"
//
class CATStorageData;
class CATUuid;
class CATIStorageData_var;
class CATLISTP(CATIDocId);
class CATIDocId;
class CATDocumentProperty;
class CATOmbVVSUrlDocId;

#define CATFileDescriptor  CATxPDMInternalDescriptor   

class CATxPDMInternalDescriptor : public CATIFileDescriptor
{
public:
  /**
  * Creates a file descriptor on a document from its path.
  * <b>Role:</B> This method retrieves a CATIFileDescriptor on file based document without loading it.
  * The document, identified by the given Filepath,  must be a valid V5 file
  * This interface provides services on this document. The returned interfaces must be released.
  * @param FilePath
  *  The file path of the file based document.
  * @param oppFileDescriptor
  *  The returned handler on the CATIFileDescriptor.
  */
  ExportedByAC0XXLNK static HRESULT CreateFileDescriptor(const CATUnicodeString& FilePath, CATIFileDescriptor** oppFileDescriptor);

  /**
  * Creates a file descriptor on a document from its DocId.
  * <b>Role:</B> This method retrieves a CATIFileDescriptor on file based document without loading it.
  * The document, identified by the given DocId,  must be a valid V5 file
  * This interface provides services on this document. The returned interfaces must be released.
  * @param DocId
  *  The docId of the document.
  * @param oppFileDescriptor
  *  The returned handler on the CATIFileDescriptor.
  * Notice that CATVVSUrl based CATIDocId's created by DocIdCATDocIdServices::CreateDocIdFromUrl are supported but file specific APIs (GetAccessRight, GetLastModificationTime...) will fail.
  */
  ExportedByAC0XXLNK static HRESULT CreateFileDescriptor(CATIDocId& DocId, CATIFileDescriptor** oppFileDescriptor);
private:
  // Standard operator
  CATxPDMInternalDescriptor(const CATxPDMInternalDescriptor&);
  CATxPDMInternalDescriptor& operator= (const CATxPDMInternalDescriptor&);
};

#endif
