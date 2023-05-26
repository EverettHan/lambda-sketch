// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATCkeCoreBusinessLogic.h
// Header definition of CATCkeCoreBusinessLogic
//
//===================================================================
//
// Usage notes:
// Provides core business logic services
//
//===================================================================



#ifndef CATCkeCoreBusinessLogic_H 
#define CATCkeCoreBusinessLogic_H 

// Module export
#include "KnowledgeItf.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATCkePLMDefinitions.h"

class CATUnicodeString;

/**
 * Services used by navigation UI to access critical BLs.<br> 
 */
class ExportedByKnowledgeItf CATCkeCoreBusinessLogic 
{

  public:

	  /**
	  * Indicates if an object in a particular state, for a particular policy is to be considered as "frozen"
	  * meaning that it can not be edited in session (it is true for metastate frozen, released and obsolete)
	  * @param
	  * iPolicyName name of the policy (can be empty)
	  * @param
	  * iState name of the state of the object
	  * @param
	  * oIsFrozen indicate that the state is frozen. If no business rule found, the answer will be false by default
	  * @return
	  *  <ol>
	  * 	 <li> E_FAIL the business rule failed 
	  * 	 <li> S_OK the business rule succeeded
	  *  </ol>
      */
	  static HRESULT IsStateFrozen (const CATUnicodeString &iPolicyName,
									const CATUnicodeString &iStateName,
									CATBoolean &oIsFrozen) ;

	  /**
	  * Returns the meta maturity state name of an object in a particular state, for a particular policy.
	  * @param
	  * iPolicyName name of the policy (can be empty)
	  * @param
	  * iState name of the state of the object
	  * @param
	  * oMetaMaturityState indicate the meta maturity state. If no business rule found, the answer will be undefined by default
	  * @return
	  *  <ol>
	  * 	 <li> E_FAIL the business rule failed 
	  * 	 <li> S_OK the business rule succeeded
	  *  </ol>
      */
	  static HRESULT GetMetaMaturityState ( const CATUnicodeString &iPolicyName,
											const CATUnicodeString &iStateName,
											CATCkePLMDefinitions::MetaMaturityState &oMetaMaturityState);

private: 

};
 

#endif
