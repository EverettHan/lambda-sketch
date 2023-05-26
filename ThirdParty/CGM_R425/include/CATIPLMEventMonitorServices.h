// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMEventMonitorServices.h
// Define the CATIPLMEventMonitorServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2011  Creation: FBN
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMEventMonitorServices_H
#define CATIPLMEventMonitorServices_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATIPLMCompEventMonitorServices.h"

class CATIPLMRecordReadSet;
class CATUnicodeString;
class CATPLMID_Any;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMEventMonitorServices;
#else
extern "C" const IID IID_CATIPLMEventMonitorServices ;
#endif
//------------------------------------------------------------------

/**
 * Interface belonging to the provider.
 */
class ExportedByCATPLMServicesItf CATIPLMEventMonitorServices: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	virtual HRESULT GetLog(CATUnicodeString &iName, LogType iType, CATOmxAny &oListEntry) = 0;
	virtual HRESULT PurgeLog(CATUnicodeString &iName, LogType iType, const CATOmxAny &iListEntry) = 0;

	/**
	 * @param iRepository [in]
	 *   Provider on which the service will be called. Can be NULL : will use the connected provider.
	 */
	virtual HRESULT PurgeAll(CATUnicodeString &iName, LogType iType) =0;
};
//------------------------------------------------------------------
#endif
