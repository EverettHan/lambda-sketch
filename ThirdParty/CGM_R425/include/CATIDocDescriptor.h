/* -*-c++-*- */
#ifndef CATIDocDescriptor_h
#define CATIDocDescriptor_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/** 
* @level Private
* @usage U3
*/
  

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
class CATIDocId;
class CATIDocEnvironment;
class CATUnicodeString;
class CATDocument;
class CATTime;


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDocDescriptor;

/**
* @nodoc
* Interface allowing access to a document and to its identification information.
*/

class ExportedByAD0XXBAS CATIDocDescriptor: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
  * @nodoc
	* This method is not used. The implementation should return E_NOTIMPL.
	*/
  virtual HRESULT GetDocLinks(CATLISTV(CATBaseUnknown_var)& oDocIds) = 0;

  /**
  * @nodoc
    *  Retrieves the document's unique identification information.
	*  @param oDocId
	*		  A pointer to the retrieved document unique identification information
	*  @return
	*    S_OK if the document unique identification information is successfully retrieved, or E_FAIL otherwise
    */
  virtual HRESULT GetDocId(CATIDocId ** oDocId) = 0;

  /**
  *  @nodoc
    *  Retrieves the document type.
	*  <br>This is the document late type, also used as suffix, such as CATPart, CATProduct.
	*  @param oDocType
	*		  The retrieved document type
	*  @return
	*    S_OK if the document type is successfully retrieved, or E_FAIL otherwise
    */
  virtual HRESULT GetDocType(CATUnicodeString& oDocType) = 0;

  /**
  *  @nodoc
    *  Retrieves the document environment.
	*  @param oDocEnvironment
	*         A pointer to the document environment
	*  @return
	*    S_OK if the document environment is successfully retrieved, or E_FAIL otherwise
    */
  virtual HRESULT GetDocEnvironment(CATIDocEnvironment ** oDocEnvironment) = 0;

  /** 
  * @nodoc
    *  Retrieves the document if it is already loaded in the session. 
	*  <br> <b> Note: </b>If the document isn't loaded in the session, this method should not load it.
	*  @param oDocument
    *         A pointer to the retrieved document
	*  @return
	*    S_OK if the document is successfully retrieved, or E_FAIL otherwise
    */
  virtual HRESULT GetDocument(CATDocument ** oDocument) = 0;

  /** 
    * @nodoc
    *  Retrieves the document time stamp.
	*  @param oTimeStamp
    *         The document time stamp
	*  @return
	*    S_OK if the document time stamp is successfully retrieved, or E_FAIL otherwise
    */
  virtual HRESULT GetTimeStamp(CATTime ** oTimeStamp) = 0;

  /**
    * @nodoc
    *  Loads the document in the session.
	*  <br> <b> Note: </b>If the document is already loaded in the session, a pointer
	*  to it is returned using GetDocument. Otherwise, the document is loaded and a pointer to it is returned.
	*  @param oDocument
	*         The document loaded in the session
	*  @return
	*    S_OK if the document is successfully loaded or retrieved, or E_FAIL otherwise
    */
  virtual HRESULT LoadDoc(CATDocument ** oDocument) = 0;
};

CATDeclareHandler(CATIDocDescriptor, CATBaseUnknown);

#endif
