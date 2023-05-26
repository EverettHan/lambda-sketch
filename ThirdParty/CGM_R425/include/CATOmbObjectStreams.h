#ifndef CATOmbObjectStreams_H
#define CATOmbObjectStreams_H

// System
#include "CATUuid.h"
// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxList.h"
#include "CATOmxMapIter.h"
#include "CATOmxOHMap.h"
#include "CATOmxSR.h"
#include "CATOmxQIPtr.h"
// CATVirtualVaultSystem
#include "CATVVSURLConnection.h"
// CATPLMServices
#include "CATPLMStreamDescriptor.h"
// ObjectModelerBase
#include "CATOmbLoadableDataUniqueKey.h"
// CATPLMStreamDescriptor
#include "CATPLMStreamDescriptorForInfraOnly.h"
#include "CATIOmbStreamDescriptor.h"
#include "CATAsyncTrace.h"


//WKN3 TODOS : 
// ProcessCATBackParameters ApplyCATBackLevel  CreateLinkableV5Document SetLinkable CreateLinkableSD CreateLinkableSD
// Change this garbage *((objectStreamsDocHandler.m_LinkableDoc)?objectStreamsDocHandler.m_LinkableDoc:objectStreamsDocHandler.m_PreqLinkableDoc)
// Create class to handle loading and unloading of ObjectStreams

/**
* OMB Parameters dictionary for CATOmbObjectStreams :
* key : "OMBGenerationContext"        / value type : unsigned int                                  / Read  by OMB and Read/Write by Application  / role : context of generation
* key : "OMBLinkablePersistencyName"  / value type : CATUnicodeString                              / Set by caller, read by OMB for Linkable SD creation / role: keep same name as XCAD visu context.
* key : "OMBVisuPersistencyName"      / value type : CATUnicodeString                              / Set by caller, read by OMB for visu SD creation / role: keep same name as XCAD visu context.
* key : "OMBCatBackTargetLevel"       / value type : CATUnicodeString - eg "CATIAV5R25"            / Set by caller, read by OMB for CATBack initialization. Only V5 levels are supported, for DO generation only and this apply to all stream generations requested within this request.
* key : "OMBCatBackMode"              / value type : CATUnicodeString - "asSpec" or "asResult"     / Same as OMBCatBackTargetLevel for mode (used only for Authoring stream). Default behaviour if not set is "asResult"
* key : "OMBBypassV5V6Certification"  / value type : CATBoolean - TRUE: bypass certification error / Set by caller, read by OMB at updateSds time   / role : retry input data load on V5-V6 catalog compliance error
* key : "OMBV5V6CertificationReport"  / value type : CATUnicodeString                              / Set by OMB, read by caller at updateSds time   / role : get eventual report about V5-V6 catalog compliance issues
* key : OMBUrlOfXCADFile              / value type : CATUnicodeString                              / Set by caller, read by OMB at init
* key : OMBUrlOfFormerLinkable        / value type : CATUnicodeString                              / Set by caller, read by OMB at init
* key : OMBUrlOfFormerVisu            / value type : CATUnicodeString                              / Set by caller, read by OMB at init
* key : OMBErrorContext               / value type : CATUnicodeString                              / Set strictly by OMB or on the CATOmbImportExportParameters ptr directly
* key : OMBInternalError              / value type : CATUnicodeString                              / Set strictly by OMB or on the CATOmbImportExportParameters ptr directly
* key : OMBUrlOfFormerLinkable        / value type : CATUnicodeString                              / Set by caller, read by OMB at init
* key : OMBForceRegen                 / value type : CATOmbObjectStreamsRegenFlags                 / Set by caller, read by OMB at init
* key : WriteToILB                    / value type : Uuid                                          / Set strictly by OMB
* other parameters could be inside CATOmbObjectStreams parameters table in order tho share them between caller and callee of OMB
*/
//state of CATOmbObjectStreams
enum CATOmbObjectStreamsAction {
  OmbSA_Unknown = 0,//Newly created / unused object 
  // At this stage ALl data members are set to default 
  OmbSA_Init = 1,//initialized 
  // At this stage Component is set for Cloud and m_ListOfTargetStreamDefinition is filled
  OmbSA_Check = 2,// Check input and prepare to generate files
  // At this stage Generation related info  are set and ObjectStreams is valid for file generation
  OmbSA_Stream = 3,// Generate file to TemporaryCache
  OmbSA_Share = 4,// provide ListofStreamDescriptors so GetSDsDefinition works only after UpdateSDsContentAndSaveInPLMCache or if state is OmbSA_None
  OmbSA_Associate = 5,// associate serverurl to cache url through PrepareUploadOfSDsStreams
  OmbSA_Upload = 6,//upload url through CommunicateWithVault
  OmbSA_None = 7,//already computed and uploaded so nothing to do
  OmbSA_Error = 8,//bad SD input
  OmbSA_MAX
};

enum CATOmbObjectStreamsEnv {
  OmbSA_WithTOS = 0,
  OmbSA_WithoutTOS = 1
};

enum CATOmbObjectStreamsSource {
  OmbSA_FromRep = 0,
  OmbSA_FromExternalFile = 1
};
class CATPLMStreamDescriptor;
class CATOmbImportExportParameters;
class CATError;
class CATUnicodeString;
class CATDocument;
class CATVVSUrl;
class CATOmbLoadableDataUniqueKey;
class CATILockBytes2;
class CATOmyIncidentGroup;

struct ErrorInfo
{
  CATOmxSR<CATError>   m_OmbError;
  CATOmxList<CATError> m_InternalErrors;
  CATOmxList<CATError> m_InternalWarnings;
  CATOmxList<CATError> m_OmbWarnings;
};

struct SourceStreamInfo
{
  CATVVSUrl  m_InputURL;
  CATOmxQIPtr<CATIOmbStreamDescriptor> m_sourceSD;
  CATUnicodeString  m_SourceFileExtension;
};

struct LinkableInfo
{
  CATUnicodeString  m_LinkableExtension;
  CATUnicodeString  m_LinkableRole;
};

struct ViewableInfo
{
  CATUnicodeString  m_ViewableExtension;
  CATUnicodeString  m_ViewableRole;
};



class ExportedByCATPLMStreamDescriptor CATOmbObjectStreams : public CATOmxSharable
{
  friend class CATOmbSdsStreamServices;
  friend class CATOmbStreamDescriptorSessionService;
  friend class CATOmbTstLinkableUtilities;
  friend class CATOmbObjectStreamsCollection;
  friend class CATOmbObjectStreamsForDO; // This is needed to do SubsequentDo Generations
  friend class __TA__TestLinkableStreamsGenerationAndUpdate;
  friend class __TA__TestStreamsGenerationForDO;
  friend class __TA__TestLSCloudForDO;
  friend class __TA__TestLSMultipleGen;
public:
  /*
  * build a wrapper of a component to update
  * @param iComponent [inout]
  *   The component to be managed
  */
  CATOmbObjectStreams(CATBaseUnknown* iComponent);
  /*
  * build a wrapper of a a list of CATVVSUrl & CATPLMSDProperties couples to update
  * To be used only for NoTos RepRef
  * @param iComponnentPhysId [in]
  *   The PhysicalId of the component to be managed
  * @param iVStreamDescStr [in]
  *   The String of the VSTreamDescp
  */
  CATOmbObjectStreams(const CATUnicodeString iComponnentPhysId, const CATUnicodeString iVStreamDescStr);
  /*
  * Manage shared parameters between different layers operating Streams content
  * see parameter dictionary at top of header
  */
  HRESULT AddParameter(const CATUnicodeString& iParameterName, CATOmxAny iValue);
  HRESULT GetParameter(const CATUnicodeString& iParameterName, CATOmxAny& oValue) const;

  // only available at Compute step
  CATOmbImportExportParameters* GetSharedParameters();
  /*
  * Provide the definition of the StreamDescriptor to update
  */
  HRESULT GetSDsDefinition(CATOmxList<CATPLMStreamDescriptor>& ioSDdefs);

  HRESULT SetExternalFileForGeneration(const CATVVSUrl& iUrl);
  /**
   * @brief Add an additional Derived Output generation
   *
   * @param iKey The LoadableDataUniqueKey of the source Stream descriptor
   * @param iSD  The output Stream descriptor
   * @return S_OK if every is ok E_FAIL if iKey does not exist
   */
  HRESULT AddSubsequentDOGeneration(const CATOmbLoadableDataUniqueKey& iKey, CATPLMStreamDescriptor* iSD);

  /**
   * @brief Set the Prerequisite Object Streams object
   * 
   * @param ipreq The original CATOmbObjectStreams
   * @param iGenerationContext 
   * @return HRESULT 
   */
  HRESULT SetPrerequisiteObjectStreams(CATOmxSR<CATOmbObjectStreams> ipreq, const unsigned int iGenerationContext);
  /**
   * @brief Return number of the requested Subsequent Derived Output generations
   *
   * @return TRUE if Object has Subsequent DO FALSE otherwise
   */
  CATOmxMapIter<CATPLMStreamDescriptor*, CATOmbLoadableDataUniqueKey> GetSubsequentDOIter();
  /* returns the CATVVSURLConnection corresponding to streamed SD,
returns NULL if SD has not been streamed
*/
  CATOmxSR<CATVVSURLConnectionSharable> GetVVSUrlConnectionFromSDDefinition(CATPLMStreamDescriptor* iSD);
  /*
  * Provide target server url in order to prepare the VVS transaction  of upload
  */
  HRESULT SetServerUrl(const CATVVSUrl& iUrl, CATUuid iTransId, const CATOmbLoadableDataUniqueKey& iKey);
  /**
   * @brief   * Provide current error of CATOmbObjectStreams during generate/update sequence
  *
   * @return the eventual specific error, if available, raised for this component at current sequence step
  *
  * Examples for a Switch/Load error:
  *
  * If UpdateSDsAttributesAndSaveInPLMCache fails, for any reason, at component switch/load step:
  *  a global switch error [key ERR_OMB_1113: Error when trying to get linkable stream (switch)] is raised and stacked by CATIOmyIncidentCollector
  *
  *  GetError outputs the switch error that may have occured for this component [key ERR_OMB_SWITCH_(LOAD, etc)]
  *
  *   If V5-V6 certification error(s) are raised:
  *
  *   Whatever they stop the execution or are bypassed:
  *     A specific error report can be read using GetParameter(OMBV5V6CertificationReport, <a CATUnicodeString formatted message>)
  *     This CATNls message contents the detailed report of the certification issue.
  *
  *   When OMBBypassV5V6Certification parameter set to true as input on ALL ObjectStreams getting the certification error: this error is only a warning,
  *     UpdateSDsAttributesAndSaveInPLMCache continues and returns S_OK, and GetError returns NULL, if no other fatal/severe error.
  *
  *   When OMBBypassV5V6Certification parameter not set/set to false as input, on at least ONE ObjectStreams getting the certification error : this error is severe,
  *     UpdateSDsAttributesAndSaveInPLMCache stops and returns CATOmy_E_V5V6_Catalog_Compliance, and GetError returns ERR_OMB_SWITCH_LOAD, if no other previous fatal/severe error.
  */
  CATError* GetError();

  inline const CATOmxList<CATError> GetInternalErrors() const { return m_errorInfo.m_InternalErrors; }

  inline const CATOmxList<CATError> GetInternalWarnings() const { return m_errorInfo.m_InternalWarnings; }

  inline const CATOmxList<CATError> GetOmbWarnings() const { return m_errorInfo.m_OmbWarnings; }

  virtual ~CATOmbObjectStreams();

  /* Tracing functions */

  /**
   * @brief Dump Params JSON 
   * 
   * @return CATUnicodeString 
   */
    virtual CATUnicodeString DumpObjectStreamsParams();
  /**
   * @brief  Dump everything to JSON
   * 
   * @return CATUnicodeString 
   */
  virtual CATUnicodeString DumpObjectstreamsStr();

protected:
  // **    Rep Related Data    ** //
  CATOmxSR<CATBaseUnknown> m_Component;  //component to work on
  CATUnicodeString m_ComponentPhysId;
  CATUnicodeString m_VStreamDescStr;
  // **    Subsequent DO Generations    **
  CATOmxOHMap<CATPLMStreamDescriptor*, CATOmbLoadableDataUniqueKey, com_manager> m_ListOfSubsequentDoRequests;
  // **    Prereq Documents   **
  CATOmbObjectStreams*            m_PrereqOutgoingEdge;
  CATOmbObjectStreams*            m_PrereqIngoingEdge;
  // **    list of SD to generate/update    **
  CATOmxList<CATPLMStreamDescriptor>       m_ListOfTargetStreamDefinition;
  CATOmxOHMap<CATPLMStreamDescriptor*, CATVVSURLConnectionSharable*, com_manager, sharable_manager> m_VVSUrlConnectionMapping;
  // **    Url List for Input VStreamDesc (CloudOnly)    **
  CATOmxOHMap<CATOmbLoadableDataUniqueKey, CATVVSUrl> m_UrlList;
  // **    State of ObjectStreams (Cloud or PLM session)    **
  CATOmbObjectStreamsEnv m_Env;
  // **    m_SourceLocation (Rep or IFC)    **
  CATOmbObjectStreamsSource m_SourceLocation;
  //    **this state control which operation could be performed and if a parameter could be modified    **
  CATOmbObjectStreamsAction m_State;
  // **    parameters for generate/update    **
  CATOmxSR<CATOmbImportExportParameters> m_sharedparameters;
  // **   Error storage    **
  ErrorInfo m_errorInfo;
  // **   Generation related info    **
  SourceStreamInfo m_streamSourceInfo;
  LinkableInfo     m_linkableInfoInfo;
  ViewableInfo     m_viewableInfoInfo;
  // ** Debug related info **
  CATUnicodeString  m_ObjStreamsHash;

  // Used to identify ObjectStreams in traces ... DON'T USE OTHERWISE OR I'LL SUE YOU
  virtual CATUnicodeString GetHashObjStreams();
  /**
  * @brief  Get PhysicalId of the component held by the ObjectStreams object
  *
  * @return CATUnicodeString
  */
  virtual CATUnicodeString GetRepPhysId() const;

  /**
   * @brief Set the Connexion On Streamed Stream Descriptor Def object
   *
   * @param iSD
   * @param iConnection
   */
  virtual void SetConnexionOnStreamedSDDef(CATPLMStreamDescriptor* iSD, CATVVSURLConnectionSharable* iConnection);

  /**
   * @brief Set/Get The internal state of the object
   * check enum CATOmbObjectStreamsAction in this header
   */
  void InternalSetState(CATOmbObjectStreamsAction);
  /**
  * @brief Check if ObjectStreams was created in  a PLM context or in NoTOS mode
  *
  * @return TRUE if NoTOS mode FALSE if
  */
  inline CATBoolean IsForCloud() const { return m_Env == OmbSA_WithoutTOS; }

  inline CATBoolean IsSourceFromRep() const { return m_SourceLocation == OmbSA_FromRep; }

  HRESULT InitNoTosComponent();
  // *************************************************************
  //  Error Handling and storing                 
  // *************************************************************
  CATOmbObjectStreamsAction InternalGetState();
  void InternalSetError(const CATUnicodeString& iErrorCode, const CATUnicodeString& iErrorMessage);
  void InternalSetError(CATOmxSR<CATError> error);
  void InternalSetWarning(const CATUnicodeString& iErrorCode, const CATUnicodeString& iErrorMessage);
  void InternalSetWarning(CATOmxSR<CATError> error);
  /**
  * @brief Read errors stored in CATOmyIncidentGroup by Converters,Exporters or Updaters and stores them in m_errorInfo.m_InternalErrors

  * @return S_OK if everything went well
  *         E_FAIL if a pointer to CATError that is stored in the parameter is null
  */
  HRESULT StoreInternalErrorsFromGroup(CATOmyIncidentGroup& iGroup);

  /**
   * @brief Get the GenerationContext
   *
   * @return ViewableGeneration        0x01
   *         LinkableGeneration        0x02
   *         DerivedOutputGeneration   0x04
   *         ViewableGenerationFromXCAD 0x8
   */
  int GetGenerationContext() const;

  // *************************************************************
  //                   Prereq and Subsequent
  // *************************************************************
  CATOmbObjectStreams* GetPrereqOutgoingEdge() {return m_PrereqOutgoingEdge;}
  CATOmbObjectStreams* GetPrereqIngoingEdge()  {return m_PrereqIngoingEdge;}
  CATBaseUnknown*        GetPrereqComponent()  {return ((m_PrereqIngoingEdge)?m_PrereqIngoingEdge->m_Component.Ref():nullptr);}
  // *************************************************************
  //  Generation related info                  
  //  Get and Set the following Objects
  //  - Input Url of the Authoring Stream
  //  - Session Stream Descriptor of the Authoring Stream
  //  - The Extention of the Linkable to generate
  //  - The Extention of the Viewable to Generate
  //  - The Format, Role, PersistencyType, PersistencyName & LateType of the Stream Descriptor of the Authoring Stream
  //
  // *************************************************************
  inline CATVVSUrl& GetInputURL() { return  m_streamSourceInfo.m_InputURL; }
  inline const CATOmxQIPtr<CATIOmbStreamDescriptor>& GetSourceSD() const { return m_streamSourceInfo.m_sourceSD; }
  inline const CATUnicodeString& GetLinkableExtension() const { return m_linkableInfoInfo.m_LinkableExtension; }
  inline const CATUnicodeString& GetLinkableRole() const { return m_linkableInfoInfo.m_LinkableRole; }
  inline const CATUnicodeString& GetViewableExtension() const { return m_viewableInfoInfo.m_ViewableExtension; }
  inline const CATUnicodeString& GetViewableRole() const { return m_viewableInfoInfo.m_ViewableRole; }

  // *************************************************************
  //  Source Stream/File info (all virtual to allow IFC manipulation in CATOmbObjectStreamsForDO)                  
  // *************************************************************
  virtual const CATOmbLoadableDataUniqueKey& GetSourceSDKey() const;
  virtual const CATOmbStreamDescriptorFormat& GetSourceSDFormat() const;
  virtual const CATUnicodeString& GetSourceSDRole() const;
  virtual /*WKN3 aligne moi ca */ CATUnicodeString GetSourceSDExtension();
  virtual HRESULT GetSourceDocument(CATDocument*& oDoc) const;
  virtual CATBoolean IsSourceNative();
  // *************************************************************
  //  Setters                 
  // *************************************************************
  void SetInputURL(const CATVVSUrl&);
  void SetSourceSD(const CATOmxQIPtr<CATIOmbStreamDescriptor>&);
  CATBoolean SetLinkableExtension(const CATUnicodeString&);
  void SetLinkableRole(const CATUnicodeString&);
  CATBoolean SetViewableExtension(const CATUnicodeString&);
  void SetViewableRole(const CATUnicodeString&);

private:
  CATAsyncTrace _IPCSTracer;

  // Caller Cannot pass a CATUnicodeString as an argument
  // This "hack" will show access denied to private function error
  template<typename T>
  HRESULT SetExternalFileForGeneration(T);


  CATOmbObjectStreams(CATOmbObjectStreams&);
  CATOmbObjectStreams& operator=(CATOmbObjectStreams&);
};

#endif // CATOmbObjectStreams_H
