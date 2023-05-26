// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMReIdentificationAdapter.h
// Define the CATPLMReIdentificationAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMReIdentification
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMReIdentificationAdapter_H
#define CATPLMReIdentificationAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMReIdentification.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

/**
 * gives an adapter to the interface CATIPLMReIdentification
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMReIdentificationAdapter : public CATIPLMReIdentification
{
public:
    CATPLMReIdentificationAdapter();
    virtual ~CATPLMReIdentificationAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GetNewPLMId( CATPLMID & oId );

private:
    CATPLMReIdentificationAdapter (CATPLMReIdentificationAdapter &);
    CATPLMReIdentificationAdapter& operator=(CATPLMReIdentificationAdapter&);
};

#endif
