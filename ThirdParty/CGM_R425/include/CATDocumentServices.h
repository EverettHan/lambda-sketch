#ifndef CATDocumentServices_H
#define CATDocumentServices_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U1
  */


#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "booleanDef.h"
#include "CATUnicodeString.h"
#include "CATDocumentsInSession.h"
#include "CATListOfCATUnicodeString.h"
class CATDocument;
class CATUuid;
class CATIDocId;

/**
* Services to create, open and close documents.
* <b>Role:</b>All methods of this class must be used to create, open or close a document when <b>no
* visualization is necessary</b>. This is always the case in batch mode, but it is also possible 
* in interactive mode. 
* <br>If you want to visualize the document, use the <i>CATIIniInteractiveSession</i>
* interface. This last interface is defined in the InteractiveInterfaces Framework.
* <br><br>There are three methods for creating a (or several) new document(s) in the current session:
* <ul>
* <li>@href #New </li>
* <li>@href #OpenDocument </li>
* </ul>
* There are three methods for saving a document:
* <ul>
* <li>@href #Save (to use only in interactive mode)</li>
* <li>@href #SaveAs </li>
* <li>@href #SaveAsNew </li>
* </ul>
*  There is one method for closing a document:
* <ul>
* <li>@href #Remove </li>
* </ul>
* There is one method for retrieving a document by its filename:
* <ul>
* <li>@href #GetDocumentInSession
* </ul>
* <b>Life cycle of the document:</b>
* <br>
* <br><i>The AddRef/Release mechanism is not used:</i>
* <br>All methods which return a CATDocument pointer have not performed an Addref on the pointer. So
* there is no need to release it. 
* <br> A CATDocument object created by <tt>New</tt> or <tt>Open</tt>(*) must 
* be removed from the session by the <tt>Remove</tt> method. 
* <br>(*)Note that if the "open" is actually a "reopen", only one call to <tt>Remove</tt> must be done.
* <br>
* <br><i>The Lock/Unlock mechanism is used</i>
* <br>Look at this example:
* <br>1)Open a CATProduct which contains a CATPart
* <br>2)Open independently the same CATPart too 
* <br>You should <tt>Remove</tt> the 2 documents, but when the CATProduct document will be closed, 
* the CATPart will be also. So a specific call to <tt>Remove</tt> for the independent CATPart 
* will end in an error. 
* <br>So a multi-reference mechanism is necessary: @href CATLockDocument and
* @href CATUnLockDocument. 
* <br><br><i>When do you lock a document ?</i>
* <br> In batch mode, if you are not sure of the relation between each model opened, 
* lock the model after each open, and unlock it to remove it. 
* <br> In interactive mode, if your class keeps a pointer on a document, lock it and 
* unlock it when the pointer is no longer needed. 
* @see CATDocument 
*/

class ExportedByAC0XXLNK CATDocumentServices
{
 public:

  /**
  * Test if a given document type is meant to be CATIA loadable.
  * <br><b>Role:</b> Provide support to know if a given document type can be or not 
  * loaded in session memory as a CATDocument 
  * <br>Being a loadable document requires CATIPersistent implementation on the given type
  * @param iType
  *     The string to define the kind of document to test. 
  *     it returns S_OK otherwise E_FAIL
  */
  static HRESULT IsKnownAsAPersistentType(const CATUnicodeString& iType);

  /**
  * Test if a given document alias is meant to be CATIA creatable.
  * <br><b>Role:</b> Provide support to know if a given document alias can be or not 
  * provided to be created in session memory as a CATDocument (See New) 
  * <br>Being a creatable document requires CATIDocAlias or CATIPersistent implementation on the given alias
  * @param iAliasType
  *     The string to define the kind of document to test. 
  *     it returns S_OK, this can be used as a creation alias
  *     it returns E_FAIL, this is not.
  */
  static HRESULT IsKnownAsAnAliasType(const CATUnicodeString& iAliasType);

  /**
  * @nodoc 
  * Creates a document of a given type.
  * <br><b>Role:</b> Creates and initializes data of a document of the given type. The
  * initialization is done thanks to the @href CATInit#init method.
  * <br>The document must be removed from the session before exiting or when it is
  * no longer needed. See explanations, at the top of this page, about the life 
  * cycle of the document.
  * <br>The name of the document is <tt>iType + Number + suffix</tt>. The suffix 
  * is dedicated to iType such as <tt>.CATPart</tt> for the type <tt>Part</tt>.  
  * <br>As long as the document is not saved, the storage name ( @href CATDocument#StorageName ),
  * is equal to the name. 
  * @param iType
  *     The string to define the kind of document to create. 
  *     <br> The string is the one which appears in the panel File/New.
  * @param oNewDoc 
  *     The document created.
  */
  static HRESULT New (const CATUnicodeString& iType, CATDocument*& oNewDoc);
  
  /**
  * @nodoc
  *
  * Opens a given document.
  * <br><b>Role:</b> If the file already exists in the session, it will not be re-loaded.
  * <br>The document must be removed from the session before exiting or when it is no 
  * longer needed. See explanations at the top of this page about the life 
  * cycle of the document.
  * @param iStorageName
  *      The complete access name of the file to open (path + name of the file ). 
  *      <br>See @href CATDocument#StorageName for more information about the storage name.
  * @param oOpenedDoc 
  *      The opened document.
  *      <br>If the "open" is a "re-open", the pointer is not a new pointer. Do not remove 
  *      the pointer twice.
  * @param iReadOnly
  *      FALSE: Default value, the document will be in read/write mode.
  *  <br> TRUE: The document is in read only mode.
  *  <br>In case of a re-opening, the mode of the document is defined by the first open.
  * @return
  *		 S_OK : The document was opened sucessfully.
  *	<br> S_FALSE : The document has already been loaded. The returned oOpenedDoc pointer 
  * points to this document.
  *	<br> E_FAIL : The open operation failed.
  */
  static HRESULT Open ( const CATUnicodeString& iStorageName, CATDocument*& oOpenedDoc, CATBoolean iReadOnly=FALSE);

  /** @nodoc */
  static HRESULT Open ( const CATUnicodeString& storageName, CATDocument*& oOpenedDoc, const CATUnicodeString& type, CATBoolean ReadOnly=FALSE);

  /** @nodoc */
  static HRESULT Open ( CATIDocId* iDocId, CATDocument*& oOpenedDoc, CATBoolean ReadOnly=FALSE);

  
  /**
  * @nodoc 
  * Opens a given document.
  * <br><b>Role:</b> If the file already exists in the session, it will not be re-loaded.
  * <br>The document must be removed from the session before exiting or when it is no 
  * longer needed. See explanations at the top of this page about the life 
  * cycle of the document.
  * <br><b>Note:</b> This method does not allow opening .feat or .CATfct catalogs. It is not possible to access .feat
  * catalogs because they contain Dassault Systemes private data. To open a .CATfct catalog, see <i>CATCatalogFactoryServices</i>
  * (ObjectSpecsModeler framework). 
  * @param iStorageName
  *      The complete access name of the file to open ( path + name of the file ). 
  *      <br>See @href CATDocument#StorageName for more information about the storage name.
  * @param oOpenedDoc 
  *      The opened document.
  *      <br>If the "open" is a "re-open", the pointer is not a new pointer. Do not remove 
  *      the pointer twice.
  * @param iReadOnly
  *      FALSE: Default value, the document will be in read/write mode.
  *  <br> TRUE: The document is in read only mode.
  *  <br>In case of a re-opening, the mode of the document is defined by the first open.
  * @return
  *		 S_OK : The document was opened sucessfully.
  *	<br> S_FALSE : The document has already been loaded. The returned oOpenedDoc pointer 
  * points to this document.
  *	<br> E_FAIL : The open operation failed.
  */
  static HRESULT OpenDocument ( const CATUnicodeString& iStorageName, CATDocument*& oOpenedDoc, CATBoolean iReadOnly=FALSE);

  /**
  * Retrieves a document in session by its complete access name.
  * @param iStorageName
  *      The complete access name to the searched file (path + name of the file ).
  *      <br>See @href CATDocument#StorageName for more information about the storage name.
  * @param oOpenedDoc
  *      The found document.
  */
  static HRESULT GetDocumentInSession ( const CATUnicodeString& iStorageName, CATDocument*& oOpenedDoc);

  /** @nodoc */
  static HRESULT GetDocumentInSession ( const CATUnicodeString& fileName, const CATUuid& fileUuid, CATDocument*& oOpenedDoc);
	
  /** @nodoc */
  static HRESULT GetDocumentInSession ( CATIDocId* iDocId, CATDocument*& oOpenedDoc);

  /**
  * @nodoc 
  * Saves a given document in interactive mode.
  * <br><b>Role:</b>To save a document two cases:
  * <ul>
  * <li>In interactive mode, use this method or the method  
  * <i>CATIIniInteractiveSession::Save</i> twice are equal</li>
  * <li>In batch mode, use @href #SaveAs in using the current storage name of your document @href CATDocument#StorageName</li>
  * <pre>
  *     CATUnicodeString StorageNameDocument ;
  *     StorageNameDocument = pDocument->StorageName();
  *     ::SaveAs(pDocument,StorageNameDocument);
  * </pre>
  * </ul>
  * @param iDocument
  *       The document to save.
  * @param iSavePointedIfNecessary
  *       TRUE : default value, to save all documents referred to by iDocument if they have 
  *              been modified during the session.
  *       <br> FALSE: only iDocument will be saved.
  * @return
  *		 S_OK : The document was saved successfully.
  *	<br> S_FALSE : The document does not need to be saved.
  *	<br> E_FAIL : The document save operation failed.
  */
  static HRESULT  Save ( CATDocument& iDocument, CATBoolean iSavePointedIfNecessary = TRUE);
  
  /**
  * @nodoc 
  * Saves a document with a different name.
  * <br><b>Role:</b>Save the document in the file specified by iStorageName. 
  * @param iDocument
  *       The document to save.
  * @param iStorageName
  *       The complete access name of the file.
  *       <br>The format of this argument is: path + name of the file.
  *       <br>It is the new storage name of the document. 
  *       <br>See @href CATDocument#StorageName to have more information about the storage name.
  * @param iFormat
  *       To save the document with a specific format. (recognized by iDocument).
  *     <br> The string is the one which appears in the "Format" combo of the panel
  *        File/Save or File/SaveAs.
  * @param SavePointedIfNecessary
  *      TRUE : default value, to save all documents referred by iDocument if they 
  *             have been modified during the session.
  *       <br> FALSE: only iDocument will be saved.
  */
  static HRESULT  SaveAs ( CATDocument& iDocument,const CATUnicodeString& iStorageName,const CATUnicodeString& iFormat="", CATBoolean iSavePointedIfNecessary = TRUE);

  /** @nodoc */
  static HRESULT  SaveAs ( CATDocument& iDocument, CATIDocId *iDocId );

  /**
  * Removes a document.
  * <br><b>Role:</b>This method closes the document in the session.  
  * <br><b>Caution</b>This method is without effect if the document has been previously
  * locked. If you have locked your document, a call to this method is not necessary, the last
  * unlock closes it. 
  * <br>Read information at the top of the page about the life cycle of the document.  
  * @param iDoc
  *       The document to remove.
  * @param iEmptyClipbordIfNecessary
  *       TRUE : will remove all the links from clipboard to iDoc.
  */
  static HRESULT  Remove ( CATDocument& iDoc, short iEmptyClipbordIfNecessary=TRUE);

  /**
  * @nodoc 
  * Creates a new document from an existing one and saves it.
  * <br><b>Role:</b>The new document is identical to the original except for its UUIDs. 
  * The original document, iDocument, remains unchanged.  
  * <br>The new document does not exist in the session,it is just created in a file. 
  * @param iDocument
  *        The original document from which the new document will be generated and saved 
  *        with different UUIDs.
  * @param iStorageName
  *        The name under which the new document will be saved.
  * @param iSaveRecursively 
  *        Not used.  FALSE by default.
  */
  static HRESULT  SaveAsNew ( CATDocument& iDocument, const CATUnicodeString& iStorageName, CATBoolean iSaveRecursively=FALSE);

  /**
  * @nodoc 
  * Retrieves the last save version of a document by its identifier.
  * @param iDocId
  *        The identifier of the document.
  * @param oVersion
  *        The last save version of the document (this information is only accessible for documents created from V5R10 and after. 
  *        <br>(for example : &lt Version &gt 5/ &lt Version &gt &lt Release &gt 10/ &lt Release&gt &lt ServicePack&gt 1/&lt ServicePack &gt &lt BuildDate &gt mm-dd-yyyy.hh.mm/ &lt BuildDate &gt).
  * @return 
  *     <li>S_OK: The version has been correctly retrieved, 
  *	    <li>E_FAIL : The version could not be retrieved. </li>
  *     </ul>
  */
  static HRESULT GetDocumentLastSaveVersion ( CATIDocId* iDocId, CATUnicodeString& oVersion);

  /**
  * nodoc
  * Check if a document has been saved with an educational licence.
  * This API will be officially exposed in V5R17.
  * @param iDocId
  *        The identifier of the document.
  * @param iEducational
  *     <li>0: This is a standard document. </li>
  *	    <li>Otherwise: This document has been saved with an educational license. </li>
  * @return 
  *     <li>S_OK: The check has been successfully done. 
  *	  <li>E_FAIL : Impossible to perform this check. </li>
  *     </ul>
  */
  static HRESULT HasDocumentEducationalFlag ( CATIDocId* iDocId, int& iEducational);

};
#endif
