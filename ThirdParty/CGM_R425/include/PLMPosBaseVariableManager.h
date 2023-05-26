// (C) Copyright Dassault Systemes - 2010
// -----------------------------------------------------------------------
// Class declaration PLMPosBaseVariableManager
// -----------------------------------------------------------------------
// Creation: 2010-11-25
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U1
 */

#ifndef _PLMPosBaseVariableManager_H_
#define _PLMPosBaseVariableManager_H_

#include "CATBaseUnknown.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class PLMIVariable_var;
class CATLISTV(CATBaseUnknown_var);

#include "CATHashDico.h"
#include "CATHDICO_Clean.h"
#define CATHDICO_Insert
#define CATHDICO_Locate
#define CATHDICO_ApplyDelete
#define	CATHDICO_Remove
#define CATHDICO_RemoveAll
#include "CATHDICO_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByGUIDPLMPosBaseInterfaces
CATHDICO_DECLARE( PLMIVariable )
#define HashPLMIVariable CATHDICO( PLMIVariable )


class ExportedByGUIDPLMPosBaseInterfaces PLMPosBaseVariableManager : public CATBaseUnknown
{
	CATDeclareClass;
public:
	PLMPosBaseVariableManager();
	~PLMPosBaseVariableManager();
	// Interface PLMIVariableManager methods:
	/**
	 * Get a variable
	 */
	HRESULT GetVariable(const CATUnicodeString &iName, PLMIVariable_var &oVar);
	// Interface PLMIVariableManagerInit methods:
	/**
	 * Set a variable from a stream line
	 */
	HRESULT SetVariable(const CATUnicodeString &iRawVar, const CATUnicodeString &iRawValue, PLMIVariable_var &oVar);
	/**
	 * Get all variables
	 */
	HRESULT GetVariables(CATLISTV(CATBaseUnknown_var) &oListVar);
private:
    void SetListFrom(const CATUnicodeString& isList, CATListOfCATUnicodeString& ioList);
    HashPLMIVariable _variables;
    CATListOfCATUnicodeString _categories;
protected:
	//
	virtual HRESULT Decrypt(int iAlgo, const CATUnicodeString &iParam, const CATUnicodeString &iEncryptedValue, CATUnicodeString &oDecryptedValue);
};

#endif
