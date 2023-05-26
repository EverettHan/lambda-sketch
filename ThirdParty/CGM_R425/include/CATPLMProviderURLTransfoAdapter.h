// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProviderURLTransfoAdapter.h
// Define the CATPLMProviderURLTransfoAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMProviderURLTransfo
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMProviderURLTransfoAdapter_H
#define CATPLMProviderURLTransfoAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMProviderURLTransfo.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMProviderURLTransfo
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMProviderURLTransfoAdapter : public CATIPLMProviderURLTransfo
{
public:
    CATPLMProviderURLTransfoAdapter();
    virtual ~CATPLMProviderURLTransfoAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GetPLMIDFromURL (const CATUnicodeString & iURL, CATPLMID & oPLMID);

private:
    CATPLMProviderURLTransfoAdapter (CATPLMProviderURLTransfoAdapter &);
    CATPLMProviderURLTransfoAdapter& operator=(CATPLMProviderURLTransfoAdapter&);
};

#endif
