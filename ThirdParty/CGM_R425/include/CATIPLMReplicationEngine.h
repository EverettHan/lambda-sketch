// COPYRIGHT Dassault Systemes 2005-2015
//===================================================================
//
// CATIPLMReplicationEngine.h
// Define the CATIPLMReplicationEngine interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  April     2005  Creation:      PFI
//  September 2015  Modificiation: JLM  Object: Cleaning of comments and add options at Publish 
//===================================================================
#ifndef CATIPLMReplicationEngine_H
#define CATIPLMReplicationEngine_H

/**
  * @level Protected
  * @usage U3
  */

#include "CATPLMIntegrationInterfaces.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATIAV5Level.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMReplicationEngine;
#else
extern "C" const IID IID_CATIPLMReplicationEngine ;
#endif

#include "CATCollec.h"

class CATLISTV(CATPLMIdentifier)     ;
class CATLISTP(CATPLMPackageSpec)    ;
class CATLISTV(CATPLMID)             ;
class CATPLMRepositoryName           ;
class CATIPLMCompleteGraph           ;
class CATIPLMBriefcaseHeader         ;
class CATUnicodeString               ;
class CATPLMREBusinessCard           ;
class CATPLMREBriefcaseImportOptions ;
class CATPLMREBriefcaseExportOptions ;
class CATIPLMREExchangeForm;
//------------------------------------------------------------------

/**
  * Interface associated with the Replication Engine.
  * <br><b>Role</b>: it describes how the ReplicationEngine has to be used by its client
  *   
  * <p><b>1.	Definition of the ReplicationEngine</b>
  * 
  * <br>The ReplicationEngine provides all the services necessary to handle replication.
  * <br> - The Change site ownership : Allowing to transfer the ownership of an object to another site.
  * <br> - The Capture : Allowing to collect all the data that need to be replicated to another site
  * <br> - The Apply : Allowing to insert in the current site replicated data comming from another site
  * <br> - The Acknowledge : Allowing to insert the acklowledgement comming from a replicated site.
  * <br> - The Reclaim Ownership : Allowing to force a local ownership if it has been lost during a transfer.
  * <br><br>
  * Additionally, it provides the capability to copy components from a repository to another:
  * <br> - ExportToBriefcase: Generates a file containing the components extracted from repository A.
  * <br> - ImportBriefcaseAsNew: Imports in repository B the content of the file by creating new objects.
  * 
  * <p><b>2.	Access to the ReplicationEngine</b>
  * <br> This interface is returned by the @href CATPLMEnginesToolbox#GetReplicationEngine method .
  * 
  * @see CATPLMEnginesToolbox
  */
class ExportedByCATPLMIntegrationInterfaces CATIPLMReplicationEngine : public CATBaseUnknown
{
   CATDeclareInterface ;

   public:

    /**
      * Exportable status of a set of PLM entities
      * <tt> Possible values:</tt>
      * <dl>
      * <dt>@param Exportable</dt>           <dd>This set of PLM entitites can be exported.</dd>
      * <dt>@param HeterogeneousList</dt>    <dd>This set of PLM entities can not be exported because it contains PLM entities from different providers.</dd>
      * <dt>@param UnsupportedProvider</dt>  <dd>This set of PLM entities can not be exported because it contains entities belonging to a provider that does not support PLMBriefcase export.</dd>
      * <dt>@param UnsupportedModeler</dt>   <dd>This set of PLM entities can not be exported because it contains entities belonging to a modeler that does not support PLMBriefcase export.</dd>
      * </dl>
      */
      enum CATPLMExportableStatus 
      {
        Exportable         = 0
      , HeterogeneousList  = 1
      , UnsupportedProvider= 2
      , UnsupportedModeler = 3
      } ;

      /** 
      * Briefcase exchange compatibility mode:
      * 
      * @param UpwardCompatibility
      *   Upward compatibility mode.
      * @param DownwardCompatibility
      *   Downward compatibility mode.
      * @param DownwardCompatibility_NotSupported
      *   Downward compatibility mode but target level not supported.
      * @param SameLevel
      *   Exchange on same level.
      */
      enum CATPLMExchangeCompatibilityMode
      {
           Undefined                          = 0
         , UpwardCompatibility                = 1
         , DownwardCompatibility              = 2
         , DownwardCompatibility_NotSupported = 3
         , SameLevel                          = 4
      } ;

    /**
      * Tests if a set of PLM components can be exported to a PLMBriefcase.
      * <br><b>Role:</b>This method analyses a list of component identifiers to check if they can be exported to a PLMBriefcase.
      * @param iComponents
      *   A list of PLMIDs describing the PLM entities that need to be exported. 
      * @param oStatus
      *   The status of this set of PLM components (see CATPLMExportableStatus)
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>   <dd>The provided PLM components can be exported.</dd>
      *   <dt>S_OK</dt>   <dd>The provided PLM components can not be exported.</dd>
      *   <dt>E_FAIL</dt> <dd>The provided list is empty or the method failed for an unexpected reason.</dd>
      * </dl>
      */ 
      virtual HRESULT IsExportSupported( CATLISTV(CATPLMID)     & iComponents
                                       , CATPLMExportableStatus & oStatus ) = 0 ;

    /**
      * Gets downward compatibility levels.
      * <br><b>Role:</b>This method allows to get the downward compatibility levels.
      * @param oListOfCompatibleLevels
      *   A list compatibility levels. 
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>   <dd>Success.</dd>
      *   <dt>E_FAIL</dt> <dd>Fail.</dd>
      * </dl>
      */ 
      virtual HRESULT GetDownwardCompatibilityLevels( CATListOfCATUnicodeString & oListOfCompatibleLevels ) = 0 ;

    /**
      * Compute exchange mode: downward, upward, supported or not.
      * <br><b>Role:</b>This method allows to get the compatibility mode.
      * @param ipHeader
      *   Header of Briefcase. 
      * @param oCompatibilityExchangeMode
      *   Exchange mode: upward, downward (supported or not), same level. 
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>   <dd>Success.</dd>
      *   <dt>E_FAIL</dt> <dd>An unexpected error occurred.</dd>
      * </dl>
      */
      virtual HRESULT GetCompatibilityExchangeMode( CATIPLMBriefcaseHeader          * ipHeader
                                                  , CATPLMExchangeCompatibilityMode & oCompatibilityExchangeMode ) = 0 ;

    /**
      * Exports a set of components to a Briefcase file.
      * <br><b>Role:</b>Generates a briefcase that that can be imported in another repository through the @href CATIPLMReplicationEngine#ImportBriefcaseAsNew method.
      * <br>All components in the list should belong to the same repository. 
      * <br>It is advised to complete the list of components with an "integrity" complete-graph to make sure the briefcase can be imported in any repository.
      * <br>The client should be already connected to the repository.
      * @param iBriefcasePath
      *   Local path where the briefcase must be generated
      * @param ipComponents
      *   A list of PLMIDs describing the PLM entities that need to be exported. Some of the PLM entities might be in a "deleted" state.
      * @param iBriefcaseHeader
      *   Optional briefcase header information initialized by the client 
      * @param iExportOptions
      *   Optional export parameters.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The export operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The export operation failed because at least one component could not be exported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument </dd>
      * </dl>
      */ 
      virtual HRESULT ExportToBriefcase( const CATUnicodeString         & iBriefcasePath
                                       , CATLISTV(CATPLMID)             & iComponents
                                       , CATIPLMBriefcaseHeader         * ipBriefcaseHeader = NULL
                                       , CATPLMREBriefcaseExportOptions * iExportOptions    = NULL ) = 0 ;
    /**
      * Exports a set of components to a Briefcase file.
      * <br><b>Role:</b>Generates a briefcase that that can be imported in another repository through the @href CATIPLMReplicationEngine#ImportBriefcaseAsNew method.
      * <br>All components in the list should belong to the same repository. 
      * <br>It is advised to complete the list of components with an "integrity" complete-graph to make sure the briefcase can be imported in any repository.
      * <br>The client should be already connected to the repository.
      * @param iBriefcasePath
      *   Local path where the briefcase must be generated
      * @param iComponents
      *   A list of PLMIDs describing the PLM entities that need to be exported. Some of the PLM entities might be in a "deleted" state.
      * @param iComponentsToDelegate
      *   A list of PLMIDs describing the PLM entities that need to be exported with delegation.
      * @param iComponentsToWaive
      *   A list of PLMIDs describing the PLM entities that need to be exported with waive.
      * @param ipBriefcaseHeader
      *   Optional briefcase header information initialized by the client 
      * @param iExportOptions
      *   Optional export parameters.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The export operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The export operation failed because at least one component could not be exported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument </dd>
      * </dl>
      */ 
      virtual HRESULT ExportToBriefcase( const CATUnicodeString         & iBriefcasePath
                                       , CATLISTV(CATPLMID)             & iComponents
                                       , CATLISTV(CATPLMID)             & iComponentsToDelegate
                                       , CATLISTV(CATPLMID)             & iComponentsToWaive
                                       , CATIPLMBriefcaseHeader         * ipBriefcaseHeader = NULL
                                       , CATPLMREBriefcaseExportOptions * iExportOptions    = NULL ) = 0 ;

      /**
      * Exports a set of components to a Briefcase file.
      * <br><b>Role:</b>Generates a briefcase that that can be imported in another repository through the @href CATIPLMReplicationEngine#ImportBriefcaseAsNew method.
      * <br>All components in the complete graph should belong to the same repository.
      * <br>The client should be already connected to the repository.
      * @param iBriefcasePath
      *   Local path where the briefcase must be generated
      * @param ipCompleteGraph
      *   Mandatory Complete Graph defining the components to be exported
      * @param iBriefcaseHeader
      *   Optional briefcase header information initialized by the client 
      * @param iExportOptions
      *   Optional export parameters.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The export operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The export operation failed because at least one component could not be exported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument </dd>
      * </dl>
      */ 
      virtual HRESULT ExportToBriefcase( const CATUnicodeString         & iBriefcasePath
                                       , CATIPLMCompleteGraph           * ipCompleteGraph
                                       , CATIPLMBriefcaseHeader         * ipBriefcaseHeader = NULL
                                       , CATPLMREBriefcaseExportOptions * iExportOptions    = NULL ) = 0 ;

    /**
      * Exports a set of components to a Briefcase file.
      * <br><b>Role:</b>Generates a briefcase that that can be imported in another repository through the @href CATIPLMReplicationEngine#ImportBriefcaseAsNew method.
      * <br>All components in the complete graph should belong to the same repository.
      * <br>The client should be already connected to the repository.
      * @param iBriefcasePath
      *   Local path where the briefcase must be generated
      * @param iExportOptions
      *   Optional export parameters.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The export operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The export operation failed because at least one component could not be exported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT ExportToBriefcase( const CATUnicodeString         & iBriefcasePath
                                       , CATPLMREBriefcaseExportOptions & iExportOptions ) = 0 ;

    /**
      * Sets the import environment.
      * <br><b>Role:</b>The import environment is used to choose the custom type of PLM entities created during briefcase import. 
      * <br>SetImportEnvironment should be called prior to import. Available environments can be retrieved through @href CATAdpDictionaryServices#ListEnvironments.
      * @param iEnvironmentName
      *   An environment id chosen among the list returned by ListEnvironments
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>The import environment was successfully set.</dd>
      *   <dt>E_FAIL</dt>  <dd>The service failed for an unexpected reason.</dd>
      * </dl>
      */ 
      virtual HRESULT SetImportEnvironment( const CATUnicodeString & iEnvironmentName ) = 0 ;

    /**
      * @deprecated R207
      * Imports the content briefcase into a repository.
      * <br><b>Role:</b>Imports a briefcase file generated through @href CATIPLMReplicationEngine#ExportToBriefcase. <br>
      * All components are imported as new objects, with a generated PLMID. 
      * The same briefcase can be imported multiple times. The identification set of the objects must then be incremented through prefixing to avoid collisions.<br>
      * The client should be already connected to the repository.<br>
      * @param ipBriefcasePath
      *   Local path of the briefcase to be imported
      * @param iRepositoryName
      *   Name of the repository instance where the data must be imported (client should be connected to this repository)
      * @param iIDSetPrefix
      *   Prefix used to increment identification sets (will be used on first modifiable string attribute). 
      * @param ioImportedEntityIDs
      *   Optional list where PLMIds of the imported entities must be appended.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The import operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The import operation was rolled-backed because at least one component could not be imported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT ImportBriefcaseAsNew( const CATUnicodeString     & iBriefcasePath
                                          , const CATPLMRepositoryName & iRepositoryName
                                          , const CATUnicodeString     & iIDSetPrefix
                                          , CATLISTV(CATPLMID)         * ioImportedEntityIDs = NULL ) = 0 ;

    /**
      * Imports the content briefcase into a repository.
      * <br><b>Role:</b>Imports a briefcase file generated through @href CATIPLMReplicationEngine#ExportToBriefcase. <br>
      * All components are imported as new objects, with a generated PLMID. 
      * The same briefcase can be imported multiple times. The identification set of the objects must then be incremented through prefixing to avoid collisions.<br>
      * The client should be already connected to the repository.<br>
      * @param ipBriefcasePath
      *   Local path of the briefcase to be imported
      * @param iRepositoryName
      *   Name of the repository instance where the data must be imported (client should be connected to this repository)
      * @param iIDSetPrefix
      *   Prefix used to increment identification sets (will be used on first modifiable string attribute). 
      * @param iImportOptions
      *   Optional Import parameters.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The import operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The import operation was rolled-backed because at least one component could not be imported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT ImportBriefcaseAsNew( const CATUnicodeString         & iBriefcasePath
                                          , const CATPLMRepositoryName     & iRepositoryName
                                          , const CATUnicodeString         & iIDSetPrefix
                                          , CATPLMREBriefcaseImportOptions & iImportOptions ) = 0 ;

    /**
      * @deprecated R207
      * Imports the content briefcase into a repository.
      * <br><b>Role:</b>Imports a briefcase file generated through @href CATIPLMReplicationEngine#ExportToBriefcase. <br>
      * If some components already exist in the target repository, they are updated. 
      * The client should be already connected to the repository.<br>
      * @param ipBriefcasePath
      *   Local path of the briefcase to be imported
      * @param iRepositoryName
      *   Name of the repository instance where the data must be imported (client should be connected to this repository)
      * @param ioUpdatedEntityIDs
      *   Optional list where PLMIds of the updated entities must be appended.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The import operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The import operation was rolled-backed because at least one component could not be imported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT ImportBriefcase( const CATUnicodeString     & iBriefcasePath
                                     , const CATPLMRepositoryName & iRepositoryName
                                     , CATLISTV(CATPLMID)         * ioUpdatedEntityIDs = NULL ) = 0 ;

    /**
      * Imports the content briefcase into a repository.
      * <br><b>Role:</b>Imports a briefcase file generated through @href CATIPLMReplicationEngine#ExportToBriefcase. <br>
      * If some components already exist in the target repository, they are updated. 
      * The client should be already connected to the repository.<br>
      * @param ipBriefcasePath
      *   Local path of the briefcase to be imported
      * @param iRepositoryName
      *   Name of the repository instance where the data must be imported (client should be connected to this repository)
      * @param iImportOptions
      *   Optional Import parameters.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The import operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The import operation was rolled-backed because at least one component could not be imported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT ImportBriefcase( const CATUnicodeString         & iBriefcasePath
                                     , const CATPLMRepositoryName     & iRepositoryName
                                     , CATPLMREBriefcaseImportOptions & iImportOptions) = 0 ;

    /**
      * Detach a set of components from a repository. 
      * <br><b>Role:</b>This service removes a set of components that were imported through @href CATIPLMReplicationEngine#ImportBriefcase.
      * <br>Detaching a reference propagates to all its instances and aggregated objects, provided that all of them are detachable.
      * <br>The client should be already connected to the repository.
      * @param iComponentIds
      *   The PLMIDs of the components to be detached. 
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>The components were succesfully detached.</dd>
      *   <dt>E_FAIL</dt>  <dd>The export operation was aborted because at least one component could not be detached. An error message can be obtain through @href CATError#CATGetLastError.</dd>
      * </dl>
      */ 
      virtual HRESULT DetachComponents( const CATLISTV(CATPLMID) & iComponentIds ) = 0 ;

    /**
      * Returns the business card of the current connected repository. 
      * <br><b>Role:</b>This service valuates a business-card with identification information from the current connected repository.
      * <br>The business card can be serialized to a file using @href CATIPLMBriefaseServices#WriteBusinessCardToFile
      * @param opBusinessCard
      *   The business-card object. 
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>The business-card was successfully created.</dd>
      *   <dt>E_FAIL</dt>  <dd>The business card could not be created because of an unexpected error.</dd>
      * </dl>
      */ 
      virtual HRESULT GetConnectedRepoBusinessCard( CATPLMREBusinessCard & oBusinessCard ) = 0 ;


    /**
      * Available capture modes:
      * <ul>
      * <li>Full: Send full RBOs.</li>
      * <li>Incr: Send only elements of RBOs that have been modified (since last aknowledgement).</li>
      * </ul>
      **/
      enum CaptureMode
      {
        Incr = 0
      , Full = 1
      } ;

    /**
      * @deprecated R204
      * Performs a capture operation.
      * @param iLogFileName
      *   Name of the file that will contain the execution log of the capture operation
      * @param iCaptureFileName
      *   Name of the file that will contain the replicated data. Must be left to empty string if iCaptureFileBaseName/iMaxNumberOfRBOs are set.
      * @param iCaptureFileBaseName
      *   Used in conjunction with <tt>iMaxNumberOfRBOs</tt> to generate several capture files instead of one. The genrated files will be named according to the value of iCaptureFileBaseName followed by a number automatically incremented.
      * @param iMaxNumberOfRBOs
      *   Used in conjunction with <tt>iCaptureFileBaseName</tt> to generate several capture files instead of one. This indicates how many RBOs can be stored into a file before switching to the next one.
      * @param iVaultCopyToPath
      *   Directory where the documents extracted from the Vault in order to be replicated will be stored.
      * @param iTargetSiteName
      *   Name of the target site.
      * @param iTransferFileName
      *   Name of the file that will contain the name of the files to transfer to the target site.
      * @param iListPackageSpec
      *   List containing the RBOs to replicate. 
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The capture operation succeeded.</dd>
      *   <dt>E_FAIL</dt>        <dd>The capture operation failed.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */
      virtual HRESULT Capture( const CATUnicodeString            & iLogFileName
                             , const CATUnicodeString            & iCaptureFileName
                             , const CATUnicodeString            & iCaptureFileBaseName
                             , const int                           iMaxNumberOfRBOs
                             , const CATUnicodeString            & iVaultCopyToPath
                             , const CATUnicodeString            & iTargetSiteName
                             , const CATUnicodeString            & iTransferFileName
                             , int                                 iCaptureMode
                             , const CATLISTP(CATPLMPackageSpec) & iListPackageSpec  ) = 0 ;

    /**
      * @deprecated R204
      * Performs a change owner site operation.
      * @param iTargetSiteName
      *   Name of the target site.
      * @param iListPackageSpec
      *   List containing the RBOs to replicate.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The capture operation succeeded.</dd>
      *   <dt>E_FAIL</dt>        <dd>The capture operation failed.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */
      virtual HRESULT ChangeOwnerSite( const CATUnicodeString           & iTargetSiteName
                                     , const CATLISTV(CATPLMIdentifier) & lIdentifiers  ) = 0 ;

    /**
      * @deprecated R204
      * Performs an apply operation. Import in the current site data comming from another site.
      * @param iLogFileName
      *   Name of the file that will contain the execution log of the apply operation
      * @param iApplyFileName
      *   Name of the file that will contain the replicated data.
      * @param iAckowledgeFileName
      *   Name of the acknowledgement file that will be generated.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The apply operation succeeded.</dd>
      *   <dt>E_FAIL</dt>        <dd>The apply operation failed.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */
      virtual HRESULT Apply( const CATUnicodeString & iLogFileName
                           , const CATUnicodeString & iApplyFileName
                           , const CATUnicodeString & iAcknowledgeFileName
                           , const CATUnicodeString & iVaultCopyFromPath ) = 0 ;

    /**
      * @deprecated R204
      * Performs an ackowledge operation. Import in the current site the current status of a replicated site.
      * @param iLogFileName
      *   Name of the file that will contain the execution log of the capture operation
      * @param iAckowledgeFileName
      *   Name of the acknowledgement file that will be generated.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The capture operation succeeded.</dd>
      *   <dt>E_FAIL</dt>        <dd>The capture operation failed.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */
      virtual HRESULT Acknowledge( const CATUnicodeString & iLogFileName
                                 , const CATUnicodeString & iAcknowledgeFileName ) = 0 ;

    /**
      * @deprecated R204
      * Recover from a change owner site operation.
      * @param iListPackageSpec
      *   List containing the RBOs to get the site ownership back.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The reclaim operation succeeded.</dd>
      *   <dt>E_FAIL</dt>        <dd>The reclaim operation failed.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */
      virtual HRESULT ReclaimSiteOwnership( const CATLISTV(CATPLMIdentifier) & lIdentifiers ) = 0 ;

    /**
      * Exports a set of components to a Briefcase file, some of objects with delegation.
      * <br><b>Role:</b>Generates a briefcase that that can be imported in another repository through the @href CATIPLMReplicationEngine#ImportBriefcaseAsNew method.
      * <br>All components in the list should belong to the same repository. 
      * <br>It is advised to complete the list of components with an "integrity" complete-graph to make sure the briefcase can be imported in any repository.
      * <br>The client should be already connected to the repository.
      * @param iBriefcasePath
      *   Local path where the briefcase must be generated
      * @param ipComponents
      *   A list of PLMIDs describing the PLM entities that ALL need to be exported. Some of the PLM entities might be in a "deleted" state.
      * @param iComponentsToDelegate
      *   A list of PLMIDs devoted to be delegated, they must be in a LOCAL or DELEGATED State.
      * @param iBriefcaseHeader
      *   Optional briefcase header information initialized by the client
      * @param iExportOptions
      *   Optional export options
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The export operation succeeded and the briefcase was generated.</dd>
      *   <dt>E_FAIL</dt>        <dd>The export operation failed because at least one component could not be exported.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT ExportToBriefcaseWithDelegation( const CATUnicodeString         & iBriefcasePath
                                                     , CATLISTV(CATPLMID)             & iComponents
                                                     , CATLISTV(CATPLMID)             & iComponentsToDelegate
                                                     , CATIPLMBriefcaseHeader         * ipBriefcaseHeader = NULL
                                                     , CATPLMREBriefcaseExportOptions * iExportOptions    = NULL ) = 0 ;

    /**
      * Revoke Delegation on objects that should be in a DELEGATOR or FORWARD State.
      * <br><b>Role:</b>Revoke Delegation on objects that should be in a Delegator or Forward State.
      * <br>All components in the list should belong to the same repository. 
      * <br>The client should be already connected to the repository.
      * @param iComponentsToRevoke
      *   List of identifiers devoted to be revoked
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The revoke operation succeeded and all objects have been revoked.</dd>
      *   <dt>E_FAIL</dt>        <dd>The revoke operation failed because at least one component could not be revoked.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */ 
      virtual HRESULT RevokeDelegation( CATLISTV(CATPLMID) & iComponentsToRevoke ) = 0 ;

    /**
      * Waive Delegation on objects that should be in a DELEGATED State.
      * <br><b>Role:</b>Waive Delegation on objects that should be in a Delegated State.
      * <br>All components in the list should belong to the same repository. 
      * <br>The client should be already connected to the repository.
      * @param iComponentsToWaive
      *   List of identifiers devoted to be waived
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>          <dd>The waive operation succeeded and all objects have been waived.</dd>
      *   <dt>E_FAIL</dt>        <dd>The waive operation failed because at least one component could not be waived.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>Invalid argument.</dd>
      * </dl>
      */
      virtual HRESULT WaiveDelegation( CATLISTV(CATPLMID) & iComponentsToWaive ) = 0 ;

    /**
      * Method to fetch pointer to exchange form object contained in replication engine.
      * <br><b>Role</b>: Exchange form object is used to set context, exchange and operation scopes on objects during Export and Site information operations.
      *
      * @param opExchangeForm [out, CATBaseUnknown#Release]
      *   Pointer to exchange form object contained in replication engine.
      * @return
      * <br><b>Legal values</b>
      *   <dl>  
      *   <dt>S_OK</dt>    <dd>If method succeeds.</dd>
      *   <dt>E_FAIL</dt>  <dd>Internal error when trying to return object.</dd>
      *   </dl>
      */
      virtual HRESULT GetExchangeFormObject( CATIPLMREExchangeForm *&opExchangeForm ) = 0 ;

#ifdef CATIAR424 //FUN118229
	  /**
	  * Method to fetch pointer to downward exchange form object.
	  * <br><b>Role</b>: Exchange form object is used at downward to set information for report
	  *
	  * @param opExchangeFormForDw [out, CATBaseUnknown#Release]
	  *   Pointer to exchange form object.
	  * @return
	  * <br><b>Legal values</b>
	  *   <dl>
	  *   <dt>S_OK</dt>    <dd>If method succeeds.</dd>
	  *   <dt>E_FAIL</dt>  <dd>Internal error when trying to return object.</dd>
	  *   </dl>
	  */
	  virtual HRESULT GetExchangeFormObjectForDw(CATIPLMREExchangeForm *&opExchangeFormForDw) = 0;
#endif
} ;

//------------------------------------------------------------------
CATDeclareHandler( CATIPLMReplicationEngine , CATBaseUnknown ) ;

#endif
