// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMRecordReadSetAdapter.h
// Define the CATPLMRecordReadSetAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMRecordReadSet
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMRecordReadSetAdapter_H
#define CATPLMRecordReadSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMRecordReadSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

class CATPLMClientTasks;

/**
 * gives an adapter to the interface CATIPLMRecordReadSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMRecordReadSetAdapter : public CATIPLMRecordReadSet
{
public:
    CATPLMRecordReadSetAdapter();
    virtual ~CATPLMRecordReadSetAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Next(CATIPLMRecordRead ** oRecordRead);

    /** 
    * @nodoc
    */
    virtual HRESULT GetReport(CATIPLMError ** oError);

    /**
    * @nodoc
    */
    CATIPLMError* GetReport();

    /**
    * @nodoc
    */
    virtual CATPLMClientTasks GetClientTasks();
private:
    CATPLMRecordReadSetAdapter (CATPLMRecordReadSetAdapter &);
    CATPLMRecordReadSetAdapter& operator=(CATPLMRecordReadSetAdapter&);
};

#endif
