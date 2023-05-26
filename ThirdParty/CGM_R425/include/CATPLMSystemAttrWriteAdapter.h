// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMSystemAttrWriteAdapter.h
// Define the CATPLMSystemAttrWriteAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMSystemAttrWrite
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMSystemAttrWriteAdapter_H
#define CATPLMSystemAttrWriteAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMSystemAttrWrite.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

/**
 * gives an adapter to the interface CATIPLMSystemAttrWrite
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMSystemAttrWriteAdapter : public CATIPLMSystemAttrWrite
{
public:
    CATPLMSystemAttrWriteAdapter();
    virtual ~CATPLMSystemAttrWriteAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT SetCEStamp( const CATPLMCEStamp & oStamp );

private:
    CATPLMSystemAttrWriteAdapter (CATPLMSystemAttrWriteAdapter &);
    CATPLMSystemAttrWriteAdapter& operator=(CATPLMSystemAttrWriteAdapter&);
};

#endif
