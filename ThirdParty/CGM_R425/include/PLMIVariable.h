// (C) Copyright Dassault Systemes - 2010
// -----------------------------------------------------------------------
// Interface declaration: PLMIVariable
// -----------------------------------------------------------------------
// Creation: 2010-11-25
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIVariable_H_
#define _PLMIVariable_H_

#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIVariable;
#else
extern "C" const IID IID_PLMIVariable;
#endif



class ExportedByGUIDPLMPosBaseInterfaces PLMIVariable : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get variable name
	 */
	virtual HRESULT GetName(CATUnicodeString &oName) = 0;
	/**
	 * Get Value type (simple or list)
	 * Returns S_OK when it is a list, S_FALSE otherwise
	 */
	virtual HRESULT IsList() = 0;
	/**
	 * Get internal type (internal or not)
	 * Returns S_OK when it is internal, S_FALSE otherwise
	 */
	virtual HRESULT IsInternal() = 0;
	/**
	 * Get Value
	 */
	virtual HRESULT GetValue(CATUnicodeString &oValue) = 0;
	/**
	 * Get list of Values
	 */
	virtual HRESULT GetValues(CATListOfCATUnicodeString &oListOfValues) = 0;
	/**
	 * Get variable category
	 */
	virtual HRESULT GetCategory(CATUnicodeString &oCategory) = 0;
	/**
	 * Get external type (external parameters are pushed in connection parameters)
	 * Returns S_OK when it is external, S_FALSE otherwise
	 */
	virtual HRESULT IsExternal() = 0;
};

CATDeclareHandler(PLMIVariable,CATBaseUnknown);

#endif
