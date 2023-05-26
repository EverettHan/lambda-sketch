#ifndef CATOmbConverterManager_H
#define CATOmbConverterManager_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATOmbConverterForInfraOnly.h"

#include "CATUnicodeString.h"

#include "CATVVSUrl.h"
#include "CATOmbSessionService.h"
#include "CATIOmyIncidentCollector.h"
#include "CATOmxOHMap.h"
#include "CATOmxMapIter.h"

class CATDocument;
class CATVVSURLConnection;
class CATError;
class V5OmbUnicodeStringHashtable;
class CATIDocId;
class CATComponentId;
class CATIOmbStreamDescriptor;
class CATIContainer;
class CATOmxKeyValueBlock;



/**
 * This class aims at
 * - computing the sream format to use to stream a document
 * - instantiante the converter to be used
 * - call the converter to unstream/stream the document
 */
class ExportedByCATOmbConverter CATOmbConverterManager: public CATOmbSessionService
{
  public:
    CATOmbConverterManager(CATOmbSessionContext *ipSessionContext = NULL);
    CATOmbConverterManager(const unsigned char iKey,CATOmbSessionContext *ipSessionContext = NULL);
    virtual ~CATOmbConverterManager(); 

    /** 
    * This method allows streaming a V5 document to a non V5 legacy stream. 
    *
    * <br><b>Role</b>: 
    * This method retrieves the converter to stream a document and call it on its stream method.  
    * @param iDoc [in]
    *   The document to be streamed. 
    * @param iUrlConnection [in]
    *   The URLConnection that give access to the ILB where the document will be streamed. 
    * @param iSDFormat [in]
    *   Format of the Stream Descriptor such as Authoring...
    * @param iSDRole [in]
    *   Role of the Stream Descriptor
    * @param iLateType [in]
    *   LateType of the CATDocument to be streamed.
    * @param iStreamFormat [in]
    *   The stream format in which the document will be streamed. 
    * @param oError [out]
    *   In case of error, an end-user error that can be displayed in an error panel. 
 	  * @param iParamList [in]
    *	A list of parameters useful for streams conversion	
    * @param ioIncidentCollector [inout]
    *   Incident Collector logging errors raised during stream conversion 
    *
    * @return
    *   <code>S_OK</code> document has been streamed correctly.
    *
    *   IMPORTANT: in following error cases, always check ioIncidentCollector content after execution and empty it after eventual error message display,
    *   using  @href CATIOmyIncidentCollector::EmptyCollector() in order to avoid later ghost messages:
    *
    *   <code>CATOmb_S_NOCONVERSION</code> an error occurs but converter manages to generate a default archive. ioIncidentCollector contains more information.
    *   <code>E_FAIL</code> an error occurs. ioIncidentCollector contains more information.
    */
    virtual HRESULT StreamDocumentToExternalFormat(CATDocument& iDoc, CATVVSURLConnection& iUrlConnection,const CATUnicodeString& iSDFormat, const CATUnicodeString& iSDRole, const CATUnicodeString& iLateType, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector);


    /** 
    * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
    *
    * <br><b>Role</b>: 
    * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
    * CATDocument generated should have the same behavior than a document generated by CATInit::Init and CATIPersistent::Load
    * in CATIA3D, on cluster document, URLConnection is on the vault while in 3dlive, URLConnection points to the SelectiveLoading Cache. 
    *
    * @param iDocId [in]
    *   The Identifier of the Document to be unstreamed.
    * @param iComId [in]
    *   The identifier of the PLM Component this document and its Stream Descriptor are attached to.
    * @param iUrlConnection [in]
    *   The URLConnection giving access to the ILB of the document to be unstreamed.
    * @param ioStreamDescriptor [in]
    *   The Stream Descriptor associated to the document to be unstreamed. 
    * @param iStreamFormat [in]
    *   The stream format in which the document will be unstreamed. 
    * @param iParamList [in]
    *	  A list of parameters useful for streams conversion.
    * @param opDoc [out]
    *   The document unstreamed and loaded in session.
    * @param ioIncidentCollector [inout]
    *   Incident Collector logging errors raised during stream conversion.
    *
    * @return
    *   <code>S_OK</code> document has been streamed correctly.
    *
    *   IMPORTANT: in following error cases, always check ioIncidentCollector content after execution and empty it after eventual error message display,
    *   using  @href CATIOmyIncidentCollector::EmptyCollector() in order to avoid later ghost messages:
    *
    *   <code>CATOmb_S_NOCONVERSION</code> an error occurs but converter manages to create a default document. ioIncidentCollector contains more information.
    *   <code>E_FAIL</code> an error occurs. ioIncidentCollector contains more information.
    */
    virtual HRESULT UnstreamDocumentFromExternalFormat(CATIDocId& iDocId, const CATComponentId& iComId, CATVVSURLConnection& iUrlConnection, CATIOmbStreamDescriptor& ioStreamDescriptor, const CATUnicodeString& iStreamFormat,CATOmxKeyValueBlock& iParamList,CATDocument*& opDoc,CATIOmyIncidentCollector_var& ioIncidentCollector);

   /** 
    * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
    *
    * <br><b>Role</b>: 
    * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
    * CATDocument generated should have the same behavior than a document generated by CATInit::Init and CATIPersistent::Load
    * in CATIA3D, on cluster document, URLConnection is on the vault while in 3dlive, URLConnection points to the SelectiveLoading Cache. 
    *
    * @param iDocId [in]
    *   The Identifier of the Document to be unstreamed.
    * @param iComId [in]
    *   The identifier of the PLM Component this document and its Stream Descriptor are attached to.
    * @param iUrlConnection [in]
    *   The URLConnection giving access to the ILB of the document to be unstreamed.
    * @param iLateType [in]
    *   LateType of the CATDocument to be unstreamed.
    * @param iFormat [in]
    *   Format of the Stream Descriptor for the document to be unstreamed.
    * @param iRole [in]
    *   Role of the  Stream Descriptor for the document to be unstreamed.
    * @param iStreamFormat [in]
    *   The stream format in which the document will be unstreamed. 
    * @param iParamList [in]
    *	  A list of parameters useful for streams conversion.
    * @param opDoc [out]
    *   The document unstreamed and loaded in session.
    * @param ioIncidentCollector [inout]
    *   Incident Collector logging errors raised during stream conversion.
    *
    * @return
    *   <code>S_OK</code> document has been streamed correctly.
    *
    *   IMPORTANT: in following error cases, always check ioIncidentCollector content after execution and empty it after eventual error message display,
    *   using  @href CATIOmyIncidentCollector::EmptyCollector() in order to avoid later ghost messages:
    *
    *   <code>CATOmb_S_NOCONVERSION</code> an error occurs but converter manages to create a default document. ioIncidentCollector contains more information.
    *   <code>E_FAIL</code> an error occurs. ioIncidentCollector contains more information.
    */
    virtual HRESULT UnstreamDocumentFromExternalFormat(CATIDocId& iDocId, const CATComponentId& iComId, CATVVSURLConnection& iUrlConnection, const CATUnicodeString& iFormat, const CATUnicodeString& iRole, const CATUnicodeString& iStreamFormat,CATOmxKeyValueBlock& iParamList,CATDocument*& opDoc,CATIOmyIncidentCollector_var& ioIncidentCollector);
                    
private:
  // Copy Constructor and copy operator are forbidden. 
  //CATOmbConverterManager();
  CATOmbConverterManager (CATOmbConverterManager &);
  CATOmbConverterManager& operator=(CATOmbConverterManager&);       

  HRESULT CreateRepRefWithDocument(const CATComponentId& iComId, CATDocument*& ioDocument, const CATUnicodeString& iStreamFormat);

  HRESULT InitAllApplicativeContainers(CATDocument& iDocument);
  HRESULT SendCallBacks(CATIContainer& iCont, CATDocument& iDoc);
  unsigned char m_cmkey;
};



#endif
