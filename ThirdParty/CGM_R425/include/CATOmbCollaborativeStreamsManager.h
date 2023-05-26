/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2016
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#ifndef CATOmbCollaborativeStreamsManager_H
#define CATOmbCollaborativeStreamsManager_H

// ObjectModelerCollection
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxKeyValueBlock.h"
// ObjectModelerBase
#include "CATOmbAccessModeSdTuple.h"
#include "CATOmbComponentStreamsManager.h"
#include "CATOmbImportExportParameters.h"
#include "CATOmbLoadableDataUniqueKey.h"
#include "CATOmbSelectiveLoading.h"
#include "CATOmbStreamDescriptorQualifiers.h"
#include "omb_cst.h"

class CATComponentId;
class CATBaseUnknown;
class CATOmyCioUrlUsageCtx;
class CATOmbStreamDescriptorObjectImpl;

enum CollaborativeStreamsStatus {NONE=0, OK, KOCollaborative, KODerivedFromCollaborative};

struct CollaborativeStreamInfo
{
  CATBoolean m_IsSynchronized;
  CATOmbLoadableDataUniqueKey m_key; // The PersistencyName stored in the key identify the streams
};
template<> ExportedByCATOmbSelectiveLoading CATOmxCollecManager& CATOmxDefaultCollecManager<CollaborativeStreamInfo>::manager();


//=====================================================================================================================================

class ExportedByCATOmbSelectiveLoading CATOmbCollaborativeStreamsManager : public CATOmbComponentStreamsManager
{
public:
  //-------------------------------------------------------------------------------------------------------------------
  //                                   Access to a PLM component streams                                       
  //-------------------------------------------------------------------------------------------------------------------

  /**
   * Initialize a CATOmbCollaborativeStreamsManager from a pointer.
   * ipComponent must be a pointer to a representation reference or entity with stream.
   * If you already have the CATComponentId object, for performance reason prefer next constructor.
   */
  CATOmbCollaborativeStreamsManager(CATBaseUnknown* ipComponent);

  /**
   * Initialize a CATOmbCollaborativeStreamsManager from a CATComponentId.
   * iComponentID must be a refer to a representation reference or entity with stream.
   */
  CATOmbCollaborativeStreamsManager(const CATComponentId& iComponentID);

  /** dtor*/
  ~CATOmbCollaborativeStreamsManager();


  //-------------------------------------------------------------------------------------------------------------------
  //                                   Stream Life Cycle in session and repository                                        
  //-------------------------------------------------------------------------------------------------------------------

  /** 
  * This method allows to get the access mode of the RepRef (Native Access or Collaborative Access).
  * @param oAccessInfos [out]
  *   The status of the access.
  * @return
  *   <code>S_OK</code> Collaborative Streams exist.
  *   <code>E_FAIL</code> Collaborative Streams do not exist.
  */
  HRESULT GetRepRefStreamsAccess(RepRefDataAccess& oAccessInfos);

  /** 
  * This method allows to change the access mode of the RepRef (Native Access or Collaborative Access).
  * The RepRef must be loaded in PLM Mode.
  * @param iAccessInfos [in]
  *   The status of the access.
  * @return
  *   <code>S_OK</code> Collaborative Streams exist.
  *   <code>E_FAIL</code> Collaborative Streams do not exist or the rep is loaded in a not supported mode.
  */
  HRESULT SwitchRepRefStreamsAccess(RepRefDataAccess iAccessInfos);

  /** 
  * This method allows to get the synchronization status and access information of the collaborative streams attached to a RepRef.
  * @param oInfos [out]
  *   The status of the access.
  * @param oCollaborativeStreamsStatus [out]
  *   pointer to a valid enum CollaborativeStreamsStatus, give the repRef collaborative status (NONE, OK, KOCollaborative, KODerivedFromCollaborative, WarningCollaborative)
  * @return
  *   <code>S_OK</code> Collaborative streams status was properly retrieved.
  *   <code>E_FAIL</code> Collaborative streams status was not properly retrieved.
  */	
  HRESULT GetCollaborativeStreamInfos(CATOmxArray<CollaborativeStreamInfo>& oInfos, CollaborativeStreamsStatus& oCollaborativeStreamsStatus);
  HRESULT GetCollaborativeStreamInfos(CATOmxArray<CollaborativeStreamInfo>& oInfos);

  /**
  * This method allows to generate all the collaborative streams and attach them to an empty RepRef. 
  * This method can be called to update an existing RepRef or to create a new one from scratch.
  * @param iCollaborativeUrl [in]
  *   The url of the collaborative stream to import.
  * @param iCollaborativeFileName [in]
  *   The filename that will be used to store the generated file on the server.
  * @param iParam [in]
  *   The parameters of the exporter that will be used to generate the authoring and visu streams.
  *   Use key/Value  omb_cst::OMB_ForceCollaborativeUpdate/TRUE(1) to force collaborative streams generation even if they are up to date.
  * @return
  *   <code>S_OK</code> Collaborative streams was properly generated.
  *   <code>E_FAIL</code> Collaborative streams was not properly generated.
  */
  HRESULT GenerateCollaborativeStreamsForExternalFile(CATVVSUrl& iCollaborativeUrl, CATUnicodeString& iCollaborativeFileName, CATOmxKeyValueBlock& iParam);

  /**
  * This method has the same behavior as GenerateCollaborativeStreamsForExternalFile but differs on these points : 
  *   - the main SD will be a CATXCADNonCATIADocument latetype instead of a CATNonCATIADocument.
  *   - the visu stream is generated directly after import from imported XCAD file (not at save).
  *   - no CATIA Authoring stream is generated.
  * @param iCollaborativeUrl [in]
  *   The url of the collaborative stream to import.
  * @param iCollaborativeFileName [in]
  *   The filename that will be used to store the generated file on the server.
  * @param iParam [in]
  *   Mandatory : Insert the value for key 'XCADLatetype' corresponding to latetype you want to instantiate. Values accepted {CATXCAD2DDocument, CATXCAD3DDocument}
  *   The parameters of the exporter that will be used to generate the authoring and visu streams.
  *   Use key/Value  omb_cst::OMB_ForceCollaborativeUpdate/TRUE(1) to force collaborative streams generation even if they are up to date.
  * @return
  *   <code>S_OK</code> Collaborative streams was properly generated.
  *   <code>E_FAIL</code> Collaborative streams was not properly generated.
  */
  HRESULT GenerateCollaborativeStreamsForXCADExternalFile(CATVVSUrl& iCollaborativeUrl, CATUnicodeString& iCollaborativeFileName, CATOmxKeyValueBlock& iParam);

  /**
  * This method allows to generate all the collaborative streams and attach them to a CATIA RepRef (a RepRef that does have an Authoring CATPart and a Visu CGR).
  * The RepRef must be loaded in PLM Mode. This method can be called to update an existing RepRef or to create a new one from scratch.
  * @param iCollaborativeFileName [in]
  *   The filename that will be used to store the generated file on the server. It will be used as PersistencyName for SD key, meaning that changing it leads to Delete then Add operation on FCS.
  * @param piImportExportParameters [in]
  *   Parameters of the exporter that will be used to generate the collaborative stream.
  * @param iParam [in]
  *   The parameters of the converter that will be used to generate the authoring and visu streams.
  *   Use key/Value  omb_cst::OMB_ForceCollaborativeUpdate/TRUE(1) to force collaborative streams generation even if they are up to date.
  * @return
  *   <code>S_OK</code> Collaborative streams was properly generated.
  *   <code>E_FAIL</code> Collaborative streams was not properly generated.
  *   <code>S_FALSE</code> Collaborative streams are already synchronized.
  */
  HRESULT GenerateCollaborativeStreamsForCATIARepRef(CATUnicodeString& iCollaborativeFileName, CATOmbImportExportParameters *piImportExportParameters, CATOmxKeyValueBlock& iParam);
  

  /** 
  * This method allows to send the collaborative stream with external format keeping the Name provided on Checkin
  * @param iDirectory [in]
  *   The directory where to put the file
  * @param iFileName [in]
  *   The Name of the result file, else persistency name
  * @return
  *   <code>S_OK</code> Collaborative Streams exist.
  *   <code>E_FAIL</code> Collaborative Streams do not exist.
  */
  HRESULT SendCollaborativeStreamToFile(CATUnicodeString& iDirectory, CATUnicodeString& iFileName);

  /*
  * This method allow to get the main authoring sd key without its Persistency Name. This key can be compared to standard static keys in CATOmbLoadableDataUniqueKey.h
  * for instance Authoring, AuthoringCollaborative, AuthoringVisuDerivedFromCollaborative, etc ...
  * @return 
  *   return a new copy of the key without its persitency name
  **/
  CATOmbLoadableDataUniqueKey GetMainAuthoringCanonicalType();

  /* A combination of #GetRepRefStreamsAccess and #GetMainAuthoringCanonicalType , See their descriptions above for more details.
  */
  HRESULT GetAccessAndMainAuthoringCanonicalType(RepRefDataAccess& oAccessInfos ,CATOmbLoadableDataUniqueKey& oCanonicalKey);

  /*
  * Get all sd keys that are loadable in current context
  * @param
  *   out oKeys : array that will contains all keys that are loadable (must be empty)
  * @return
  *   E_FAIL : something went wrong
  *   S_FALSE : no key loadable
  *   S_OK : all is fine
  */
  HRESULT GetLoadableKeys(CATOmxArray<CATOmbLoadableDataUniqueKey> & oKeys);

  /*
  * Get all CATOmbAccessModeSdTuple (tuple of Access, LoadingMode, SDkey loaded for it, and method to know if sd is master).
  * @param
  *   oAvailableTuples : the vector that will contains availables tuples (must be empty)
  *   iAccess : define access where tuples are queried. If not set or set to UnknownAccess, it will query all accesses.
  * @return
  *   E_FAIL if something went wrong
  *   S_FALSE no mode available
  *   S_OK else
  */
  HRESULT ListAvailableModesTuples(CATOmxVector<CATOmbAccessModeSdTuple>& oAvailableTuples, RepRefDataAccess iAccess = UnknownAccess);
  /*
  * Same as above but access is restricted to current RepRef access
  */
  HRESULT ListAvailableModesTuplesFromCurrentAccess(CATOmxVector<CATOmbAccessModeSdTuple>& oAvailableTuples);


private:
  CATOmbCollaborativeStreamsManager(const CATOmbCollaborativeStreamsManager& iCopy);
  CATOmbCollaborativeStreamsManager operator=(CATOmbCollaborativeStreamsManager& iCopy);

  HRESULT _GenerateCollaborativeStream(CATUnicodeString& iCollaborativeFileName,
                                       CATOmbImportExportParameters *piImportExportParameters,
                                       CATOmxSR<CATOmyCioUrlUsageCtx>& oCtx);

  HRESULT _GenerateCollaborativeStreamFromImport(CATVVSUrl& iCollaborativeUrl, CATUnicodeString& iCollaborativeFileName, const CATUnicodeString& importFileLatetype, CATOmxKeyValueBlock& iParam);

  HRESULT _AddStreamsDerivedFromCollaborativeStream(CATOmyCioUrlUsageCtx &iCtx, CATOmxKeyValueBlock &iParam);

  HRESULT _AddSDForNonCATIADocument(CATVVSUrl& iCollaborativeUrl, CATOmbLoadableDataUniqueKey& key, const CATUnicodeString& iDocumentLatetype, CATOmxSR<CATOmyCioUrlUsageCtx>& oCtx);

  HRESULT _AddVisuStreamDerivedFromXCAD(CATOmyCioUrlUsageCtx &iCtx, CATOmxKeyValueBlock &iParam);

  CATOmbStreamDescriptorQualifiers _GenerateTmpPathAndQualifiersForNewSD(const CATUnicodeString& latetype, CATOmbStreamDescriptorObjectImpl* masterSD);

  CATBoolean _IsRepInPlmMode(CATBoolean iAllowNullLoadingMode=FALSE/*at rep creation*/);

  CATBoolean _IsSessionDirty();

  CATBoolean _CollaborativeStreamsAreSynchro();

  CATBoolean _IsRepV6();

  HRESULT _OnGenerationTerminated();

  HRESULT _CreateUrlUsageContext(const CATVVSUrl& iUrl, CATOmxSR<CATOmyCioUrlUsageCtx>& oCtx);
};

#endif
