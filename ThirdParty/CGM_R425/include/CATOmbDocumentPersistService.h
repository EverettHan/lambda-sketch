/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Private
 * @usage U1
 **/

#ifndef CATOmbDocumentPersistService_H
#define CATOmbDocumentPersistService_H

#include "CATOmbPersistency.h"
#include "CATBoolean.h"
#include "stddef.h"

// ObjectModelerBase
#include "CATOmbSessionService.h"

class CATDocument;
class CATIDocId;
class CATVVSUrl;
class CATVVSURLConnection;
class CATVVSTransaction;
class CATComponentId;

// à virer dès qu'arrivé en rel
#define V6TOV5SERVICES

/**
 * Services to ensure documents persistency
 * <b>Role</b>: This session service ensures documents persistency
 *
 * NOTE: <i>Always instanciate this service on the stack.</i>
 */
class ExportedByCATOmbPersistency CATOmbDocumentPersistService : CATOmbSessionService
{
public:

  /**
  * Creates the service. 
  *
  * @param ipSessionContext
  *		A pointer to the session to be used as a context for this service. 
  **/
  CATOmbDocumentPersistService(CATOmbSessionContext *ipSessionContext = NULL);

  /**
  * Destroys the service.
  **/
  ~CATOmbDocumentPersistService();

  /**
  * Opens a given document from a Document Identifier and the connection of a stream.
  *  
  * Anthorized Client : 
  *      Only implementation of Document Environment are authorized to use this API.
  *
  * @param [OUT] oDocument
  *      The CATDocument in CATIA memory
  * @param [IN] iComId
  *      The identifier of the component. 
  *      The link's table will be rebuilt from the relations aggregated by component.
  *      (optional parameter, can be initialized with CATComponentId_Null)
  * @param [IN] iDocId
  *      The identifier of the Document Version we want to load
  * @param [IN] iUrlConnection
  *      The connection on the stream that contains document's data.
  * @result [OUT]
  *      S_OK    : The document has been successfully opened
  *      S_FALSE : If the document has already been opened or if the document
  *                was already partially loaded.
  *	     E_FAIL  : The open operation failed.
  */
  HRESULT OpenDocumentFromComponentIdDocIdAndUrlConnection ( CATDocument              *& oDocument
                                                           , const CATComponentId      & iComId
                                                           , CATIDocId                 & iDocId
                                                           , const CATVVSURLConnection & iUrlConnection
                                                           , CATBoolean iUrlSupportPartialLoading=FALSE
                                                           , CATBoolean iAssertDocumentIsNotInSession = FALSE);

  /**
  * Stream document content to an associated URL via cache infrastructure.
  * @param [IN] iDoc
  *      The document to stream
  * @param [IN] iUrl
  *      The location of the stream where we will stream
  *      e.g. : protocol://site/identifier?searchpart
  *             file://E:/geometry.CATPart
  * @param [IN] iStreamSlaves
  *   This flag indicates that the slave documents associated to a master document will be streamed,
  *   at the same location (URL)
  * @result [OUT]
  *      S_OK    : The document has been successfully saved 
  *	     E_FAIL  : The save operation failed.
  */
  
  HRESULT StreamDocumentToUrlConnection(CATDocument* iDoc, const CATVVSURLConnection* iUrlConnection, CATVVSTransaction* iTransaction = NULL);

    // Wrapper pour 3dxml -> migration vers OpenDocumentFromComponentIdDocIdAndUrlConnection
  HRESULT OpenDocumentFromComponentIdDocIdAndUrl ( CATDocument         *& oDocument
                                                 , const CATComponentId & iComId
                                                 , CATIDocId            & iDocId
                                                 , const CATVVSUrl      & iUrl
                                                 , CATBoolean             iUrlSupportPartialLoading = FALSE);

  /**
  * Stream document content to an associated URL with R1xx format
  *  
  * Anthorized Client : 
  *      Only CATBack implementation is authorized to use this API.
  *
  * @param [IN] iDoc
  *      The document to stream
  *
  * @param [IN] iUrlConnection
  *      The location of the stream where we will stream
  *      e.g. : protocol://site/identifier?searchpart
  *             file://E:/geometry.CATPart
  *
  * @result [OUT]
  *      S_OK    : The document has been successfully saved 
  *	     E_FAIL  : The save operation failed.
  */
  HRESULT StreamDocumentToUrlConnectionWithR1xxFormat (CATDocument * iDoc, const CATVVSURLConnection* iUrlConnection);

private:
  // copy constructor is private
  CATOmbDocumentPersistService(const CATOmbDocumentPersistService& ICOPY);  
  CATOmbDocumentPersistService operator=(CATOmbDocumentPersistService& ICOPY);
};
#endif






