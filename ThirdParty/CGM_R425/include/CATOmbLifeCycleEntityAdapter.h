// COPYRIGHT Dassault Systemes 2006
#ifndef CATOmbLifeCycleEntityAdapter_H
#define CATOmbLifeCycleEntityAdapter_H
/**
 * @level Private 
 * @usage U2
 */

#include "CATOmbLifeCycle.h"
#include "CATIOmbLifeCycleEntity.h"
//------------------------------------------------------------------
#define AuthorizedModule 999
// List of authorized modules 
#define CATOmbLifeCycle                            AuthorizedModule
#define CATPLMClientCoreModel                      AuthorizedModule
#define CATPLMSpecsGenericBag                      AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATIOmbLifeCycleDelegate Services from a non-authorized module
// Fatal error on solaris
@error 
#endif

#undef CATOmbLifeCycle
#undef CATPLMClientCoreModel
#undef CATPLMSpecsGenericBag

//-----------------------------------------------------------------------

/**
* Adapter for interface CATIOmbLifeCycleEntity.
*
*/
class ExportedByCATOmbLifeCycle CATOmbLifeCycleEntityAdapter: public CATIOmbLifeCycleEntity
{

public:

	// Standard constructors and destructors
	// -------------------------------------
	CATOmbLifeCycleEntityAdapter ();
	virtual ~CATOmbLifeCycleEntityAdapter ();

	 virtual HRESULT ListPrerequisitesForRemove( CATListPtrCATBaseUnknown & oPreqs );
	 virtual HRESULT ListPostrequisitesForRemove( CATListPtrCATBaseUnknown & oPreqs );

private:
	// Copy constructor and equal operator
	// -----------------------------------
	CATOmbLifeCycleEntityAdapter (CATOmbLifeCycleEntityAdapter &);
	CATOmbLifeCycleEntityAdapter& operator=(CATOmbLifeCycleEntityAdapter&);

};

//-----------------------------------------------------------------------

#endif
