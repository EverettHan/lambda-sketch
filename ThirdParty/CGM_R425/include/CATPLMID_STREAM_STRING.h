#ifndef CATPLMID_STREAM_STRING_H 
#define CATPLMID_STREAM_STRING_H
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// -----------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIdentifier                  AuthorizedModule
#define CATPLMTos                         AuthorizedModule
#define CATOxiPLMId                       AuthorizedModule
#define CATPLMId_ABCoverage               AuthorizedModule
#define CATPLMDebugServices               AuthorizedModule
#define CATPLMDebugProviderImpl           AuthorizedModule
#define TstTestEngineUtilities            AuthorizedModule
#define CATFavoritesDBPersistency         AuthorizedModule
#define CATFavoritesStreamServices        AuthorizedModule
#define CATPLMSpecServices                AuthorizedModule
#define CATFavODTModelUtils               AuthorizedModule
#define CATBusManager                     AuthorizedModule
#define CATImmIGCommands                  AuthorizedModule
#define CATImmIGDocument                  AuthorizedModule
#define CATSMTOpenEngineImpl              AuthorizedModule
#define CATSMTOpenCmd                     AuthorizedModule
#define CATOpenImpl                       AuthorizedModule
#define CATPLMQL_Visitor                  AuthorizedModule
#define TransitionEngineBatch             AuthorizedModule
#define CoexistenceBatchUI                AuthorizedModule
#define CATPLMImplAdapterBase             AuthorizedModule
#define CATPLMMessages                    AuthorizedModule
#define CATPLMxODTBase                    AuthorizedModule
#define PLM3DSearchAsync                  AuthorizedModule
#define CATImmNavCollab                   AuthorizedModule
#define CATImmNavigatorsUI                AuthorizedModule
#define CATPLMUIEditability               AuthorizedModule
#define CATPLMErrorEditability            AuthorizedModule
#define CATInstantCollabService           AuthorizedModule
#define CATVPMNavPLMAccessBase            AuthorizedModule
#define DNBPPRSessionTST                  AuthorizedModule
#define CATPLMWorkspaceImplCompEngine     AuthorizedModule
#define DNBPPRSessionTST                  AuthorizedModule
#define CATAuthoringCollaborationBase     AuthorizedModule
#define CATCfgXMLExprParser               AuthorizedModule
#define PLMProposal                       AuthorizedModule
#define CATPLMTemplates                   AuthorizedModule
#define BatchV4V6                         AuthorizedModule
#define PLMBatchV4ToV6UI                  AuthorizedModule
#define CATUFO                            AuthorizedModule
#define CATXPLMDataSet                    AuthorizedModule
#define CATOxiPLMIDBuildersAndMarshallers AuthorizedModule
#define CATOxiMinorMajor									AuthorizedModule
#define CATPLMBatchPLMIDRegeneration			AuthorizedModule
#define CATFmtToolsServices               AuthorizedModule
#define CATCfgXMLFilterParser             AuthorizedModule
#define CATPLMWorkspaceCmd                AuthorizedModule
#define TSTPlmidTool                      AuthorizedModule
#define CATImmVPMNavCollab                AuthorizedModule
#define PLMExchangeExperienceModel        AuthorizedModule
#define CATPLMModelBuilder                AuthorizedModule
#define CATCfgFavoritePVSMigrationBatch   AuthorizedModule
#define CATPLMReplicationEngineBase       AuthorizedModule
#define CATPLMOfflineContentBase          AuthorizedModule
#define CATOmbTestLib_PLM                 AuthorizedModule
#define CATPLMConfigUIAuthItf             AuthorizedModule
#define CATOmbTestLoadPipeline_M1         AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMID_STREAM_STRING if not authorized by infrastructure team
@error
#endif
#undef CATPLMIdentifier
#undef CATPLMTos
#undef CATOxiPLMId
#undef CATPLMId_ABCoverage
#undef CATPLMDebugServices
#undef CATPLMDebugProviderImpl
#undef TstTestEngineUtilities
#undef CATFavoritesDBPersistency
#undef CATFavoritesStreamServices
#undef CATPLMSpecServices
#undef CATFavODTModelUtils
#undef CATBusManager
#undef CATImmIGCommands
#undef CATImmIGDocument
#undef CATSMTOpenEngineImpl
#undef CATSMTOpenCmd
#undef CATOpenImpl
#undef CATPLMQL_Visitor
#undef TransitionEngineBatch
#undef CoexistenceBatchUI
#undef CATPLMImplAdapterBase
#undef CATPLMMessages
#undef CATPLMxODTBase
#undef PLM3DSearchAsync
#undef CATImmNavCollab
#undef CATImmNavigatorsUI
#undef CATPLMUIEditability
#undef CATPLMErrorEditability
#undef CATInstantCollabService
#undef CATVPMNavPLMAccessBase
#undef DNBPPRSessionTST
#undef CATPLMWorkspaceImplCompEngine
#undef DNBPPRSessionTST
#undef CATAuthoringCollaborationBase
#undef CATCfgXMLExprParser
#undef PLMProposal
#undef CATPLMTemplates
#undef BatchV4V6
#undef PLMBatchV4ToV6UI
#undef CATUFO
#undef CATXPLMDataSet
#undef CATOxiPLMIDBuildersAndMarshallers
#undef CATOxiMinorMajor
#undef CATPLMBatchPLMIDRegeneration
#undef CATFmtToolsServices
#undef CATCfgXMLFilterParser
#undef CATPLMWorkspaceCmd
#undef TSTPlmidTool
#undef CATImmVPMNavCollab
#undef PLMExchangeExperienceModel        
#undef CATPLMModelBuilder
#undef CATCfgFavoritePVSMigrationBatch
#undef CATPLMReplicationEngineBase 
#undef CATPLMOfflineContentBase
#undef CATOmbTestLib_PLM
#undef CATPLMConfigUIAuthItf
#undef CATOmbTestLoadPipeline_M1


// ----------------------------------------------------------------------------------------------------------
#include "CATPLMIdentificationAccess.h"
#include "CATPLMIDMAXFormatVersion.h"
#include "IUnknown.h"

class CATString;
class CATPLMID;

/**
* This mashalling format is restricted to a very specific infrastructure usage.
* It is STRICTLY FORBIDDEN to store this stream inside PLM persistency.
* For example :
* - Don't stored this format inside a PLM Attribute
* - Don't stored this format into a binary stored in vault
* If you don't respect this rules, your data will be strongly corrupted.
* It means :
* - No versioning
* - No cloning
* - No Import-Export
* - No Impact Graph integration
* - No MLC between 2 Major releases
* - ...
*/
class ExportedByCATPLMIdentificationAccess CATPLMID_STREAM_STRING
{
public:

  /**
  * Sream the contents of PLMID
  *
  * @param iPLMID
  *        The PLMID to be streamed
  * @param oString
  *        The string result
  * @param iMessageVersion
  *        The version to be generated
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : otherwise
  */
  static  HRESULT  Stream(const CATPLMID& iPLMID,
    CATString& oString,
    const BYTE                   iMessageVersion = CATPLMIDMAXFormatVersion_MinorMajorCompatibility);

  /**
  * Unstream the contents of PLMID
  *
  * @param iString
  *        The string
  * @param oPLMID
  *        The PLMID
  * @param oMessageVersion
  *        The version
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : otherwise
  */
  static  HRESULT  Unstream(const CATString& iString,
    CATPLMID& oPLMID,
    BYTE* oMessageVersion = NULL);
};

#endif
