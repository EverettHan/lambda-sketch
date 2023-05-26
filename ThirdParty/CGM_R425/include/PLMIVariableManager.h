// (C) Copyright Dassault Systemes - 2010
// -----------------------------------------------------------------------
// Interface declaration: PLMIVariableManager
// -----------------------------------------------------------------------
// Creation: 2010-11-25
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIVariableManager_H_
#define _PLMIVariableManager_H_

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIVariableManager;
#else
extern "C" const IID IID_PLMIVariableManager;
#endif

class CATUnicodeString;
class PLMIVariable_var;


class ExportedByGUIDPLMPosBaseInterfaces PLMIVariableManager : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get a variable
	 */
	virtual HRESULT GetVariable(const CATUnicodeString &iName, PLMIVariable_var &oVar) = 0;
	/**
	 * Get all variables
	 */
	virtual HRESULT GetVariables(CATLISTV(CATBaseUnknown_var) &oListVar) = 0;
};

CATDeclareHandler(PLMIVariableManager,CATBaseUnknown);

#endif
