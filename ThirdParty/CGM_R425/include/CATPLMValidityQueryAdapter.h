// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMValidityQueryAdapter.h
// Define the CATPLMValidityQueryAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMQuery
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMValidityQueryAdapter_H
#define CATPLMValidityQueryAdapter_H

#include "CATIPLMValidityQuery.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

class CATIPLMQueryFilter;
class CATIPLMRecordReadSet;

/**
 * gives an adapter to the interface CATIPLMValidityQuery
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMValidityQueryAdapter : public CATIPLMValidityQuery
{
public:
    CATPLMValidityQueryAdapter();
    virtual ~CATPLMValidityQueryAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT QueryValidity(  CATIPLMQueryFilter         * iFilter, CATLISTV(CATPLMValidityResult) &oResult );

private:
    CATPLMValidityQueryAdapter (CATPLMValidityQueryAdapter &);
    CATPLMValidityQueryAdapter& operator=(CATPLMValidityQueryAdapter&);
};

#endif
