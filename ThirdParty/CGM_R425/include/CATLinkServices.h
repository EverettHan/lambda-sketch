// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLinkServices_H
#define CATLinkServices_H

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"

#include "CATISymbolicLink.h"
#include "CATUnicodeString.h"
#include "sequence_octet.h"
#include "CATCORBABoolean.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
class CATListValCATBaseUnknown_var;

class CATDocument;
class CATILinkableObject;
class CATILinkableObject_var;
class CATILinkableObject;
class CATIBindParameters;
class CATIDocDescriptor;
class CATIDocId;


// =======================================================================================
// ExternalLink Services (has provided by CATIExternalLinks/CATIExternalLink introspections) 
// =======================================================================================
// 
//return 1, continue Visit, 0 stop visit
//A prototype function to be called on one abstract link
//ISynchroStatus: -1: undef, 0: Local Copy in place (assynchronous loading possible), 1: Direct Reference  (synchronous loading required)
//IAggregationStatus: pointed is -1: undef, 0: reference, 1: aggregated
//IIOStatus: pointed is -1: undef, 0: neutral, 1: in, 2:out
//IVisibility: pointed is -1: undef, 0: not_seen by user, 1: to be seen by user
typedef int SelectLinkInfoFct(CATBaseUnknown* ILink, const int& IAggregationStatus, const int& iSynchroStatus, const int& IIOStatus, const int& i_visibility, const CATUnicodeString& iType, CATBaseUnknown* iOwner, CATBaseUnknown* iPointing, CATBaseUnknown* iPointed, const SEQUENCE(octet)& iPointedNameB, CATListValCATBaseUnknown_var& iSelected_infos, void* iData);

// =======================================================================================
// Document name services
// =======================================================================================

// ---------------------------------------------------------------------------
// Scan of the loaded documents to find the searched one
// If it is not in session, and according to the value of the last argument
// the service will load the document if the storagename corresponds to an existing path
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
CATDocument * FindThroughStorageName(const CATUnicodeString & type
  , const CATUnicodeString & storageName
  , boolean                  LoadIfNecessary);

//---------------------------------------------------------------------------------
// As above, the service returns :
//			 S_OK if the document was sucessfully found and loaded
//			 S_FALSE if the document was sucessfully found and was already loaded
//			 E_FAIL if the document couldn't be found
// --------------------------------------------------------------------------------
ExportedByCATObjectModelerBase
HRESULT FindThroughStorageName(CATDocument*& oDocument, const CATUnicodeString & type
  , const CATUnicodeString & storageName
  , boolean                  LoadIfNecessary);


// ---------------------------------------------------------------------------
// Change the storagename according to the search order
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
void  StorageToSearchOrder(const CATUnicodeString& oldstorageName, CATUnicodeString& newstorageName, boolean& foundsomething);

// ---------------------------------------------------------------------------
// Generation of a linkable name corresponding to the input document
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
SEQUENCE(octet)  GetDocumentLinkableName(CATDocument* doc);

// ---------------------------------------------------------------------------
// Generation of a linkable name for the document corresponding to the input parameters
//    - document_path : path name of the document to link
//    - document_type : type of the document
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
SEQUENCE(octet)  GetDocumentLinkableName(const CATUnicodeString& document_path
  , const CATUnicodeString& document_type);

// ---------------------------------------------------------------------------
// Generation of a linkable name for the document corresponding to the input parameter
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
HRESULT GetDocumentLinkableName(CATIDocId *iDocId, SEQUENCE(octet)& oLinkableName);

// ---------------------------------------------------------------------------
// Recovering the document filename (with or without the path)
//  - from the document pointer
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
CATUnicodeString  GetDocumentFileName(CATDocument* doc
  , boolean      pathIncluded = TRUE);

//  - from any linkableObject contained in this document
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
CATUnicodeString  GetDocumentFileName(const CATILinkableObject_var& object
  , boolean      pathIncluded = TRUE);



// =======================================================================================

enum SeekParameters
{
  LinkFirst,
  SearchOrderFirst,
  LinkOnly,
  SearchOrderOnly
};

// ---------------------------------------------------------------------------
// Getting a document by means of the hint of a linkable name,
// according to the input strategy
// ---------------------------------------------------------------------------
ExportedByCATObjectModelerBase
CATDocument*  SeekDocument(const SEQUENCE(octet)& hint
  , SeekParameters         strategy = LinkFirst
  , boolean                LoadIfNecessary = TRUE);


//---------------------------------------------------------------------------------
// As above, the service returns :
//			 S_OK if the document was sucessfully found and loaded
//			 S_FALSE if the document was sucessfully found and was already loaded
//			 E_FAIL if the document couldn't be found
// --------------------------------------------------------------------------------
ExportedByCATObjectModelerBase
HRESULT  SeekDocument(CATDocument*& oDocument, const SEQUENCE(octet)& hint
  , SeekParameters         strategy = LinkFirst
  , boolean                LoadIfNecessary = TRUE);



//---------------------------------------------------------------------------------
// As above, the service returns :
//			 S_OK if the document was sucessfully found and loaded
//			 S_FALSE if the document was sucessfully found and was already loaded
//			 E_FAIL if the document couldn't be found
// --------------------------------------------------------------------------------
ExportedByCATObjectModelerBase
HRESULT  SeekDocument(CATDocument*& oDocument, const SEQUENCE(octet)& hint, CATIBindParameters*);

ExportedByCATObjectModelerBase
const CATUnicodeString& SearchOrderSeparator();

ExportedByCATObjectModelerBase
boolean LinkExistUnicodeName(const CATUnicodeString& Str);


/**
 * Retieves the list of directories stored in the search order settings
 * <br><b>Role</b>: Allocates a list of CATUnicodeString to be filled with
 * the directories stored in the CATSettings through Search Order panel.
 * @param oSearchOrderDirectories
 *  pointer to a CATListOfCATUnicodeString. Don't forget to delete it after use.
 * @param iForDisplay
 *  boolean allowing to choose the kind of result:
 *  if set to FALSE (default value), the returned CATUnicodeStrings are file names
 *  or logical names compatible with the use of CATMakePath, CATGetFileInfo, or
 *  any call to System function on paths operations.
 *  if set to TRUE, the returned CATUnicodeStrings are file names, or DLNames
 *  that can be used as is to be displayed.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK:</tt> on success: settings are not empty and have been read.
 *  <br><tt>S_FALSE:</tt> settings are empty.
 */
ExportedByCATObjectModelerBase
HRESULT CATGetSearchOrderDirectories(CATListOfCATUnicodeString **oSearchOrderDirectories, boolean iForDisplay = FALSE);

/**
 * Writes a list of directories in the search order settings
 * <br><b>Role</b>: Stores in CATSettings a list of CATUnicodeString filled with
 * directories.
 * @param iSearchOrderDirectories
 *  pointer to a CATListOfCATUnicodeString.
 * @param iForDisplay
 *  if set to FALSE (default value), the CATUnicodeStrings in iSearchOrderDirectories
 *  are file names or logical names.
 *  if set to TRUE, the rCATUnicodeStrings in iSearchOrderDirectories are file names,
 *  or DLNames.
 * @return
 *  <b>Legal values</b>:
 *  <br><tt>S_OK:</tt> on success.
 *  <br><tt>E_FAILED:</tt> on failure.
 */
ExportedByCATObjectModelerBase
HRESULT CATPutSearchOrderDirectories(const CATListOfCATUnicodeString *iSearchOrderDirectories, boolean iFromDisplay = FALSE);

ExportedByCATObjectModelerBase
HRESULT CATGetInfoOnLink(const SEQUENCE(octet)& iLink,
  CATUnicodeString& oDocName,
  CATDocument *& oPointedDoc,
  int& oResolutionInfo,
  CATDocument * iPointingDocument = NULL);

ExportedByCATObjectModelerBase
HRESULT CATGetInfoOnLink(const SEQUENCE(octet)& iLink,
  CATUnicodeString& oDocName,
  CATDocument *& oPointedDoc,
  int& oResolutionInfo,
  const CATUnicodeString & iPointingDocEnv,
  const CATUnicodeString & iPointingDocPath,
  const CATUnicodeString & iPointingDocType);

/* CATFindDocDescriptor
 *  @param oDocDescriptor [out,CATBaseUnknown#Release]
 */
ExportedByCATObjectModelerBase
HRESULT CATFindDocDescriptor(const SEQUENCE(octet)& iNameB,
  CATIDocDescriptor ** oDocDescriptor,
  CATDocument* iPointingDocument);

/* CATFindDocDescriptor
 *  @param oDocDescriptor [out,CATBaseUnknown#Release]
 */
ExportedByCATObjectModelerBase
HRESULT CATFindDocDescriptor(const SEQUENCE(octet)& iNameB,
  CATIDocDescriptor ** oDocDescriptor,
  CATIDocId * iPointingDocId = NULL);

/* CATFindDocId
 *  @param oDocDescriptor [out,CATBaseUnknown#Release]
 */
ExportedByCATObjectModelerBase
HRESULT CATFindDocId(const SEQUENCE(octet)& iNameB,
  CATIDocId ** oDocId,
  CATDocument* iPointingDocument = NULL);

ExportedByCATObjectModelerBase
HRESULT CATFindDocId(const SEQUENCE(octet)& iNameB,
  CATUnicodeString& oEnvironment,
  CATUnicodeString& oIdentifier,
  CATDocument* iPointingDocument = NULL);

ExportedByCATObjectModelerBase
CATILinkableObject* CATBindInDocument(CATILinkableObject *iPointedObject,
  CATIDocId *iDocId,
  CATIBindParameters *iParams = NULL);

ExportedByCATObjectModelerBase
CATILinkableObject* CATBindInDocument(const SEQUENCE(octet)& iNameB,
  CATIDocId *iDocId,
  CATIBindParameters *iParams = NULL);

#endif

