// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATIOmbConverter3.h
// Define the CATIOmbConverter3 interface
//===================================================================
// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// /!\ WARNING /!\
//
// Any C++ class that implements CATIOmbConverter3 must inherit from
// the adapter CATEOmbConverter3 (with a E)
//
// /!\ WARNING /!\
//
//
//===================================================================
//
// Usage notes:
//   
//
//===================================================================
//
//===================================================================
#ifndef CATIOmbConverter3_H
#define CATIOmbConverter3_H

/**
* @level Protected
* @usage U3
*/

#include "CATOmbConverterForRestrictedClients.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbConverter IID IID_CATIOmbConverter3;
#else
extern "C" const IID IID_CATIOmbConverter3;
#endif

#include "CATBaseUnknown.h"
#include "CATIOmbConverter2.h"
#include "IUnknown.h"
#include "CATOmxSR.h"
class CATDocument;
class CATVVSUrl;
class CATUuid;
class CATOmbImportExportParameters;
class CATIOmyIncidentCollector;
class CATILockBytes2;

class ExportedByCATOmbConverter CATIOmbConverter3 : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
  * The 3 following methods enable to work with a converter in a transactional mode
  * in order to update several CATDocument with a same non legacy V5 stream as an input
  *
  * <br><b>Role</b>:
  * The 3 following methods enable to work with a converter in a transactional mode
  * in order to update several CATDocument with a same non legacy V5 stream as an input
  .   * Step 1 : initialization through InitializeJob
  * @param iUrl [in]
  *   The url of data used for conversion
  * @param iUuid [in]
  *   The uuid of transaction computed to operate the transaction of conversion
  * @return
  *   <code>S_OK</code> Initialization has been performed correctly
  *   <code>E_FAIL</code> an error occurs. iIncidentCollector contains more information.
  *
  .   * Step 2 : conversion and update of document through UpdateDocumentFromExternalFormat. This might be call several times with several inputs as we have started a transaction
  * @param ioDoc [inout]
  *   The document to be updated
  * @param iParameters [in]
  *   Parameters table contains several parameters. The parameters could provide the context of conversion such the config name for sldprt conversion.
  *   Mandatory parameters are the StreamDescriptor format associated to the document, the uuid of transaction computed to operate the transaction of conversion
  *   these mnadatory are Read-only.
  *   OMB Parameters dictionary for iParameters :
  *     key : "OMBGenerationContext"          / value type : unsigned int                                  / Read  by OMB and Read/Write by Application  / role : context of generation
  *     other parameters could be inside iParameters parameters table in order tho share them between caller and callee of OMB
  *
  * @return
  *   <code>S_OK</code> update  has been performed correctly for the input document
  *   <code>E_FAIL</code> an error occurs. iIncidentCollector contains more information.
  *
  .   * Step 3 : end of conversion and release of resources
  * @param iUuid [in]
  *   The uuid of transaction computed to operate the transaction of conversion
  * @return
  *   <code>S_OK</code> Initialization has been performed correctly
  *   <code>E_FAIL</code> an error occurs. iIncidentCollector contains more information.
  *
  */
  virtual HRESULT InitializeJob(CATVVSUrl& iUrl, CATUuid& iUuid, CATIOmyIncidentCollector* iIncidentCollector) = 0;
  virtual HRESULT UpdateDocumentFromExternalFormat(CATDocument& ioDoc, const CATUuid& iUuid, CATOmbImportExportParameters* iParameters, CATIOmyIncidentCollector* iIncidentCollector) = 0;
  virtual HRESULT StopJob(CATUuid& ioUuid, CATIOmyIncidentCollector* iIncidentCollector) = 0;

  /**
  * This method allows streaming a V5 document to a non V5 legacy stream.
  *
  * <br><b>Role</b>:
  * This method allows streaming a V5 document to a non V5 legacy stream.
  * Document state should not be modified. (It remains dirty)
  * in CATIA3D, on cluster document, URLConnection is on the vault while in 3dlive, URLConnection points to the SelectiveLoading Cache.
  *
  * @param iDoc [in]
  *   The document to be streamed.
  * @param ioILB [in]
  *   The ILB where conversion should be streamed.
  * @param iStreamFormat [in]
  *   The stream format in which the document will be streamed.
  * @param iParamList [in]
  *	A list of parameters useful for streams conversion
  * @param ioIncidentCollector [inout]
  *   Incident monitor logging errors raised during stream conversion
  *
  * @return
  *   <code>S_OK</code> document has been streamed correctly.
  *   <code>E_FAIL</code> an error occurs. oError contains more information.
  *
  *
  */
  virtual HRESULT StreamDocumentToExternalFormat(CATDocument& iDoc, CATOmxSR<CATILockBytes2> ioILB, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector) = 0;

  /**
  * This method allows streaming a non V5 legacy stream to a non V5 legacy stream.
  *
  * <br><b>Role</b>:
  * This method retrieves the converter to stream a document and call it on its stream method.
  * @param iInputUrl [in]
  *   The url of the stream to convert.
  * @param ioILB [in]
  *   The ILB where conversion should be streamed.
  * @param iInputFormat [in]
  *   LateType of the stream to be converted.
  * @param iOutputFormat [in]
  *   The latetype of output stream.
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
  virtual HRESULT StreamExternalFormatToExternalFormat(CATVVSUrl& iInputUrl, const CATUnicodeString& iInputFormat, CATOmxSR<CATILockBytes2> ioILB, const CATUnicodeString& iOutputFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector) = 0;

  virtual HRESULT StreamExternalFormatToDocument(CATVVSUrl& iInputUrl, const CATUnicodeString& iInputFormat, CATOmxSR<CATILockBytes2> ioILB, const CATUnicodeString& iOutputFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector) = 0;

  /**
  * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
  *
  * <br><b>Role</b>:
  * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
  * This method must have the same behavior than CATIPersistent::Load
  * Reading the non V5 legacy stream, this method will instantiate and add to the document, features that has been streamed.
  *
  * in CATIA3D, on cluster document, URLConnection is on the vault while in 3dlive, URLConnection points to the SelectiveLoading Cache.
  *
  * @param iDoc [inout]
  *   The document to be loaded
  * @param iUrl [in]
  *   The URL of the input document to read and convert.
  * @param iStreamFormat [in]
  *   Type of the non V5 legacy stream to be used to generate the document
  * @param iParamList [in]
  *	A list of parameters useful for streams conversion
  * @param ioIncidentCollector [inout]
  *   Incident monitor logging errors raised during stream conversion
  *
  * @return
  *   <code>S_OK</code> document has been streamed correctly.
  *   <code>E_FAIL</code> an error occurs. oError contains more information.
  *
  */
  virtual HRESULT UnstreamDocumentFromExternalFormat(CATDocument& ioDoc, CATVVSUrl& iUrl, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector) = 0;

};
CATDeclareHandler(CATIOmbConverter3, CATBaseUnknown);

#endif
