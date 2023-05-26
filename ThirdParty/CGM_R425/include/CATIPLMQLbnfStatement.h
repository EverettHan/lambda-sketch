#ifndef CATIPLMQLbnfStatement_H
#define CATIPLMQLbnfStatement_H

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMQLCPPParser.h"
#include "CATBaseUnknown.h"

class CATIPLMExpandResultHandler;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCATPLMQLCPPParser IID IID_CATIPLMQLbnfStatement;
#else
	extern "C" const IID IID_CATIPLMQLbnfStatement ;
#endif

//------------------------------------------------------------------

/**
 * Interface belonging to the <b>PLMQL services</b>.
 *
 * Provides basic methods for executing statements and retrieving results.
 */

class CATIPLMCompRecordReadSet;

class ExportedByCATPLMQLCPPParser CATIPLMQLbnfStatement: public CATBaseUnknown
{
 CATDeclareInterface;

public:

  virtual HRESULT SetAdditionnalParam(const CATUnicodeString& iKey,const CATUnicodeString& iValue) = 0;

  /**
  * Execute a PLMQL statement.
  * @param oRecordSet [out, CATBaseUnknown#Release]
  *    a CATIPLMCompRecordReadSet interface provides access to the result . 
  *	@return
  *			Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Statement is successfully executed .</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the Statement . get further information by using CATIPLMError</dd>
  *   </dl>
  */

	virtual HRESULT Execute (CATIPLMCompRecordReadSet ** oRecordSet)=0;

  /**
  * Execute Query count  PLMQL statement.
  * @param oNumberOfResults[out ,int]
  *    no of records
  *	@return
  *			Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Statement is successfully executed .</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the Statement . get further information by using CATIPLMError</dd>
  *   </dl>
  */

	virtual HRESULT ExecuteQueryCount (int & oNumberOfResults)=0;
  /**
  * Execute a PLMQL Push Expand statement.
  * @param iExpandHandler
  *     CATIPLMExpandResultHandler - expand handler
  *	@return
  *			Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Statement is successfully executed .</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the Statement . get further information by using CATIPLMError</dd>
  *   </dl>
  */
	virtual HRESULT ExecutePushExpand (CATIPLMExpandResultHandler * iExpandHandler)=0;
};
#endif
