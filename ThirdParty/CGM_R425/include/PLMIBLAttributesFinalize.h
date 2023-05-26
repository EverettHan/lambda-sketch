// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// PLMIBLAttributesFinalize.h
// Define the PLMIBLAttributesFinalize interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2008  Creation: Code generated by the CAA wizard  LHX
//===================================================================
#ifndef PLMIBLAttributesFinalize_H
#define PLMIBLAttributesFinalize_H

/**
* @level Protected
* @usage U1
*/

#include "PLMBusinessLogicInterfaces.h"
#include "CATBaseUnknown.h"

class CATIInstance_var;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLAttributesFinalize;
#else
extern "C" const IID IID_PLMIBLAttributesFinalize ;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* PLMIBLAttributesFinalize are ...
* <p>
* Do not use the PLMIBLAttributesFinalize interface for such and such

*
* @example
*  // example is optional
*  PLMIBLAttributesFinalize* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_PLMIBLAttributesFinalize,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByPLMBusinessLogicInterfaces PLMIBLAttributesFinalize: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Checks the coherence of the public PLM attributes valuation from the business logic definition point of view.
    *
    * @param iPLMComponent
    *   Component (may be a proxy) on which the check is requested
    *
    * @return
    *   <ul>
    *       <li> S_OK      if the business logic is successfully integrated </li>
    *       <li> S_FALSE   if their is no business logic to integrate </li>
    *       <li> E_FAIL    if an error occurs. The following error classes and error identifiers can be associated with:
    *           <ul>
    *               <li>   @error PLMBLAttributesValuationError PLMBLAttributesValuationError::RunCheck::InternalError
    *                      The business logic access service failed
    *               </li>
    *               <li>   @error PLMBLAttributesValuationError PLMBLAttributesValuationError::RunCheck::ValidationError
    *                      The business logic definition reported some attributes valuations warnings and/or errors
    *               </li>
    *               <li>   @error PLMBLAttributesValuationError PLMBLAttributesValuationError::RunCheck::ExecutionError
    *                      The business logic definition execution failed
    *               </li>
    *           </ul>
    *       </li>
    *   </ul>
    */
    virtual HRESULT RunCheck(CATIInstance_var & iPLMComponent) = 0;
};

//------------------------------------------------------------------

#endif