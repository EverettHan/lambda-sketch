#ifndef _CATPLMIndexError_H
#define _CATPLMIndexError_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U3
 */

#include "CATListOfCATUnicodeString.h"
#include "IUnknown.h" // for HRESULT

// System
#include "CATBoolean.h"

// Error Catalog
#include "CATMsgCatalog.h"

// Export
#include "GUIDCATPLMIndexInterfaces.h"

class ExportedByGUIDCATPLMIndexInterfaces CATPLMIndexError;

// List management
#include "CATLISTV_Clean.h"
#define CATLISTV_Append
#include "CATLISTV_Declare.h"
#undef  CATLISTV_eqOP
#undef  CATLISTV_neOP
CATLISTV_DECLARE(CATPLMIndexError)
typedef CATLISTV(CATPLMIndexError) CATListOfCATPLMIndexError;

/**
 * This class supplies methods to manage index errors.
 * <b>Role</b>: This class enables to get information related 
 * to the index errors.
 */
class ExportedByGUIDCATPLMIndexInterfaces CATPLMIndexError
{

public:

	CATPLMIndexError();

	// For usual case :
	// - SetErrorKey
	// - SetDefaultMessage
	// - Push
	CATPLMIndexError(const CATString &iKey, const CATUnicodeString &iMsg);

	~CATPLMIndexError();

	/**
	 *  Define Error Catalog (default is "CATPLMIndex").
	 */
	void SetErrorCatalog(const CATString &iCtlg);

	/**
	 *  Get Error Catalog.
	 */
	void GetErrorCatalog(CATString &oCtlg);

	/**
	 *  Define Error Key.
	 */
	void SetErrorKey(const CATString &iKey);

	/**
	 *  Get Error Key.
	 */
	void GetErrorKey(CATString &oKey);

	/**
	 *  Define Error Parameters List.
	 */
	void SetErrorParameters(const CATListOfCATUnicodeString &iParamList);

	/**
	 *  Add a CATUnicodeString parameter to the parameters list.
	 */
	void AddParam(const CATUnicodeString &iParam);

	/**
	 *  Add a parameter to the parameters list.
	 */
	void AddParam(const int iParam);

	/**
	 *  Default message (usefull if something gets wrong while reading NLS message).
	 */
	void SetDefaultMessage(const CATUnicodeString &iMsg);

	/**
	 *  Retrieve builded error message.
	 */
	void GetMessage(CATUnicodeString &oMsgReq, CATUnicodeString &oMsgDiag, CATUnicodeString &oMsgAdvice) ;

	/**
	 *  Add Error to stack.
	 */
	void Push() const;

	/**
	 *  Clean stack.
	 */
	static void CleanErrorStack();

	/**
	 *  Retrieve number of errors.
	 */
	static int GetErrorCount();

	/**
	 *  Get Error by number (Last error is given by GetErrorCount()).
	 */
	static void GetError(const int i, CATPLMIndexError &oError);

	/**
	 *  Get last error.
	 */
	static void GetLastError(CATPLMIndexError &oError);

	/**
	 *  @nodoc
	 */
	void operator = (const CATPLMIndexError &iError);


private:
	CATString					m_Ctlg;
	CATString					m_Key;
	CATListOfCATUnicodeString	m_ParamList;
	CATUnicodeString			m_Default;

	//CATMsgCatalog				m_MsgCatalog;
	//CATBoolean					m_MsgCatalogLoaded;

	static CATListOfCATPLMIndexError	&m_ErrorList;

	void GetDefaultMessage(CATUnicodeString &oMsgReq, CATUnicodeString &oMsgDiag, CATUnicodeString &oMsgAdvice) const;
};

#endif
