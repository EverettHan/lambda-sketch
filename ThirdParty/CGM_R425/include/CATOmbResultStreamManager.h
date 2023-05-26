/* -*-c++-*- */
/**
* @level Protected
* @usage U1
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2012
//-----------------------------------------------------------------------------
//
// class CATOmbResultStreamManager :
// 
// Regenerates Visualization streams linked to a CATIA CATPart 
// to some external proprietary formats
//
//-----------------------------------------------------------------------------
// 01/06/04 Creation                                                        VCS
//-----------------------------------------------------------------------------

#ifndef CATOmbResultStreamManager_H
#define CATOmbResultStreamManager_H

// System
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATOmbStreamDescriptorDefinitionQualifiers.h"
#include "CATOmbSelectiveLoading.h"

class CATBaseUnknown;
class CATDocument;
class CATILockBytes2;
class CATOmbImportExportParameters;
class CATIOmbStreamDescriptor_var;
class CATIOmyIncidentCollector_var;

#define VCS_RefreshVisuStreams_SDCreationSignature_build_flag

typedef HRESULT (*pCATOmbCheckForVisuStreamRefresh)(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);

template<> ExportedByCATOmbSelectiveLoading CATOmxCollecManager& CATOmxDefaultCollecManager<pCATOmbCheckForVisuStreamRefresh>::manager();

template<> ExportedByCATOmbSelectiveLoading CATOmxCollecManager& CATOmxDefaultCollecManager< CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers, pCATOmbCheckForVisuStreamRefresh> >::manager();

typedef HRESULT (*pCATOmbCheckForVisuStreamDelete)(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc);

template<> ExportedByCATOmbSelectiveLoading CATOmxCollecManager& CATOmxDefaultCollecManager<pCATOmbCheckForVisuStreamDelete>::manager();

template<> ExportedByCATOmbSelectiveLoading CATOmxCollecManager& CATOmxDefaultCollecManager< CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers, pCATOmbCheckForVisuStreamDelete> >::manager();


namespace ResultStream
{
  /**
  * The internal format(s) of results streams to be (re)generated
  * @param CGR
  *   ask for Visu CGR stream check and (re)generation
  * @param UVR
  *   ask for Visu UVR stream check and (re)generation
  */
  enum Format{CGR=1, UVR=2};
}

/**
* Services to perform migration of CATIA documents to external proprietary formats.
* <br><b>Role:</b> Migrates specific CATIA V6 applicative data to external proprietary formats
* <br> specifies by user exit functions
*/
class ExportedByCATOmbSelectiveLoading CATOmbResultStreamManager
{
public:

  CATOmbResultStreamManager(CATBaseUnknown* ipComponent);
  ~CATOmbResultStreamManager();

  /**
  * @deprecated  3DEXPERIENCER2018X
  * @use  HRESULT RefreshVisuStreams(int iFormats, HRESULT (*ipExtCheckVisuStream)(ResultStream::Format iAFormat, CATBoolean ibV5Native, CATOmxSR<CATBaseUnknown>& ipPartDoc, CATOmxSR<CATILockBytes2>& ipVisuILB,
  *                                  CATOmxSR<CATOmbImportExportParameters>& ioExportParms, CATBoolean& obRegenerate))
  *
  * Generates or regenerates visualization streams linked to a CATIA CATPart specification stream
  * <br><b>Role:</b> Re-computes and saves into Session Cache+Provider the CGR and/or UVR Visualization streams
  * <br> linked to a CATIA CATPart specification stream aggregated under a given V6 component
  * <br> Use restrictions:
  * <ul>
  * <li> This service is not to be called by any DS legacy process, excepted a specific utility one.</li>
  * <li> The computation input can only be an authoring CATIA CATPart/CATShape one. No other type accepted.</li>
  * <li> The CATPart computation input should not have been modified since last Save, as it is a(re)generate operation, not an update following Authoring modification.</li>
  * <li> The (re)generation is only performed if visu stream is considered as to be re-computed by the DS software owning the visu format, excepted for following case: </li>.
  * <li> The visualisation stream(s), if no more exists or accessible from FCS, are directly re-computed, without asking the application, as this is then considered as a repair operation.</li>
  * <li> This regeneration can only performed on DS internal visualization stream formats CGR and/or UVR</li>.
  * </ul>
  * @param iFormats 
  *     DS internal format regeneration is to be applied to: CGR and/or UVR
  *     possibles values are ResultStream::CGR / ResultStream::UVR / ResultStream::CGR|ResultStream::UVR
  * @param ipExtCheckVisuStream
  *     a pointer on the DS applicative entry to be implemented by an external function or static class method, 
  *      matching the following signature:
  *        HRESULT ExtCheckVisuStream(ResultStream::Format iAFormat, CATBaseUnknown* ipBUStream), where:
  *          - iAFormat is exclusively one of the available formats: CGR OR UVR
  *          - ipBUStream is the handle on the CGR OR UVR document to be checked by this class caller
  *            it must return SUCCEEDED when NO regeneration to be performed and FAILED otherwise.
  *          - ioIncidentCollector is the list of incidents/errors user may want to fill while checking Visu stream
  *          - it is created by user or by this method and is also passed to ExtCheckVisuStream
  * @param ioIncidentCollector
  *        A list of errors that may have occured during operation
  * @return
  *		 S_OK : regeneration successfull
  * <br> E_FAIL  : An internal error occured  
  * <br> E_INVALIDARG : CATOmbResultStreamManager not initialized with a valid or alive RepRef component
  * <br> ERROR_INVALID_DATATYPE : Authoring input stream to be used for compute is not a DS CATPart type
  * <br> ERROR_BAD_EXE_FORMAT : This service is not to be called by any DS legacy executable process (CATIA, DELMIA, SIMULIA, ..etc)
  *                             excepted the dedicated DS utility batch
	*/
  HRESULT RefreshVisuStreams(int iFormats, HRESULT (*ipExtCheckVisuStream)(ResultStream::Format iAFormat, CATBaseUnknown* ipBUStream, CATIOmyIncidentCollector_var& ioIncidentCollector),
                             CATIOmyIncidentCollector_var& ioIncidentCollector);

  /**
  * Generates or regenerates main visualization streams linked to a CATIA specification stream 
  *    Re-computes and saves into Session Cache+Provider the Visualization streams
  *    linked to a CATIA specification stream aggregated under a given V6 component
  * Use restrictions:
  * - This service is not to be called by any DS legacy process, excepted a specific utility one.
  * - The computation input can only be an authoring V6 CATIA CATPart/CATShape/CATDrawing/CATData or Authoring V5Native CATPart/CATShape/CATDrawing specification streams. No other type accepted.
  * - The CATPart computation input should not have been modified since last Save, as it is a(re)generate operation, not an update one.
  * - The (re)generation is only performed if visu stream is considered as to be re-computed by the DS software owning the visu format, excepted for following case:
  * - The visualisation stream(s), if no more exists or accessible from FCS, are directly re-computed, without asking the application, as this is then considered as a repair operation.
  * - This regeneration can only performed on DS internal visualization stream formats CGR and/or UVR and/or AlternativeVisu.
  * - The Authoring stream is globally loaded in session by a switch to AuthoringFullEdit_Mode, if not yet.
  *
  * @param iVisuStreamHandles 
  *     The list of (StreamDescriptorDefinition | decision function pointer) couples refering to the streams to be (re)generated
  *
  * StreamDescriptorDefinition: the unique CATOmbStreamDescriptorDefinitionQualifiers(SDkey, "StreamType") couple defining the Stream(+Descriptor) to be regenerated, where: 
  *
  *                             StreamDescriptor key addresses the stream to be (re) generated. Possible values for the key (Format, Role, PersistencyName) are:
  *                               (CATOmbStreamDescriptorFormat_AuthoringVisu, "", empty or UserDefined)
  *                               (CATOmbStreamDescriptorFormat_AuthoringVisu2, "", empty or UserDefined)
  *                               (CATOmbStreamDescriptorFormat_AuthoringVisu, omb_cst().ALTERNATIVE, UserDefined)
  *
  *                             StreamType is the file extension of the stream (cgr, uvr, svg ...etc)
  *                             Be aware that StreamType is usefull as input when the StreamDescriptor doesn't already exist on the RepRef : the StreamDescriptor is then generated from iVisuDef along with its stream.
  *                             Otherwise, StreamType is read from the already existing SD. Streamtype is case sensitive.
  *                             An error occurs when StreamDescriptor doesn't already exist and Streamtype not given as input.
  *
  * decision function pointer:  the applicative function to ask for the effective regeneration, depending on applicative own criteria (Settings, initial conditions..etc),
  *                             to be implemented by an external function or static class method, and matching the following signature:
  *
  * HRESULT (*pCATOmbCheckForVisuStreamRefresh)(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms) :
  * 
  *          - iVisuDef      : The unique CATOmbStreamDescriptorDefinitionQualifiers(SDkey, "StreamType") couple defining the Stream(+Descriptor) to be regenerated, as described above.
  *          - ipPartDoc     : a pointer on the Authoring Document, currently loaded in session, which iVisuKey visualization stream is to be regenerated
  *          - ipVisuILB     : the handle on the current CGR or UVR or AlternativeVisu stream, downloaded to session cache, and to be eventually checked by this function caller,
  *                            before deciding or not to regenerate
  *          - ioExportParms : a default set of parameters, to be eventually enreached by this function
  *                            this set is then passed as input to cgr/uvr/alternative visu exporter invoked during the Save performed by RefreshVisuStreams
  *                            As input, this set is
  *                               -empty before V6R2015x
  *                               -filled with default "RefreshV5NativeCGR" CATOmxAny parameter, typed as boolean, from V6R2015x on:
  *                                   true when a cgr resulting from a V5Native Authoring stream isasked to be (re)generated  
  *          - return        : S_OK when regeneration to be performed, S_FALSE when regeneration useless and FAILED otherwise (error or any undetermined state) 
  *                            if FAILED, RefreshVisuStreams aborts, logs error ERR_OMB_SD_004 and returns immediately the HRESULT
  *          @href CATIOmyIncidentCollector services can be used to manage a list of incidents/errors user may want to fill while checking Visu stream
  *          using this, errors are pushed into a stack accessible anywhere, and implicitely logged into system ErrorStatistics + OMB_XML_TRACE + console STD_ERR output
  * @return
  *		 S_OK   : regeneration successfull
  *    E_INVALIDARG : CATOmbResultStreamManager not initialized with a valid or alive RepRef component / No Authoring SD on RepRef
  *    ERROR_INVALID_DATATYPE : Authoring input stream to be used for compute is not a DS CATPart/CATShape/CATDrawing/CATData type
  *    ERROR_BAD_EXE_FORMAT : This service is not to be called by any DS legacy executable process (CATIA, DELMIA, SIMULIA, ..etc)
  *                           excepted the dedicated DS utility batch
  *    E_UNEXPECTED : SD V6 Native before V6R2015x / The Authoring stream is seen as modified
  *    FAILED : any other unexpected error code returned by the decision function or this call
  *
  * example of use:
  *
  * DECISION FUNCTIONS
  *
  * class CATxxxCheckForVisuRegen
  * {
  *   public:
	*   CATxxxCheckForVisuRegen();
	*    virtual ~CATxxxCheckForVisuRegen();
  *    static HRESULT CgrStreamToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);
  *    static HRESULT UvrStreamToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);
  *    static HRESULT pAlternativeToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);
  * };
  *
  * HRESULT CATxxxCheckForVisuRegen::CgrStreamToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParmss)
  * {
  *   HRESULT HR = SomeEventualIntrospectionOf(ipPartDoc) or SomeEventuaiIntrospectionOf(ipVisuILB) or ParamValue(s)Read or SettingsRead or AnyOtherApplicativeConditions()
  *   if (FAILED(HR)) return HR;
  *   if (RegenerateThisStream)
  *     return S_OK;
  *   else if (KeepItAsIs)
  *     return S_FALSE;
  * }
  * ...etc
  *
  * REGENERATION CALL 
  * {
  *   ...
  *   CATBaseUnknown* pRepRef = AnyRepRefGetter();
  *   CATOmbResultStreamManager RSM(pRepRef);
  *
  *   pCATOmbCheckForVisuStreamRefresh pCgrToBeRegenerated = &CATxxxCheckForVisuRegen::CgrStreamToBeRegenerated;
  *   pCATOmbCheckForVisuStreamRefresh pUvrToBeRegenerated = &CATxxxCheckForVisuRegen::UvrStreamToBeRegenerated;
  *   pCATOmbCheckForVisuStreamRefresh pAlternativeToBeRegenerated = &CATxxxCheckForVisuRegen::UvrStreamToBeRegenerated;
  *
  *   CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers,pCATOmbCheckForVisuStreamRefresh> RegenStreamsHandle;
  *   RegenStreamsHandle.Insert(CATOmbStreamDescriptorDefinitionQualifiers(CATOmbLoadableDataUniqueKey::AuthoringVisu(),"cgr"),pCgrToBeRegenerated);
  *   RegenStreamsHandle.Insert(CATOmbStreamDescriptorDefinitionQualifiers(CATOmbLoadableDataUniqueKey::AuthoringVisu2(),"uvr"),pUvrToBeRegenerated);
  * 
  *   CATOmbStreamDescriptorDefinitionQualifiers AlterVisuDef(CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_AuthoringVisu,omb_cst().ALTERNATIVE,"AlternativeSDId"),"svg");
  *   RegenStreamsHandle.Insert(AlterVisuDef,pAlternativeToBeRegenerated);
  *
  *   HRESULT HR == RSM.RefreshVisuStreams(RegenStreamsHandle);
  *   ...
  *  }
  */
  HRESULT RefreshVisuStreams(const CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers, pCATOmbCheckForVisuStreamRefresh>& iVisuStreamHandles);

  /**
  * Generates or regenerates main visualization streams linked to a CATIA specification stream
  * and/or 
  * Deletes Extended/Alternative secondary visualization streams linked to a CATIA specification stream
  *
  *    Re-computes and saves and or deletes into Session Cache+Provider the Visualization streams
  *    linked to a CATIA specification stream aggregated under a given V6 component
  * Use restrictions:
  * - This service is not to be called by any DS legacy process, excepted a specific utility one.
  * - The computation input can only be an authoring V6 CATIA CATPart/CATShape/CATDrawing/CATData or Authoring V5Native CATPart/CATShape/CATDrawing specification streams. No other type accepted.
  * - The CATPart/CATShape/CATDrawing computation input should not have been modified since last Save, as it is a(re)generate or Delete operation, not an update one.
  * - The (re)generation is only performed if main visu stream is considered as to be re-computed by the DS software owning the visu format, excepted for following case:
  * - The visualisation stream(s), if no more exists or accessible from FCS, are directly re-computed, without asking the application, as this is then considered as a repair operation.
  * - The regeneration can only performed on DS internal visualization stream formats CGR and/or UVR and/or AlternativeVisu.
  * - The deletion can only be performed on Non CATIA visualization stream formats ExtendedVisu/AlternativeVisu.
  * - The Authoring stream is globally loaded in session by a switch to AuthoringFullEdit_Mode, if not yet.
  *
  * @param iVisuRefresHandles
  *     The list of (StreamDescriptorDefinition | decision function pointer) couples refering to the streams to be (re)generated
  *
  * @param iVisuDeleteHandles
  *     The list of (StreamDescriptorDefinition | decision function pointer) couples refering to the streams to be deleted
  *
  * StreamDescriptorDefinition: the unique CATOmbStreamDescriptorDefinitionQualifiers(SDkey, "StreamType") couple defining the Stream(+Descriptor) to be regenerated/deleted, where:
  *
  *                             StreamDescriptor key addresses the stream to be (re) generated or deleted. Possible values for the key (Format, Role, PersistencyName) are:
  *                             for Refresh
  *                               (CATOmbStreamDescriptorFormat_AuthoringVisu, "", empty or UserDefined)
  *                               (CATOmbStreamDescriptorFormat_AuthoringVisu2, "", empty or UserDefined)
  *                               (CATOmbStreamDescriptorFormat_AuthoringVisu, omb_cst().ALTERNATIVE, UserDefined)
  *                             for Delete


  *                             StreamType is the file extension of the stream (cgr, uvr, svg ...etc)
  *                             Be aware that StreamType is usefull as input when the StreamDescriptor doesn't already exist on the RepRef : the StreamDescriptor is then generated from iVisuDef along with its stream.
  *                             Otherwise, StreamType is read from the already existing SD. Streamtype is case sensitive.
  *                             An error occurs when StreamDescriptor doesn't already exist and Streamtype not given as input.
  *
  * decision function pointer:  the applicative function to ask for the effective regeneration, depending on applicative own criteria (Settings, initial conditions..etc),
  *                             to be implemented by an external function or static class method, and matching the following signatures :
  *
  * For Refresh:
  * HRESULT (*pCATOmbCheckForVisuStreamRefresh)(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms) :
  *
  *          - iVisuDef      : The unique CATOmbStreamDescriptorDefinitionQualifiers(SDkey, "StreamType") couple defining the Stream(+Descriptor) to be regenerated, as described above.
  *          - ipPartDoc     : a pointer on the Authoring Document, currently loaded in session, which iVisuKey visualization stream is to be regenerated
  *          - ipVisuILB     : the handle on the current CGR or UVR or AlternativeVisu stream, downloaded to session cache, and to be eventually checked by this function caller,
  *                            before deciding or not to regenerate
  *          - ioExportParms : a default set of parameters, to be eventually enreached by this function
  *                            this set is then passed as input to cgr/uvr/alternative visu exporter invoked during the Save performed by RefreshVisuStreams
  *                            As input, this set is
  *                               -empty before V6R2015x
  *                               -filled with default "RefreshV5NativeCGR" CATOmxAny parameter, typed as boolean, from V6R2015x on:
  *                                   true when a cgr resulting from a V5Native Authoring stream isasked to be (re)generated
  *          - return        : S_OK when regeneration to be performed, S_FALSE when regeneration useless and FAILED otherwise (error or any undetermined state)
  *                            if FAILED, RefreshVisuStreams aborts, logs error ERR_OMB_SD_004 and returns immediately the HRESULT
  *          @href CATIOmyIncidentCollector services can be used to manage a list of incidents/errors user may want to fill while checking Visu stream
  *          using this, errors are pushed into a stack accessible anywhere, and implicitely logged into system ErrorStatistics + OMB_XML_TRACE + console STD_ERR output
  *
  * For Delete:
  * HRESULT (*pCATOmbCheckForVisuStreamRefresh)(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc) :
  *
  *          - iVisuDef      : The unique CATOmbStreamDescriptorDefinitionQualifiers(SDkey, "StreamType") couple defining the Stream(+Descriptor) to be deleted, as described above.
  *          - ipPartDoc     : a pointer on the Authoring Document, currently loaded in session, which iVisuKey visualization stream is to be regenerated
  *
  * @return
  *		 S_OK   : regeneration successfull
  *    E_INVALIDARG : CATOmbResultStreamManager not initialized with a valid or alive RepRef component / No Authoring SD on RepRef
  *    ERROR_INVALID_DATATYPE : Authoring input stream to be used for compute is not a DS CATPart/CATShape/CATDrawing/CATData type
  *    ERROR_BAD_EXE_FORMAT : This service is not to be called by any DS legacy executable process (CATIA, DELMIA, SIMULIA, ..etc)
  *                           excepted the dedicated DS utility batch
  *    E_UNEXPECTED : SD V6 Native before V6R2015x / The Authoring stream is seen as modified
  *    FAILED : any other unexpected error code returned by the decision function or this call
  *
  * example of use:
  *
  * DECISION FUNCTIONS
  *
  * class CATxxxCheckForVisuChange
  * {
  *   public:
  *   CATxxxCheckForVisuChange();
  *    virtual ~CATxxxCheckForVisuChange();
  *    static HRESULT CgrStreamToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);
  *    static HRESULT UvrStreamToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);
  *    static HRESULT pAlternativeToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms);
  *    static HRESULT pSecondaryStreamToBeDeleted(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc);
  * };
  *
  * HRESULT CATxxxCheckForVisuChange::CgrStreamToBeRegenerated(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc, CATILockBytes2& ipVisuILB, CATOmxSR<CATOmbImportExportParameters>& ioExportParms)
  * {
  *   HRESULT HR = SomeEventualIntrospectionOf(ipPartDoc) or SomeEventuaiIntrospectionOf(ipVisuILB) or ParamValue(s)Read or SettingsRead or AnyOtherApplicativeConditions()
  *   if (FAILED(HR)) return HR;
  *   if (RegenerateThisStream)
  *     return S_OK;
  *   else if (KeepItAsIs)
  *     return S_FALSE;
  * }
  *
  * HRESULT CATxxxCheckForVisuChange::pSecondaryStreamToBeDeleted(const CATOmbStreamDescriptorDefinitionQualifiers& iVisuDef, CATDocument& ipPartDoc)
  * {
  *   HRESULT HR = SomeEventualIntrospectionOf(ipPartDoc) or SettingsRead or AnyOtherApplicativeConditions()
  *   if (FAILED(HR)) return HR;
  *   if (DeleteThisStream)
  *     return S_OK;
  *   else if (KeepItAsIs)
  *     return S_FALSE;
  * }
  *
  * ...etc
  *
  * REGENERATION and/or DELETION CALL
  * {
  *   ...
  *   CATBaseUnknown* pRepRef = AnyRepRefGetter();
  *   CATOmbResultStreamManager RSM(pRepRef);
  *
  *   pCATOmbCheckForVisuStreamRefresh pCgrToBeRegenerated = &CATxxxCheckForVisuRegen::CgrStreamToBeRegenerated;
  *   pCATOmbCheckForVisuStreamRefresh pUvrToBeRegenerated = &CATxxxCheckForVisuRegen::UvrStreamToBeRegenerated;
  *   pCATOmbCheckForVisuStreamRefresh pAlternativeToBeRegenerated = &CATxxxCheckForVisuRegen::UvrStreamToBeRegenerated;
  *   pCATOmbCheckForVisuStreamDelete pSecondaryToBeDeleted = &CATxxxCheckForVisuRegen::pSecondaryStreamToBeDeleted;
  *
  *   CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers,pCATOmbCheckForVisuStreamRefresh> RegenStreamsHandle;
  *   RegenStreamsHandle.Insert(CATOmbStreamDescriptorDefinitionQualifiers(CATOmbLoadableDataUniqueKey::AuthoringVisu(),"cgr"),pCgrToBeRegenerated);
  *   RegenStreamsHandle.Insert(CATOmbStreamDescriptorDefinitionQualifiers(CATOmbLoadableDataUniqueKey::AuthoringVisu2(),"uvr"),pUvrToBeRegenerated);
  *
  *   CATOmbStreamDescriptorDefinitionQualifiers AlterVisuDef(CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_AuthoringVisu,omb_cst().ALTERNATIVE,"AlternativeSDId"),"svg");
  *   RegenStreamsHandle.Insert(AlterVisuDef,pAlternativeToBeRegenerated);
  *
  *   CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers,pCATOmbCheckForVisuStreamDelete> DeleteStreamsHandle;
  *   CATOmbStreamDescriptorDefinitionQualifiers ExtVisuDef01(CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_AuthoringVisu,omb_cst().EXTENDED,"ExtSDId_01"),"txt");
  *   CATOmbStreamDescriptorDefinitionQualifiers AlterVisuDef01(CATOmbLoadableDataUniqueKey(CATOmbStreamDescriptorFormat_AuthoringVisu,omb_cst().ALTERNATIVE,"AlterSDId_0&"),"jpg");
  *   DeleteStreamsHandle.Insert(ExtVisuDef01,pSecondaryToBeDeleted);
  *   DeleteStreamsHandle.Insert(AlterVisuDef01,pSecondaryToBeDeleted);
  *
  *   HRESULT HR == RSM.RefreshVisuStreams(RegenStreamsHandle, DeleteStreamsHandle);
  *   ...
  *  }
  */
  HRESULT RefreshVisuStreams(const CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers,pCATOmbCheckForVisuStreamRefresh>& iVisuRefresHandles, 
    const CATOmxOHMap<CATOmbStreamDescriptorDefinitionQualifiers,pCATOmbCheckForVisuStreamDelete>& iVisuDeleteHandles);
  
private:

  CATBaseUnknown* _pComponent;

  HRESULT SwitchToStreamAccess(const CATUnicodeString iTargetLoadMode, CATUnicodeString& oInitialLoadMode, CATIOmbStreamDescriptor_var & ohStreamDesc, CATDocument*& opDocument);

  // copy constructor is private
  CATOmbResultStreamManager (const CATOmbResultStreamManager& iCopy);

  // = operator is private
  CATOmbResultStreamManager operator=(CATOmbResultStreamManager& iCopy);
};
#endif
