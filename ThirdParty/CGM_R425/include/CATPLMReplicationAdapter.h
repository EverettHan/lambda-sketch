// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMReplicationAdapter.h
// Define the CATPLMReplicationAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMReplication
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Private
* @usage U2
*/

#ifndef CATPLMReplicationAdapter_H
#define CATPLMReplicationAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMReplication.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMReplication
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMReplicationAdapter : public CATIPLMReplication
{
public:
    CATPLMReplicationAdapter();
    virtual ~CATPLMReplicationAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Capture(    const CATUnicodeString & iLogFileName,
                                const CATUnicodeString & iCaptureFileName,
                                const CATUnicodeString & iCaptureFileBaseName,
                                const int                iMaxNumberOfRBOs,
                                const CATUnicodeString & iVaultCopyToPath,
                                const CATUnicodeString & iTargetSiteName,
                                const CATUnicodeString & iTransferFileName,
                                int                        iMode,
                                const CATLISTV(CATPLMID) & iListOfEntitiesIDs );

    /** 
    * @nodoc
    */
    virtual HRESULT ChangeOwnerSite(    const CATUnicodeString & iTargetSiteName,
                                const CATLISTV(CATPLMID) & iListOfEntitiesIDs );

    /** 
    * @nodoc
    */
    virtual HRESULT Apply(  const CATUnicodeString & iLogFileName,
                            const CATUnicodeString & iApplyFileName,
                            const CATUnicodeString & iAcknowledgeFileName,
                            const CATUnicodeString & iVaultCopyFromPath );

    /** 
    * @nodoc
    */
    virtual HRESULT Acknowledge(    const CATUnicodeString & iLogFileName,
                                    const CATUnicodeString & iAcknowledgeFileName );

    /** 
    * @nodoc
    */
    virtual HRESULT Import(const CATListOfCATUnicodeString& iListOptions);

    /** 
    * @nodoc
    */
    virtual HRESULT Export( const CATLISTV(CATPLMID) & iListOfEntitiesIDs,
                            const CATListOfCATUnicodeString& iListOptions      );

    /** 
    * @nodoc
    */
    virtual HRESULT ReclaimSiteOwnership ( const CATLISTV(CATPLMID) & iListOfEntitiesIDs );

    /** 
    * @nodoc
    */
    virtual HRESULT ExportPLMData(  const CATLISTV(CATPLMID) &iToBeExported,
                                    CATPLMTextOutputStream &oPLMDataOutputStream,
                                    const CATListOfCATUnicodeString& iListOptions,
                                    CATLISTV(CATPLMReplicationStreamInfo) &oStreamsToBeExtracted);

    /** 
    * @nodoc
    */
    virtual HRESULT CheckForCollisionsAtExport( const CATLISTV(CATPLMReplicationStreamInfo) &iExtractedStreams );

    /** 
    * @nodoc
    */
    virtual HRESULT CreateReplicationTransaction( CATIPLMReplicationTransaction *& opTransaction );

    /** 
    * @nodoc
    */
    virtual HRESULT ExportPLMReplicationExtract(    const CATLISTV(CATPLMID) &iListOfEntitiesIDs, 
                                                    const CATListOfCATUnicodeString &iListOfOptions, 
                                                    CATIPLMRecordReadSet *&opReplicationExtract);

    /** 
    * @nodoc
    */
    virtual HRESULT RequestSiteOwnershipTransfer(   const CATPLMPhysicalRepositoryID  &iDestinationPRI,
                                                    CATLISTV(CATPLMID)                &iComponents);

    /** 
    * @nodoc
    */
    virtual HRESULT CancelSiteOwnershipTransfer(    const CATPLMID                 &iEntity);

    /** 
    * @nodoc
    */
    virtual HRESULT EmitSiteOwnership ( const CATPLMPhysicalRepositoryID      &iDestinationPRI,
                                        const CATPLMID                        &iEntityToTransfer,
                                        CATPLMTextOutputStream                &ioOTC);

    /** 
    * @nodoc
    */
    virtual HRESULT ReceiveSiteOwnership (  CATPLMTextInputStream   &iOTC,
                                            CATPLMTextOutputStream        &ioOC);

    /** 
    * @nodoc
    */
    virtual HRESULT ApplySiteOwnershipTransferConfirmation( CATPLMTextInputStream &iReceivedOC);

private:
    CATPLMReplicationAdapter (CATPLMReplicationAdapter &);
    CATPLMReplicationAdapter& operator=(CATPLMReplicationAdapter&);
};

#endif
