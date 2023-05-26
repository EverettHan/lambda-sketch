// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMDeleteRefRecordWriteSetAdapter.h
// Define the CATPLMDeleteRefRecordWriteSetAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMDeleteRefRecordWriteSet
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMDeleteRefRecordWriteSetAdapter_H
#define CATPLMDeleteRefRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMDeleteRefRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMCloneRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMDeleteRefRecordWriteSetAdapter : public CATIPLMDeleteRefRecordWriteSet
{
public:
    CATPLMDeleteRefRecordWriteSetAdapter();
    virtual ~CATPLMDeleteRefRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompDeleteRefRecordWrite ** oRecordWrite);

private:
    CATPLMDeleteRefRecordWriteSetAdapter (CATPLMDeleteRefRecordWriteSetAdapter &);
    CATPLMDeleteRefRecordWriteSetAdapter& operator=(CATPLMDeleteRefRecordWriteSetAdapter&);
};

#endif
