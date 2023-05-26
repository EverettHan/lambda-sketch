/* -*-c++-*- */
#ifndef CATSessionServices_H
#define CATSessionServices_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U1
  */

#include "CATWTypes.h"

#include "CATDocumentsInSession.h"
#include  "AC0XXLNK.h"

class CATDocument;
class CATIContainer;
class CATUnicodeString;
class CATSession;

/**
* Returns all documents in the current session.
* <br>All documents in the output list have not been AddRef'ed.
*/
ExportedByAC0XXLNK
const CATLISTP(CATDocument)* ListDocuments();

/**
* @nodoc
* Returns all documents in the current session.
*/
ExportedByAC0XXLNK
const CATDocumentsInSession* ListDocuments2();
    
/**
* @nodoc
* Returns document with a given storage name.
* @param iStorageName
*      storage name of the searched document ( path + name of the file ).
*/
ExportedByAC0XXLNK
CATDocument * GetDocumentFromStorageName(const CATUnicodeString& iStorageName);

/**
* Increases the reference's counter of links on the document.
* <br><b>Role:</b>  
* The life cycle of the document is not managed by the AddRef/Release 
* mechanism. The mechanism of reference/unreference is <tt>CATLockDocument</tt> to increase the 
* count of links on the document, and @href CATUnLockDocument to decrease its count. Such as
* Release, <tt>CATUnLockDocument</tt> closes the document in the session when the counter is null.
* <br><br><u>When do you use this mechanism ? </u>
* <ul>
* <li> interactive mode, if your class keeps a pointer on a @href CATDocument, use this 
* method to add a link, and when the pointer is no longer needed use the 
* <tt>CATUnLockDocument</tt> method</li>
* <li> batch mode, after @href CATDocumentServices#New or @href CATDocumentServices#Open , 
* you lock your document if this document can be pointed by an another one. </li>
* </ul>
* @param iDocument
*      The document that is to be locked.
* @see CATDocumentServices
*/
ExportedByAC0XXLNK
HRESULT CATLockDocument( CATDocument& iDocument);

/**
* Decreases the reference's counter of links on the document.
* @param iDocument
*      The document that is to be unlocked.
* @see CATLockDocument
*/
ExportedByAC0XXLNK
HRESULT CATUnLockDocument( CATDocument& iDocument);

/**
* Creates a session.
* @param iSessionName
*       Name to give to the session.
* @param oSession
*       session created.
* @return
*      S_OK: Session created.
* <br> E_FAIL: Failed to create session.
* <br> S_FALSE: A session with the same name already exists.
* @see Delete_Session
*/
ExportedByAC0XXLNK HRESULT Create_Session(char const * iSessionName , CATSession *& oSession);

/**
* Deletes a session.
* @param iSessionName
*       Name of the session to delete.
* @param iODTRollMode
*       Do not use.
* @param iExitContext
*       Do not use.
* @see Create_Session
*/
ExportedByAC0XXLNK HRESULT Delete_Session(char const * iSessionName, int iODTRollMode = 0, int iExitContext = 0);

/** 
* Returns the current session. 
*  @param oSession
*    The returned session.
*  <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
*   returned value.  
*/
ExportedByAC0XXLNK
HRESULT GetPtrSession(CATSession*&  oSession) ;

// Service to be called at the beginning of a document load
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATStartOpen();

// Service to be called at the end of a document load
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATEndOpen();

// Service to check whether a document load is happening
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATIsOpenStarted();

// Service to be called at the beginning of a document save
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATStartSave();

// Service to be called at the end of a document save
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATEndSave();

// Service to check whether a document save is happening
/** @nodoc */
ExportedByAC0XXLNK
HRESULT CATIsSaveStarted();
   
#endif
