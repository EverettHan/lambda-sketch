//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMMetaDataHandlingAdapter.h
// Define the CATPLMMetaDataHandlingAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMMetaDataHandling
//
//===================================================================
//
// Feb 2009
// Creation: EPB
//
//===================================================================

/**
* @level Private
* @usage U2
*/

#ifndef CATPLMMetaDataHandlingAdapter_H
#define CATPLMMetaDataHandlingAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMMetaDataHandling.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMMetaDataHandling
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMMetaDataHandlingAdapter : public CATIPLMMetaDataHandling
{
public:
    CATPLMMetaDataHandlingAdapter();
    virtual ~CATPLMMetaDataHandlingAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GetBehavior (CATPLMProvMetaDataBehavior &oBehavior);

    /** 
    * @nodoc
    */
    virtual HRESULT GetRequestedVersion (CATIALevelInfo &oLevel);

    /** 
    * @nodoc
    */
    virtual HRESULT GetSupportedModelers (CATListValCATUnicodeString &oModelers);

private:
    CATPLMMetaDataHandlingAdapter (CATPLMMetaDataHandlingAdapter &);
    CATPLMMetaDataHandlingAdapter& operator=(CATPLMMetaDataHandlingAdapter&);
};

#endif
