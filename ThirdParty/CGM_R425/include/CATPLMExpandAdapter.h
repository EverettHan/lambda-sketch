//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMExpandAdapter.h
// Define the CATPLMExpandAdapter adapter
//
//===================================================================
//
// Usage notes:
//   New adapter: You must use this adapter if you implement CATIPLMExpand
//                (for M1, use the adapter CATPLMxExpandAdapter.cpp 
//                which inherits from the current class)
//
//===================================================================
//
// Jan 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMExpandAdapter_H
#define CATPLMExpandAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

#include "CATIPLMExpand.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

class CATIPLMQueryFilter;
class CATPLMExpandAdapterResultHandler;

/**
 * Adapter for Expand. You must use this adapter if you implement CATIPLMExpand
 */
class ExportedByCATPLMImplAdapterClass CATPLMExpandAdapter: public CATIPLMExpand
{
public:
    CATPLMExpandAdapter();
    virtual ~CATPLMExpandAdapter();

    virtual HRESULT Expand( CATIPLMQueryFilter * iFilter,
                            CATIPLMExpandResultHandler * iExpandHandler);

    virtual HRESULT Expand( CATAsyncTaskID& oTaskID, CATIPLMQueryFilter * iFilter,
                            CATIPLMExpandResultHandler * iExpandHandler,
                            CATIAsyncTaskCompletionCallBackBase &iAsyncTaskCompletionCallBack);

    virtual HRESULT Expand( CATAsyncTaskID& oTaskID, CATIPLMQueryFilter * iFilter,
                            CATIPLMExpandResultHandler * iExpandHandler,
                            CATIAsyncTaskCompletionCallBack &iAsyncTaskCompletionCallBack);

private:
    CATPLMExpandAdapter (CATPLMExpandAdapter &);
    CATPLMExpandAdapter& operator=(CATPLMExpandAdapter&);
};

#endif
