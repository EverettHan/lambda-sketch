// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATPLMQLbnfServices.h				NKJ
//===================================================================

#ifndef CATPLMQLbnfServices_H
#define CATPLMQLbnfServices_H

/**
* @level Private
* @usage U1
*/


//for exported by
#include "CATPLMQLCPPParser.h"
#include "CATBaseUnknown.h"


//fwd decl...
class CATPLMRepositoryName;
class CATUnicodeString;
class CATIPLMQLbnfStatement;
class CATITemplatePLMQLbnfStatement;
#include "CATCollec.h"
class CATLISTV(CATUnicodeString);
//-----------------------------------------------------------------------

/**
* Services class to create PLMQL statements.
*/
class ExportedByCATPLMQLCPPParser CATPLMQLbnfServices
{
  friend class TSTCATPLMxCATPLMQLChangeMaturity_On_Two_Plmids;//to be able to use CreateTemplatePLMQLStatement(const CATLISTV(CATUnicodeString)& ilplmql, CATITemplatePLMQLbnfStatement **oStatement, CATPLMRepositoryName *iProviderName=NULL);
public:
  /**
  * Validates the PLMQL statement and give access to the CATIPLMQLbnfStatement for executing the statement.
  * @param iplmql [In]
  *    a PLMQL statement string. 
  * @param oStatement [out, CATBaseUnknown#Release]
  *    a CATIPLMQLbnfStatement interface provides access to the Execute. 
  * @param iProviderName [In]
  *    Connected provider name. 
  *	@return
  *			Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>PLMQL statement is syntactically and semantically correct </dd>
  *     <dt>E_FAIL </dt>
  *     <dd>PLMQL statement is either syntactically or semantically  incorrect,get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */

  static HRESULT CreatePLMQLStatement(CATUnicodeString *iplmql, CATIPLMQLbnfStatement **oStatement, CATPLMRepositoryName *iProviderName=NULL);
  /**
  * Validates the Template PLMQL statement and give access to the CATITemplatePLMQLbnfStatement for executing the statement.
  * @param iplmql [In]
  *    a PLMQL statement string. 
  * @param oStatement [out, CATBaseUnknown#Release]
  *    a CATIPLMQLbnfStatement interface provides access to the Execute. 
  * @param iProviderName [In]
  *    Connected provider name. 
  *	@return
  *			Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>PLMQL statement is syntactically correct </dd>
  *     <dt>E_FAIL </dt>
  *     <dd>PLMQL statement is syntactically incorrect,get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  static HRESULT CreateTemplatePLMQLStatement(CATUnicodeString *iplmql, CATITemplatePLMQLbnfStatement **oStatement, CATPLMRepositoryName *iProviderName=NULL);
private:
  static HRESULT CreateTemplatePLMQLStatement(const CATLISTV(CATUnicodeString)& ilplmql, CATITemplatePLMQLbnfStatement **oStatement, CATPLMRepositoryName *iProviderName=NULL);

};
#endif
