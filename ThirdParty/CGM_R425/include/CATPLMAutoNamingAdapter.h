// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMAutoNamingAdapter.h
// Define the CATPLMAutoNamingAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
//
//===================================================================
//
//  Feb 2009  Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMAutoNamingAdapter_H
#define CATPLMAutoNamingAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMAutoNaming.h"

/**
 * gives an adapter to the interface CATIPLMAutoNaming
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMAutoNamingAdapter : public CATIPLMAutoNaming
{
public:
    CATPLMAutoNamingAdapter();
    virtual ~CATPLMAutoNamingAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GenerateNames (const CATOmxVector<CATPLMAutoNamingInput> &iInputs, CATPLMAutoNamingOutput *oOutput);

    /** 
    * @nodoc
    */
    virtual HRESULT GenerateNames (const CATLISTP (CATPLMAutoNamingInput) &iInputs, CATPLMAutoNamingOutput *oOutput);

private:
    CATPLMAutoNamingAdapter (CATPLMAutoNamingAdapter &);
    CATPLMAutoNamingAdapter& operator=(CATPLMAutoNamingAdapter&);
};

#endif
