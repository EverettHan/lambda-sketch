//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMFetchQueryAdapter.h
// Define the CATPLMFetchQueryAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMFetchQuery
//
//===================================================================
//
// Feb 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMFetchQueryAdapter_H
#define CATPLMFetchQueryAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMFetchQuery.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMFetchQuery
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMFetchQueryAdapter : public CATIPLMFetchQuery
{
public:
    CATPLMFetchQueryAdapter();
    virtual ~CATPLMFetchQueryAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT QueryPageIDs(   const CATIPLMQueryFilter  *iFilter       ,
                                    CATListOfCATUnicodeString &oPageIDs     ,
                                    CATIPLMRecordReadSet  **oFirstPage);

    /** 
    * @nodoc
    */
    virtual HRESULT QueryPage(  const CATIPLMQueryFilter *iFilter    ,
                                const CATUnicodeString   &iPageID   ,
                                CATListOfCATUnicodeString & ioPageIDs ,
                                CATIPLMRecordReadSet **oPage);

    virtual HRESULT QueryPage(  const CATIPLMQueryFilter *iFilter    ,
                                const CATUnicodeString   &iPageID   ,
                                CATIPLMRecordReadSet **oPage);

private:
    CATPLMFetchQueryAdapter (CATPLMFetchQueryAdapter &);
    CATPLMFetchQueryAdapter& operator=(CATPLMFetchQueryAdapter&);
};
#endif

