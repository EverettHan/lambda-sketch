#ifndef CATCkePLMHighLevelServicesSupport_h
#define CATCkePLMHighLevelServicesSupport_h

// COPYRIGHT Dassault Systemes 2012 
#include <stddef.h>
#include "CATBoolean.h"
#include "CATBaseUnknown.h" // HRESULT
#include "PLMDictionaryInterfaces.h"
#include "CATListOfCATUnicodeString.h"

class CATUnicodeString;

 


class ExportedByPLMDictionaryInterfaces CATCkePLMHighLevelServicesSupport 
{
	public:

		// retrieves a pointer to the current solution/environement. Pointer may be NULL if no environment set
		// In this case, you can consider that the system supports no operation
		static CATCkePLMHighLevelServicesSupport &GetCurrentSolution ();

		CATCkePLMHighLevelServicesSupport(const CATCkePLMHighLevelServicesSupport &Copy);

		enum Options {  MajorRevision =1,
						MinorRevision =2,
						Maturity =3 };

#if 0
    //-- [chd:02.12.2019] apparemment cette méthode est inutilisée
		// Does the system support this operation
		// HRESULT S_OK is supports, S_FALSE if does not support
		HRESULT SupportsThisOption (const Options iOption) const;
#endif
						
		// returns the list of attributes to hide in the masks 
		const CATListOfCATUnicodeString *ListNotSupportedAttributes () const;

	private:
		CATCkePLMHighLevelServicesSupport();
		~CATCkePLMHighLevelServicesSupport();
		
		// current solution
		static CATCkePLMHighLevelServicesSupport _Current;
		
		// list of attributes 
		CATBoolean _computed;
		int _collab_ENOVIA_Maturity_Browse;
		int _collab_ENOVIA_Lifecycle_MajorVersion_Browse;
		int _collab_ENOVIA_Lifecycle_MinorVersion_Browse;
		int _collab_ENOVIA_Duplicate_Origin_Browse;
		int _collab_ENOVIA_Ownership_Organization_Browse;
		int _collab_ENOVIA_Collaborative_Policy_Browse;
		int _collab_ENOVIA_DesignRange_Browse;
		CATListOfCATUnicodeString _notSupportedAttributes;

		void Compute();

};

#endif // CATCkePLMHighLevelServicesSupport_h

