//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMImportRecordWriteSetAdapter.h
// Define the CATPLMImportRecordWriteSetAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMImportRecordWriteSet
//
//===================================================================
//
// Feb 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMImportRecordWriteSetAdapter_H
#define CATPLMImportRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMImportRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMImportRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMImportRecordWriteSetAdapter : public CATIPLMImportRecordWriteSet
{
public:
    CATPLMImportRecordWriteSetAdapter();
    virtual ~CATPLMImportRecordWriteSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompImportRecordWrite **pWrite);

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompImportRecordWrite **pWrite, int iUrls);

    /** 
    * @nodoc
    */
    virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompRecordWrite **pWrite);

    /** 
    * @nodoc
    */
    virtual HRESULT NextSection ();

private:
    CATPLMImportRecordWriteSetAdapter (CATPLMImportRecordWriteSetAdapter &);
    CATPLMImportRecordWriteSetAdapter& operator=(CATPLMImportRecordWriteSetAdapter&);
};

#endif
