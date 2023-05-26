#ifndef CATOmbObjectStreamerServices_H
#define CATOmbObjectStreamerServices_H

// System
#include "CATUuid.h"
#include "CATOmbIPCS.h"
// ObjectModelerCollection
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATOmxSet.h"
#include "CATOmxSharable.h"
// CATVirtualVaultSystem
#include "CATVVSURLConnection.h"
#include "CATVVSUrl.h"
// ObjectModelerBase
// CATPLMStreamDescriptor
#include "CATOmyCioGenerator.h"
#include "CATOmbIPCS.h"
#include "CATOmbImportExportParameters.h"
#include "CATOmbStreamDescriptorDefinitionQualifiers.h"
#include "CATDocument.h"
#include "CATIOmyIncidentCollector.h"
#include "CATOmxArray.h"
#include "CATAsyncTrace.h"

// (ease of use)
// Declare component to error map 
typedef CATOmxOHMap<CATBaseUnknown*, CATError*, com_manager, com_manager> OmbComponentErrors;
typedef CATOmxOHMap<CATBaseUnknown*, unsigned int, com_manager> OmbComponentFlags;

//Load retry mode
#define ByPassOnError 0xF00 // Code AND-ed to error search and retry, when retrying load with error bypass
#define V5V6CatalogComplianceError 0x10 // load is re-tried for treated RepRef, on V5INV6 catalog compliance error(s) only, by-passing the error check

enum CATOmbStreamingType {
  OmbSA_NotSet = 0,
  OmbSA_Exporter = 1,
  OmbSA_Converter2 = 3,
  OmbSA_Converter3 = 4
};

class CATOmyFileStreamer;
class CATBaseUnknown;
class CATPLMSDProperties;
struct CATOmbStreamDescriptorQualifiers;


typedef CATOmxOHMap<unsigned int, CATBaseUnknown*>  CATOmbObjectStreamingMap;

class ExportedByCATOmbIPCS CATOmbObjectStreamerServices
{
  friend class CATOmbSdsStreamServices;
  friend class CATOmbObjectStreamsForDO;
  friend class CATOmbTstLinkableUtilities;
  friend class CATOmbObjectStreamsCollection;

public:
  CATOmbObjectStreamerServices();
  virtual ~CATOmbObjectStreamerServices();

  HRESULT
    CheckExporter(
      const CATBaseUnknown* iRepRef
      , const CATUnicodeString& iExtension
      , const CATUnicodeString& iUsage
      , const CATUnicodeString& iRole
      , CATOmbImportExportParameters* iParameters
      , CATOmxSR<CATBaseUnknown>& oStreamer);

  HRESULT
    CheckUpdater(
      CATVVSUrl& iUrl
      , const CATUnicodeString& iInputExtension
      , const CATUnicodeString& iOutputExtension
      , const CATUnicodeString& iFormat
      , const CATUnicodeString& iRole
      , CATOmbImportExportParameters* iParameters
      , CATOmxSR<CATBaseUnknown>& oStreamer);

  // MUST DELETE
  HRESULT
    CheckFromXCADToNativeConverterV1(
      CATVVSUrl& iUrl
      , const CATUnicodeString& iInputPersistencyType
      , const CATUnicodeString& iOutputLateType
      , CATOmbImportExportParameters* iParameters
      , CATOmxSR<CATBaseUnknown>& oStreamer);

  HRESULT
    CheckFromXCADToNativeConverter(
      CATVVSUrl& iUrl
      , const CATUnicodeString& iNativeFormat
      , const CATUnicodeString& iNativeRole
      , const CATUnicodeString& iNativeLateType
      , const CATUnicodeString& iInputLateType
      , CATOmbImportExportParameters* iParameters
      , CATOmxSR<CATBaseUnknown>& oStreamer);

  HRESULT
    CheckFromNativeToXCADConverter(
      CATVVSUrl& iUrl
      , const CATUnicodeString& iInputFormat
      , const CATUnicodeString& iInputRole
      , const CATUnicodeString& iInputLateType
      , const CATUnicodeString& iOutputLateType
      , CATOmbImportExportParameters* iParameters
      , CATOmxSR<CATBaseUnknown>& oStreamer);

  HRESULT
    CheckXCADConverter(
      CATVVSUrl& iUrl
      , const CATUnicodeString& iInputLatetype
      , const CATUnicodeString& iOutputLatetype
      , CATOmbImportExportParameters* iParameters
      , CATOmxSR<CATBaseUnknown>& oStreamer);

  HRESULT
    StopStreamerJob();


  HRESULT
    UpdateNativeFromExternal(
     const CATBaseUnknown*  iStreamer
      , CATDocument& ioDoc
      , CATOmbImportExportParameters* ipParameters) ;

  HRESULT
    StreamNativetInCache(
      CATDocument& iDoc
      , const CATUnicodeString& iTargetVersion
      , CATOmyCioUrlUsageCtx_iter& oUrlContextIter);

  HRESULT
    ExportViewableInCache(
     const CATBaseUnknown*  iStreamer
      , const CATBaseUnknown* iRepRef
      , const CATUnicodeString& iViewableExtension
      , const CATUnicodeString& iViewableUsage
      , CATOmbImportExportParameters* iParameters
      , CATOmyCioUrlUsageCtx_iter& oUrlContextIter);

  //StreamConversionFromDocumentInCache
  HRESULT
    ConvertFromNative(
     const CATBaseUnknown*  iStreamer
      , CATDocument& iDoc
      , const CATUnicodeString& iStreamExtension
      , const CATUnicodeString& iStreamFormat
      , CATOmbImportExportParameters* iParamList
      , CATOmyCioUrlUsageCtx_iter& oUrlContextIter);

  //StreamConversionFromXCADToDocumentInCache
  HRESULT
    ConvertFromNonCATIAToNativeInCache(
     const CATBaseUnknown*  iStreamer
      , const CATVVSUrl& iUrl
      , const CATUnicodeString& iInputLateType
      , const CATUnicodeString& iOutputLateType
      , CATOmbImportExportParameters* iParamList
      , CATOmyCioUrlUsageCtx_iter& oUrlContextIter);

  //StreamConversionFromXCADInCache
  HRESULT
    ConvertFromNonCATIAInCache(
     const CATBaseUnknown*  iStreamer
      , const CATVVSUrl& iUrl
      , const CATUnicodeString& iInputLateType
      , const CATUnicodeString& iOutputLateType
      , CATOmbImportExportParameters* iParamList
      , CATOmyCioUrlUsageCtx_iter& oUrlContextIter);


  HRESULT StartGeneratorTransaction();

  HRESULT StopGeneratorTransaction();

  HRESULT CancelGeneratorTransaction();

private:
  CATOmbObjectStreamerServices(CATOmbObjectStreamerServices&);
  CATOmbObjectStreamerServices& operator=(CATOmbObjectStreamerServices&);

  CATOmyCioGenerator _generator;
  CATAsyncTrace _IPCSTracer;
  CATUuid _ConversionTransaction;
  CATOmxSR<CATIOmyIncidentCollector> _incidentCollector;
  CATOmxSet<CATOmyFileStreamer, sharable_manager> _FileStreamerHandler;
  CATOmbObjectStreamingMap _streamerObjectMap;

  CATBaseUnknown* FindStreamingHandler(const unsigned int&) const;

  CATUnicodeString ComputeKey(
    const CATUnicodeString&
    , const CATUnicodeString&
    , const CATUnicodeString & = CATUnicodeString()
    , const CATUnicodeString & = CATUnicodeString()
    , const CATUnicodeString & = CATUnicodeString()) const;

 /*****************************************************************************/
  /****************************************************************************/
  /**********                   Service Stuff                   ***************/
  /****************************************************************************/
  /****************************************************************************/
    /**
  * Verify that Authoring (XCAD) and AuthoringVisu streams are present and the second is synchronized with first one. Also check
  * param
  *   - iCID : the component to check
  *   - iGenerationContext : context of generation, cf CATOmbSdsStreamServices.h
  * return
  *   - S_OK : a linkable stream has to be generated (not created or not synchro)
  *   - S_FALSE : nothing has to be done (linkable stream already synchronized)
  *   - E_XXX : something went wrong
  */
  HRESULT CheckXCADRepRefState(
    const CATBaseUnknown* iRepRef
    , CATOmbImportExportParameters* iParameters
    , CATOmbStreamDescriptorDefinitionQualifiers*& oSecondarySD
    , const CATUnicodeString& iObjStreamsHash
    , const CATUnicodeString& iSourceLateType);


  /**
  * Creates a new V5 CATDocument(CXR25) in order to have a linkable stream on XCAD reps)
  * param
  *   - iLatetype : the latetype of document to create
  *   - oDoc : the CATDocument created
  * return
  *   S_OK : everything ran well
  *   E_XXX : error
  */
  HRESULT CreateLinkableV5Document(const CATUnicodeString& iLatetype,
    CATDocument*& oDoc,
    CATOmbImportExportParameters* iParamList,
    CATUnicodeString& oTargetVersion);
  /**
   * @brief Checks if the requested CATBack level is highed than the current one
   *
   * @param iDoc The Linkable Document
   * @param iParamList  The Shared Parameters list from the ObjectStreams(ForDO)
   * @param oTargetVersion The requested targetversion returned
   * @return HRESULT        S_OK if the requested target is authorized E_FAIL otherwise
   */
  HRESULT CheckCATBackLevel(CATDocument& iDoc,
    CATOmbImportExportParameters* iParamList,
    CATUnicodeString& oTargetVersion);

  HRESULT SetLinkable(CATDocument& iDoc);

  /* iRepRefs : map of component to switch. values contain the specific target mode for given component. If it contains an empty string, other rules (than plmid ones) will apply.
  */
  HRESULT TryForceLinkableAndSourceStreamsLoad(const CATOmxOHMap<CATBaseUnknown*, CATUnicodeString>& iRepRefs, const unsigned int iRetryOn, OmbComponentErrors& oRepRefsToRetry);

  // used for linkable document for its update and stream. Then it will be reattached
  HRESULT SetSDUrlAfterStreamInCache(CATBaseUnknown* ioSD, const CATVVSUrl& iIndexURL, const CATUnicodeString& iPN);
  HRESULT CreateLinkableSD(const CATBaseUnknown* iRepRef, const CATOmbStreamDescriptorQualifiers& iQualifiers, CATOmxSR<CATBaseUnknown>& oSD);
  HRESULT CreateViewableSD(const CATBaseUnknown* iRepRef, const CATOmbStreamDescriptorQualifiers& iQualifiers, CATOmxSR<CATBaseUnknown>& oSD);


  HRESULT AssociateServerUrlToSD(CATVVSUrl& iUrl, CATOmbLoadableDataUniqueKey& iKey, const CATBaseUnknown* iRepRef, const CATUuid& iTransactionUuid);

  HRESULT SetStreamDescriptorsWSAndSynchroStamp(const CATBaseUnknown* iRepRef, int iGenerationContext, CATOmxArray<CATPLMSDProperties*, naive_manager>& ioSDsList);
  HRESULT SetStreamDescriptorsWSAndSynchroStampForDO(const CATBaseUnknown* iRepRef, CATOmxArray<CATPLMSDProperties*, naive_manager>& ioSDsList);

};

#endif
