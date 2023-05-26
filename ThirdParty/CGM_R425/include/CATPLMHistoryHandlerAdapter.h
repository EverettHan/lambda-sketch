//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMHistoryHandlerAdapter
//
//===================================================================
//
// we provide an adapter for the interface CATIPLMHistoryHandler
//
//===================================================================
//
// Jan 2009 Creation EPB
// 
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMHistoryHandlerAdapter_H
#define CATPLMHistoryHandlerAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMHistoryHandler.h" // CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

class CATPLMHistoryRecord;
class CATPLMHistoryRecordLight;

class ExportedByCATPLMImplAdapterClass CATPLMHistoryHandlerAdapter : public CATIPLMHistoryHandler
{
public:
    CATPLMHistoryHandlerAdapter();
    virtual ~CATPLMHistoryHandlerAdapter();

    /** 
    * Short role of the method.
    *
    * <br><b>Role</b>: Explain what this method does.
    *
    * @param iRecord [in]
    *   The parameter role...
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise...
    *
    */
    virtual HRESULT TreatHistoryRecord( CATPLMHistoryRecord *iRecord );

    virtual HRESULT TreatHistoryRecord( CATPLMHistoryRecordLight *iRecord );

private:
  CATPLMHistoryHandlerAdapter (CATPLMHistoryHandlerAdapter &);
  CATPLMHistoryHandlerAdapter& operator=(CATPLMHistoryHandlerAdapter&);

};

#endif

