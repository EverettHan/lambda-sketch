// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMFilterRelationQuality.h
// Define the CATIPLMFilterRelationQuality interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Nov 2005  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterRelationQuality_H
#define CATIPLMFilterRelationQuality_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterRelationQuality;
#else
extern "C" const IID IID_CATIPLMFilterRelationQuality ;
#endif


class CATString;

//------------------------------------------------------------------

/**
* Interface representing Filter on relation Quality : Category or/and role. 
*
* CATIPLMFilterRelationQuality is used for specifying on which relation qualities you want to navigate
* Relation depends on the orientation (IN-OUT-NEUTRAL-IN/OUT) held by the category of the SR. 
* It depends also on others Categories qualifiers (Propagation Orientation, Visibility, Synchrosensitivity..) and Role of SR.
*/
class ExportedByCATPLMServicesItf CATIPLMFilterRelationQuality: public CATBaseUnknown
{
	CATDeclareInterface;
public:

	/**
	* Returns the Category applied on this semantic relation.
	* @param oCategory
	*   the category. NULL is no category applied.
	*/
	virtual HRESULT GetCategory( CATString ** oCategory ) = 0; 

	/**
	* Returns the Role applied on this semantic relation.
	* @param oRole
	*   the role. NULL is no role applied.
	*/
	virtual HRESULT GetRole( CATString ** oRole ) = 0; 

};

//------------------------------------------------------------------

#endif
