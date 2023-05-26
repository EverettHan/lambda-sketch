// (C) Copyright Dassault Systemes - 2010
// -----------------------------------------------------------------------
// Interface declaration: PLMIPosSecurityEngineVarMgr
// -----------------------------------------------------------------------
// Creation: 2010-11-25
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIPosSecurityEngineVarMgr_H_
#define _PLMIPosSecurityEngineVarMgr_H_

#include "CATBaseUnknown.h"

#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIPosSecurityEngineVarMgr;
#else
extern "C" const IID IID_PLMIPosSecurityEngineVarMgr;
#endif

class CATUnicodeString;
class PLMIVariableManager_var;


class ExportedByGUIDPLMPosBaseInterfaces PLMIPosSecurityEngineVarMgr : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get a variable
	 */
	virtual HRESULT SetVariableManager(PLMIVariableManager_var &iVarMgr) = 0;
};

CATDeclareHandler(PLMIPosSecurityEngineVarMgr,CATBaseUnknown);

#endif
