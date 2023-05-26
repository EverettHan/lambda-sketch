// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMRefreshRecordWriteSetAdapter.h
// Define the CATPLMRefreshRecordWriteSetAdapter interface
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

#ifndef CATPLMRefreshRecordWriteSetAdapter_H
#define CATPLMRefreshRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMRefreshRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMCloneRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMRefreshRecordWriteSetAdapter : public CATIPLMRefreshRecordWriteSet
{
public:
    CATPLMRefreshRecordWriteSetAdapter();
    virtual ~CATPLMRefreshRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompRefreshRecordWrite ** oRecordWrite);

private:
    CATPLMRefreshRecordWriteSetAdapter (CATPLMRefreshRecordWriteSetAdapter &);
    CATPLMRefreshRecordWriteSetAdapter& operator=(CATPLMRefreshRecordWriteSetAdapter&);
};

#endif
