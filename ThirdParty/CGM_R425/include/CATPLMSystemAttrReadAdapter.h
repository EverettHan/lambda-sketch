// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMSystemAttrReadAdapter.h
// Define the CATPLMSystemAttrReadAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMSystemAttrRead
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMSystemAttrReadAdapter_H
#define CATPLMSystemAttrReadAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMSystemAttrRead.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

/**
 * gives an adapter to the interface CATIPLMSystemAttrRead
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMSystemAttrReadAdapter : public CATIPLMSystemAttrRead
{
public:
    CATPLMSystemAttrReadAdapter();
    virtual ~CATPLMSystemAttrReadAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GetCEStamp( CATPLMCEStamp & oStamp )const;

private:
    CATPLMSystemAttrReadAdapter (CATPLMSystemAttrReadAdapter &);
    CATPLMSystemAttrReadAdapter& operator=(CATPLMSystemAttrReadAdapter&);
};

#endif
