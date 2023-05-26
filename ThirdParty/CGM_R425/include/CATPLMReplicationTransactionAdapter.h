// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMReplicationTransactionAdapter.h
// Define the CATPLMReplicationTransactionAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMReplicationTransaction
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMReplicationTransactionAdapter_H
#define CATPLMReplicationTransactionAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMReplicationTransaction.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMReplicationTransaction
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMReplicationTransactionAdapter : public CATIPLMReplicationTransaction
{
public:
    CATPLMReplicationTransactionAdapter();
    virtual ~CATPLMReplicationTransactionAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT ImportPLMData(  CATPLMTextInputStream &iPLMDataInputStream, 
                                    const CATListOfCATUnicodeString& iListOptions,
                                    CATLISTV(CATPLMReplicationStreamInfo) &oStreamsToBeImported,
                                    CATLISTV(CATPLMID) *ioImportedEntityIDs = NULL);

    /** 
    * @nodoc
    */
    virtual HRESULT Commit();

    /** 
    * @nodoc
    */
    virtual HRESULT Rollback();

private:
    CATPLMReplicationTransactionAdapter (CATPLMReplicationTransactionAdapter &);
    CATPLMReplicationTransactionAdapter& operator=(CATPLMReplicationTransactionAdapter&);
};

#endif
