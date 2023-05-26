// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMQueryAdapter.h
// Define the CATPLMQueryAdapter interface
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

#ifndef CATPLMQueryAdapter_H
#define CATPLMQueryAdapter_H

#include "CATIPLMQuery.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

class CATIPLMQueryFilter;
class CATIPLMRecordReadSet;

/**
 * gives an adapter to the interface CATIPLMQuery
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMQueryAdapter : public CATIPLMQuery
{
public:
    CATPLMQueryAdapter();
    virtual ~CATPLMQueryAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT QueryCount( CATIPLMQueryFilter * iFilter,
                        int               * oNumOfResults );

    /** 
    * @nodoc
    */
    virtual HRESULT Query(  CATIPLMQueryFilter         * iFilter,
                    CATIPLMRecordReadSet      ** oRecordSet);

private:
    CATPLMQueryAdapter (CATPLMQueryAdapter &);
    CATPLMQueryAdapter& operator=(CATPLMQueryAdapter&);
};

#endif
