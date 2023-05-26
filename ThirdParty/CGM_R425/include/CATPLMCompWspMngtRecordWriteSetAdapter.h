// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCompWspMngtRecordWriteSetAdapter.h
// Define the CATPLMCompWspMngtRecordWriteSetAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMCloneRecordWriteSet
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMCompWspMngtRecordWriteSetAdapter_H
#define CATPLMCompWspMngtRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMWspMngtRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMCloneRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMCompWspMngtRecordWriteSetAdapter : public CATIPLMWspMngtRecordWriteSet
{
public:
    CATPLMCompWspMngtRecordWriteSetAdapter();
    virtual ~CATPLMCompWspMngtRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompWspMngtRecordWrite ** oRecordWrite);

    virtual HRESULT InitWspMngtTrs (CATIPLMCompTransactionService::PLMWspMngtTrnsType iTransType,CATListOfCATUnicodeString& iHeaderParams);

private:
    CATPLMCompWspMngtRecordWriteSetAdapter (CATPLMCompWspMngtRecordWriteSetAdapter &);
    CATPLMCompWspMngtRecordWriteSetAdapter& operator=(CATPLMCompWspMngtRecordWriteSetAdapter&);
};

#endif
