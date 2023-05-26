// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATIPLMCompProviderRestrictedAccess.h
// To manage specific access to provider internal data
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  May 2003  Creation: Code generated by the CAA wizard  xjt
//===================================================================
/**
* @level Private
* @usage U3
*/
#ifndef CATIPLMCompProviderRestrictedAccess_H
#define CATIPLMCompProviderRestrictedAccess_H

#include "CATPLMServicesRestrictedAccess.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesRestrictedAccess IID IID_CATIPLMCompProviderRestrictedAccess;
#else
extern "C" const IID IID_CATIPLMCompProviderRestrictedAccess ;
#endif

#include "CATListOfCATBinary.h"
#include "CATLISTV_CATPLMID.h"
#include "CATError.h"
#include "CATLISTV_CATPLMCEStamp.h"
#include "CATPLMID.h"
#include "CATOmxOMap.h"
#include "CATDbdGlassBoxInfo.h"
#include "CATPLMRepositoryName.h"
#include "CATPLMOmxCollections.h"

/**
* Adapter interface to access internal provider data.
*/
class ExportedByCATPLMServicesRestrictedAccess CATIPLMCompProviderRestrictedAccess: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  enum OrchestrationDefines
  {
    PSN,                 //V4
    PUBSUB,              //V4
    VPMUUID_LST,         //V4
    VPMNav,             //V5
    UNKNOWN
  };

  /**
  *   Returns PLMID based on binary provider dependent data.
  *   <Note> : The output list indexes are based on the inputs list indexes.
  *   @param iBinInputs
  *     List of binary inputs
  *   @param  oPLMIdentifiers 
  *     List of resulting PLMID based on each inputs.
  *   @param  iRepo
  *     The provider on which the service will be call. The provider must be connected.
  *     If not set, the current connection will be used.
  *   @return
  *     <S_OK>    : All inputs have been successfuly translated
  *     <S_FALSE> : Some inputs have not been translated. Corresponding PLMID can be unusable.
  *     <E_NOTIMPL> : The repository does not support the service.
  *     <E_FAIL>  : Communication problem with the repository or not possible to find a good Repository.
  */    
  virtual HRESULT GetPLMIDFromProviderIdentifiers ( const CATListOfCATBinary &iBinInputs,
    CATPLMIDs &oPLMIdentifiers,
    CATPLMRepositoryName *iRepo=NULL ) =0;

  /**
  *   Returns binary provider dependent data based on PLMID.
  *   <Note> : The output list indexes are based on the inputs list indexes.
  *   @param  iPLMIdentifiers 
  *     List of inputs PLMID.
  *   @param oBinOutputs
  *     List of binary outputs based on each inputs.
  *   @param  iRepo
  *     The provider on which the service will be call. The provider must be connected.
  *     If not set, the current connection will be used.
  *   @return
  *     <S_OK>    : All inputs have been successfuly translated
  *     <S_FALSE> : Some inputs have not been translated. Corresponding CATBinary are empty.
  *     <E_NOTIMPL> : The repository does not support the service.
  *     <E_FAIL>  : Communication problem with the repository or not possible to find a good Repository.
  */    
  virtual HRESULT GetProviderIdentifiersFromPLMID ( const CATPLMIDs &iPLMIdentifiers,
    CATListOfCATBinary &oBinOutputs,
    CATPLMRepositoryName *iRepo=NULL ) =0;

  /**
  * On M1, the logical id stores 2 informations: versioning + cloning.
  * On others DS providers (3DXML,TSTPROVIDER...), the logical id only stores 1 information: versioning (2 objets of the same version family have the same logical id).
  * Suppose you are connected on a provider developped by a competitor or any DS provider that doesn't store versioning on the logical id,
  * we have to provide a way to associate the PLMID to the version stored by this PDM.
  *
  * This method gives the ability to associate the versioning information stored by a PDM (PDM that doesn't store versioning on the logical id) and the PLMID.
  *
  *  @param iPLMIdentifiers
  *    List of inputs PLMID.
  *  @param  oBinInputs
  *    Versioning information stored by PDM developped by a competitor.
  *   @param  iRepo
  *    The provider on which the service will be call. The provider must be connected.
  *    If not set, the current connection will be used.
  *  @return
  *   <S_OK>    : All inputs have been successfuly translated
  *   <E_FAIL>  : Communication problem with the repository or not possible to find a good Repository.
  *   <E_NOTIMPL> : The repository does not support the service.
  */
  virtual HRESULT GetProviderVersionFamiliesFromPLMIDs( const CATPLMIDs & iPLMIdentifiers ,
    CATListOfCATBinary &oBinInputs ,
    const CATPLMRepositoryName & iRepo ) = 0;

  /**
  * On M1, the logical id stores 2 informations: versioning + cloning.
  * On others DS providers (3DXML,TSTPROVIDER...), the logical id only stores 1 information: versioning.
  * Suppose you are connected on a PDM developped by a competitor or any DS provider that doesn't store versioning on the logical id,
  * we have to provide a way to associate the PLMID to the version stored by this PDM.
  *
  * This method gives the ability to associate the versioning information stored by a PDM (PDM that doesn't store versioning on the logical id) and the PLMID.
  *
  *  @param  iBinInputs
  *    Versioning information stored by PDM developped by a competitor.
  *  @param oPLMIdentifiers
  *    List of inputs PLMID.
  *   @param  iRepo
  *    The provider on which the service will be call. The provider must be connected.
  *    If not set, the current connection will be used.
  *  @return
  *   <S_OK>    : All inputs have been successfuly translated
  *   <E_FAIL>  : Communication problem with the repository or not possible to find a good Repository.
  *   <E_NOTIMPL> : The repository does not support the service.
  */
  virtual HRESULT GetPLMIDsFromProviderVersionFamilies( const CATListOfCATBinary &iBinInputs ,
    CATPLMIDs & oPLMIdentifiers ,
    const CATPLMRepositoryName & iRepo ) = 0;

  virtual HRESULT GetProvidersIdentifiersFromFileIds( const CATListOfCATBinary & iBinPointing,
    const CATListOfCATBinary & iBinPointed,
    CATListOfCATBinary & oBinOutputs,
    const CATPLMRepositoryName & iRepo) = 0;

  /**
  *  @param  iRepresentations
  *    List of rep PLMID to get the context from.
  *  @param oContextObjects
  *    List of outputs PLMID from the context.
  *  @param  oContextObjectsCEStamp
  *    The list of stamp of the context objects.
  *  @param  oTrees
  *    The list of index of context objects used for each of the representations.
  *   @param  iRepo
  *    The provider on which the service will be call. The provider must be connected.
  *    If not set, the current connection will be used.
  */
  virtual HRESULT GetContextFromRepresentations( const CATPLMIDs & iRepresentations,
    CATPLMIDs & oContextObjects,
    CATPLMCEStamps &oContextObjectsCEStamp,
    CATListOfInt *&oTrees,
    const CATPLMRepositoryName & iRepo ) = 0;

  /**
  * On M1, the logical id stores 2 informations: versioning + cloning.
  * On others DS providers (3DXML,TSTPROVIDER...), the logical id only stores 1 information: versioning (2 objets of the same version family have the same logical id).
  * Suppose you are connected on a PDM developped by a competitor:
  * On this PDM, logical id has no sense. Versioning informations are stored differently.
  *
  * Ability to associate the versioning information stored by the PDM developped by a competitor and the PLMID.
  *
  *  @param iPLMIdentifiers
  *    List of inputs PLMID.
  *  @param  oBinOutputsMajorInfos
  *   Major Versioning information stored by PDM developped by a competitor.
  *  @param  oBinOutputsMajorInfos
  *   Minor Versioning information stored by PDM developped by a competitor.
  *  @param  iRepo
  *    The provider on which the service will be call. The provider must be connected.
  *    If not set, the current connection will be used.
  *  @return
  *   <S_OK>    : All inputs have been successfuly translated
  *   <E_FAIL>  : Communication problem with the repository or not possible to find a good Repository.
  *   <E_NOTIMPL> : The repository does not support the service.
  */
  virtual HRESULT GetProviderVersionInfosFromPLMIDs( const CATPLMIDs & iPLMIdentifiers,
    CATListOfCATBinary &oBinOutputsMajorInfos, 
    CATListOfCATBinary &oBinOutputsMinorInfos,
    const CATPLMRepositoryName & iRepo ) = 0;


  /**
  * On M1, the logical id stores 2 informations: versioning + cloning.
  * On others DS providers (3DXML,TSTPROVIDER...), the logical id only stores 1 information: versioning (2 objets of the same version family have the same logical id).
  * Suppose you are connected on a PDM developped by a competitor:
  * On this PDM, logical id has no sense. Versioning informations are stored differently.
  *
  * Ability to associate the versioning information stored by the PDM developped by a competitor and the PLMID.
  *
  *  @param iPLMIdentifiers
  *    List of inputs PLMID.
  *  @param  iBinOutputsMajorInfos
  *   Major Versioning information stored by PDM developped by a competitor.
  *  @param  iBinOutputsMajorInfos
  *   Minor Versioning information stored by PDM developped by a competitor.
  *  @param  iRepo
  *    The provider on which the service will be call. The provider must be connected.
  *    If not set, the current connection will be used.
  *  @return
  *   <S_OK>    : All inputs have been successfuly translated
  *   <E_FAIL>  : Communication problem with the repository or not possible to find a good Repository.
  *   <E_NOTIMPL> : The repository does not support the service.
  */
  virtual HRESULT SetProviderVersionInfosToPLMIDs( const CATPLMIDs & iPLMIdentifiers,
    const CATListOfCATBinary &iBinInputsMajorInfos, 
    const CATListOfCATBinary &iBinInputsMinorInfos,
    const CATPLMRepositoryName & iRepo ) = 0;

  /**
  *  @param  iRefAndRepPLMIDs
  *    List of rep and rep ref PLMID exposed objects information is retrieved from.
  *  @param oExposedDataMigrator
  *    Exposed object information returned under the form of a VPMIExposedDataMigrator object
  */
  virtual HRESULT GetExposedDataMigrator(CATPLMIDs &iRefAndRepPLMIDs, 
    CATBaseUnknown* & oExposedDataMigrator,
    const CATPLMRepositoryName & iRepo) = 0;

  /** 
  * Completes the scope built by RepScopeBuilder with the associated configured connections.
  *
  *
  * @param iListPLMIDs [input]
  *   The list of PLMIDs to be transferred (all types) is passed as input. This list has been built by
  *   RepScopeBuilder. st doesn't contain the Configuration connections, VPMCfgEffectivity.
  * @param oListPLMIDsCompletedWithConfig [outpout]
  *   The input list is completed in the implementation with the configured connection, VPMCfgEffectivity.
  *
  * @param oError [out]
  *           In case of error, an end-user error that can be displayed in an error panel.
  *
  * @return
  *   <code>S_OK</code>Scope building is successful.
  *   <code>S_FALSE</code>Scope Building raised an error to check.
  *   <code>E_FAIL</code>Scope building failed.
  *
  */
  virtual HRESULT CompleteScopeToTransferWithConfig( const CATPLMIDs& iListPLMIDs, 
    CATPLMIDs& oListPLMIDsCompletedWithConfig,  
    CATError*& oError,
    const CATPLMRepositoryName & iRepo ) = 0;


  typedef CATOmxOMap<CATPLMID, CATDbdGlassBoxInfo,CATOmxDefaultCollecManager< CATPLMID >::manager,CATOmxDefaultCollecManager< CATDbdGlassBoxInfo >::manager > CATDbdMapGBInfo;
  /** 
  * Return the internal names and internal IDs of every internal components. Used to correlate Exposed structure with the BlackBox
  * in GlassBox mode.
  *
  *
  * @param ioMapInternalInfo [input/output]
  *   Map binding a component PLMID with the names and IDs of its internal components
  * @return
  *   <code>S_OK</code>Success.
  *   <code>E_FAIL</code>Unknown error occured.
  *
  */
  virtual HRESULT GetListOfInternalNamesFromRepPLMIDs(CATDbdMapGBInfo &ioMapInternalInfo, const CATPLMRepositoryName &iRepo) = 0;

  /**                                        
  * Required after Batch server mode: Informs provider that next batch job is to be started..                                       
  * Called to perform/check :                                       
  * - if various static cache of a Provider are cleaned                                         
  * - Required processing for setting of Environment Variables                                  
  *                                             
  * @param iBatchName [input]                                                 
  * Name of the Batch (like CoexistenceV5V6).. Can be useful in some context                                  
  * @return                                          
  * <code>S_OK</code>Success when session is ‘clean’ and fully ready for a new transaction, including the Successful processing for Env Vars                                           
  * <code>S_FALSE </code> if not implemented by the connector                                              
  * <code>E_FAIL</code>In case of trouble when preparing the session for a new transaction                                     
  *                                             
  */                                           
  virtual HRESULT StartBatchSrvModeTransaction (CATString & iBatchName,const CATPLMRepositoryName & iRepoName = CATPLMRepositoryName_Null) = 0;                                                

  /**                                        
  * Required after Batch server mode: Informs provider that current batch job has ended..                                           
  * Called to perform:                                      
  * - clean/re-initialize various static cache of a Provider                                                
  *                                             
  * @return                                          
  * <code>S_OK</code>Clean up data to close the transaction                                     
  * <code>S_FALSE </code> if not implemented by the connector                                              
  * <code>E_FAIL</code> In case of trouble when ending the transaction                                              
  *                                             
  */                                           
  virtual HRESULT EndBatchSrvModeTransaction(const CATPLMRepositoryName & iRepoName = CATPLMRepositoryName_Null) = 0;

  /**/
  virtual HRESULT GetListOfPLMIDFromFile(OrchestrationDefines  iFileType,
    const CATUnicodeString & iusiFilePath,
    CATListValCATPLMID     & oPLMIdentifiers,
    CATUnicodeString       & ousReportMessage,
    const CATPLMRepositoryName& iRepo) = 0;

  /**/
  virtual HRESULT GetDrawingLinksInformation(CATPLMSequenceOfOctetToArrayOfBin &ioMapDrawingInfo, const CATPLMRepositoryName& iRepo) = 0;
};

#endif