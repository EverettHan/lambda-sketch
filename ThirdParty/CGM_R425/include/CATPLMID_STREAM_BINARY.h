#ifndef CATPLMID_STREAM_BINARY_H 
#define CATPLMID_STREAM_BINARY_H
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// -----------------------------------------------------------------------------------------------------------
#define AuthorizedModule                       999
#define CATPLMIdentifier                       AuthorizedModule
#define CATPLMTos                              AuthorizedModule
#define CATOxiPLMId                            AuthorizedModule
#define CATDCInfraMappingTbl                   AuthorizedModule
#define CATFbdMappingTable                     AuthorizedModule
#define CATOmbMigrationAccess                  AuthorizedModule
#define CATPLMId_ABCoverage                    AuthorizedModule
#define CATPXnMarshallingFactory               AuthorizedModule
#define TransitionEngine                       AuthorizedModule
#define AC0XXLNK                               AuthorizedModule
#define CATOmbLinkTrader                       AuthorizedModule
#define CATOmbSelectiveLoading                 AuthorizedModule
#define SelectiveLoadingTST_RepRefTSTImpl      AuthorizedModule
#define CATxPDMLog                             AuthorizedModule
#define CATPLMTosPending                       AuthorizedModule
#define PLMPosCltSetModel                      AuthorizedModule
#define CATPLMTagDB                            AuthorizedModule
#define CATVPMV4Services                       AuthorizedModule
#define CATPLMSmarTeam1ProviderImpl            AuthorizedModule
#define PLMBatchVPLMServices                   AuthorizedModule
#define CATPLMTosStream                        AuthorizedModule
#define CoexistenceAdmin                       AuthorizedModule
#define CAT3DXMLEngine                         AuthorizedModule
#define CATOxiPLMIDBuildersAndMarshallers      AuthorizedModule
#define CoexApplicativeMapping                 AuthorizedModule
#define CATFmtToolsServices                    AuthorizedModule
#define CATPLMImplAdapterQLBase                AuthorizedModule
#define CATLowCostPLMBatch                     AuthorizedModule
#define CATScriptPLMContainers                 AuthorizedModule
#define CATUFO                                 AuthorizedModule
#define CATOmbLinks                            AuthorizedModule
#define CATPLMIndexSimilarServices             AuthorizedModule
#define CAT3DAppSimilarSearch                  AuthorizedModule
#define CATPLMToolkit                          AuthorizedModule
#define CATPLMImplAdapterClass                 AuthorizedModule
#define CATPLMIntegration                      AuthorizedModule
#define CATPLMImplAdapterBase                  AuthorizedModule
#define CATPLMServicesItf                      AuthorizedModule
#define PLMOccurrenceBase                      AuthorizedModule
#define CATPLMEditabilityImpl                  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMID_STREAM_BINARY from a non-infrastructure module
@error 
#endif

#undef AuthorizedModule
#undef CATPLMIdentifier
#undef CATPLMTos
#undef CATOxiPLMId
#undef CATDCInfraMappingTbl
#undef CATFbdMappingTable
#undef CATOmbMigrationAccess
#undef CATPLMId_ABCoverage
#undef CATPXnMarshallingFactory
#undef TransitionEngine
#undef AC0XXLNK
#undef CATOmbLinkTrader
#undef CATOmbSelectiveLoading
#undef SelectiveLoadingTST_RepRefTSTImpl
#undef CATxPDMLog
#undef CATPLMTosPending
#undef PLMPosCltSetModel
#undef CATPLMTagDB
#undef CATVPMV4Services
#undef CATPLMSmarTeam1ProviderImpl
#undef PLMBatchVPLMServices
#undef CATPLMTosStream
#undef CoexistenceAdmin
#undef CAT3DXMLEngine
#undef CATOxiPLMIDBuildersAndMarshallers
#undef CoexApplicativeMapping
#undef CATFmtToolsServices
#undef CATPLMImplAdapterQLBase    
#undef CATLowCostPLMBatch
#undef CATScriptPLMContainers
#undef CATUFO
#undef CATOmbLinks
#undef CATPLMIndexSimilarServices
#undef CAT3DAppSimilarSearch
#undef CATPLMToolkit
#undef CATPLMImplAdapterClass
#undef CATPLMIntegration
#undef CATPLMImplAdapterBase
#undef CATPLMServicesItf
#undef PLMOccurrenceBase
#undef CATPLMEditabilityImpl

// ----------------------------------------------------------------------------------------------------------
#include "CATPLMIdentificationAccess.h"
#include "CATPLMIDMAXFormatVersion.h"
#include "IUnknown.h"

class CATBinary;
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
class ExportedByCATPLMIdentificationAccess CATPLMID_STREAM_BINARY
{
public:

  /**
  * Sream the contents of PLMID
  *
  * @param iPLMID
  *        The PLMID to be streamed
  * @param oBytes
  *        The binary result
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : otherwise
  */
  static  HRESULT  Stream(const CATPLMID             & iPLMID,
                          CATBinary                  & oBytes,
                          const BYTE                   iMessageVersion=CATPLMIDMAXFormatVersion_MinorMajorCompatibility);
  
  /**
  * Unstream the contents of PLMID
  *
  * @param iBytes
  *        The binary
  * @param oPLMID
  *        The PLMID
  * @param oMessageVersion
  *        The version
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : otherwise
  */
  static  HRESULT  Unstream(const CATBinary & iBytes,
                            CATPLMID        & oPLMID,
                            BYTE            * oMessageVersion=NULL);

};

#endif

