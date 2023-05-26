/* -*-c++-*- */
#ifndef CATIFileDescriptor_h
#define CATIFileDescriptor_h
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998  
//-----------------------------------------------------------------------------
// class CATIFileDescriptor:
// 
// 
// This class is used for retreiving informations on
// files. 
//
//-----------------------------------------------------------------------------
// Usage Notes:
//
// 
// cf comments
//
//-----------------------------------------------------------------------------
// Creation by slg  - Dec.98
//-----------------------------------------------------------------------------//

/**
* @level Private
* @usage U3
*/

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
//
#include "CATListOfCATUnicodeString.h"
#include "CATIDocDescriptor.h"
#include "booleanDef.h"
#include "CATWTypes.h"
#include "CATLib.h"

class CATUuid;
class CATLISTP(CATIDocId);
class CATIStorageData_var;

class CATIFileDescriptor : public CATBaseUnknown
{
public:
  /**
  * Get the origin path of the file based document
  * @param oFilePath
  *  The returned path of the document's file.
  */
  virtual HRESULT GetFilePath(CATUnicodeString & oFilePath) = 0;

  /**
  * Check specified right on the document.
  * @param AccessMode
  *  The asked right (included in CATUnistd.h):
  *    <UL>
  *      <LI><B>F_OK</B>: document's file exists</LI>
  *      <LI><B>X_OK</B>: access in execution mode</LI>
  *      <LI><B>W_OK</B>: access in write mode</LI>
  *      <LI><B>R_OK</B>: access in read mode</LI>
  *      <LI><B>F_OK|X_OK|W_OK|R_OK</B>: full access</LI>
  *    </UL>
  * @param oStatus
  *  The returned Status about the asked right: CATLibSuccess on success, else CATLibError.
  */
  virtual HRESULT GetAccessRight(int AccessMode, CATLibStatus & status) = 0;

  /**
  * Get the time of the last modification on this document's file.
  * @param oLastModif
  *  The returned time of the last modification on this document.
  * @return S_OK;
  */
  virtual	HRESULT GetLastModificationTime(time_t & LastModif) = 0;

  /**
  * Get the type of the document.
  * @param oDocType
  *  The returned document late type, also used as suffix, such as CATPart, CATProduct..
  * @return S_OK on found type, else E_FAIL
  */
  virtual HRESULT GetDocumentType(CATUnicodeString & DocType) = 0;

  /**
  * Get the Uuid of the root container of the document
  * @param oUuid
  *  The returned Uuid of the root container
  * @return S_OK if the root container is found, else E_FAIL
  */
  virtual HRESULT GetRootContainerUuid(CATUuid & Uuid) = 0;

  /**
  * Get the list of the filenames pointed by the document.
  * @param oPointedFileNames
  *  The filenames' list of the pointed document
  * @return S_OK the list is found, else E_FAIL
  */
  virtual HRESULT GetPointedFileNames(CATListOfCATUnicodeString & PointedFileNames) = 0;

  //
  //  Pointed documents management
  //  ----------------------------

  /**
  * Retrieves the list of pointed doc identifiers that are streamed.
  * <br><b>Role:</b>Currently, this method returns the doc identifiers after they have been retrieved by the doc
  * locators, but it won't be the case in the future. If the pointed document is not found, the streamed link
  * is returned. The caller must do a "Release" on each pointer of the oPointedDocIds list after use.
  * @params oPointedDocIds
  *   The list of doc identifiers.
  * Always returns S_OK.
  */
  virtual  HRESULT GetPointedDocIds(CATLISTP(CATIDocId) & oPointedDocIds) = 0;

  /**
  * Get the last saved storage named of the document.
  * @param oStoredDocPath
  *  The returned storage name
  * @return S_OK if the <I>oStoredDocPath</I> is not empty, else E_FAIL
  */
  virtual  HRESULT GetStoredDocPath(CATUnicodeString & oStoredDocPath) = 0;

  /**
  * (The document must be a valid CNEXT file)
  * --> must migrate under HRESULT GetStorageData(CATIStorageData_var&)
  * @return smart pointer on CATIStorageData
  */
  virtual CATIStorageData_var GetStorageData() = 0;
};


#endif
