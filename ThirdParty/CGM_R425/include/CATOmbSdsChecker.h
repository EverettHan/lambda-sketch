//===================================================================
// COPYRIGHT Dassault Systemes 2020-02-28
//===================================================================
// CATOmbSdsChecker.cpp
// Header definition of class CATOmbSdsChecker
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2020-02-28 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmbSdsChecker_H
#define CATOmbSdsChecker_H

#include "CATOmxList.h"
#include "CATObjectModelerBase.h"
#include "CATOmxArray.h"
#include "CATPLMSDProperties.h"
#include "CATOmyResourceReference.h"

//-----------------------------------------------------------------------
class CATPLMSDProperties;
class CATOmyResourceReference;
class CATPLMID;
class CATUnicodeString;
class CATBaseUnknown;
class CATComponentId;
class CATVVSURLConnection;
class CATILockBytes2;
class CATVVSUrl;

class ExportedByCATObjectModelerBase CATOmbSdsChecker
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATOmbSdsChecker();
	virtual ~CATOmbSdsChecker();
	/**
	* Check Cache integrity by finding possible corruptions
	* Checks either storage or MD5 (depends on how the SD were saved)
	* Compatible with legacy data.
	* @param iSds [in]
	*   SD list to be checked (Format, Role, PersistencyType, PersistencyName, LateType, Watermarkstamp, SynchroStamp 
	*   and Url must be all set in the Block).
	* @param iAuthSd [in]
	*	the Authoring SD (all attributes must be set just like iSds)
	* @param oILB2 [out]
	*	The iLockByte to the connection made with the Authoring SD Url
	* @param oIsCorrupt [out]
	*	Test Result :
	*		TRUE : Record Corrupted
	*		FALSE : Record clean
	* @param oMessage [out]
	*	Error message (if oIsCorrupt is TRUE
	* @return
	*   <code>S_OK</code> if everything ran ok, otherwise E_FAIL;
	*/
	static HRESULT CheckStreamIntegrity(CATOmxArray<CATPLMSDProperties> iSds, const CATPLMSDProperties &iAuthSd,
		CATILockBytes2 *&oILB2, CATBoolean &oIsCorrupt, CATUnicodeString &oMessage);

private:
	// Copy constructor and equal operator
	// -----------------------------------
	CATOmbSdsChecker(CATOmbSdsChecker &);
	CATOmbSdsChecker& operator=(CATOmbSdsChecker&);
	static HRESULT CheckMD5OnComponent(CATOmxArray<CATOmyResourceReference> iUrlInfos, CATOmxArray<CATUnicodeString> SdMD5List, CATBoolean & oIsCorrupt, CATUnicodeString & oMessage);
	static HRESULT CheckWsInStorage(CATILockBytes2 * iILB2, int iWMS, CATBoolean & oIsCorrupt, CATUnicodeString & oMessage);

};

//-----------------------------------------------------------------------

#endif