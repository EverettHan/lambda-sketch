#ifndef _CATOMBWOnLinkable_h
#define _CATOMBWOnLinkable_h

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"

#include "CATBaseUnknown.h"

#include "sequence_octet.h"
#include "CATBooleanDef.h"

//class dedicated to Give an identifier on linkable object
//strictly restricted to the R14 Delmia/cgr/TP project

#ifdef CATTPSFeatHashTable
#undef CATTPSFeatHashTable
#endif
#ifdef CATEFTAGenerateId
#undef CATEFTAGenerateId
#endif
#ifdef CATFTAIDServices
#undef CATFTAIDServices 
#endif
#ifdef CATEFTALightGenerateId
#undef CATEFTALightGenerateId
#endif
#ifdef CATEFTALightSetGenerateId
#undef CATEFTALightSetGenerateId
#endif
#ifdef CATOMBWOnLinkableTester
#undef CATOMBWOnLinkableTester 
#endif

class CATILinkableObject;
class CATOMBWOnLinkablePrivateData;

class ExportedByCATObjectModelerBase CATOMBWOnLinkable
{

	friend class CATTPSFeatHashTable; friend class CATEFTAGenerateId;
	friend class CATFTAIDServices; friend class CATEFTALightGenerateId;
	friend class CATEFTALightSetGenerateId;
	friend class CATOMBWOnLinkableTester;

	CATOMBWOnLinkable(CATILinkableObject* );

	CATOMBWOnLinkable(const SEQUENCE(octet)& CompleteId);

	CATOMBWOnLinkable(const SEQUENCE(octet)& ComponentId, const SEQUENCE(octet)& RelativeId);

	~CATOMBWOnLinkable();

	HRESULT GetClusterIdentifier (SEQUENCE(octet)& oName);

	HRESULT GetObjectRelativeIdentifier (SEQUENCE(octet)& oName);
	
	HRESULT GetHKeyOnIdentifier (unsigned int& oHkey);

	CATBoolean IsTheSame (CATOMBWOnLinkable&);	
	
	HRESULT GetIdentifier (SEQUENCE(octet)& oName);

	CATOMBWOnLinkablePrivateData& _Data;
};

#endif
  
