// COPYRIGHT Dassault Systemes 2018
//===============================================

#ifndef CATEOmbConverter3_h
#define CATEOmbConverter3_h
// ==============================================
// Adapter for CATIOmbConverter3
// ==============================================

#include "CATIOmbConverter3.h"
#include "CATOmbConverterForRestrictedClients.h"
#include "IUnknown.h"
class CATDocument;
class CATVVSUrl;
class CATUuid;
class CATOmbImportExportParameters;
class CATIOmyIncidentCollector; 

class ExportedByCATOmbConverter CATEOmbConverter3 : public CATIOmbConverter3
{
public:
  virtual HRESULT InitializeJob(CATVVSUrl& iUrl, CATUuid& iUuid, CATIOmyIncidentCollector* iIncidentCollector);
  virtual HRESULT UpdateDocumentFromExternalFormat(CATDocument& ioDoc, const CATUuid& iUuid, CATOmbImportExportParameters* iParameters, CATIOmyIncidentCollector* iIncidentCollector);
  virtual HRESULT StopJob(CATUuid& ioUuid, CATIOmyIncidentCollector* iIncidentCollector);
  virtual HRESULT StreamDocumentToExternalFormat(CATDocument& iDoc, CATOmxSR<CATILockBytes2> ioILB, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector);
  virtual HRESULT StreamExternalFormatToExternalFormat(CATVVSUrl& iInputUrl, const CATUnicodeString& iInputFormat, CATOmxSR<CATILockBytes2> ioILB, const CATUnicodeString& iOutputFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector);
  virtual HRESULT StreamExternalFormatToDocument(CATVVSUrl& iInputUrl, const CATUnicodeString& iInputFormat, CATOmxSR<CATILockBytes2> ioILB, const CATUnicodeString& iOutputFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector);
  virtual HRESULT UnstreamDocumentFromExternalFormat(CATDocument& ioDoc, CATVVSUrl& iUrl, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector);
};


#endif
