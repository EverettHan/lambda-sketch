//----------------------------------------------------------------------------
// CATISwapFromModelToView.h
//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009                                     
//============================================================================
#ifndef CATISwapFromModelToView_H
#define CATISwapFromModelToView_H

/**
* @level Protected
* @usage U3
*/

#include "CATInteractiveInterfaces.h"
//
#include "CATSysBoolean.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#ifndef ListOfVarBaseUnknown
#define ListOfVarBaseUnknown CATLISTV(CATBaseUnknown_var)
#endif



#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATISwapFromModelToView;
#else
extern "C" const IID IID_CATISwapFromModelToView ;
#endif

/**
* Interface to support transformation of a model-oriented to a view-oriented object.
*/
class ExportedByCATInteractiveInterfaces CATISwapFromModelToView : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    /**
    * Predicate to know if object as a different modelization between model and view.
    * @return
    *   <dl>
    *     <dt>TRUE</dt>
    *     <dd>Operation supported</dd>
    *     <dt>FALSE</dt>
    *     <dd>Operation not supported</dd>
    *   </dl>  
    */
    virtual CATBoolean IsSwapFromModelToViewSupported() = 0;

    /**
    * Retrieves the corresponding view objects (possibly several ones).
    * @param oCorrespondingObjectsInView
    *   The list of view objects corresponding to current model object.
    * @return
    *   <dl>
    *     <dt>S_OK</dt>
    *     <dd>Operation succeeded</dd>
    *     <dt>S_FALSE</dt>
    *     <dd>Operation succeeded: value is unchanged</dd>
    *     <dt>E_FAIL</dt>
    *     <dd>Operation failed</dd>
    *   </dl>  
    */
    virtual HRESULT ApplySwapFromModelToView(CATBaseUnknown_var spCtx, ListOfVarBaseUnknown &oCorrespondingObjectsInView) = 0;
};

CATDeclareHandler(CATISwapFromModelToView, CATBaseUnknown);

#endif // CATISwapFromModelToView_H
