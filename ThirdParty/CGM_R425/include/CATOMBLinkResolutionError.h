#ifndef CATOmbLinkResolutionError_H
#define CATOmbLinkResolutionError_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"

#include "CATOmbErrorDef.h"

class CATUnicodeString;


class ExportedByCATObjectModelerBase CATOMBLinkResolutionError
{
public :

	/** @nodoc */
	static HRESULT  GetErrorReason(HRESULT , CATUnicodeString&);

private:

	/** @nodoc */
	CATOMBLinkResolutionError();

	/** @nodoc */
	~CATOMBLinkResolutionError();
};

// Links error codes: from CATOmb_ERR_BASE + 0x00 -> CATOmb_ERR_BASE + 0x39

#define PrivateLinkError(err)\
	MAKE_HRESULT(SEVERITY_ERROR,FACILITY_ITF, (  CATOmb_ERR_BASE + (unsigned long)err ) )


//HRESULT OK
//ivd la double definition est temporaire le temps de la migration des HR_LINKSOLVE......
#define HR_LINKSOLVE_ObjectDoesNotExist                 PrivateLinkError(11)
#define HR_LINKSOLVE_ObjectNotFound						PrivateLinkError(11)


#define HR_LINKSOLVE_InvalidLink						PrivateLinkError(1)
#define HR_LINKSOLVE_InvalidHint						PrivateLinkError(1)
#define HR_LINKSOLVE_InvalidSequence					PrivateLinkError(1)
#define HR_LINKSOLVE_UnknownNamingContextError          PrivateLinkError(1)

#define HR_LINKSOLVE_DataNotLoaded                      PrivateLinkError(10)
#define HR_LINKSOLVE_ContainerNotLoaded					PrivateLinkError(23)

#define HR_LINKSOLVE_DynamicTargetNotDefined            PrivateLinkError(2)
#define HR_LINKSOLVE_ResolutionCurrentlyImpossible      PrivateLinkError(12)

#define HR_LINKSOLVE_MismatchingUUID					PrivateLinkError(3)
#define HR_LINKSOLVE_ContainerNotFound                  PrivateLinkError(3)
//.edu
#define HR_LINKSOLVE_ContainerNotFoundInSession         PrivateLinkError(10)


//Private Usage Only: CATIALocate usage only DO NOT USE
#define HR_LINKSOLVE_ComponentInVisuMode                PrivateLinkError(4)
#define HR_LINKSOLVE_DocumentNotLoaded					PrivateLinkError(5)
#define HR_LINKSOLVE_ComponentDoesNotExist              PrivateLinkError(7)
#define HR_LINKSOLVE_ComponentInTOSMode					PrivateLinkError(8)
#define HR_LINKSOLVE_ProxyNotSynchronized				PrivateLinkError(15)

#define HR_LINKSOLVE_DocNotFoundByLocator				PrivateLinkError(14)
#define HR_LINKSOLVE_DocNotFound						PrivateLinkError(14)

// Link unset by system during LinkDoctor consultation (typically after FBDI import)
#define HR_LINKSOLVE_LinkUnsetBySystem					PrivateLinkError(22)

#define CATReturnLinkError( iCode ) return HR_LINKSOLVE_##iCode


#endif
