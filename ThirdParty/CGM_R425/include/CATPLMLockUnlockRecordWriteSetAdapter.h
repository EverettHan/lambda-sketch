// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMLockUnlockRecordWriteSetAdapter.h
// Define the CATPLMLockUnlockRecordWriteSetAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMLockUnlockRecordWriteSet
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Private
* @usage U2
*/

#ifndef CATPLMLockUnlockRecordWriteSetAdapter_H
#define CATPLMLockUnlockRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMLockUnlockRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMLockUnlockRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMLockUnlockRecordWriteSetAdapter : public CATIPLMLockUnlockRecordWriteSet
{
public:
    CATPLMLockUnlockRecordWriteSetAdapter();
    virtual ~CATPLMLockUnlockRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompLockUnlockRecordWrite *&pWrite);

private:
    CATPLMLockUnlockRecordWriteSetAdapter (CATPLMLockUnlockRecordWriteSetAdapter &);
    CATPLMLockUnlockRecordWriteSetAdapter& operator=(CATPLMLockUnlockRecordWriteSetAdapter&);
};

#endif
