#ifndef CATIOmbUpdateOnCCMVariants_H
#define CATIOmbUpdateOnCCMVariants_H

/**
* @level Private
* @usage U3
*/

// List of forbidden re-define
#if defined (private) || defined(friend) || defined (protected)
	#error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif

// List of authorized infrastructure modules 
#define AuthorizedModule             999
#define CATOmbLinkApplicativeAccess   AuthorizedModule
#define PLMModelerBaseConfigInternal  AuthorizedModule
#define CATMxamModeler                AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden Access To CATIOmbUpdateOnCCMVariants
        // Fatal error on solaris
        @error 
#endif

#undef AuthorizedModule
#undef CATOmbLinkApplicativeAccess
#undef PLMModelerBaseConfigInternal
#undef CATMxamModeler

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

class CATComponentId;
class CATListValCATComponentId;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbUpdateOnCCMVariants ;
#else
extern "C" const IID IID_CATIOmbUpdateOnCCMVariants ;
#endif

/**
* @nodoc
* For internal use only.
*/
class ExportedByCATObjectModelerBase CATIOmbUpdateOnCCMVariants : public CATBaseUnknown
{
    CATDeclareInterface ;

public :

    virtual CATBoolean IsActivated() = 0;

    virtual HRESULT Do(CATListValCATComponentId & iOldCIDs, CATListValCATComponentId & iNewCIDs) = 0;
} ;

#endif

