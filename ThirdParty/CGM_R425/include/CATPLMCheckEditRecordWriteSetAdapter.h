// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCheckEditRecordWriteSetAdapter.h
// Define the CATPLMCheckEditRecordWriteSetAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
//
//===================================================================
//
//  Feb 2009  Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMCheckEditRecordWriteSetAdapter_H
#define CATPLMCheckEditRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMCheckEditRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMCheckEditRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMCheckEditRecordWriteSetAdapter : public CATIPLMCheckEditRecordWriteSet
{
public:
    CATPLMCheckEditRecordWriteSetAdapter();
    virtual ~CATPLMCheckEditRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT SetLockMode(CATPLMEditabilityLockMode iLockMode);

    /** 
    * @nodoc
    */
    virtual HRESULT Next(const CATPLMID & iId, CATIPLMCompCheckEditRecordWrite** oRecordWrite);

private:
    CATPLMCheckEditRecordWriteSetAdapter (CATPLMCheckEditRecordWriteSetAdapter &);
    CATPLMCheckEditRecordWriteSetAdapter& operator=(CATPLMCheckEditRecordWriteSetAdapter&);
};
#endif
