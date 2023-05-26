/* -*-c++-*- */
#ifndef CATIDocEnvironment_h
#define CATIDocEnvironment_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @level Private
  * @usage U3
  */

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
class CATIDocLocator;
class CATDocument;
class CATIDocId;
class CATIDocDescriptor;
class CATUnicodeString;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDocEnvironment;

/**
* Interface allowing access to a document's identification and descriptor elements.
*/

class ExportedByAD0XXBAS CATIDocEnvironment: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
    * Retrieves the NLS name. 
	*/
  virtual HRESULT GetName(CATUnicodeString& oName) = 0;

  /** Retrieves the display name of the document.
	* @param iDocId
	*  The object which identifies the document in this environment.
	* @param oDocDisplayName
	*  The name of the document to display, for example in the document's window.
    */
  virtual HRESULT GetDocDisplayName(CATIDocId * iDocId, CATUnicodeString& oDocDisplayName) = 0;

  /**
    * @nodoc 
    * Retrieves the list of locator.
	* <br><b>Role:</b>for one environment you can have severals locator. 
	* @param oDocLocators
	*  The list of locator.
    */
  virtual HRESULT GetDocLocators(CATLISTV(CATBaseUnknown_var)& oDocLocators) = 0;

  /** 
    * @nodoc 
    *  Retrieves the document's identification element.
	*  @param iIdentifier
	*         The document identifier. This is the storage path name of the document.
	*  @param iType
	*         The document type. This is the document's suffix, such as CATPart, CATDraw, etc.
	*  @param oDocId
	*         The returned document identification element.
    */
  virtual HRESULT RecoverDocId(const CATUnicodeString& iIdentifier, const CATUnicodeString& iType, CATIDocId ** oDocId) = 0;

  /**
    *  @nodoc 
    *  Retrieves the document's descriptor element.
    *  @param iDocId
	*         The document's identification element.
	*  @param oDocDescriptor
	*         The returned document descriptor element.
    */
  virtual HRESULT RecoverDocDescriptor(CATIDocId * iDocId, CATIDocDescriptor ** oDocDescriptor) = 0;

  /**
    * @nodoc 
    * Saves the document.
	* @param iDocument
	* @param iDocId
    */
  virtual HRESULT RegisterDoc(CATDocument * iDocument, CATIDocId * iDocId) = 0;
};

CATDeclareHandler(CATIDocEnvironment, CATBaseUnknown);

#endif
