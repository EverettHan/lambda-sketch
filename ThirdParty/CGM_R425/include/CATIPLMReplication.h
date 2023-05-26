#ifndef CATIPLMReplication_H
#define CATIPLMReplication_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
// MODIF PA DEB 02/11/2006
// #include "CATPLMPackageSpec.h"
#include "CATIPLMRecordReadSet.h"
// MODIF PA FIN 02/11/2006
#include "CATCollec.h"

class CATPLMID;
class CATLISTV(CATPLMID);
class CATIPLMReplicationTransaction;
class CATLISTV(CATPLMReplicationStreamInfo);
class CATPLMTextOutputStream;
class CATPLMTextInputStream;
class CATPLMPhysicalRepositoryID;
class CATPLMSiteOwnershipTransferDoc;
class CATDbBinary;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMReplication;
#else
extern "C" const IID IID_CATIPLMReplication;
#endif

/**
 * @level Protected
 * @usage U3
 */

/**
 * Interface associated with the Replication commands.
 * <br><b>Role</b>: centralization of the replication command API. <br>
 * This API should be used only be the replication engine.
 * The interface should be implemented on any provider that wants to be replication compliant.
 */

class ExportedByCATPLMServicesItf CATIPLMReplication: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
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
* @param iListOfEntitiesIDs
*   List containing the PLM entities to replicate. 
* @return 
* <br><b>Legal values</b>
*   <dt>S_OK</dt>  
*   <dd>The capture operation succeeded. 
*   </dd>
*   <dt>E_FAIL</dt>  
*   <dd>The capture operation failed.
*   </dd>
*   <dt>E_INVALIDARG</dt>  
*   <dd>Invalid argument</dd>
* <br>
*/
  virtual HRESULT Capture( const CATUnicodeString & iLogFileName,
                           const CATUnicodeString & iCaptureFileName,
                           const CATUnicodeString & iCaptureFileBaseName,
                           const int                iMaxNumberOfRBOs,
                           const CATUnicodeString & iVaultCopyToPath,
                           const CATUnicodeString & iTargetSiteName,
                           const CATUnicodeString & iTransferFileName,
						   int                        iMode,
                           const CATLISTV(CATPLMID) & iListOfEntitiesIDs ) =0 ;

  /**
   * Performs a change owner site operation.
   * @param iTargetSiteName
   *   Name of the target site.
   * @param iListOfEntitiesIDs
   *   List containing the PLM entities the owner site is to be changed.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The ChangeOwnerSite operation succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The ChangeOwnerSite operation failed.
   *   </dd>
   *   <dt>E_INVALIDARG</dt>  
   *   <dd>Invalid argument</dd>
   * <br>
   */
  
  virtual HRESULT ChangeOwnerSite( const CATUnicodeString & iTargetSiteName,
                                   const CATLISTV(CATPLMID) & iListOfEntitiesIDs ) =0 ;


  /**
   * Performs an apply operation. Import in the current site data comming from another site.
   * @param iLogFileName
   *   Name of the file that will contain the execution log of the apply operation
   * @param iApplyFileName
   *   Name of the file that will contain the replicated data.
   * @param iAckowledgeFileName
   *   Name of the acknowledgement file that will be generated.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The apply operation succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The apply operation failed.
   *   </dd>
   *   <dt>E_INVALIDARG</dt>  
   *   <dd>Invalid argument</dd>
   * <br>
   */
  virtual HRESULT Apply( const CATUnicodeString & iLogFileName,
                         const CATUnicodeString & iApplyFileName,
                         const CATUnicodeString & iAcknowledgeFileName,
                         const CATUnicodeString & iVaultCopyFromPath ) = 0 ;

  /**
   * Performs an ackowledge operation. Import in the current site the current status of a replicated site.
   * @param iLogFileName
   *   Name of the file that will contain the execution log of the capture operation
   * @param iAckowledgeFileName
   *   Name of the acknowledgement file that will be generated.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The capture operation succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The capture operation failed.
   *   </dd>
   *   <dt>E_INVALIDARG</dt>  
   *   <dd>Invalid argument</dd>
   * <br>
   */
  virtual HRESULT Acknowledge( const CATUnicodeString & iLogFileName,
                               const CATUnicodeString & iAcknowledgeFileName ) = 0;
  

 /**
   * performs an Import operation.
   * Import data coming from an Export Operation.
   * @param iListOptions
   * a list of options for the Import operation.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The import operation succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The import operation failed.
   *   </dd>
   *   <dt>E_INVALIDARG</dt>  
   *   <dd>Invalid argument</dd>
   * <br>
   */
virtual HRESULT Import(const CATListOfCATUnicodeString& iListOptions) = 0;

  /**
   * performs an export operation.
   * export data described by the List of their PLM Ids.
   * @param iListOfEntitiesIDs
   *   List containing the PLM entities to export. 
   * @param iListOptions
   * a list of options for the export operation.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The export operation succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The export operation failed.
   *   </dd>
   *   <dt>E_INVALIDARG</dt>  
   *   <dd>Invalid argument</dd>
   * <br>
   */ 
   
   virtual HRESULT Export( const CATLISTV(CATPLMID) & iListOfEntitiesIDs,
                           const CATListOfCATUnicodeString& iListOptions      )=0;

   /**
   * recover from a change site owner command.
   * @param iListOfEntitiesIDs
   *   List containing the PLM entities to get their ownership back.  
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The reclaim operation succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The reclaim operation failed.
   *   </dd>
   *   <dt>E_INVALIDARG</dt>  
   *   <dd>Invalid argument</dd>
   * <br>
   */
   
   virtual HRESULT ReclaimSiteOwnership ( const CATLISTV(CATPLMID) & iListOfEntitiesIDs ) = 0;

// NEW EXPORT/IMPORT DEDICATED METHODS

   /**
   * Exports a list of entities.
   * <b>Role:</b>
   * @param iToBeExported
   *   Identifiers of the entities to be exported
   * @param ipPLMDataOutputStream
   *   CATILockBytes2 output stream where the exported PLM data should be written.
   * @param iListOptions
   *   list of additional (provider specific) options, with the (option1, value1, option2, value2...) format.
   * @param oStreamsToBeExtracted
   *   list of streams to be extracted from the vault.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd></dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The export operation failed. An error can be obtained with CATGetLastError().</dd>
   *   <dd></dd>
   * <br>
   */
virtual HRESULT ExportPLMData( const CATLISTV(CATPLMID) &iToBeExported,
                               CATPLMTextOutputStream &oPLMDataOutputStream,
                               const CATListOfCATUnicodeString& iListOptions,
                               CATLISTV(CATPLMReplicationStreamInfo) &oStreamsToBeExtracted) = 0;
   /**
   * Checks that streams have not been modified since their extraction.
   * @param iExtractedStreams
   *   The list of streams that have been extracted, with their localization and their extract watermarkstamp.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>No stream was modified since extraction</dd>
   *   <dt>S_FALSE</dt>  
   *   <dd>At least one stream was modification since extraction</dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The operation could not complete due to an unexpected error. An error can be obtained with CATGetLastError().</dd>
   * <br>
   */
virtual HRESULT CheckForCollisionsAtExport( const CATLISTV(CATPLMReplicationStreamInfo) &iExtractedStreams ) = 0;

   /**
   * Creates a replication transaction for data import.
   * <b>Role:</b>
   * @param opTransaction
   *    If successful, the add-refed transaction.
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The transaction was successfully created</dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The transaction could not be created due to an unexpected error.</dd>
   *   <dd></dd>
   * <br>
   */
virtual HRESULT CreateReplicationTransaction( CATIPLMReplicationTransaction *& opTransaction ) = 0;

  /**
   * Export a replication extract from a repository.
   * <b>Role:</b>
   * @param iListOfEntitiesIDs
   *   The list of PLMIds of entities.
   * @param iListOfOptions
   *   The list of options driving the replication extract generation (none for the while)
   * @param opReplicationExtract
   *    If successful, the replication extract containing the replication information
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The replication extract was successfully created</dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The replication extract could not be created due to an unexpected error.</dd>
   *   <dd></dd>
   * <br>
   */
virtual HRESULT ExportPLMReplicationExtract( const CATLISTV(CATPLMID) &iListOfEntitiesIDs, 
											 const CATListOfCATUnicodeString &iListOfOptions, 
                                             CATIPLMRecordReadSet *&opReplicationExtract) = 0;   

    /**
    * Logs a request of Site Ownership transfer for a set of PLM Entities to a distant repository.
    * @param iComponents 
    *   List of CATPLMIDs of the PLM entities to transfer. They will be define an unbreakable package to transfer as a whole.
    * @param iDestinationPRI
    *   ID of repository which to transfer entities. 
    * @return 
    * <br><b>Legal values</b>
    *   <dt>S_OK</dt>  
    *   <dd>The transfer request has succeeded. 
    *   </dd>
    *   <dt>S_FALSE</dt>  
    *   <dd>The transfer request cannot be done due to an invalid prerequisite (wrong status/date...).
    *   </dd>
    *   <dt>E_FAIL</dt>  
    *   <dd>The transfer request failed due to an unexpected internal error.
    *   </dd>
    * <br>
    */  
    virtual HRESULT RequestSiteOwnershipTransfer( 
        const CATPLMPhysicalRepositoryID  &iDestinationPRI,
        CATLISTV(CATPLMID)                &iComponents) = 0;


    /**
    * Cancels a request of site ownership transfer for a package.
    * @param iEntity 
    *   PLMID of an entity of the package to cancel.
    * @return 
    * <br><b>Legal values</b>
    *   <dt>S_OK</dt>  
    *   <dd>The request cancel has succeeded. The package doesn't exist anymore.
    *   </dd>
    *   <dt>S_FALSE</dt>  
    *   <dd>The cancellation cannot be done due to an invalid prerequisite (wrong status...).
    *   </dd>
    *   <dt>E_FAIL</dt>  
    *   <dd>The request cancel failed due to an unexpected internal error.
    *   </dd>
    * <br>
    */      
    virtual HRESULT CancelSiteOwnershipTransfer( 
        const CATPLMID                 &iEntity) = 0;

    /**
    * Creates a Site Ownership Transfer Certificate for a given package to the intended target repository.
    * @param iDestinationPRI
    *   Physical ID of the destination repository. Use only for check with the one log during request operation.
    * @param iEntityToTransfer 
    *   PLMID of an entity of the package to transfer.
    * @param ioOTC
    *   OwnershipTransferDocument to send to the receiver repository. Contains the transfer information for the whole targetted package.
    * @return 
    * <br><b>Legal values</b>
    *   <dt>S_OK</dt>  
    *   <dd>The transfer has succeeded. 
    *   </dd>
    *   <dt>S_FALSE</dt>  
    *   <dd>The transfer cannot be done due to an invalid prerequisite (wrong status/date...). But OTC is still generated.
    *   </dd>
    *   <dt>E_FAIL</dt>  
    *   <dd>The transfer failed due to an unexpected internal error. OTC is null.
    *   </dd>
    * <br>
    */   
    virtual HRESULT EmitSiteOwnership (
        const CATPLMPhysicalRepositoryID      &iDestinationPRI,
        const CATPLMID                        &iEntityToTransfer,
        CATPLMTextOutputStream                &ioOTC) = 0 ;

    /**
    * Reads an OTC and performs the transfer site ownership. An OC to send to the emitter repository is created. 
    * @param iOTC 
    *   OTC to read and apply on the local repository.
    * @param ioOC
    *   OC to send to the emitter repository, containing the result of transfer.
    * @return 
    * <br><b>Legal values</b>
    *   <dt>S_OK</dt>  
    *   <dd>The OTC has successful be read and the OC created. Transfer on receiver side is successful.
    *   </dd>
    *   <dt>S_FALSE<dt>
    *   <dd>OTC is intended to the local repository but one of the packaged entities is not distant, is absent of the database, or has a wrong iteration number. Transfer is not done. But an OC is still generated.
    *   </dd>    
    *   <dt>S_FALSE</dt>  
    *   <dd>The transfer reception cannot be done due to an invalid prerequisite (wrong status/date...).
    *   </dd>
    *   <dt>E_FAIL</dt>  
    *   <dd>The OTC cannot be read or is not intended to local repository. OC is null.
    *   </dd>
    * <br>
    */      
    virtual HRESULT ReceiveSiteOwnership ( 
        CATPLMTextInputStream   &iOTC,
        CATPLMTextOutputStream        &ioOC) = 0;

    /**
    * Reads an OC and performs the transfer confirmation on emitter site. Targetted entitie are officialy distant. 
    * @param iReceivedOC 
    *   OC to read and to apply on the local repository.
    * @return 
    * <br><b>Legal values</b>
    *   <dt>S_OK</dt>  
    *   <dd>The OC has successfully be read. Transfer has been done successfully.
    *   </dd>
    *   <dt>S_FALSE</dt>  
    *   <dd>The transfer confirmation cannot be done due to an invalid prerequisite (wrong status/date...) on emitter or receiver repository.<br>
    *       Entities return to 'waiting' status.
    *   </dd>
    *   <dt>E_FAIL</dt>  
    *   <dd>The targetted package cannot be flaged distant due to an unexpected internal error.
    *   </dd>
    * <br>
    */      
    virtual HRESULT ApplySiteOwnershipTransferConfirmation( 
        CATPLMTextInputStream &iReceivedOC) = 0;

};

#endif
