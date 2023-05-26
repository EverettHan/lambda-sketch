// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATIPLMAdditionalSave.h
// Define the CATIPLMAdditionalSave interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2015  Creation: Code generated by the CAA wizard  son
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMAdditionalSave_H
#define CATIPLMAdditionalSave_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"


class CATLISTV(CATComponentId);
class CATComponentId;
class CATIOmyIncidentCollector_var;


#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAdditionalSave;
#else
extern "C" const IID IID_CATIPLMAdditionalSave ;
#endif

//------------------------------------------------------------------

/**
 * This interface is the external view of the additional save protocol.
 * <br><b>Role</b>: it is aimed at processing additional save transactions (on multiple providers), once regular save transaction has been performed successfully.
 *                      
 */

class ExportedByCATPLMIntegrationInterfaces CATIPLMAdditionalSave: public CATBaseUnknown
{
	CATDeclareInterface;
  public:

/**
* Processes an additional save transaction, once main save transaction has been performed successfully.
*                 	The save engine will never fail by calling this method, even in case of failure.
*                       However, in such case, errors posted will be shown to the end-uer.
* @param  iObjToSave 
*   The scope of the save. 
* @param  oErrorCollector
*   Allows the callee to post errors, that will be shown to the end-user.
* @return 
* <br><b>Legal values</b>
*   <dt>S_OK</dt>  
*   <dd>The additional save has succeeded. 
*       <br>Please note that S_OK means that no error occured during the additional save: nothing will be reported to the end-user.
*   </dd>
*   <dt>E_FAIL</dt>  
*   <dd>System error. Posted errors will be shown to the end-user, but the global save transaction won't fail.
*   </dd>
*   <dt>E_INVALIDARG</dt>  
*   <dd>Invalid argument</dd>
* <br>
* @see CATIPLMSaveScope, CATPLMEngineToolbox,CATIPLMEngineListener
*/
virtual HRESULT ExecuteAdditionalSave(const CATLISTV(CATComponentId) &iObjToSave, CATIOmyIncidentCollector_var &oErrorCollector) = 0;

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMAdditionalSave, CATBaseUnknown );

#endif
