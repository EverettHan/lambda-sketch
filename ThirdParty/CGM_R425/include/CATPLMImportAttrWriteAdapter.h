//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMImportAttrWriteAdapter.h
// Define the CATPLMImportAttrWriteAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMImportAttrWrite
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

#ifndef CATPLMImportAttrWriteAdapter_H
#define CATPLMImportAttrWriteAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMImportAttrWrite.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

/**
 * gives an adapter to the interface CATIPLMImportAttrWrite
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMImportAttrWriteAdapter : public CATIPLMImportAttrWrite
{
public:
    CATPLMImportAttrWriteAdapter();
    virtual ~CATPLMImportAttrWriteAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT SetRepoPrivilege (const CATPLMRepoPrivilege &iRepoPrivilege);

private:
    CATPLMImportAttrWriteAdapter (CATPLMImportAttrWriteAdapter &);
    CATPLMImportAttrWriteAdapter& operator=(CATPLMImportAttrWriteAdapter&);
};

#endif
