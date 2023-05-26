// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMRecordWriteSetAdapter.h
// Define the CATPLMRecordWriteSetAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMRecordWriteSet
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMRecordWriteSetAdapter_H
#define CATPLMRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

class CATPLMID;
class CATIPLMCompRecordWrite;

/**
 * gives an adapter to the interface CATIPLMRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMRecordWriteSetAdapter : public CATIPLMRecordWriteSet
{
public:
    CATPLMRecordWriteSetAdapter();
    virtual ~CATPLMRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompRecordWrite **pWrite);

    /** 
    * @nodoc
    */
    virtual HRESULT NextSection ();

private:
    CATPLMRecordWriteSetAdapter (CATPLMRecordWriteSetAdapter &);
    CATPLMRecordWriteSetAdapter& operator=(CATPLMRecordWriteSetAdapter&);
};

#endif
