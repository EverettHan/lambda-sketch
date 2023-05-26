// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIBRUtilities.h
// Define the CATIBRUtilities interface
//
//===================================================================
//
// Usage notes:
//   New interface: it is used to provide some BR services.
//
//===================================================================
//
//  Sept 2007  Creation: Code generated by the CAA wizard  hcg
//===================================================================
#ifndef CATIBRUtilities_H
#define CATIBRUtilities_H

#include "CATLifSpecs.h"

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIInstance.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIBRUtilities;
#else
extern "C" const IID IID_CATIBRUtilities ;
#endif

class CATIRuleBase_var;

//------------------------------------------------------------------

/**
* Interface representing BRUtilities.
*
* <br><b>Role</b>: Components that implement the BR execution services.
* CATIBRExecutionServices is used to execute BR services.
*
*/
class ExportedByCATLifSpecs CATIBRUtilities: public CATBaseUnknown
{
	CATDeclareInterface;

public:
 
	/**
	* To generate the corresponding CATIRuleBase from the given PLM RuleSet
	*
	* @param iPLMRuleSet
	*   A given PLM RuleSet reference object.
	* @param oRuleBase
	*   The returned corresponding CATIRuleBase object
	* 
	* @return S_OK
	*   The CATIRuleBase object is successfully generated.
	* @return E_FAIL
	*   Fail to generate CATIRuleBase object.
	*/
	virtual HRESULT GenerateRuleBase (const CATBaseUnknown_var& iPLMRuleSet, CATIRuleBase_var& oRuleBase) = 0;

};

CATDeclareHandler(CATIBRUtilities, CATBaseUnknown);
//------------------------------------------------------------------

#endif
